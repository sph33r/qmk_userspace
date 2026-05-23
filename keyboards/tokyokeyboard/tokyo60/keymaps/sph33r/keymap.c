#include QMK_KEYBOARD_H

#define BL 0
#define FN 1

// begin home row mods
// Left-hand home row mods
//#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
//#define HOME_SCLN RGUI_T(KC_SCLN)
// end home row mods


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer */
[BL] = LAYOUT_60_hhkb(
        QK_GESC,   KC_1,  KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,  KC_EQL, KC_BSLS, KC_DEL,
        LT(FN, KC_TAB),   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL,          KC_A,   HOME_S, HOME_D, HOME_F, KC_G,   KC_H,   HOME_J, HOME_K, HOME_L, KC_SCLN,  KC_QUOT,       KC_ENT,
        KC_LSFT,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH,      KC_RSFT, MO(FN),
             KC_LALT, KC_LGUI,              KC_SPC,                         KC_RGUI, KC_RALT ),

    /* 1: Function layer */
[FN]= LAYOUT_60_hhkb(
       KC_GRV,  KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  _______,  KC_DEL,
       _______,  KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_INS,  _______,  KC_PSCR, _______, _______,  _______,
       _______,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,    _______,
       _______,           _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,    _______, _______,
             _______, _______,                   _______,                         _______, QK_BOOT ),
};


