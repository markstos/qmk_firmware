#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// tap dance layers
enum {
 TD_CLN = 0, // ; or : or tap/dbl
 TD_CP = 3, // copy/paste/get last clipboard item/clipboard manager for tap/dbl/trpl/hold
 TD_DASH = 4, // - or _ for tap/dbl
 TD_QUOTE = 5, // ' or '' for tap/dbl
 TD_NUMTERM = 6, // hold for num layer, dbl tap toggle num layer, or tap for term
};

enum my_keycodes {
  TOGGLE_LIGHTS = SAFE_RANGE,
  BRIGHTER,
  DIMMER
};

#define _QWERTY 0
#define _COLEMAK 1
#define _NAV 2
#define _SYMBOLS 3
#define _COMMAND 4
#define _NUMBERS 5

#define _CODE MO(_COMMAND)
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
#define _PREV_TAB LGUI(LSFT(KC_LBRC))
#define _NEXT_TAB LGUI(LSFT(KC_RBRC))
#define _TD_CLN TD(TD_CLN)
#define _TD_CP TD(TD_CP)
#define _TD_DASH TD(TD_DASH)
#define _TD_QUOTE TD(TD_QUOTE)
#define _TD_NUMTERM TD(TD_NUMTERM)
#define _WINMODE MAGIC_TOGGLE_CTL_GUI
#define ____ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _TD_DASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _CODE,    KC_A,    KC_S,    KC_D,   KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,   _TD_CLN, _TD_QUOTE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  _ZCTL,   _XALT,   _CGUI,    KC_V,    KC_B,  _TD_CP,        _TD_NUMTERM, KC_N,    KC_M,   _COMGUI, _DOTALT, _SLSHCTL, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MO(_NAV), KC_DEL,  _ENTGUI,                  _SPCNAV, KC_BSPC,  MO(_SYMBOLS)
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _TD_DASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    _TD_CLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _CODE,    KC_A,    KC_R,    KC_S,   KC_T,    KC_D,                                KC_H,    KC_N,    KC_E,    KC_I,    KC_O,   _TD_QUOTE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  _ZCTL,   _XALT,   _CGUI,    KC_V,    KC_B,  _TD_CP,        _TD_NUMTERM, KC_K,    KC_M,   _COMGUI, _DOTALT, _SLSHCTL, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MO(_NAV), KC_DEL,  _ENTGUI,                  _SPCNAV, KC_BSPC,  MO(_SYMBOLS)
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),


    [_NAV] = LAYOUT(
   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RGB_TOG, BRIGHTER, RGB_HUI, RGB_SPI, RGB_SAI,  ____,                              ____,   KC_BTN1, KC_BTN2,   ____,  KC_WH_U,  ____,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      RGB_MOD, DIMMER,  RGB_HUD, RGB_SPD, RGB_SAD,  ____,                              KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D,  ____,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      ____, TOGGLE_LIGHTS, ____, KC_MUTE, KC_VOLU,  ____,                            KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,  ____,    ____,
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, KC_VOLD,  ____,    ____,              ____, _PREV_TAB,_LINE_DOWN,_LINE_UP,_NEXT_TAB,   ____,   ____,
   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       ____,   ____,   ____,                         ____,   ____,    ____
   //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
	[_SYMBOLS] = LAYOUT(
   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       ____,    ____,    ____,    ____,    ____,   ____,                                ____,    ____,  KC_LBRC, KC_RBRC,    ____,   ____,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       ____,    ____,    ____,    ____,    ____,   ____,                                KC_LT,   KC_GT,  KC_LCBR, KC_RCBR, LSFT(KC_MINUS), ____,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       ____,    ____,    ____,    ____,    ____,   ____,                                KC_PLUS, KC_EQL, KC_LPRN, KC_RPRN,  KC_MINUS,   ____,
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       ____,    ____,    ____,    ____,    ____,   ____,   ____,                ____,   ____,   KC_GRV,   KC_LT,   KC_GT,    ____,   ____,
   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       ____,    ____,    ____,                      ____,    ____,    ____
   //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),
	[_COMMAND] = LAYOUT(
   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       ____,    ____,    ____,    ____,    ____,    ____,                          HYPR(KC_6),HYPR(KC_7),HYPR(KC_8),HYPR(KC_9),   ____,   ____,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       ____, TO(_QWERTY),_WINMODE, ____,   RESET,   ____,                          HYPR(KC_Y),HYPR(KC_U),HYPR(KC_I),HYPR(KC_O),   ____,   ____,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TRNS,  ____,    ____,   DEBUG,    ____,    ____,                         HYPR(KC_H),HYPR(KC_J),HYPR(KC_K),HYPR(KC_L),   ____,   ____,
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       ____,    ____,    ____, TO(_COLEMAK), ____,    ____,    ____,           ____,HYPR(KC_N),HYPR(KC_M),HYPR(KC_COMMA),HYPR(KC_DOT),  ____,   ____,
   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       ____,    ____,    ____,                      ____,  KC_TRNS,   ____
   //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),
   	[_NUMBERS] = LAYOUT(
   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       ____,    ____,    ____,    ____,    ____,    ____,                                ____,    ____,    ____,    ____,    ____,    ____,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       ____,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),                  LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),LSFT(KC_MINUS),
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       ____,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINUS,
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       ____,    ____,    ____,    ____,    ____,    ____,     ____,           KC_TRNS,     ____,    ____,    ____,    ____,    ____,    ____,
   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       ____,    ____,    ____,                      ____,    ____,     ____
   //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   )
};

// Tap Dance Stuff

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  HOLD = 1,
  SINGLE_TAP = 2,
  DOUBLE_TAP = 3,
  TRIPLE_TAP = 4,
  QUAD_TAP = 5
};

int cur_dance (qk_tap_dance_state_t *state) {
  if(state->pressed)
    return HOLD;

  if (state->count == 1)
    return SINGLE_TAP;

  if (state->count == 2)
    return DOUBLE_TAP;

  if (state->count == 3)
    return TRIPLE_TAP;

  if (state->count == 4)
    return QUAD_TAP;

   return -1;
}

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

// TODO add triple tap to undo a copy - e.g., open clipboard history, hit down twice and enter
static int dance_copypaste_state = -1;
void dance_copypaste_fin (qk_tap_dance_state_t *state, void *user_data) {
  dance_copypaste_state = cur_dance(state);
  switch (dance_copypaste_state) {
    case SINGLE_TAP:
        register_mods(MOD_BIT(KC_LGUI));
        register_code(KC_C);
        break;
    case DOUBLE_TAP:
        register_mods(MOD_BIT(KC_LGUI));
        register_code(KC_V);
        break;
    case TRIPLE_TAP:
        SEND_STRING(SS_LGUI(SS_LALT("c")) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_ENTER));
        break;
    case HOLD:
        register_mods(MOD_BIT(KC_LGUI));
        register_mods(MOD_BIT(KC_LALT));
        register_code(KC_C);
    }
}

void dance_copypaste_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_copypaste_state) {
    case SINGLE_TAP:
        unregister_code(KC_C);
        unregister_mods(MOD_BIT(KC_LGUI));
        break;
    case DOUBLE_TAP:
        unregister_code(KC_V);
        unregister_mods(MOD_BIT(KC_LGUI));
        break;
    case HOLD:
        unregister_code(KC_C);
        unregister_mods(MOD_BIT(KC_LGUI));
        unregister_mods(MOD_BIT(KC_LALT));
    }
    dance_copypaste_state = -1;
}

static int dance_dash_state = -1;
void dance_dash_fin (qk_tap_dance_state_t *state, void *user_data) {
  dance_dash_state = cur_dance(state);
  switch (dance_dash_state) {
    case SINGLE_TAP:
        register_code(KC_MINUS);
        break;
    case DOUBLE_TAP:
        register_mods(MOD_BIT(KC_LSFT));
        register_code(KC_MINUS);
        break;
    }
}

void dance_dash_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_dash_state) {
    case SINGLE_TAP:
        unregister_code(KC_MINUS);
        break;
    case DOUBLE_TAP:
        unregister_code(KC_MINUS);
        unregister_mods(MOD_BIT(KC_LSFT));
        break;
    }
    dance_dash_state = -1;
}

void dance_quote_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_QUOT);
  } else {
    register_code (KC_RSFT);
    register_code (KC_QUOT);
  }
}

void dance_quote_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_QUOT);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_QUOT);
  }
}

// TODO add triple tap to undo a copy - e.g., open clipboard history, hit down twice and enter
static int dance_numterm_state = -1;
void dance_numterm_fin (qk_tap_dance_state_t *state, void *user_data) {
  dance_numterm_state = cur_dance(state);
  switch (dance_numterm_state) {
    case SINGLE_TAP:
        register_mods(MOD_BIT(KC_LGUI));
        register_code(KC_GRV);
        break;
    case DOUBLE_TAP:
        // do nothing here
        break;
    case HOLD:
        layer_on(_NUMBERS);
    }
}

void dance_numterm_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_numterm_state) {
    case SINGLE_TAP:
        unregister_code(KC_GRV);
        unregister_mods(MOD_BIT(KC_LGUI));
        break;
    case DOUBLE_TAP:
        if (layer_state_is(_NUMBERS))
        {
            layer_off(_NUMBERS);
        } else {
            layer_on(_NUMBERS);
        }
        break;
    case HOLD:
        layer_off(_NUMBERS);
    }
    dance_numterm_state = -1;
}

// TODO: ADD doubletap to code key for capslock w/ color managment
// void dance_capslock_fin (qk_tap_dance_state_t *state, void *user_data) {
//   switch (dance_dash_state) {
//     case SINGLE_TAP:
//         unregister_code(KC_MINUS);
//         break;
//     case DOUBLE_TAP:
//         unregister_code(KC_MINUS);
//         unregister_mods(MOD_BIT(KC_LSFT));
//         break;
//     case HOLD:

//     }
//     dance_dash_state = -1;
// }

qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset), // semicolon and colon on tap/dbltap
 [TD_CP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_copypaste_fin, dance_copypaste_reset), // copy/paste/undo-copy/clipboard history
 [TD_DASH] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_dash_fin, dance_dash_reset), // - or _ for tap/dbl
 [TD_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_quote_finished, dance_quote_reset), // ' or '' for tap/dbl
 [TD_NUMTERM] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_numterm_fin, dance_numterm_reset)
};
// Custom tapping terms

#define TAPPING_TERM 250
uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case _ENTGUI:
      return 190;
    case _SLSHCTL:
      return 300;
    default:
      return TAPPING_TERM;
  }
}

uint8_t prev = _QWERTY;
uint32_t check;
uint32_t desired = 1;
uint8_t autolayer_mode = 1;
int autolayer_brightness = 120;
#define DEFAULT_COLOR 11, 255, autolayer_brightness
void keyboard_post_init_user() {
    rgblight_sethsv(DEFAULT_COLOR);
	rgblight_mode(1);
}

void toggle_layer_mode(void){
    if(autolayer_mode == 1){
      autolayer_mode = 0;
    }else{
      autolayer_mode = 1;
    }
}

uint32_t layer_state_set_user(uint32_t state) {
  if(autolayer_mode == 0){
    return state  ;
  }
  uint8_t layer = get_highest_layer(state);
   uprintf("layer: %u colemak: %u\n", layer, _COLEMAK);
	  switch (layer) {
        case _QWERTY:
            rgblight_sethsv_noeeprom(DEFAULT_COLOR);
            rgblight_mode_noeeprom(1);
        break;
        case _COLEMAK:
            rgblight_sethsv_noeeprom(DEFAULT_COLOR);
            rgblight_mode_noeeprom(13);
        break;
        case _NAV:
            rgblight_sethsv_noeeprom(DEFAULT_COLOR);
            rgblight_sethsv_noeeprom(100, rgblight_get_sat(), rgblight_get_val());
            rgblight_mode_noeeprom(1);
        break;
        case _SYMBOLS:
            rgblight_sethsv_noeeprom(DEFAULT_COLOR);
            rgblight_sethsv_noeeprom(148 , rgblight_get_sat(), rgblight_get_val());
            rgblight_mode_noeeprom(1);
        break;
        case _COMMAND:
            rgblight_sethsv_noeeprom(DEFAULT_COLOR);
            rgblight_decrease_val();
            rgblight_mode_noeeprom(15);
        break;
        case _NUMBERS:
            rgblight_sethsv_noeeprom(DEFAULT_COLOR);
            rgblight_sethsv_noeeprom(69, rgblight_get_sat(), rgblight_get_val());
            rgblight_mode_noeeprom(1);
        break;
	  }
  prev = layer;
  return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TOGGLE_LIGHTS:
    if (!record->event.pressed) {
        toggle_layer_mode();
    }
      return false;
    case BRIGHTER:
    if (!record->event.pressed) {
        rgblight_increase_val_noeeprom();
        autolayer_brightness = rgblight_get_val();
    }
    return false;
    case DIMMER:
    if (!record->event.pressed) {
        rgblight_decrease_val_noeeprom();
        autolayer_brightness = rgblight_get_val();
    }
    return false;
  }
  return true;
}




// notes and unused code
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif
//   return true;
// }

// Future tap dance excellence
// https://pastebin.com/V8jcmNGr
