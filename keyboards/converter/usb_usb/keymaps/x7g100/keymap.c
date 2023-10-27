#include "shared_enum.h"
#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl│
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [_ORIGINAL] = LAYOUT_62_G100X7(
                            KC_F7       , KC_F8       , KC_F9         , KC_F10       , KC_F11   , TO(_LAYER_CHOOSER) , // KC_VOLU ,
                            KC_F1       , KC_F2       , KC_F3         , KC_F4        , KC_F5    , KC_F6              , // KC_VOLD ,
        TD(TD_ESC_ZERO)                 , KC_5        , KC_6          , KC_7         , KC_8     , KC_9               , KC_MINS    , KC_EQUAL , KC_CAPS_LOCK ,
        KC_GRV                          , KC_1        , KC_2          , KC_3         , KC_4     , KC_T               , KC_B       , KC_O     , KC_BACKSPACE ,
        KC_TAB                          , KC_Q        , KC_W          , KC_E         , KC_R     , KC_COMMA           , KC_DOT     , KC_PGUP  ,
        KC_LSFT                         , KC_A        , KC_S          , KC_D         , KC_F     , KC_G               , KC_J       , KC_PGDN  ,
        KC_LCTL                         , KC_Z        , KC_X          , KC_C         , KC_Y     , KC_U               , KC_K       , KC_L     ,
        KC_LALT                         , KC_V        , KC_N          , KC_M         , KC_SPACE , KC_ENT
    )                                   ,

   [_LAYER_CHOOSER] = LAYOUT_62_G100X7(
                            XXXXXXX     , XXXXXXX     , XXXXXXX       , XXXXXXX      , XXXXXXX  , TO(_LAYER_CHOOSER) , // XXXXXXX ,
                            XXXXXXX     , XXXXXXX     , XXXXXXX       , XXXXXXX      , XXXXXXX  , XXXXXXX            , // XXXXXXX ,
        TD(TD_ESC_ZERO)                 , TO(_KEYPAD) , TO(_ORIGINAL) , TO(_VALHEIM) , XXXXXXX  , XXXXXXX            , XXXXXXX    , XXXXXXX  , XXXXXXX      ,
        XXXXXXX                         , XXXXXXX     , XXXXXXX       , XXXXXXX      , XXXXXXX  , XXXXXXX            , XXXXXXX    , XXXXXXX  , XXXXXXX      ,
        XXXXXXX                         , XXXXXXX     , XXXXXXX       , XXXXXXX      , XXXXXXX  , XXXXXXX            , XXXXXXX    , XXXXXXX  ,
        XXXXXXX                         , XXXXXXX     , XXXXXXX       , XXXXXXX      , XXXXXXX  , XXXXXXX            , XXXXXXX    , XXXXXXX  ,
        XXXXXXX                         , XXXXXXX     , XXXXXXX       , XXXXXXX      , XXXXXXX  , XXXXXXX            , XXXXXXX    , XXXXXXX  ,
        XXXXXXX                         , XXXXXXX     , XXXXXXX       , XXXXXXX      , XXXXXXX  , XXXXXXX
    )                                   ,

   [_KEYPAD] = LAYOUT_62_G100X7(
                            KC_F7       , KC_F8       , KC_F9         , KC_F10       , KC_F11   , TO(_LAYER_CHOOSER) , // KC_VOLU ,
                            KC_F13      , KC_F14      , KC_F15        , KC_F16       , KC_F17   , KC_F18             , // KC_VOLD ,
        TD(TD_ESC_ZERO)                 , KC_F1       , KC_F2         , KC_F3        , KC_F4    , KC_F5              , KC_F6      , KC_9     , KC_0         ,
        KC_GRV                          , KC_1        , KC_2          , KC_3         , KC_4     , KC_5               , KC_6       , KC_7     , KC_8         ,
        KC_TAB                          , KC_F10      , KC_UP         , KC_F11       , KC_P7    , KC_P8              , KC_P9      , KC_PMNS  ,
        KC_LSFT                         , KC_LEFT     , KC_DOWN       , KC_RIGHT     , KC_P4    , KC_P5              , KC_P6      , KC_PEQL  ,
        KC_LCTL                         , KC_PAST     , KC_PPLS       , KC_PMNS      , KC_P1    , KC_P2              , KC_P3      , KC_P0    ,
        KC_LALT                         , KC_UNDO     , KC_PSLS       , KC_M         , KC_SPACE , KC_PENT
    )
};
