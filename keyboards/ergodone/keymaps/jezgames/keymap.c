#include QMK_KEYBOARD_H

enum {
    TD_LAYER_FN,
    TD_INSERT_COPY_PASTE,
    TD_ALTS_TOGGLE,
    TD_GRAVE_TOGGLE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /*
     * ,--------------------------------------------------.    ,--------------------------------------------------.
     * |    0   |   1  |   2  |   3  |   4  |   5  |  6   |    |  38  |  39  |  40  |  41  |  42  |  43  |   44   |
     * |--------+------+------+------+------+------+------|    |------+------+------+------+------+------+--------|
     * |    7   |   8  |   9  |  10  |  11  |  12  |  13  |    |  45  |  46  |  47  |  48  |  49  |  50  |   51   |
     * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
     * |   14   |  15  |  16  |  17  |  18  |  19  |------|    |------|  52  |  53  |  54  |  55  |  56  |   57   |
     * |--------+------+------+------+------+------|  26  |    |  58  |------+------+------+------+------+--------|
     * |   20   |  21  |  22  |  23  |  24  |  25  |      |    |      |  59  |  60  |  61  |  62  |  63  |   64   |
     * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
     *   |  27  |  28  |  29  |  30  |  31  |                                |  65  |  66  |  67  |  68  |  69  |
     *   `----------------------------------'                                `----------------------------------'
     *                                       ,-------------.  ,-------------.
     *                                       |  32  |  33  |  |  70  |  71  |
     *                                ,------+------+------|  |------+------+------.
     *                                |      |      |  34  |  |  72  |      |      |
     *                                |  35  |  36  |------|  |------|  74  |  75  |
     *                                |      |      |  37  |  |  73  |      |      |
     *                                `--------------------'  `--------------------'
     */

[0] = LAYOUT_ergodox(
// left hand

KC_ESC , KC_1         , KC_2   , KC_3        , KC_4           , KC_5, KC_6  ,
KC_TAB , KC_Q         , KC_W   , KC_E        , KC_R           , KC_T, KC_GRV,
TD(TD_GRAVE_TOGGLE), KC_A         , KC_S   , KC_D        , KC_F           , KC_G,
KC_LSFT, KC_NUBS      , KC_Z   , KC_X        , KC_C           , KC_V, KC_B  ,
KC_LCTL, OSM(MOD_LGUI), KC_LALT, TD(TD_INSERT_COPY_PASTE), TD(TD_LAYER_FN),

// left thumb

        KC_HOME, KC_END ,
                 KC_PGUP,
KC_SPC, KC_ENT , KC_PGDN,

// right hand

KC_7   , KC_8, KC_9 , KC_0        , KC_MINS, KC_EQL , KC_BSPC,
KC_LBRC, KC_Y, KC_U , KC_I        , KC_O   , KC_P   , KC_NUHS,
         KC_H, KC_J , KC_K        , KC_L   , KC_SCLN, KC_QUOT,
KC_RBRC, KC_N, KC_M , KC_COMM     , KC_DOT , KC_SLSH, KC_RSFT,
               TD(TD_LAYER_FN), KC_DEL, TD_ALTS_TOGGLE, KC_APP , KC_RCTL,

// right thumb

KC_LEFT, KC_RGHT,
KC_UP  ,
KC_DOWN, KC_ENT , KC_SPC
),

[1] = LAYOUT_ergodox(
// left hand

TO(4)  , KC_F1           , KC_F2         , KC_F3    , KC_F4           , KC_F5  , KC_F6  ,
_______, KC_EXLM         , KC_HOME       , KC_UP    , KC_END          , KC_PGUP, _______,
_______, KC_HASH         , KC_LEFT       , KC_DOWN  , KC_RIGHT        , KC_PGDN ,
_______, LALT(KC_LEFT)   , LCTL(KC_LEFT) , XXXXXXX  , LCTL(KC_RIGHT)  , LALT(KC_RIGHT) ,  _______,
EEP_RST, _______, _______, _______, _______,

// left thumb

         _______, _______,
                  _______,
_______, _______, _______,

// right hand

KC_F7  , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12 , KC_F11 ,
_______, KC_UP  , KC_7   , KC_8  , KC_9  , KC_ASTR, KC_F12 ,
         KC_DOWN, KC_4   , KC_5  , KC_6  , KC_PLUS, _______,
_______, KC_AMPR, KC_1   , KC_2  , KC_3  , KC_BSLS, _______,
                  _______, KC_DOT, KC_0  , KC_EQL , _______,

// right thumb

_______, _______,
_______,
_______, _______, _______
),

[2] = LAYOUT_ergodox(
// left hand

_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, KC_MS_U, _______, _______, KC_VOLU,
_______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
_______, _______, _______, _______, _______, _______, KC_VOLD,
_______, _______, KC_BTN1, KC_BTN2, _______,

// left thumb

         _______, _______,
                  _______,
_______, _______, _______,

// right hand

_______, _______, _______, _______, _______, _______, _______,
_______, _______, KC_HOME, KC_UP  , KC_END , _______, _______,
         _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_MPLY,
KC_MUTE, _______, KC_WBAK, KC_MPRV, KC_MNXT, _______, _______,
                  _______, _______, _______, _______, _______,

// right thumb

_______, _______,
_______,
_______, _______, _______
),

[3] = LAYOUT_ergodox(
// left hand

_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______,

// left thumb

         _______, _______,
                  _______,
_______, _______, _______,

// right hand

_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
                  _______, _______, _______, _______, _______,

// right thumb

_______, _______,
_______,
_______, _______, _______
),

[4] = LAYOUT_ergodox(
// left hand

_______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
KC_TAB , KC_Q, KC_W, KC_E, KC_R, KC_T, KC_I,
_______, KC_A, KC_S, KC_D, KC_F, KC_G,
_______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_U,
TO(0)  , KC_7, KC_8, KC_9, KC_0,

// left thumb

        KC_MS_L, KC_MS_R,
                 KC_MS_U,
KC_SPC, KC_PPLS, KC_MS_D,

// right hand

KC_RBRC, KC_INS , KC_NLCK, KC_PSLS, KC_PAST, KC_DEL, KC_PMNS,
KC_NUHS, KC_PGUP, KC_P7  , KC_P8  , KC_P9  , KC_END, KC_HOME,
         KC_PGDN, KC_P4  , KC_P5  , KC_P6  , KC_M  , KC_PPLS,
KC_ENT , XXXXXXX, KC_P1  , KC_P2  , KC_P3  , KC_J  , KC_PENT,
                  KC_SPC , KC_P0  , KC_PDOT, KC_L  , KC_PENT,

// right thumb

KC_BTN1, KC_BTN2,
TO(5)  ,
OSL(5) , KC_SPC , KC_RGHT
),

[5] = LAYOUT_ergodox(
// left hand

_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______,

// left thumb

         _______, _______,
                  _______,
_______, _______, _______,

// right hand

KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
_______, _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
                  _______, _______, _______, _______, _______,

// right thumb

_______, _______,
_______,
_______, _______, _______
)
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
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
            break;
    }

};


#define _BASE_LAYER 0
#define _FUN_LAYER 1
#define _MOUSE_LAYER 2
#define _GAMES_LAYER 4
#define TAPPING_TERM 200

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

void caps_grave_tab(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_TAP(X_CAPSLOCK));
    } else {
        SEND_STRING(SS_TAP(X_GRAVE) SS_TAP(X_TAB));
    }
}

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
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LAYER_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, dance_layers_finish),
  [TD_INSERT_COPY_PASTE] = ACTION_TAP_DANCE_FN(insert_copy_paste),
  [TD_ALTS_TOGGLE] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
  [TD_GRAVE_TOGGLE] = ACTION_TAP_DANCE_FN(caps_grave_tab)
};
