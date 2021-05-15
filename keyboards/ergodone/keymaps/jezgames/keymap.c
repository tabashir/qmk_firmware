#include QMK_KEYBOARD_H

enum {
    TD_LAYER_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ergodox(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_GRV, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LCTL, OSM(MOD_LGUI), KC_LALT, LCTL(KC_INS), TD(TD_LAYER_FN), KC_HOME, KC_END, KC_PGUP, KC_ENT, KC_SPC, KC_PGDN, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_LBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NUHS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, TG(2), LSFT(KC_INS), KC_RALT, KC_APP, KC_RCTL, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, KC_DEL, KC_SPC),
	[1] = LAYOUT_ergodox(TO(4), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV, KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, EEP_RST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F11, KC_TRNS, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12, KC_DOWN, KC_4, KC_5, KC_6, KC_PLUS, KC_TRNS, KC_TRNS, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS, KC_TRNS, KC_DOT, KC_0, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_ergodox(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_MPLY, KC_MUTE, KC_TRNS, KC_WBAK, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT_ergodox(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT_ergodox(KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_I, KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_U, TO(0), KC_7, KC_8, KC_9, KC_0, KC_MS_L, KC_MS_R, KC_MS_U, KC_SPC, KC_PPLS, KC_MS_D, KC_RBRC, KC_INS, KC_NLCK, KC_PSLS, KC_PAST, KC_DEL, KC_PMNS, KC_NUHS, KC_PGUP, KC_P7, KC_P8, KC_P9, KC_END, KC_HOME, KC_PGDN, KC_P4, KC_P5, KC_P6, KC_M, KC_PPLS, KC_ENT, KC_NO, KC_P1, KC_P2, KC_P3, KC_J, KC_PENT, KC_SPC, KC_P0, KC_PDOT, KC_L, KC_PENT, KC_BTN1, KC_BTN2, TO(5), OSL(5), KC_SPC, KC_RGHT),
	[5] = LAYOUT_ergodox(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 4:
            ergodox_right_led_3_on();
            break;
        case 5:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};


#define _BASE_LAYER 0
#define _FUN_LAYER 1
#define _MOUSE_LAYER 2
#define _GAMES_LAYER 4

bool fn_held;

void dance_layers(qk_tap_dance_state_t *state, void *user_data) {
  if (state->pressed)
  {
    layer_on(_FUN_LAYER);
    fn_held = true;
  }
  switch (state->count)
  {
  case 1: //off all layers, just base on
    if (!state->pressed)
    {
      layer_move(0);
      fn_held = false;
    }
    break;
  case 2: //function layer on
    layer_on(_FUN_LAYER);
    layer_off(_MOUSE_LAYER);
    break;
  case 3: //mouse layer on
    layer_on(_MOUSE_LAYER);
    layer_off(_FUN_LAYER);
    break;
  case 4: //games layer on
    layer_move(_GAMES_LAYER);
    break;
  }
}

void dance_layers_finish(qk_tap_dance_state_t *state, void *user_data) {
  if (fn_held)
  {
    layer_move(_BASE_LAYER);
    fn_held = false;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LAYER_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, dance_layers_finish)
};
