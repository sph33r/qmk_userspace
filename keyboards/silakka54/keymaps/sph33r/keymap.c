// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// begin home row mods
// Left-hand home row mods
//#define HRM_A LGUI_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LSFT_T(KC_D)
#define HRM_F LCTL_T(KC_F)

// Right-hand home row mods
#define HRM_J RCTL_T(KC_J)
#define HRM_K RSFT_T(KC_K)
#define HRM_L RALT_T(KC_L)
//#define HRM_SCLN RGUI_T(KC_SCLN)
// end home row mods

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        QK_GESC,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        LT(2,KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL,       KC_A,    HRM_S,   HRM_D,   HRM_F,   KC_G,                               KC_H,    HRM_J,   HRM_K,   HRM_L,   KC_SCLN, KC_QUOT,
        KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                            KC_LGUI, MO(1), KC_LSFT,           KC_SPC,  MO(2),  KC_LALT
    ),
    [1] = LAYOUT(
        KC_TILD,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_DEL,
        _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, KC_LBRC, KC_RBRC, _______,
        _______,  _______, _______, _______, KC_UNDS, KC_MINS,                            _______, _______, _______, KC_LCBR, KC_RCBR, _______,
        _______,  _______, _______, _______, KC_EQL,  KC_PLUS,                            _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______,  MO(3),  _______
    ),
    [2] = LAYOUT(
        KC_GRV,   _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_DEL,
        _______,  _______, _______, _______, _______, _______,                            _______, _______, KC_INS,  _______, KC_PSCR, _______,
        _______,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
                                            _______, MO(3), _______,           _______,  _______,  _______
    ),
    [3] = LAYOUT(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
        _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______,  _______,  _______
    )

};
