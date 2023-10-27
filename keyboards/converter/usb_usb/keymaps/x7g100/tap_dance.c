#include "shared_enum.h"
#include "quantum.h"

enum tap_dance_state {
    SINGLE_HOLD = 1,
    SINGLE_TAP,
    DOUBLE_TAP,
    TRIPLE_TAP,
};

static int tap_state   = 0;

// Watch the state of the tap dance
int cur_dance(qk_tap_dance_state_t *state) {
    if (state->pressed) {
        return SINGLE_HOLD;
    }
    if (state->count == 1) {
        return SINGLE_TAP;
    }
    if (state->count == 2) {
        return DOUBLE_TAP;
    }
    if (state->count == 3) {
        return TRIPLE_TAP;
    }

    return -1;
};

void esc_to_zero(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      tap_code(KC_ESC);
      break;
    case 2:
      tap_code(KC_ESC);
      tap_code(KC_ESC);
      break;
    default:
      layer_clear();
      layer_move(_ORIGINAL);
      break;
  }
};

void all_atk(qk_tap_dance_state_t *state, void *user_data) {
  tap_code(KC_Q);
  tap_code(KC_E);
};

void alt_1_n_alt_1(qk_tap_dance_state_t *state, void *user_data) {
  tap_state = cur_dance(state);
  switch (tap_state) {
    case SINGLE_TAP:
      SEND_STRING("N1");
    break;
    case DOUBLE_TAP:
      SEND_STRING("N"SS_LALT("1"));
    break;
  }
};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch (keycode) {
//    case TD_1_N_ALT_1:
//      tap_code(KC_N);
//      return true;
//      //return false;
//    break;
//  }
//  return true;
//}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_ZERO] = ACTION_TAP_DANCE_FN(esc_to_zero),
  [TD_ATK_ALL] = ACTION_TAP_DANCE_FN(all_atk),
  [TD_1_ALT_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, LALT(KC_1)),
  [TD_2_ALT_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, LALT(KC_2)),
  [TD_3_ALT_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, LALT(KC_3)),
  [TD_4_ALT_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, LALT(KC_4)),
  [TD_5_ALT_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, LALT(KC_5)),
  [TD_6_ALT_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, LALT(KC_6)),
  [TD_7_ALT_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, LALT(KC_7)),
  [TD_8_ALT_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, LALT(KC_8)),
  [TD_9_ALT_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, LALT(KC_9)),
  [TD_0_ALT_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, LALT(KC_0)),

  [TD_1_N_ALT_1] = ACTION_TAP_DANCE_FN(alt_1_n_alt_1),
  [TD_2_N_ALT_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, LALT(KC_2)),
  [TD_3_N_ALT_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, LALT(KC_3)),
  [TD_4_N_ALT_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, LALT(KC_4)),
  [TD_5_N_ALT_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, LALT(KC_5)),
  [TD_6_N_ALT_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, LALT(KC_6)),
  [TD_7_N_ALT_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, LALT(KC_7)),
  [TD_8_N_ALT_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, LALT(KC_8)),

  [TD_F1_S_F1] = ACTION_TAP_DANCE_DOUBLE(KC_F1, LSFT(KC_F1)),
  [TD_F2_S_F2] = ACTION_TAP_DANCE_DOUBLE(KC_F2, LSFT(KC_F2)),
  [TD_F3_S_F3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, LSFT(KC_F3)),
  [TD_F4_S_F4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, LSFT(KC_F4)),
  [TD_F5_S_F5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, LSFT(KC_F5)),
  [TD_F6_S_F6] = ACTION_TAP_DANCE_DOUBLE(KC_F6, LSFT(KC_F6)),
  [TD_F7_S_F7] = ACTION_TAP_DANCE_DOUBLE(KC_F7, LSFT(KC_F7)),
  [TD_F8_S_F8] = ACTION_TAP_DANCE_DOUBLE(KC_F8, LSFT(KC_F8)),
  [TD_F9_S_F9] = ACTION_TAP_DANCE_DOUBLE(KC_F9, LSFT(KC_F9)),
  [TD_F10_S_F10] = ACTION_TAP_DANCE_DOUBLE(KC_F10, LSFT(KC_F10)),
  [TD_F11_S_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F11, LSFT(KC_F11)),
  [TD_F12_S_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F12, LSFT(KC_F12)),
  [TD_INS_S_INS] = ACTION_TAP_DANCE_DOUBLE(KC_INS, LSFT(KC_INS)),
  [TD_DEL_S_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, LSFT(KC_DEL)),
  [TD_HOME_S_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, LSFT(KC_HOME)),
  [TD_END_S_END] = ACTION_TAP_DANCE_DOUBLE(KC_END, LSFT(KC_END)),
  [TD_PGUP_S_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, LSFT(KC_PGUP)),
  [TD_PGDN_S_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, LSFT(KC_PGDN)),
  [TD_T_OR_X] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_X),
  [TD_1_5] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_5),
  [TD_2_6] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_6),
  [TD_3_7] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_7),
  [TD_4_8] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_8),
  [TD_5_9] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_9),
  [TD_Z_A1] = ACTION_TAP_DANCE_DOUBLE(KC_Z, LALT(KC_1)),
  [TD_V_A2] = ACTION_TAP_DANCE_DOUBLE(KC_V, LALT(KC_2)),
  [TD_B_A3] = ACTION_TAP_DANCE_DOUBLE(KC_B, LALT(KC_3))
};


