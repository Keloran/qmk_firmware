# NKey Rollover
NKRO_ENABLE = yes

# Smaller build
LTO_ENABLE = yes

# Words Per Minute
WPM_ENABLE = yes

# Extra key functions
TAP_DANCE_ENABLE = yes

# WebUSB
WEBUSB_ENABLE = no
ORYX_ENABLE = no

# include the build
SRC += ./keloran.c
SRC += ./oled.c
SRC += ./bitc.c
SRC += ./tap_dance.c
SRC += ./rotary.c
SRC += ./rgb.c
