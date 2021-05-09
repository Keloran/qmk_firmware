# Keloran's userspace
This is some of the code that is used by multiple of my keyboards

___
# Builder
You can use the builder for yourself, you need to copy the builder.json file and put in your users folder

then modify the file with your boards and username

edit the ```.gitignore``` and add your ```builder.yaml``` to the allow ```!users/<username>/builder.yaml``` 

now edit ```.github/workflows/builder.yaml``` and change to your repo, and users path for the json ```line 23```

now when ever you make a change to your keymap files it will build in your github actions