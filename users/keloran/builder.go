package main

import (
	"bytes"
	"flag"
	"fmt"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"sort"
	"strings"
	"io/ioutil"
	"encoding/json"
)

type Board struct {
	Name string
	Path string
}

type Boards struct {
	Username string  `json:"user"`
	Boards   []Board `json:"boards"`
}

var userName string

func getBoards() (Boards, error) {
    var boards Boards

	builderFile := "builder.json"
	fi, err := os.Lstat(builderFile)
	if err != nil {
		return boards, fmt.Errorf("getBoards - lstat: %w", err)
	}

	if fi.Mode()&os.ModeSymlink != os.ModeSymlink {
		return boards, fmt.Errorf("builder.json must be a symlink from users folder")
	}

	fp, err := filepath.EvalSymlinks(builderFile)
	if err != nil {
		return boards, fmt.Errorf("getBoards - evalSymlink: %w", err)
	}
	user := strings.TrimPrefix(fp, "users/")
	user = strings.TrimSuffix(user, fmt.Sprintf("/%s", builderFile))

	f, err := os.Open(builderFile)
	if err != nil {
		log.Fatal("you don't have a builder.json")
	}
	defer f.Close()
	content, _ := ioutil.ReadAll(f)
	json.Unmarshal(content, &boards)

	if user == "" {
	    user = boards.Username
	}

	if len(boards.Boards) == 0 {
		log.Fatal("you need need to add some boards to the builder.json")
	}

	userName = user

	return boards, nil
}

func getBoardNames() ([]string, error) {
	ret := []string{}
	boards, err := getBoards()
	if err != nil {
		return ret, fmt.Errorf("getBoardNames, getBoards: %w", err)
	}

	for _, board := range boards.Boards {
		ret = append(ret, board.Name)
	}

	return ret, nil
}

func matchBoard(keyboard string) (Board, error) {
	boards, err := getBoards()
	if err != nil {
		return Board{}, fmt.Errorf("matchBoard - getBoards: %w", err)
	}
	for _, board := range boards.Boards {
		if board.Name == keyboard {
			return board, nil
		}
	}

	return Board{}, fmt.Errorf("no boards found")
}

func main() {
	keyboard := ""
	if len(os.Args) >= 2 {
		for _, arg := range os.Args[1:] {
			if strings.Contains(arg, "-") {
				continue
			}
			keyboard = arg
		}

	}

	list := flag.Bool("list", false, "List Boards")
	help := flag.Bool("help", false, "Help")
	clean := flag.Bool("clean", false, "Clean")
	all := flag.Bool("all", false, "All Boards")
	flag.Parse()

	if *help {
		displayHelp()
		return
	}

	if *clean {
		if err := cleanBuilds(); err != nil {
			fmt.Printf("Clean Err: %s\n", err)
			return
		}
	}

	if *list {
		boards, err := getBoardNames()
		sort.Strings(boards)
		if err != nil {
			fmt.Printf("list - getBoardNames: %w\n", err)
			return
		}
		for _, board := range boards {
			fmt.Printf("%s\n", board)
		}
		return
	}

	if *all {
		boards, err := getBoardNames()
		if err != nil {
			fmt.Printf("all - getBoardNames: %w\n", err)
			return
		}

		for _, board := range boards {
			matched, err := matchBoard(board)
			if err != nil {
				fmt.Printf("all boards: %w\n", err)
				return
			}

			if err := matched.build(true); err != nil {
				fmt.Printf("%s\n", err)
				return
			}
		}
		return
	}

	if keyboard != "" {
		matched, err := matchBoard(keyboard)
		if err != nil {
			fmt.Printf("build - matchBoard: %w\n", err)
			return
		}

		if foundBoard := matched; foundBoard.Name != "" {
			foundBoard.build(false)
		} else {
			boards, err := getBoardNames()
			if err != nil {
				fmt.Printf("build - getBoardNames: %w\n", err)
				return
			}
			fmt.Printf("keyboard: %s not found\n", keyboard)
			fmt.Printf("keyboards supported: %s\n", boards)
			return
		}
	} else {
		if *clean {
			return
		} // might just want to clean
		displayHelp()
		return
	}
}

func (b Board) build(silent bool) error {
	fmt.Printf("Building: %s\n", b.Name)

	if b.Path == "" {
	    b.Path = b.Name
	}

	var out bytes.Buffer
	var errBuf bytes.Buffer
	cmd := exec.Command("make", fmt.Sprintf("%s:%s", b.Path, userName))
	cmd.Stdout = &out
	cmd.Stderr = &errBuf
	if err := cmd.Run(); err != nil {
		if !silent {
			log.Printf("%s failed: %+v\n\n%s\n%s\n", b.Name, err, out.String(), errBuf.String())
			return nil
		} else {
			return fmt.Errorf("%s failed: %+v\n\n%s\n%s\n", b.Name, err, out.String(), errBuf.String())
		}
	}
	if !silent {
		log.Printf("Board: %s\n%s", b.Path, out)
	}
	return nil
}

func displayHelp() {
	fmt.Printf("Usage: builder <keyboard>\n")
	fmt.Printf("\tKeyboards Supported:\n")
	boards, err := getBoardNames()
	if err != nil {
		fmt.Printf("displayHelp - getBoardNames: %w\n", err)
		return
	}
	for _, board := range boards {
		fmt.Printf("\t\t%s\n", board)
	}
	fmt.Printf("\n")
}

func delFiles(pattern string) error {
	p, err := os.Getwd()
	if err != nil {
		return fmt.Errorf("delFiles - Getwd: %w", err)
	}

	files, err := filepath.Glob(fmt.Sprintf("%s/%s", p, pattern))
	if err != nil {
		return fmt.Errorf("delFiles - glob: %w", err)
	}
	for _, f := range files {
		err = os.Remove(f)
		if err != nil {
			return fmt.Errorf("delFiles - %s - %w", f, err)
		}
	}

	return nil
}

func cleanBuilds() error {
	err := os.RemoveAll(".build")
	if err != nil {
		return fmt.Errorf("cleanBuilds - remove .build: %w", err)
	}

	err = delFiles("*.hex")
	if err != nil {
		return fmt.Errorf("cleanBuilds - hex: %w", err)
	}

	err = delFiles("*.bin")
	if err != nil {
		return fmt.Errorf("cleanBuilds - bin: %w", err)
	}

	if err := exec.Command("make", "clean").Run(); err != nil {
		return fmt.Errorf("failed to make clean: %w", err)
	}

	fmt.Print("Cleaned\n")
	return nil
}
