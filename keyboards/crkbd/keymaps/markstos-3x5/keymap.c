#include QMK_KEYBOARD_H

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNC 3

#define OSM_LALT OSM(MOD_LALT)
#define OSM_RALT OSM(MOD_RALT)

#define ALT_C      LALT_T(KC_C)
#define ALT_GRV    LALT_T(KC_GRV)  
#define ALT_COPY   LALT_T(KC_COPY)

#define ALT_COMM   ALGR_T(KC_COMMA)
#define ALT_MNXT   ALGR_T(KC_MNXT)

#define CTL_ESC    LCTL_T(KC_ESC)

// markstos defines

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT
};

enum combos {
  JK_ESC,
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

  // For Vim, put Escape on the home row
  [JK_ESC]    = COMBO(jk_combo, KC_ESC),

};

uint16_t get_tapping_term(uint16_t keycode) {
    switch (keycode) {
// This is on the Raise layer. I don't need a short tapping term here
//       case CTL_ESC:
//             return TAPPING_TERM_THUMB;
      case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_THUMB;
      case LT(_LOWER, KC_TAB):
            return TAPPING_TERM_THUMB;
// I rarely use the function layerc so I want to have a longer tapping term
//      case LT(_FUNC, KC_SPC):
//            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,KC_QUOTE, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_Z,    KC_X,   ALT_C,    KC_V,    KC_B,                         KC_N,    KC_M ,ALT_COMM,  KC_DOT,KC_SLSH,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                 OSM(MOD_LCTL),  GUI_T(KC_ENT),  LT(_LOWER, KC_TAB),     LT(_RAISE, KC_BSPC),  LT(_FUNC, KC_SPC),  OSM(MOD_LSFT)  \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BSLS, KC_TILD,ALT_GRV, KC_LBRC, KC_LCBR,                      KC_RCBR, KC_RBRC, ALT_COMM,KC_DOT,  KC_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,  KC_TRNS, LOWER,    KC_MINS, KC_TRNS, KC_COLON \
                                      //`--------------------------'  `--------------------------'
    ),

 
  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_DEL , XXXXXXX, KC_UNDS, KC_PLUS, KC_SCLN,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_PIPE, XXXXXXX, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_HOME, KC_END,  KC_PIPE, KC_EQL , KC_PGUP,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_APP, XXXXXXX, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LT,    KC_GT, ALT_COPY,KC_PASTE, KC_PGDN,                    KC_MPLY, KC_MPRV,ALT_MNXT, KC_VOLD, KC_VOLU, XXXXXXX, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, KC_TRNS, XXXXXXX,    RAISE, KC_TRNS, KC_TRNS \
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_CAPS, XXXXXXX, OSM_LALT,XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, OSM_RALT,XXXXXXX, RESET,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, FUNC, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  )
};

// void persistent_default_layer_set(uint16_t default_layer) {
//   eeconfig_update_default_layer(default_layer);
//   default_layer_set(default_layer);
// }
// 
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         persistent_default_layer_set(1UL<<_QWERTY);
//       }
//       return false;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _FUNC);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _FUNC);
//       }
//       return false;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _FUNC);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _FUNC);
//       }
//       return false;
//     case FUNC:
//         if (record->event.pressed) {
//           layer_on(_FUNC);
//         } else {
//           layer_off(_FUNC);
//         }
//         return false;
//     default:
//       return true;
//   }
//   return true;
// }
