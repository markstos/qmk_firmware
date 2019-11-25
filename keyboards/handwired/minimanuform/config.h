#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    bendalton
#define PRODUCT         DactylMiniManuform
#define DESCRIPTION     Mini Dactyl Manuform

/* mouse config */
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { D0, D4, C6, D7, E6 }

#define MATRIX_COL_PINS { B1, B3, B2, B6, B5, B4 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
// #define DEBOUNCING_DELAY 5

#define RETRO_TAPPING

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D1
#define USE_SERIAL

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define COMBO_COUNT 16
// #define COMBO_ALLOW_ACTION_KEYS
#define COMBO_TERM 150

#endif
