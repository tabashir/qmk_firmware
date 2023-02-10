/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

#if defined(KEYBOARD_converter_usb_usb_ble)
#    include "ble.h"
#elif defined(KEYBOARD_converter_usb_usb_hasu)
#    include "hasu.h"
#elif defined(KEYBOARD_converter_usb_usb_pro_micro)
#    include "pro_micro.h"
#endif

#define ______ KC_TRNS
#define XXX KC_NO

/*         ,---------------. ,---------------. ,---------------.
 *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
 * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
 * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
 * |-----------------------------------------------------------| |-----------| |---------------| |-------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
 * |-----------------------------------------------------------| `-----------' |---------------| |-------|
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
 * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
 * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
 * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
 * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
 * `-----------------------------------------------------------' `-----------' `---------------' `-------'
 *
 *
 * App:         Windows Menu key
 * Gui:         Windows key, Mac ⌘ key or Meta key
 *
 * Pwr:         Power for Unix and Mac
 * VDn,Vup,Mut: Volume control for Unix and Mac
 * Stp,Agn..:   for Unix
 *
 * KP,:         Brazilian Keypad Comma
 * KP=:         Keypad = for Mac
 * <,#:         ISO keys(UK legend)
 * JPY:         Japanese Yen(￥)
 * RO:          Japanese ろ or Brazilian /
 * MHEN:        Japanese 無変換 Non Conversion
 * HENK:        Japanese 変換 Conversion
 * KANA:        Japanese かな Hiragana/Katakana
 *              https://en.wikipedia.org/wiki/Keyboard_layout#Japanese
 * H/E:         Korean 한/영 Hangul/English
 * HNJ:         Korean 한자 Hanja
 *              https://en.wikipedia.org/wiki/Keyboard_layout#Hangul_.28for_Korean.29
 *
 * TODO: use same keycode to pass through instead of KC_NO?
 */
#define LAYOUT_all( \
              k68, k69, k6A, k6B, k6C, k6D, k6E, k6F, k70, k71, k72, k73, \
    k29,      k3A, k3B, k3C, k3D, k3E, k3F, k40, k41, k42, k43, k44, k45,       k46, k47, k48,  k81, k80, k7F, k66,  k75, \
\
    k35, k1E, k1F, k20, k21, k22, k23, k24, k25, k26, k27, k2D, k2E, k89, k2A,  k49, k4A, k4B,  k53, k54, k55, k56,  k78, k79, \
    k2B, k14, k1A, k08, k15, k17, k1C, k18, k0C, k12, k13, k2F, k30, k31,       k4C, k4D, k4E,  k5F, k60, k61, k57,  k76, k7A, \
    k39, k04, k16, k07, k09, k0A, k0B, k0D, k0E, k0F, k33, k34, k32, k28,                       k5C, k5D, k5E, k85,  k77, k7C, \
    kE1, k64, k1D, k1B, k06, k19, k05, k11, k10, k36, k37, k38, k87, kE5,            k52,       k59, k5A, k5B, k67,  k74, k7D, \
    kE0, kE3, kE2, k8B, k91,      k2C, k90, k8A, k88, kE6, kE7, k65, kE4,       k50, k51, k4F,  k62,      k63, k58,  k7E, k7B \
) { \
    { XXX, XXX, XXX, XXX, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, k2E, k2F }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, k3F }, \
    { k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4A, k4B, k4C, k4D, k4E, k4F }, \
    { k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5A, k5B, k5C, k5D, k5E, k5F }, \
    { k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6A, k6B, k6C, k6D, k6E, k6F }, \
    { k70, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7A, k7B, k7C, k7D, k7E, k7F }, \
    { k80, k81, XXX, XXX, XXX, k85, XXX, k87, k88, k89, k8A, k8B, XXX, XXX, XXX, XXX }, \
    { k90, k91, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { kE0, kE1, kE2, kE3, kE4, kE5, kE6, kE7, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX } \
}

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|               |  4|  5|  6|  +|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|Ent|
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
#define LAYOUT_fullsize_ansi( \
    k29,      k3A, k3B, k3C, k3D, k3E, k3F, k40, k41, k42, k43, k44, k45,  k46, k47, k48, \
\
    k35, k1E, k1F, k20, k21, k22, k23, k24, k25, k26, k27, k2D, k2E, k2A,  k49, k4A, k4B,  k53, k54, k55, k56, \
    k2B, k14, k1A, k08, k15, k17, k1C, k18, k0C, k12, k13, k2F, k30, k31,  k4C, k4D, k4E,  k5F, k60, k61, k57, \
    k39, k04, k16, k07, k09, k0A, k0B, k0D, k0E, k0F, k33, k34,      k28,                  k5C, k5D, k5E, \
    kE1,      k1D, k1B, k06, k19, k05, k11, k10, k36, k37, k38,      kE5,       k52,       k59, k5A, k5B, k58, \
    kE0, kE3, kE2,                k2C,                kE6, kE7, k65, kE4,  k50, k51, k4F,  k62,      k63 \
) { \
    { XXX, XXX, XXX, XXX, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, k2E, k2F }, \
    { k30, k31, XXX, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, k3F }, \
    { k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4A, k4B, k4C, k4D, k4E, k4F }, \
    { k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5A, k5B, k5C, k5D, k5E, k5F }, \
    { k60, k61, k62, k63, XXX, k65, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { kE0, kE1, kE2, kE3, kE4, kE5, kE6, kE7, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX } \
}

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Retn| |Del|End|PgD| |  7|  8|  9|  +|
 * |------------------------------------------------------`    | `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|    |               |  4|  5|  6|   |
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|Ent|
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|   |
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
#define LAYOUT_fullsize_iso( \
    k29,      k3A, k3B, k3C, k3D, k3E, k3F, k40, k41, k42, k43, k44, k45,  k46, k47, k48, \
\
    k35, k1E, k1F, k20, k21, k22, k23, k24, k25, k26, k27, k2D, k2E, k2A,  k49, k4A, k4B,  k53, k54, k55, k56, \
    k2B, k14, k1A, k08, k15, k17, k1C, k18, k0C, k12, k13, k2F, k30,       k4C, k4D, k4E,  k5F, k60, k61, k57, \
    k39, k04, k16, k07, k09, k0A, k0B, k0D, k0E, k0F, k33, k34, k32, k28,                  k5C, k5D, k5E, \
    kE1, k64, k1D, k1B, k06, k19, k05, k11, k10, k36, k37, k38,      kE5,       k52,       k59, k5A, k5B, k58, \
    kE0, kE3, kE2,                k2C,                kE6, kE7, k65, kE4,  k50, k51, k4F,  k62,      k63 \
) { \
    { XXX, XXX, XXX, XXX, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, k2E, k2F }, \
    { k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, k3F }, \
    { k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4A, k4B, k4C, k4D, k4E, k4F }, \
    { k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5A, k5B, k5C, k5D, k5E, k5F }, \
    { k60, k61, k62, k63, k64, k65, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX,}, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX,}, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { kE0, kE1, kE2, kE3, kE4, kE5, kE6, kE7, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX } \
}

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  ^|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  @|  [| Retn| |Del|End|PgD| |  7|  8|  9|  +|
 * |------------------------------------------------------`    | `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  ]|    |               |  4|  5|  6|   |
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shft    |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|Ent|
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|MHEN|      Space      |HENK|KNA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|   |
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
#define LAYOUT_fullsize_jis( \
    k29,      k3A, k3B, k3C, k3D, k3E, k3F, k40, k41, k42, k43, k44, k45,       k46, k47, k48, \
\
    k35, k1E, k1F, k20, k21, k22, k23, k24, k25, k26, k27, k2D, k2E, k89, k2A,  k49, k4A, k4B,  k53, k54, k55, k56, \
    k2B, k14, k1A, k08, k15, k17, k1C, k18, k0C, k12, k13, k2F, k30,            k4C, k4D, k4E,  k5F, k60, k61, k57, \
    k39, k04, k16, k07, k09, k0A, k0B, k0D, k0E, k0F, k33, k34, k32, k28,                       k5C, k5D, k5E, \
    kE1,      k1D, k1B, k06, k19, k05, k11, k10, k36, k37, k38, k87, kE5,            k52,       k59, k5A, k5B, k58, \
    kE0, kE3, kE2, k8B,      k2C,           k8A, k88, kE6, kE7, k65, kE4,       k50, k51, k4F,  k62,      k63 \
) { \
    { XXX, XXX, XXX, XXX, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, k2E, k2F }, \
    { k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, k3F }, \
    { k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4A, k4B, k4C, k4D, k4E, k4F }, \
    { k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5A, k5B, k5C, k5D, k5E, k5F }, \
    { k60, k61, k62, k63, XXX, k65, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, k87, k88, k89, k8A, k8B, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { kE0, kE1, kE2, kE3, kE4, kE5, kE6, kE7, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX } \
}
#define LAYOUT_jis( \
    K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,                   \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K89,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K28,  K4C,K4D,K4E,  K5F,K60,K61,K57, \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,K32,                        K5C,K5D,K5E,     \
    KE1,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,        K87,KE5,      K52,      K59,K5A,K5B,K58, \
    KE0,KE3,KE2,K8B,    K2C,        K8A,K88,KE6,KE7,K65,KE4,      K50,K51,K4F,  K62,    K63      \
)

#define LAYOUT_tkl_iso( \
    K05,      K44, K42, K32, K02, K21, K0A, K3E, K4E, K4D, K2D, K0D, K7D,      K23, K53, K51, \
    K45, K25, K24, K22, K20, K40, K48, K28, K2A, K2E, K2F, K4F, K4A, K3D,      K47, K4C, K46, \
    K35, K55, K54, K52, K50, K30, K38, K58, K5A, K5E, K5F, K3F, K3A,           K49, K2C, K26, \
    K34, K15, K14, K12, K10, K00, K08, K18, K1A, K1E, K1F, K0F, K1D, K6D, \
    K3B, K04, K65, K64, K62, K60, K70, K78, K68, K6A, K6E, K7F,      K1B,           K0C, \
    K41, K31, K03,                K09,                K73, K11, K33, K61,      K7C, K79, K77 \
) \
{ \
    { K00, XXX, K02, K03, K04, K05, XXX, XXX, K08, K09, K0A, XXX, K0C, K0D, XXX, K0F }, \
    { K10, K11, K12, XXX, K14, K15, XXX, XXX, K18, XXX, K1A, K1B, XXX, K1D, K1E, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, XXX, K28, XXX, K2A, XXX, K2C, K2D, K2E, K2F }, \
    { K30, K31, K32, K33, K34, K35, XXX, XXX, K38, XXX, K3A, K3B, XXX, K3D, K3E, K3F }, \
    { K40, K41, K42, XXX, K44, K45, K46, K47, K48, K49, K4A, XXX, K4C, K4D, K4E, K4F }, \
    { K50, K51, K52, K53, K54, K55, XXX, XXX, K58, XXX, K5A, XXX, XXX, XXX, K5E, K5F }, \
    { K60, K61, K62, XXX, K64, K65, XXX, XXX, K68, XXX, K6A, XXX, XXX, K6D, K6E, XXX }, \
    { K70, XXX, XXX, K73, XXX, XXX, XXX, K77, K78, K79, XXX, XXX, K7C, K7D, XXX, K7F } \
}

