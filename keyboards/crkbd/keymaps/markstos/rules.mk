# markstos: Attempt to enable Bootmagic
#BOOTMAGIC_ENABLE = lite
# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/keylogger.c \
        ./lib/mode_icon_reader.c \
        #./lib/logo_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \

# markstos: enable media keys
EXTRAKEY_ENABLE = yes

# markstos: smaller file size, litlte downsize
LINK_TIME_OPTIMIZATION_ENABLE = yes

# markstos: for combos!
COMBO_ENABLE = yes

# markstos: enable LEDs
#RGB_MATRIX_ENABLE = WS2812

# markstos: try QMK's DFU
#BOOTLOADER = qmk-dfu

# markstos
# Backlighting is not RGB underglow or RGB matrix
BACKLIGHT_ENABLE           = no  # Enable keyboard backlight functionality

# This is for RGB *underglow*
# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
RGBLIGHT_ENABLE = yes
