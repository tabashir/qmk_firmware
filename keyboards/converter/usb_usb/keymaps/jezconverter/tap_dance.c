#include "shared_enum.h"
#include "quantum.h"

enum tap_dance_state {
    SINGLE_HOLD = 1,
    SINGLE_TAP,
    DOUBLE_TAP,
    TRIPLE_TAP,
};


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

void insert_copy_paste(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count)
  {
  case 1: //copy
    SEND_STRING(SS_LCTRL(SS_TAP(X_INS)));
    break;
  case 2: //paste
    SEND_STRING(SS_LSFT(SS_TAP(X_INS)));
    break;
  case 3: //simple insert toggle
    SEND_STRING(SS_TAP(X_INSERT));
    break;
  }
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
      layer_move(_QWERTY);
      break;
  }
};

void all_atk(qk_tap_dance_state_t *state, void *user_data) {
  tap_code(KC_BTN1);
  tap_code(KC_E);
  tap_code(KC_Q);
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_INSERT_COPY_PASTE] = ACTION_TAP_DANCE_FN(insert_copy_paste),
  [TD_ESC_ZERO] = ACTION_TAP_DANCE_FN(esc_to_zero),
  [TD_ATK_ALL] = ACTION_TAP_DANCE_FN(all_atk),
  [TD_1_ALT_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, LALT(KC_1)),
  [TD_2_ALT_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, LALT(KC_2)),
  [TD_3_ALT_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, LALT(KC_3)),
  [TD_4_ALT_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, LALT(KC_4)),
  [TD_5_ALT_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, LALT(KC_5)),
  [TD_1_S_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, LSFT(KC_1)),
  [TD_2_S_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, LSFT(KC_2)),
  [TD_3_S_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, LSFT(KC_3)),
  [TD_4_S_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, LSFT(KC_4)),
  [TD_5_S_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, LSFT(KC_5))
};


