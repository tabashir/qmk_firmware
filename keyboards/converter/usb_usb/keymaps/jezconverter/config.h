/* Copyright 2020 Christopher Ko <chriskopher@gmail.com>
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

#pragma once

#define TAPPING_TERM 200  // Delay for tap modifiers until it is considered a hold

#define IGNORE_MOD_TAP_INTERRUPT          // Enable ignore mod tap interrupt: https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY  // Allows configuration of ignore mod tap interrupt per key in keymap.c

#define COMBO_COUNT 2  // Number of defined combos
#define COMBO_TERM 20  // Delay for combo keys to be chained together
                       //
// Mouse control
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_mouse_keys.md
// constant mode (velocity)
#define MK_3_SPEED
// KC_ACL0 < KC_ACL1 < unmodified < KC_ACL2
// Cursor offset per movement (unmodified)
#define MK_C_OFFSET_UNMOD 16
// Time between cursor movements (unmodified)
#define MK_C_INTERVAL_UNMOD 16
// Cursor offset per movement (KC_ACL0)
#define MK_C_OFFSET_0 8
// Time between cursor movements (KC_ACL0)
#define MK_C_INTERVAL_0 16
// Cursor offset per movement (KC_ACL1)
#define MK_C_OFFSET_1 16
// Time between cursor movements (KC_ACL1)
#define MK_C_INTERVAL_1 16
// Cursor offset per movement (KC_ACL2)
#define MK_C_OFFSET_2 32
// Time between cursor movements (KC_ACL2)
#define MK_C_INTERVAL_2 16

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0
