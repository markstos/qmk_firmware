#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
// timeout timer
static uint32_t timeout_timer = 0;
#endif

// Boolean to store LED state
bool user_led_enabled = true;

// [Post Init] --------------------------------------------------------------//
void keyboard_post_init_user(void) {
  #ifdef RGB_MATRIX_ENABLE
    // Set RGB to known state
    rgb_matrix_enable_noeeprom();
    rgb_matrix_set_color_all(RGB_GREEN);
  #endif

  user_led_enabled = true;
}


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

// markstos defines

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum combos {
  JK_ESC,
  FJ_BSPC,

  RM_BSLASH,
  VU_SLSH,

  RT_LPRN,
  YU_RPRN,

  FG_LPRN,
  HJ_RPRN,

  VB_LCBR,
  NM_RCBR
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM rm_combo[] = {KC_R, KC_M, COMBO_END};
const uint16_t PROGMEM vu_combo[] = {KC_V, KC_U, COMBO_END};

const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};

const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};

const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {

  // For Vim, put Escape on the home row
  [JK_ESC]    = COMBO(jk_combo, KC_ESC),

  // Move pinkie-tab to home row on the same hand as Tab
  // [SD_TAB]    = COMBO(sd_combo, KC_TAB),

  // Move common pinkie-backspace to the home row
  [FJ_BSPC]   = COMBO(fj_combo, KC_BSPC),

  // a line between the R & M positions draws a back slash
  [RM_BSLASH] = COMBO(rm_combo, KC_BSLASH),

  // a line between the V & U positions draws a forward slash
  [VU_SLSH]   = COMBO(vu_combo, KC_SLSH),

  // Brackets combos are pressed with a single finger in between two keys
  [RT_LPRN]   = COMBO(rt_combo, KC_LBRC),
  [YU_RPRN]   = COMBO(yu_combo, KC_RBRC),

  // Parens are pressed with a single finger between F&J or H&J
  [FG_LPRN]   = COMBO(fg_combo, KC_LPRN),
  [HJ_RPRN]   = COMBO(hj_combo, KC_RPRN),

  // Curly Braces are pressed with a single figure between two keys
  [VB_LCBR]   = COMBO(vb_combo, KC_LCBR),
  [NM_RCBR]   = COMBO(nm_combo, KC_RCBR)
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_BSPC;
        default:
            return TAPPING_TERM;
    }
}


enum macro_keycodes {
  KC_SAMPLEMACRO,
};


/*


*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINUS, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LCTL),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LSFT),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_EQL, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              OSM(MOD_LALT),  GUI_T(KC_ENT),  LOWER,     LT(_RAISE, KC_BSPC),  KC_SPC,  OSM(MOD_LSFT)  \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,ALT_T(KC_4), KC_5,                      KC_6,  ALT_T(KC_7), KC_8,    KC_9,    KC_0, KC_COLON, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_ESC,   XXXXXXX,  XXXXXXX, KC_LBRC, KC_LCBR,                    KC_RCBR, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLASH,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,  LOWER,  KC_TRNS,     KC_TRNS, LT(_ADJUST, KC_BSPC), KC_TRNS \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_END,  XXXXXXX, XXXXXXX, KC_PGUP,                      KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, KC_APP,  KC_F11,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_COPY, KC_PASTE, KC_PGDN,                     KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_F12,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   ADJUST,  KC_TRNS,     KC_TRNS, RAISE, KC_TRNS \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGBRST,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, ADJUST,     ADJUST,  XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGB_TOG:
      if (record->event.pressed) {
        #ifdef RGB_MATRIX_ENABLE
          // Toggle matrix on key press
          user_led_enabled ? rgb_matrix_disable_noeeprom() : rgb_matrix_enable_noeeprom();
        #endif
      } else {
          // Flip User_led_enabled variable on key release
          user_led_enabled = !user_led_enabled;
      }
      return false; // Skip all further processing of this key
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
    default:
      // Use process_record_keymap to reset timer on all other keypresses
      if (record->event.pressed) {
        #ifdef RGB_MATRIX_ENABLE
          timeout_timer = timer_read32();
          // Restore LEDs if they are enabled by user
          if (user_led_enabled) {
              rgb_matrix_enable_noeeprom();
          }
        #endif
      }
      return true;
  }
  return true;
}
