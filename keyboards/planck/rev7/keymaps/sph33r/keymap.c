/* Copyright 2015-2023 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _WIN,
  _MAC,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum my_keycodes {
 // apple globe key
 AP_GLOB = SAFE_RANGE,
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_WIN] = LAYOUT_planck_1x2uC(
    QK_GESC,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LT(RAISE, KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    SC_LSPO,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
    KC_LCTL,           KC_LGUI, KC_LALT, KC_HOME, LOWER,       KC_SPC,       RAISE,   MEH(KC_NO), KC_LEFT, KC_RGHT, KC_ENT
),

[_MAC] = LAYOUT_planck_grid(
    QK_GESC,            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
    LT(_RAISE, KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
    SC_LSPO,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  SC_RSPC,
    KC_LCTL,            KC_LOPT, KC_LCMD, AP_GLOB, LOWER,   KC_SPC,  KC_SPC,  RAISE,   HYPR(KC_NO), KC_LEFT, KC_RIGHT, KC_ENT
),

[_LOWER] = LAYOUT_planck_1x2uC(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, _______, _______, _______, KC_UNDS, KC_MINS, KC_PIPE, KC_LBRC, KC_RBRC, _______, _______, _______,
    _______, _______, _______, _______, KC_EQL,  KC_PLUS, KC_BSLS, KC_LCBR, KC_RCBR, _______, _______, _______,
    _______, _______, _______, KC_END, _______,     _______,      _______, _______,  KC_UP,   KC_DOWN, _______
),

[_RAISE] = LAYOUT_planck_1x2uC(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_1x2uC(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, DF(_MAC), _______, _______, _______, _______,
    UG_TOGG, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, QK_BOOT
)

};

/* Need this for layers to work */
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case AP_GLOB:
    host_consumer_send(record->event.pressed ? AC_NEXT_KEYBOARD_LAYOUT_SELECT : 0);
    return false;
  }

  return true;
}
