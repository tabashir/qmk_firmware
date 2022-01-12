#include QMK_KEYBOARD_H

enum {
    TD_LAYER_FN,
    TD_INSERT_COPY_PASTE,
    TD_ALTS_TOGGLE,
    TD_NLCK_SLCK_TOGGLE,
    TD_GRAVE_CAPS,
    TD_GRAVE_TAB,
    TD_ESC_ZERO,
    TD_HASH_SHIFT,
    TD_1_SH_1,
    TD_2_SH_2,
    TD_3_SH_3,
    TD_4_SH_4,
    TD_5_SH_5,
    TD_6_SH_6,
    TD_7_SH_7,
    TD_8_SH_8,
    TD_9_SH_9,
    TD_0_SH_0,
    TD_MINUS_SH_MINUS,
    TD_EQL_SH_EQL,
    TDT_1_F1,
    TDT_2_F2,
    TDT_3_F3,
    TDT_4_F4,
    TDT_5_F5,
    TDT_6_F6,
    TDT_7_F7,
    TDT_8_F8,
    TDT_9_F9,
    TDT_0_F10,
    TDT_11_F11,
    TDT_12_F12,
    TD_F1_SH_F1,
    TD_F2_SH_F2,
    TD_F3_SH_F3,
    TD_F4_SH_F4,
    TD_F5_SH_F5,
    TD_F6_SH_F6,
    TD_F7_SH_F7,
    TD_F8_SH_F8,
    TD_F9_SH_F9,
    TD_F10_SH_F10,
    TD_F11_SH_F11,
    TD_F12_SH_F12,
    TD_F13_SH_F13,
    TD_SH_Q,
    TD_SH_W,
    TD_SH_E,
    TD_SH_R,
    TD_SH_T,
    TD_SH_A,
    TD_SH_S,
    TD_SH_D,
    TD_SH_F,
    TD_SH_G,
    TD_SH_Z,
    TD_SH_X,
    TD_SH_C,
    TD_SH_V,
    TD_SH_B,
    TD_SH_U,
    TD_SH_DOT,
    TD_SH_COMM,
    TD_SH_SLSH,
    TD_Y_U,
    TD_O_U,
    TD_P_U,
    TD_LBRC_U,
    TD_SH_NUBS,
    TD_SH_TAB,
    X_CTL,
    SOME_OTHER_DANCE
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void k1_finished(qk_tap_dance_state_t *state, void *user_data);
void k1_reset(qk_tap_dance_state_t *state, void *user_data);
void register_td_key(uint16_t keycode1, uint16_t keycode2, qk_tap_dance_state_t *state);
void unregister_td_key(uint16_t keycode1, uint16_t keycode2, qk_tap_dance_state_t *state);


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

KC_ESC            , TD(TDT_1_F1)   , TD(TDT_2_F2) , TD(TDT_3_F3)              , TD(TDT_4_F4)     , TD(TDT_5_F5) , TD(TDT_6_F6)      ,
KC_TAB            , KC_Q          , KC_W        , KC_E                     , KC_R            , KC_T        , TD(TD_GRAVE_TAB) ,
TD(TD_GRAVE_CAPS) , KC_A          , KC_S        , KC_D                     , KC_F            , KC_G        ,
KC_LSFT           , KC_NUBS       , KC_Z        , KC_X                     , KC_C            , KC_V        , KC_B             ,
KC_LCTL           , OSM(MOD_LGUI) , KC_LALT     , TD(TD_INSERT_COPY_PASTE) , TD(TD_LAYER_FN) ,

// left thumb

KC_HOME               , KC_END        ,
KC_PGUP               ,
KC_SPC                , KC_ENT        , KC_PGDN       ,

// right hand

TD(TDT_7_F7)     , TD(TDT_8_F8) , TD(TDT_9_F9) , TD(TDT_0_F10) , TD(TDT_11_F11) , TD(TDT_12_F12) , KC_BSPC ,
KC_LBRC         , KC_Y        , KC_U        , KC_I         , KC_O          , KC_P          , KC_NUHS ,
KC_H            , KC_J        , KC_K        , KC_L         , KC_SCLN       , KC_QUOT       ,
KC_RBRC         , KC_N        , KC_M        , KC_COMM      , KC_DOT        , KC_SLSH       , KC_RSFT ,
TD(TD_LAYER_FN) , KC_DEL      , KC_LALT     , KC_APP       , KC_LCTL       ,

// right thumb

KC_LEFT               , KC_RGHT       ,
KC_UP                 ,
KC_DOWN               , KC_ENT        , KC_SPC
)                     ,

[1] = LAYOUT_ergodox(
// left hand

_______               , KC_F1         , KC_F2         , KC_F3                    , KC_F4           , KC_F5          , KC_F6            ,
_______               , XXXXXXX       , KC_HOME       , KC_UP                    , KC_END          , XXXXXXX        , _______          ,
_______               , LALT(KC_LEFT) , KC_LEFT       , KC_DOWN                  , KC_RIGHT        , LALT(KC_RIGHT) ,
_______               , XXXXXXX       , LCTL(KC_LEFT) , XXXXXXX                  , LCTL(KC_RIGHT)  , XXXXXXX        , _______          ,
_______               , _______       , _______       , _______                  , _______         ,

// left thumb

_______               , _______       ,
_______               ,
_______               , _______       , _______       ,

// right hand

KC_F7                 , KC_F8         , KC_F9         , KC_F10                   , KC_F11          , KC_F12         , KC_F13           ,
_______               , KC_UP         , KC_7          , KC_8                     , KC_9            , KC_ASTR        , _______           ,
KC_DOWN               , KC_4          , KC_5          , KC_6                     , KC_PLUS         , _______        ,
_______               , KC_AMPR       , KC_1          , KC_2                     , KC_3            , KC_BSLS        , _______          ,
_______               , KC_DOT        , KC_0          , KC_EQL                   , _______         ,

// right thumb

_______               , _______       ,
_______               ,
_______               , _______       , _______
)                     ,

[2] = LAYOUT_ergodox(
// left hand

_______               , _______       , _______       , _______                  , _______         , _______        , _______          ,
_______               , _______       , _______       , KC_MS_U                  , _______         , _______        , KC_VOLU          ,
_______               , _______       , KC_MS_L       , KC_MS_D                  , KC_MS_R         , _______        ,
_______               , _______       , _______       , _______                  , _______         , _______        , KC_VOLD          ,
_______               , _______       , KC_BTN1       , KC_BTN2                  , _______         ,

// left thumb

_______               , _______       ,
_______               ,
_______               , _______       , _______       ,

// right hand

_______               , _______       , _______       , _______                  , _______         , _______        , _______          ,
_______               , _______       , KC_HOME       , KC_UP                    , KC_END          , _______        , _______          ,
_______               , KC_LEFT       , KC_DOWN       , KC_RGHT                  , _______         , KC_MPLY        ,
KC_MUTE               , _______       , KC_WBAK       , KC_MPRV                  , KC_MNXT         , _______        , _______          ,
_______               , _______       , _______       , _______                  , _______         ,

// right thumb

_______               , _______       ,
_______               ,
_______               , _______       , _______
)                     ,

[3] = LAYOUT_ergodox(
// left hand

TO(0)                 , TO(4)         , TO(6)         , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , _______         ,

// left thumb

XXXXXXX               , XXXXXXX       ,
XXXXXXX               ,
XXXXXXX               , XXXXXXX       , XXXXXXX       ,

// right hand

XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , EEP_RST          ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
_______               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         ,

// right thumb

XXXXXXX               , XXXXXXX       ,
XXXXXXX               ,
XXXXXXX               , XXXXXXX       , XXXXXXX
)                     ,

[4] = LAYOUT_ergodox(
// left hand

TD(TD_ESC_ZERO)       , KC_1          , KC_2          , KC_3                     , KC_4            , KC_5           , KC_6             ,
KC_TAB                , KC_Q          , KC_W          , KC_E                     , KC_R            , KC_T           , KC_I             ,
_______               , KC_A          , KC_S          , KC_D                     , KC_F            , KC_G           ,
_______               , KC_Z          , KC_X          , KC_C                     , KC_V            , KC_B           , KC_U             ,
KC_LCTL               , KC_7          , KC_8          , KC_9                     , KC_0            ,

// left thumb

KC_MS_L               , KC_MS_R       ,
KC_MS_U               ,
KC_SPC                , KC_PPLS       , KC_MS_D       ,

// right hand

KC_RBRC               , KC_INS        , KC_NLCK       , KC_PSLS                  , KC_PAST         , KC_DEL         , KC_PMNS          ,
KC_NUHS               , KC_PGUP       , KC_P7         , KC_P8                    , KC_P9           , KC_END         , KC_HOME          ,
KC_PGDN               , KC_P4         , KC_P5         , KC_P6                    , KC_M            , KC_PPLS        ,
KC_ENT                , XXXXXXX       , KC_P1         , KC_P2                    , KC_P3           , KC_J           , KC_PENT          ,
KC_SPC                , KC_P0         , KC_PDOT       , KC_L                     , KC_PENT         ,

// right thumb

KC_BTN1               , KC_BTN2       ,
TO(5)                 ,
OSL(5)                , KC_SPC        , KC_RGHT
)                     ,

[5] = LAYOUT_ergodox(
// left hand

TO(0)                 , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
TO(0)                 , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         ,

// left thumb

XXXXXXX               , XXXXXXX       ,
XXXXXXX               ,
XXXXXXX               , XXXXXXX       , XXXXXXX       ,

// right hand

XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         , XXXXXXX        , XXXXXXX          ,
XXXXXXX               , XXXXXXX       , XXXXXXX       , XXXXXXX                  , XXXXXXX         ,

// right thumb

XXXXXXX               , XXXXXXX       ,
XXXXXXX               ,
XXXXXXX               , XXXXXXX       , XXXXXXX
)                     ,

[6] = LAYOUT_ergodox(
// left hand

TD(TD_ESC_ZERO)         , TD(TD_1_SH_1)    , TD(TD_2_SH_2) , TD(TD_3_SH_3)    , TD(TD_4_SH_4)   , TD(TD_5_SH_5)    , TD(TD_6_SH_6)       ,
TD(TD_SH_TAB)           , TD(TD_SH_Q)    , TD(TD_SH_W) , TD(TD_SH_E)    , TD(TD_SH_R)   , TD(TD_SH_T)    , TD(TD_GRAVE_TAB)  ,
TD(TD_NLCK_SLCK_TOGGLE) , TD(TD_SH_A)    , TD(TD_SH_S) , TD(TD_SH_D)    , TD(TD_SH_F)   , TD(TD_SH_G)    ,
KC_LSFT                 , TD(TD_SH_NUBS) , TD(TD_SH_Z) , TD(TD_SH_X)    , TD(TD_SH_C)   , TD(TD_SH_V)    , TD(TD_SH_B)       ,
KC_LCTL                 , KC_KP_DOT      , KC_LALT     , KC_INSERT      , OSL(7)   ,

// left thumb

KC_HOME                 , KC_END         ,
KC_PGUP                 ,
KC_SPC                  , KC_ENT         , KC_PGDN     ,

// right hand

TD(TD_7_SH_7)             , TD(TD_8_SH_8)    , TD(TD_9_SH_9) , TD(TD_0_SH_0)   , TD(TD_MINUS_SH_MINUS) , TD(TD_EQL_SH_EQL)  , KC_BSPC           ,
KC_LBRC                 , TD(TD_Y_U)     , TD(TD_SH_U) , KC_I           , TD(TD_O_U)    , TD(TD_P_U)     , TD(TD_HASH_SHIFT) ,
KC_H                    , KC_J           , KC_K        , KC_L           , KC_SCLN       , KC_QUOT        ,
KC_RBRC                 , KC_N           , KC_M        , TD(TD_SH_COMM) , TD(TD_SH_DOT) , TD(TD_SH_SLSH) , KC_LSFT           ,
OSL(7)                   , KC_DEL         , KC_LALT     , KC_KP_ENTER    , KC_LCTL       ,

// right thumb

KC_KP_SLASH             , KC_KP_ASTERISK ,
KC_KP_MINUS             ,
KC_KP_PLUS              , KC_ENT         , KC_SPC

),

[7] = LAYOUT_ergodox(
// left hand

_______              , TD(TD_F1_SH_F1) , TD(TD_F2_SH_F2) , TD(TD_F3_SH_F3)   , TD(TD_F4_SH_F4)   , TD(TD_F5_SH_F5)   , TD(TD_F6_SH_F6)   ,
_______              , _______              , _______              , _______                , _______                , _______                , _______                ,
_______              , _______              , _______              , _______                , _______                , _______                ,
_______              , _______              , _______              , _______                , _______                , _______                , _______                ,
_______              , _______              , _______              , _______                , _______                ,

// left thumb

_______              , _______              ,
_______              ,
KC_BTN1              , KC_BTN2              , KC_BTN3              ,

// right hand

TD(TD_F7_SH_F7) , TD(TD_F8_SH_F8) , TD(TD_F9_SH_F9) , TD(TD_F10_SH_F10) , TD(TD_F11_SH_F11) , TD(TD_F12_SH_F12) , TD(TD_F13_SH_F13) ,
_______              , _______              , _______              , KC_MS_U                , _______                , _______                , _______                ,
KC_BTN2              , KC_MS_L              , KC_MS_D              , KC_MS_R                , KC_BTN1                , _______                ,
_______              , _______              , _______              , _______                , _______                , _______                , _______                ,
_______              , _______              , _______              , _______                , _______                ,

// right thumb

_______              , _______              ,
_______              ,
KC_BTN3              , KC_BTN2              , KC_BTN1
)

}; // END OF KEYMAPS

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_led_all_set(LED_BRIGHTNESS_HI);
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};


#define _BASE_LAYER 0
#define _FUN_LAYER 1
#define _MOUSE_LAYER 2
#define _GAMES_SELECT_LAYER 3
#define _DDO_LAYER 4
#define _LOTRO_LAYER 6
#define _LOTRO_LAYER_FN 7
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
  case 4: //games Select layer on
    layer_move(_GAMES_SELECT_LAYER);
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

void grave_caps(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      SEND_STRING(SS_TAP(X_GRAVE));
      break;
    case 2:
      SEND_STRING(SS_TAP(X_GRAVE));
      SEND_STRING(SS_TAP(X_GRAVE));
      break;
    default:
      SEND_STRING(SS_TAP(X_CAPSLOCK));
      break;
  }
}

void esc_to_zero(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 3:
      layer_move(0);
      break;
    case 4:
      layer_move(0);
      break;
    case 5:
      layer_move(0);
      break;
    default:
      tap_code(KC_ESC);
      break;
  }
}

void grave_tab(qk_tap_dance_state_t *state, void *user_data) {
    SEND_STRING(SS_TAP(X_GRAVE) SS_TAP(X_TAB));
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

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed) return TD_SINGLE_HOLD;
        else return TD_SINGLE_TAP;
    } else if (state->count == 2) {
        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        /* if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP; */
        return TD_TRIPLE_TAP;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};


void register_td_key(uint16_t keycode1, uint16_t keycode2, qk_tap_dance_state_t *state) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(keycode1); break;
        case TD_SINGLE_HOLD: register_code(keycode1); break;
        case TD_DOUBLE_TAP: tap_code(keycode1); tap_code(keycode1); break;
        case TD_DOUBLE_HOLD: register_code(keycode2); break;
        case TD_TRIPLE_TAP: tap_code(keycode1); tap_code(keycode1); tap_code(keycode1); break;
        default: register_code(keycode1); break;
    }
}

void unregister_td_key(uint16_t keycode1, uint16_t keycode2, qk_tap_dance_state_t *state) {
    switch (xtap_state.state) {
        case TD_DOUBLE_HOLD: unregister_code(keycode2);
        default: unregister_code(keycode1); break;
    }
    xtap_state.state = TD_NONE;
}

void k1_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_1, KC_F1, state);
}

void k1_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_1, KC_F1, state);
}

void k2_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_2, KC_F2, state);
}

void k2_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_2, KC_F2, state);
}

void k3_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_3, KC_F3, state);
}

void k3_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_3, KC_F3, state);
}

void k4_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_4, KC_F4, state);
}

void k4_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_4, KC_F4, state);
}

void k5_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_5, KC_F5, state);
}

void k5_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_5, KC_F5, state);
}

void k6_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_6, KC_F6, state);
}

void k6_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_6, KC_F6, state);
}

void k7_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_7, KC_F7, state);
}

void k7_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_7, KC_F7, state);
}

void k8_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_8, KC_F8, state);
}

void k8_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_8, KC_F8, state);
}

void k9_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_9, KC_F9, state);
}

void k9_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_9, KC_F9, state);
}

void k0_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_0, KC_F10, state);
}

void k0_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_0, KC_F10, state);
}

void k11_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_MINUS, KC_F11, state);
}

void k11_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_MINUS, KC_F11, state);
}

void k12_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_td_key(KC_EQL, KC_F12, state);
}

void k12_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_td_key(KC_EQL, KC_F12, state);
}


qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LAYER_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, dance_layers_finish),
  [TD_INSERT_COPY_PASTE] = ACTION_TAP_DANCE_FN(insert_copy_paste),
  [TD_ALTS_TOGGLE] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
  [TD_NLCK_SLCK_TOGGLE] = ACTION_TAP_DANCE_DOUBLE(KC_NLCK, KC_SCROLLLOCK),
  [TD_GRAVE_CAPS] = ACTION_TAP_DANCE_FN(grave_caps),
  [TD_GRAVE_TAB] = ACTION_TAP_DANCE_FN(grave_tab),
  [TD_ESC_ZERO] = ACTION_TAP_DANCE_FN(esc_to_zero),
  [TD_HASH_SHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_NUHS, LSFT(KC_NUHS)),
  [TD_1_SH_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, LSFT(KC_1)),
  [TD_2_SH_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, LSFT(KC_2)),
  [TD_3_SH_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, LSFT(KC_3)),
  [TD_4_SH_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, LSFT(KC_4)),
  [TD_5_SH_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, LSFT(KC_5)),
  [TD_6_SH_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, LSFT(KC_6)),
  [TD_7_SH_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, LSFT(KC_7)),
  [TD_8_SH_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, LSFT(KC_8)),
  [TD_9_SH_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, LSFT(KC_9)),
  [TD_0_SH_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, LSFT(KC_0)),
  [TD_MINUS_SH_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, LSFT(KC_MINUS)),
  [TD_EQL_SH_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, LSFT(KC_EQL)),
  [TDT_1_F1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k1_finished, k1_reset),
  [TDT_2_F2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k2_finished, k2_reset),
  [TDT_3_F3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k3_finished, k3_reset),
  [TDT_4_F4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k4_finished, k4_reset),
  [TDT_5_F5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k5_finished, k5_reset),
  [TDT_6_F6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k6_finished, k6_reset),
  [TDT_7_F7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k7_finished, k7_reset),
  [TDT_8_F8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k8_finished, k8_reset),
  [TDT_9_F9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k9_finished, k9_reset),
  [TDT_0_F10] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k0_finished, k0_reset),
  [TDT_11_F11] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k11_finished, k11_reset),
  [TDT_12_F12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k12_finished, k12_reset),
  [TD_SH_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LSFT(KC_Q)),
  [TD_SH_W] = ACTION_TAP_DANCE_DOUBLE(KC_W, LSFT(KC_W)),
  [TD_SH_E] = ACTION_TAP_DANCE_DOUBLE(KC_E, LSFT(KC_E)),
  [TD_SH_R] = ACTION_TAP_DANCE_DOUBLE(KC_R, LSFT(KC_R)),
  [TD_SH_T] = ACTION_TAP_DANCE_DOUBLE(KC_T, LSFT(KC_T)),
  [TD_SH_A] = ACTION_TAP_DANCE_DOUBLE(KC_A, LSFT(KC_A)),
  [TD_SH_S] = ACTION_TAP_DANCE_DOUBLE(KC_S, LSFT(KC_S)),
  [TD_SH_D] = ACTION_TAP_DANCE_DOUBLE(KC_D, LSFT(KC_D)),
  [TD_SH_F] = ACTION_TAP_DANCE_DOUBLE(KC_F, LSFT(KC_F)),
  [TD_SH_G] = ACTION_TAP_DANCE_DOUBLE(KC_G, LSFT(KC_G)),
  [TD_SH_Z] = ACTION_TAP_DANCE_DOUBLE(KC_Z, LSFT(KC_Z)),
  [TD_SH_X] = ACTION_TAP_DANCE_DOUBLE(KC_X, LSFT(KC_X)),
  [TD_SH_C] = ACTION_TAP_DANCE_DOUBLE(KC_C, LSFT(KC_C)),
  [TD_SH_V] = ACTION_TAP_DANCE_DOUBLE(KC_V, LSFT(KC_V)),
  [TD_SH_B] = ACTION_TAP_DANCE_DOUBLE(KC_B, LSFT(KC_B)),
  [TD_SH_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, LSFT(KC_U)),
  [TD_SH_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_DOT)),
  [TD_SH_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),
  [TD_SH_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LSFT(KC_COMM)),
  [TD_O_U] = ACTION_TAP_DANCE_DOUBLE(KC_O, LSFT(KC_U)),
  [TD_Y_U] = ACTION_TAP_DANCE_DOUBLE(KC_Y, LSFT(KC_U)),
  [TD_P_U] = ACTION_TAP_DANCE_DOUBLE(KC_P, LSFT(KC_U)),
  [TD_LBRC_U] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_U)),
  [TD_SH_NUBS] = ACTION_TAP_DANCE_DOUBLE(KC_NUBS, LSFT(KC_NUBS)),
  [TD_SH_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, LSFT(KC_TAB)),
  [TD_F1_SH_F1] = ACTION_TAP_DANCE_DOUBLE(KC_F1, LSFT(KC_F1)),
  [TD_F2_SH_F2] = ACTION_TAP_DANCE_DOUBLE(KC_F2, LSFT(KC_F2)),
  [TD_F3_SH_F3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, LSFT(KC_F3)),
  [TD_F4_SH_F4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, LSFT(KC_F4)),
  [TD_F5_SH_F5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, LSFT(KC_F5)),
  [TD_F6_SH_F6] = ACTION_TAP_DANCE_DOUBLE(KC_F6, LSFT(KC_F6)),
  [TD_F7_SH_F7] = ACTION_TAP_DANCE_DOUBLE(KC_F7, LSFT(KC_F7)),
  [TD_F8_SH_F8] = ACTION_TAP_DANCE_DOUBLE(KC_F8, LSFT(KC_F8)),
  [TD_F9_SH_F9] = ACTION_TAP_DANCE_DOUBLE(KC_F9, LSFT(KC_F9)),
  [TD_F10_SH_F10] = ACTION_TAP_DANCE_DOUBLE(KC_F10, LSFT(KC_F10)),
  [TD_F11_SH_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F11, LSFT(KC_F11)),
  [TD_F12_SH_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F12, LSFT(KC_F12)),
  [TD_F13_SH_F13] = ACTION_TAP_DANCE_DOUBLE(KC_F13, LSFT(KC_F13)),
};
