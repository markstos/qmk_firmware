#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum {
 TD_CLN = 0,
 TD_LBR=1,
 TD_RBR=2
};

#define _QWERTY 0
#define _NAV 1
#define _SYMBOLS 2
#define _WINDOWS 3

#define _CODE MO(_WINDOWS)
#define _FSYM LT(_SYMBOLS,KC_F)
#define _ZCTL LCTL_T(KC_Z)
#define _XALT LALT_T(KC_X)
#define _CGUI LGUI_T(KC_C)
#define _TERM LGUI(KC_GRAVE)
#define _COMGUI RGUI_T(KC_COMM)
#define _DOTALT LALT_T(KC_DOT)
#define _SLSHCTL RCTL_T(KC_SLSH)
#define _ENTGUI LGUI_T(KC_ENT)
#define _SPCNAV LT(_NAV,KC_SPC)
#define _LINE_DOWN LALT(LSFT(KC_DOWN))
#define _LINE_UP LALT(LSFT(KC_UP))
#define _TD_CLN TD(TD_CLN)
#define _TD_LBR TD(TD_LBR)
#define _TD_RBR TD(TD_RBR)
#define ____ KC_NO

// enum custom_keycodes {
//   LOWER,
//   RAISE,
//   ADJUST,
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _CODE,    KC_A,    KC_S,    KC_D,   _FSYM,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,   _TD_CLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSPO,  _ZCTL,   _XALT,   _CGUI,    KC_V,    KC_B,  _TD_LBR,          _TD_RBR,    KC_N,    KC_M,   _COMGUI, _DOTALT, _SLSHCTL, KC_RSPC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MO(_NAV), KC_DEL,  _ENTGUI,                  _SPCNAV, KC_BSPC,  MO(_SYMBOLS)
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘



    ),

    [_NAV] = LAYOUT(
        RGB_TOG, RGB_SPI, RGB_HUI, RGB_VAI, RGB_SAI, ____,                     ____, ____, ____, ____, KC_WH_U, ____,
        RGB_MOD, RGB_SPD, RGB_HUD, RGB_VAD, RGB_SAD, ____,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D, ____,
        RGB_RMOD, ____, ____, KC_MUTE, KC_VOLU, KC_BTN1,                       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ____, ____,
        KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, KC_VOLD, KC_BTN2, ____,         ____, ____, _LINE_DOWN, _LINE_UP, ____, ____, ____,
                                                  ____, ____, ____,         ____, ____, ____
    ),
	[_SYMBOLS] = LAYOUT(
        ____, ____, ____, ____, ____, ____,                  ____, ____, KC_LCBR, KC_RCBR, ____, ____,
        ____, ____, ____, ____, ____, ____,                  KC_LT, KC_GT, KC_LBRC, KC_RBRC, ____, ____,
        ____, ____, ____, ____, ____, ____,                  KC_PLUS, KC_EQL, KC_LPRN, KC_RPRN, ____, ____,
        ____, ____, ____, ____, ____, ____, ____,      ____, ____, KC_GRV, KC_QUOT, KC_DQUO, ____, ____,
                                ____, ____, ____,      ____, ____, ____
    ),
	[_WINDOWS] = LAYOUT(
        ____, ____, ____, ____, ____, ____,                  HYPR(KC_6), HYPR(KC_7), HYPR(KC_8), HYPR(KC_9), ____, ____,
        ____, ____, ____, ____, RESET, ____,                  HYPR(KC_Y), HYPR(KC_U), HYPR(KC_I), HYPR(KC_O), ____, ____,
        ____, ____, ____, DEBUG, ____, ____,                  HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), ____, ____,
        ____, ____, ____, ____, ____, ____, ____,      ____, HYPR(KC_N), HYPR(KC_M), HYPR(KC_COMMA), HYPR(KC_DOT), ____, ____,
                                ____, ____, ____,      ____, KC_TRNS, ____
    )
};





void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  }
}

void dance_lbrackets_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LSFT);
    register_code (KC_9);
  } else if (state->count == 2) {
    register_code (KC_LBRC);
  } else {
    register_code (KC_LSFT);
    register_code (KC_LBRC);
  }
}

void dance_lbrackets_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_9);
    unregister_code (KC_LSFT);
  } else if (state->count == 2) {
    unregister_code (KC_LBRC);
  } else {
    unregister_code (KC_LBRC);
    unregister_code (KC_LSFT);
  }
}

void dance_rbrackets_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LSFT);
    register_code (KC_0);
  } else if (state->count == 2) {
    register_code (KC_RBRC);
  } else {
    register_code (KC_LSFT);
    register_code (KC_RBRC);
  }
}

void dance_rbrackets_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_0);
    unregister_code (KC_LSFT);
  } else if (state->count == 2) {
    unregister_code (KC_RBRC);
  } else {
    unregister_code (KC_RBRC);
    unregister_code (KC_LSFT);
  }
}


//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset),
 [TD_LBR] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_lbrackets_finished, dance_lbrackets_reset),
 [TD_RBR] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rbrackets_finished, dance_rbrackets_reset),

};
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif
//   return true;
// }

// Future tap dance excellence
// https://pastebin.com/V8jcmNGr
