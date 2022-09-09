/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

static bool scrolling_mode = false;
 
layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case 3:  // If we're on the _RAISE layer enable scrolling mode
      scrolling_mode = true;
      pointing_device_set_cpi(200);
      break;
    default:
      if (scrolling_mode) {  // check if we were scrolling before and set disable if so
	scrolling_mode = false;
	pointing_device_set_cpi(1200);
      }
      break;
  }
  return state;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  if (scrolling_mode) {
    mouse_report.h = mouse_report.x;
    mouse_report.v = -mouse_report.y;
    mouse_report.x = 0;
    mouse_report.y = 0;
  }
  return mouse_report;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_5x6_right(
     KC_1  ,KC_2  , KC_3  , KC_4  , KC_5 , KC_6  ,                            KC_7  , KC_8  , KC_9  , KC_0  , KC_MINS, KC_EQL,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BACKSPACE,
     KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  , KC_COMM,KC_DOT ,KC_SLSH, KC_RSFT,
     MO(2) , KC_PGDN, KC_PGUP,MO(1) ,KC_SPC, KC_LALT,                                MO(1) , KC_ENT, KC_LBRC,  KC_RBRC,KC_BACKSLASH,
                       KC_BTN1,KC_BTN2, KC_LGUI, MO(3),                          KC_ESC, KC_PSCR, KC_GRV
  ),

  [1] = LAYOUT_5x6_right(
     KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5, KC_F6 ,                       KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_HOME, KC_END , KC_TRNS, KC_TRNS, KC_DEL,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT,KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS,                    KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3,                             KC_TRNS, AG_TOGG, KC_TRNS
  ),

  [2] = LAYOUT_5x6_right(
     RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_MUTE, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, RGB_MOD, RGB_VAD, RGB_VAI, RGB_RMOD,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_MRWD, KC_MFFD, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS
     ),
  [3] = LAYOUT_5x6_right(
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                       KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_NO, KC_NO
     ),
};

