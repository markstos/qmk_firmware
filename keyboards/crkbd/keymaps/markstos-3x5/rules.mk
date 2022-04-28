# markstos: Attempt to enable Bootmagic
#BOOTMAGIC_ENABLE = lite

BOOTLOADER = atmel-dfu

# markstos: enable media keys
EXTRAKEY_ENABLE = yes

# markstos: smaller file size, little down-side
LINK_TIME_OPTIMIZATION_ENABLE = yes

# markstos: no more combos
COMBO_ENABLE = no

# markstos
# Backlighting is not RGB underglow or RGB matrix
BACKLIGHT_ENABLE = no  # Enable keyboard backlight functionality

# This is for RGB *underglow*
# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
RGBLIGHT_ENABLE = no

TAP_DANCE_ENABLE = no
