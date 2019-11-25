#include "kb.h"

extern keymap_config_t keymap_config;

// tap dance layers
enum {
 TD_CLN = 0, // ; or : or tap/dbl
 TD_CP = 3, // copy/paste/get last clipboard item/clipboard manager for tap/dbl/trpl/hold
 TD_DASH = 4, // - or _ for tap/dbl
 TD_QUOTE = 5, // ' or '' for tap/dbl
 TD_NUMTERM = 6, // hold for num layer, dbl tap toggle num layer, or tap for term
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
#define _QWERTY 0


// Combos
enum combos {
	WE,WF
};

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	// Horizontal Chords
  [WE] = COMBO(we_combo, KC_ESC),
  [WF] = COMBO(wf_combo, KC_ESC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        _CODE,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,   _TD_CLN, _TD_QUOTE,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,  _ZCTL,   _XALT,   _CGUI,   KC_V,    KC_B,                KC_N,    KC_M,   _COMGUI, _DOTALT, _SLSHCTL, KC_RSFT,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                           MO(_NUMBERS),  _TD_CP, KC_DEL,  _ENTGUI,            _SPCNAV, KC_BSPC,MO(_SYMBOLS),MO(_NUMBERS),
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                    _TD_NUMTERM,        MO(_SYMBOLS)
    //                                             └────────┘           └────────┘
    ),

    [_COLEMAK] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                KC_J,    KC_L,    KC_U,    KC_Y,    _TD_CLN, KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        _CODE,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                KC_H,    KC_N,    KC_E,    KC_I,    KC_O,   _TD_QUOTE,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,  _ZCTL,   _XALT,   _CGUI,   KC_V,    KC_B,                KC_K,    KC_M,   _COMGUI, _DOTALT, _SLSHCTL, KC_RSFT,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                           MO(_NUMBERS),  _TD_CP, KC_DEL,  _ENTGUI,            _SPCNAV, KC_BSPC,MO(_SYMBOLS), MO(_NUMBERS),
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                    _TD_NUMTERM,        MO(_SYMBOLS)
    //                                             └────────┘           └────────┘
    ),


    [_NAV] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        ____, TO(_QWERTY),_WINMODE, ____,   RESET,    ____,               KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  ____,   ____,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        ____,     ____,    ____,   KC_MUTE, KC_VOLU,KC_BTN1,             KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,   ____,   ____,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_LALT, DEBUG, TO(_COLEMAK),KC_VOLD,KC_BTN2,         _PREV_TAB,_LINE_DOWN,_LINE_UP,_NEXT_TAB, ____,   ____,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                         _______, _______, _______, _______,             _______, _______, _______,  _______,
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                     _______,            _______
    //                                             └────────┘           └────────┘
    ),
	[_SYMBOLS] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        ____,    ____,    ____,    ____,    ____,    ____,               KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, LSFT(KC_MINUS), ____,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        ____,    ____,    ____,    ____,    ____,    ____,               KC_PLUS,  KC_EQL, KC_LPRN, KC_RPRN,  KC_MINUS, ____,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ├────────┼────────┼────────┼────────┼────────┼────────┤
        ____,    ____,    ____,    ____,    ____,    ____,               KC_TILDE, KC_GRV,   KC_LT,   KC_GT,    ____,    ____,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                         _______, _______, _______, _______,             _______, _______, _______,  _______,
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                     _______,            _______
    //                                             └────────┘           └────────┘
    ),
   	[_NUMBERS] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        ____,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),   LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),LSFT(KC_MINUS),
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        ____,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINUS,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ┌────────┼────────┼────────┼────────┼────────┼────────┤
        ____,    ____,    ____,    ____,    ____,    ____,                 ____,    ____,    ____,    ____,    ____,    ____,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                         _______, _______, _______, _______,             _______, _______, _______,  _______,
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                     _______,            _______
    //                                             └────────┘           └────────┘
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


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
