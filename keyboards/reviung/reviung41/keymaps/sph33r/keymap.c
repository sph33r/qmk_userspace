#include QMK_KEYBOARD_H

// begin home row mods
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
// end home row mods

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    QK_GESC, KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,               KC_Y, KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC,
    KC_TAB,  KC_A,  HOME_S, HOME_D, HOME_F, KC_G,               KC_H, HOME_J, HOME_K,  HOME_L, KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
                                    KC_LGUI, LOWER, KC_SPC, RAISE, KC_LALT
),

[_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_CAPS, KC_NO,   KC_NO,  KC_NO,   KC_UNDS, KC_MINS,      KC_PIPE, KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   KC_NO,
    _______, KC_NO,   KC_NO,  KC_NO,   KC_EQL,  KC_PLUS,      KC_BSLS, KC_LCBR, KC_RCBR, _______, _______, _______,
                                    _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
    _______, KC_1,    KC_2,  KC_3,  KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
    _______, KC_NO,   KC_NO, KC_NO, KC_HOME, KC_END,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO, KC_NO,
    _______, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_PSCR,         KC_PGUP, KC_PGDN, _______, _______, _______, _______,
                                    _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT(
    QK_BOOT, _______, KC_WREF, KC_WBAK, KC_WFWD, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    _______, RGB_SPI, RGB_SAI, RGB_HUI, RGB_VAI, RGB_TOG,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    _______, RGB_SPD, RGB_SAD, RGB_HUD, RGB_VAD, RGB_MOD,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                    _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
