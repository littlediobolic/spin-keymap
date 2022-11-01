/* Copyright 2019-2020 DMQ Design
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT(KC_F13, KC_F14, TO(1), KC_TRNS,
                     KC_F16, KC_F17, KC_F18, KC_MUTE,
                     KC_F19, KC_F20, KC_F21, KC_TRNS,
                     KC_MPRV, KC_MPLY, KC_MNXT),

        [1] = LAYOUT(TO(0), KC_NUM, TO(2), KC_TRNS,
                     KC_P7, KC_P8, KC_P9, KC_MUTE,
                     KC_P4, KC_P5, KC_P6, KC_TRNS,
                     KC_P1, KC_P2, KC_P3),
        
        [2] = LAYOUT(TO(1), KC_NO, KC_TRNS, KC_TRNS,
                     KC_NO, KC_NO, KC_VOLU, KC_MUTE,
                     KC_NO, KC_NO, KC_NO, KC_TRNS,
                     KC_NO, KC_NO, KC_VOLD),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      rgblight_increase_hue(); //Cycle through the RGB hue
    } else {
      rgblight_decrease_hue();
    }
  } else if (index == 1) { /* Second encoder */  
    if (clockwise) {
      tap_code(KC_VOLU); //Example of using tap_code which lets you use keycodes outside of the keymap
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 2) { /* Third encoder */  
    if (clockwise) {
      rgblight_increase_val(); //Change brightness on the RGB LEDs
    } else {
      rgblight_decrease_val();
    }
  }
    return true;
}
