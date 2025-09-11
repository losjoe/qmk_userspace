/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers {
    QWERTY,
    EXTEND,
    COLEMAK,
    SYM,
	MOD1,
	MOD2
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT_ansi_84(
     KC_ESC,      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_CAPS,
     KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     LT(EXTEND, KC_BSPC),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,               KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            CW_TOGG,  KC_UP,    KC_END,
     KC_LGUI,     KC_LALT,  KC_LCTL,                                LT(SYM, KC_SPC),                                 MO(MOD1), MO(MOD2), _______,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[EXTEND] = LAYOUT_ansi_84(
     _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,      _______,       _______,      _______,      _______,     _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,       _______,      _______,      _______,     _______,  _______,            _______,
     _______,  _______,  LCTL(KC_Z),  _______, LCTL(KC_Y), LCTL(KC_A),  KC_PGUP,  LSFT(LCTL(KC_LEFT)), LSFT(LCTL(KC_RGHT)), LSFT(KC_HOME), LSFT(KC_END), LSFT(LALT(KC_LEFT)), LSFT(LALT(KC_RGHT)), _______, _______,
     _______,  _______,   LCTL(KC_X),  LCTL(KC_C),   LCTL(KC_V), LCTL(KC_F),  KC_PGDN, LCTL(KC_LEFT), LCTL(KC_RGHT),      KC_HOME,       KC_END,             LALT(KC_LEFT),            LALT(KC_RGHT), _______,
     _______,            _______,    _______,         _______,  _______,  _______,  KC_APP,       KC_MYCM,      KC_MAIL,      KC_MUTE,   KC_VOLD,   KC_VOLU,  _______,  _______,
     _______,  _______,  _______,                                  _______,                               KC_MPRV,  KC_MSTP,   KC_MPLY,   KC_MNXT,  KC_PAUS,  _______),

[COLEMAK] = LAYOUT_ansi_84(
     KC_ESC,      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_CAPS,
     KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,      KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     LT(EXTEND, KC_BSPC),  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,               KC_X,     KC_C,     KC_D,     KC_V,     KC_Z,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,            CW_TOGG,  KC_UP,    KC_END,
     KC_LGUI,     KC_LALT,  KC_LCTL,                                LT(SYM, KC_SPC),                                 MO(MOD1), MO(MOD2), _______,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[SYM] = LAYOUT_ansi_84(
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,    KC_LT,    KC_GT,  KC_LBRC,  KC_RBRC,   KC_DLR,  KC_PIPE,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_PMNS,  KC_PAST,  _______,  _______,            _______,
     _______,  KC_LCBR,  KC_RCBR,  KC_LPRN,  KC_RPRN,  KC_EXLM,  KC_CALC,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_PPLS,  KC_PSLS,            _______,            _______,
     _______,            KC_AMPR,  KC_CIRC,    KC_AT,  KC_HASH,  KC_PERC,  KC_KP_1,  KC_KP_2,  KC_KP_3,   KC_DOT,  _______,            _______,  _______,  _______, 
     _______,  _______,  _______,                        _______,                                        KC_KP_0,  _______,  _______,  _______,  _______,  _______),
	 
[MOD1] = LAYOUT_ansi_84(
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
     _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

[MOD2] = LAYOUT_ansi_84(
     _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  RGB_TOG,
     _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
     _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
	 
	 
	 
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

// turn on num lock if it's not already on
layer_state_t layer_state_set_user(layer_state_t state) {
    led_t led_state = host_keyboard_led_state();
    bool g_num_lock_state = led_state.num_lock;

    switch(get_highest_layer(state)) {
        // replace number with your num lock layer number
        case 3:
        if (!g_num_lock_state) {
            tap_code(KC_NUM_LOCK);
        }
        break;
    }
    return state;
};