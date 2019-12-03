#include QMK_KEYBOARD_H
#define ONESHOT_TAP_TOGGLE 3
#define IGNORE_MOD_TAP_INTERRUPT

extern keymap_config_t keymap_config;

// TODO: Define here codes involved in custom process_record_user code
//enum my_keycodes {
//  TOGGLE_LIGHTS = SAFE_RANGE,
//  BRIGHTER,
//  DIMMER
//};

#define _QWERTY 0
#define _TOGNOM 1
#define _SYMCRM 2
#define _SYMGNM 3
#define _RAISE  4
#define _CHROME 5
#define _GNOME  6


// Mark's defines
#define _OS_CTL OSM(MOD_LCTL)
#define _OS_LSFT OSM(MOD_LSFT)
#define _OS_RSFT OSM(MOD_RSFT)
#define _ALT_4 ALT_T(KC_4)
#define _ALT_7 ALT_T(KC_7)

#define _A_LBRC LALT(KC_LBRC)
#define _A_RBRC LALT(KC_RBRC)
#define _A_MIN  LALT(KC_MINUS)
#define _A_EQL  LALT(KC_EQUAL)
#define _AG_M   LALT(LGUI(KC_M))
#define _AC_COM LALT(LCTL(KC_COMMA))
#define _AC_DOT LALT(LCTL(KC_DOT))
#define _AS_M   LALT(S(KC_M))
#define _CS_F5  C(S(KC_F5))

// TODO: Use Tri layers to activate Gnome and Chrome
// TODO: Enable Combos with COMBO_ENABLE = yes in rules.mk
// TODO: Use JK combo for escape
// TODO: Use QW combo for Control-W
// TODO: Use DF combo for Control-F
// TODO: Make updates from my sheet
// TODO: Put fourth Iris thumb keys to use. (Open Clipboard and Paste into terminal?)
// TODO: Add app switching to top row?

enum combos {
  JK_ESC,
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPACE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _OS_CTL,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,  KC_SCOLON, KC_QUOTE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _OS_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,   XXXXXXX,          XXXXXXX,   KC_N,    KC_M,   KC_COMMA, KC_DOT, KC_SLASH,_OS_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                               ALT_T(KC_MINS), KC_ENT,  OSL(_SYMCRM),           MO(_RAISE),KC_SPACE,  KC_LGUI
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_TOGNOM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_TRNS, KC_TRNS,OSL(_SYMGNM),               KC_TRNS, KC_TRNS, KC_TRNS
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_SYMCRM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRAVE, KC_EXLM,  KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC,  KC_AMPR, KC_ASTR,KC_LPRN,  KC_RPRN, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS,    KC_1,   KC_2,   KC_3,    _ALT_4,    KC_5,                            KC_6,  _ALT_7,    KC_8,    KC_9,    KC_0,    KC_COLON,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS,  KC_ESC, KC_PLUS, KC_EQUAL, KC_LBRC,KC_LCBR, KC_TRNS,         KC_TRNS, KC_RCBR, KC_RBRC,  KC_TRNS, KC_TRNS, KC_TRNS,KC_BSLASH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     TO(_TOGNOM), KC_TRNS, KC_TRNS,               MO(_CHROME), KC_TRNS, KC_TRNS
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_SYMGNM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, _______, _______, _______, _______, _______,                           _______, _______, _______,  _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRAVE, KC_EXLM,  KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC, KC_AMPR , KC_ASTR,KC_LPRN,  KC_RPRN, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______,  KC_1,   KC_2,   KC_3,    _ALT_4,    KC_5,                               KC_6,  _ALT_7,    KC_8,    KC_9,    KC_0,   KC_COLON,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_ESC, KC_PLUS, KC_EQUAL, KC_LBRC,KC_LCBR, _______,          _______, KC_RCBR, KC_RBRC,  _______, _______, _______, KC_BSLASH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     TO(_QWERTY), _______, _______,                MO(_GNOME), _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_APP,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_HOME, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,                            KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,  KC_F11, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_END,  KC_VOLD, KC_PGDN, KC_PGUP, KC_VOLU, _______,          _______, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX,  KC_F12, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, KC_MS_BTN1,KC_MS_BTN2,              _______, _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_CHROME] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, _______, _______, _______, _______,_______,                             _______,_______,  _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, _A_LBRC,  _A_MIN,  _AG_M  ,  _A_EQL, _A_RBRC,                            _CS_F5,  XXXXXXX,  XXXXXXX,   KC_F5,C(S(KC_N)), KC_F4,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ , A(KC_1),  A(KC_2), A(KC_3), A(KC_4), A(KC_5),                           A(KC_6), A(KC_7), A(KC_8),G(S(KC_L)),_______,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, A(S(KC_S)),C(KC_EQL),A(KC_V),C(S(KC_V)),XXXXXXX, XXXXXXX,      _______, C(S(KC_N)),_AS_M  ,_AC_COM , _AC_DOT, _______, RESET  ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, _______,                   _______, _______,  _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_GNOME] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, _A_LBRC,  _A_MIN, XXXXXXX,  _A_EQL,  _A_RBRC,                       S(KC_SYSREQ), XXXXXXX,XXXXXXX ,G(KC_O) ,C(S(KC_P)), KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, G(KC_1),  G(KC_2), G(KC_3), G(KC_4), G(KC_5),                           G(KC_6),  G(KC_7), G(KC_8),G(KC_L) ,_______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______,  XXXXXXX, C(KC_EQL),C(A(KC_C)),C(S(KC_V)),XXXXXXX,XXXXXXX,    _______,G(S(KC_LEFT)),KC_MYCM,XXXXXXX,G(S(KC_RIGHT)),_______,RESET,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, _______,                  _______,  _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    )

};

