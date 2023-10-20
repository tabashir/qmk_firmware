#include "shared_enum.h"
#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
     * │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│Slk│Pse│
     * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│ │Num│ / │ * │ - │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │     │ │Del│End│PgD│ │ 7 │ 8 │ 9 │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ Ent│ └───┴───┴───┘ ├───┼───┼───┤ + │
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │    │               │ 4 │ 5 │ 6 │   │
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐     ├───┼───┼───┼───┤
     * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤Ent│
     * │Ctrl│GUI │Alt │                        │AlGr│ GUI│Menu│Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │   │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
     */
   [_QWERTY] = LAYOUT_fullsize_iso(
        KC_ESC                      , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6              , KC_F7   , KC_F8 , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,
        KC_PSCR                     , KC_SLCK , KC_PAUS ,

        KC_GRV                      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6               , KC_7    , KC_8  , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC ,
        KC_INSERT                   , KC_HOME , KC_PGUP ,
        KC_NLCK                     , KC_PSLS , KC_PAST , KC_PMNS ,

        KC_TAB                      , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y               , KC_U    , KC_I  , KC_O    , KC_P    , KC_LBRC , KC_RBRC ,
        KC_DEL                      , KC_END  , KC_PGDN ,
        KC_P7                       , KC_P8   , KC_P9   , KC_PPLS ,

        KC_CAPS                     , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H               , KC_J    , KC_K  , KC_L    , KC_SCLN , KC_QUOT , KC_NUHS , KC_ENT  ,
        KC_P4                       , KC_P5   , KC_P6   ,

        KC_LSFT                     , KC_NUBS , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B               , KC_N    , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
        KC_UP                       ,
        KC_P1                       , KC_P2   , KC_P3   , KC_PENT ,

        KC_LCTL                     , KC_LGUI , KC_LALT , KC_SPC  , KC_RALT , KC_RGUI , TO(_LAYER_CHOOSER) , KC_RCTL ,
        KC_LEFT                     , KC_DOWN , KC_RGHT ,
        KC_P0                       , KC_PDOT
    )                               ,

   [_LAYER_CHOOSER] = LAYOUT_fullsize_iso(
        TD(TD_ESC_ZERO) , TO(_QWERTY) , TO(_GAMES) , TO(_IMPACT) , TO(_WOW) , TO(_VALHEIM) , XXXXXXX            , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        XXXXXXX         , XXXXXXX     , XXXXXXX    ,

        XXXXXXX         , XXXXXXX     , XXXXXXX    , XXXXXXX     , XXXXXXX , XXXXXXX , XXXXXXX            , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        XXXXXXX         , XXXXXXX     , XXXXXXX    ,
        XXXXXXX         , XXXXXXX     , XXXXXXX    , XXXXXXX     ,

        XXXXXXX         , XXXXXXX     , XXXXXXX    , XXXXXXX     , XXXXXXX , XXXXXXX , XXXXXXX            , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        XXXXXXX         , XXXXXXX     , XXXXXXX    ,
        XXXXXXX         , XXXXXXX     , XXXXXXX    , XXXXXXX     ,

        XXXXXXX         , XXXXXXX     , XXXXXXX    , XXXXXXX     , XXXXXXX , XXXXXXX , XXXXXXX            , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        XXXXXXX         , XXXXXXX     , XXXXXXX    ,

        XXXXXXX         , XXXXXXX     , XXXXXXX    , XXXXXXX     , XXXXXXX , XXXXXXX , XXXXXXX            , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        XXXXXXX         ,
        XXXXXXX         , XXXXXXX     , XXXXXXX    , XXXXXXX     ,

        XXXXXXX         , XXXXXXX     , XXXXXXX    , XXXXXXX     , XXXXXXX , XXXXXXX , TO(_LAYER_CHOOSER) , XXXXXXX ,
        XXXXXXX         , XXXXXXX     , XXXXXXX    ,
        XXXXXXX         , XXXXXXX
    ),

   [_GAMES] = LAYOUT_fullsize_iso(
// Function Row
        TD(TD_ESC_ZERO) , KC_F1          , KC_F2          , KC_F3          , KC_F4          , KC_F5          , KC_F6              , KC_F7          , KC_F8          , KC_F9          , KC_F10         , KC_F11  , KC_F12  ,
        //numpad
        KC_PSCR         , KC_SLCK        , KC_PAUS        ,
// Number Row
        KC_GRV          , TD(TD_1_ALT_1) , TD(TD_2_ALT_2) , TD(TD_3_ALT_3) , TD(TD_4_ALT_4) , TD(TD_5_ALT_5) , TD(TD_6_ALT_6)     , TD(TD_7_ALT_7) , TD(TD_8_ALT_8) , TD(TD_9_ALT_9) , TD(TD_0_ALT_0) , KC_MINS , KC_EQL  , KC_BSPC ,
        //middle
        KC_INS          , KC_HOME        , KC_PGUP        ,
        //numpad
        TD(TD_1_ALT_1)  , TD(TD_2_ALT_2) , TD(TD_3_ALT_3) , TD(TD_4_ALT_4) ,
// QWERTY Row
        KC_TAB          , KC_Q           , KC_W           , KC_E           , KC_R           , KC_T           , KC_Y               , KC_U           , KC_I           , KC_O           , KC_P           , KC_LBRC , KC_RBRC ,
        //middle
        KC_DEL          , KC_END         , KC_PGDN        ,
        //numpad
        KC_Q            , KC_W           , KC_E           , KC_R           ,
// ASDF Row
        KC_BTN1         , KC_A           , KC_S           , KC_D           , KC_F           , KC_G           , KC_H               , KC_J           , KC_K           , KC_L           , KC_SCLN        , KC_QUOT , KC_NUHS , KC_ENT  ,
        //numpad
        KC_A            , KC_S           , KC_D           ,
// ZXCV Row
        KC_LSFT         , KC_NUBS        , KC_Z           , KC_X           , KC_C           , KC_V           , KC_B               , KC_N           , KC_M           , KC_COMM        , KC_DOT         , KC_SLSH , KC_RSFT ,
        //middle
        KC_UP           ,
        //numpad
        KC_Z            , KC_X           , KC_C           , KC_F           ,
// Space Row
        KC_LCTL         , KC_LWIN        , KC_LALT        , KC_SPC         , KC_RALT        , KC_RGUI        , TO(_LAYER_CHOOSER) , KC_RCTL        ,
        //middle
        KC_LEFT         , KC_DOWN        , KC_RIGHT       ,
        //numpad
        KC_P0           , KC_PDOT
    ),

   [_IMPACT] = LAYOUT_fullsize_iso(
// Function Row
        TD(TD_ESC_ZERO) , KC_F1          , KC_F2          , KC_F3          , KC_F4          , KC_F5          , KC_F6              , KC_F7   , KC_F8 , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,
        //numpad
        KC_PSCR         , KC_ACL2        , KC_V        ,
// Number Row
        KC_BTN1         , TD(TD_1_ALT_1) , TD(TD_2_ALT_2) , TD(TD_3_ALT_3) , TD(TD_4_ALT_4) , TD(TD_5_ALT_5) , KC_6               , KC_7    , KC_8  , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC ,
        //middle
        KC_INS          , KC_ACL1        , TD(TD_5_ALT_5) ,
        //numpad
        TD(TD_1_ALT_1)  , TD(TD_2_ALT_2) , TD(TD_3_ALT_3) , TD(TD_4_ALT_4) ,
// QWERTY Row
        KC_TAB          , KC_Q           , KC_W           , KC_E           , KC_R           , KC_T           , KC_Y               , KC_U    , KC_I  , KC_O    , KC_P    , KC_LBRC , KC_RBRC ,
        //middle
        KC_DEL          , KC_ACL0        , KC_Z           ,
        //numpad
        KC_A           , KC_W           , KC_D         , KC_B           ,
// ASDF Row
        KC_BTN3         , KC_A           , KC_S           , KC_D           , KC_F           , KC_G           , KC_H               , KC_J    , KC_K  , KC_L    , KC_SCLN , KC_QUOT , KC_NUHS , KC_ENT  ,
        //middle
        KC_MS_L            , KC_S           , KC_MS_R           ,
// ZXCV Row
        KC_LSFT         , TD(TD_ATK_ALL) , KC_Z           , KC_X           , KC_C           , KC_V           , KC_B               , KC_N    , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
        //middle
        KC_J            ,
        //numpad
        KC_M            , KC_X           , KC_L           , KC_F           ,
// Space Row
        KC_Q            , KC_BTN1        , KC_E           , KC_SPC         , KC_RALT        , KC_RGUI        , TO(_LAYER_CHOOSER) , KC_LCTL ,
        //middle
        KC_BTN1      , KC_LSFT        , KC_SPACE       ,
        //numpad
        KC_T         , KC_V
        //TD(TD_T_OR_X)
    ),

   [_WOW] = LAYOUT_fullsize_iso(
// Function Row
        TD(TD_ESC_ZERO) , TD(TD_F1_S_F1), TD(TD_F2_S_F2), TD(TD_F3_S_F3), TD(TD_F4_S_F4), TD(TD_F5_S_F5), TD(TD_F6_S_F6), TD(TD_F7_S_F7), TD(TD_F8_S_F8), TD(TD_F9_S_F9), TD(TD_F10_S_F10), TD(TD_F11_S_F11), TD(TD_F12_S_F12),
        //numpad
        TD(TD_5_N_ALT_5) , TD(TD_6_N_ALT_6) , TD(TD_7_N_ALT_7) ,
// Number Row
        TD(TD_PGUP_S_PGUP)          , TD(TD_1_ALT_1) , TD(TD_2_ALT_2) , TD(TD_3_ALT_3) , TD(TD_4_ALT_4) , TD(TD_5_ALT_5) , TD(TD_6_ALT_6)     , TD(TD_7_ALT_7) , TD(TD_8_ALT_8) , TD(TD_9_ALT_9) , TD(TD_0_ALT_0) , KC_MINS , KC_EQL  , KC_BSPC ,
        //middle
        TD(TD_INS_S_INS), TD(TD_HOME_S_HOME), TD(TD_PGUP_S_PGUP),
        //numpad
        TD(TD_1_N_ALT_1)  , TD(TD_2_N_ALT_2)  , TD(TD_3_N_ALT_3) , TD(TD_4_N_ALT_4) ,
// QWERTY Row
        KC_TAB          , KC_Q           , KC_W           , KC_E           , KC_R           , KC_T           , KC_Y               , KC_U           , KC_I           , KC_O           , KC_P           , KC_LBRC , KC_RBRC ,
        //middle
        TD(TD_DEL_S_DEL), TD(TD_END_S_END), TD(TD_PGDN_S_PGDN),
        //numpad
        KC_Q            , KC_W           , KC_E           , KC_R           ,
// ASDF Row
        KC_BTN1         , KC_A           , KC_S           , KC_D           , KC_F           , KC_G           , KC_H               , KC_J           , KC_K           , KC_L           , KC_SCLN        , KC_QUOT , KC_NUHS , KC_ENT  ,
        //numpad
        KC_A            , KC_S           , KC_D           ,
// ZXCV Row
        KC_LSFT         , KC_NUBS        , KC_Z           , KC_X           , KC_C           , KC_V           , KC_B               , KC_N           , KC_M           , KC_COMM        , KC_DOT         , KC_SLSH , KC_RSFT ,
        //middle
        LSFT(KC_PGDN)   ,
        //numpad
        KC_Z            , KC_X           , KC_C           , LSA_T(KC_N)    ,
// Space Row
        KC_LCTL         , KC_LWIN        , KC_LALT        , KC_SPC         , KC_RALT        , KC_RGUI        , TO(_LAYER_CHOOSER) , KC_RCTL        ,
        //middle
        KC_LCTL         , KC_LSFT        , KC_SPACE       ,
        //numpad
        KC_LALT         , LSA_T(KC_PDOT)
    ),

   [_VALHEIM] = LAYOUT_fullsize_iso(
// Function Row
        TD(TD_ESC_ZERO) , KC_F1          , KC_F2          , KC_F3          , KC_F4          , KC_F5          , KC_F6              , KC_F7   , KC_F8 , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,
        //numpad
        TD(TD_Z_A1)     , TD(TD_V_A2)    , TD(TD_B_A3)  ,
// Number Row
        KC_BTN1         , TD(TD_1_ALT_1) , TD(TD_2_ALT_2) , TD(TD_3_ALT_3) , TD(TD_4_ALT_4) , TD(TD_5_ALT_5) , KC_6               , KC_7    , KC_8  , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC ,
        //middle
        KC_INS          , KC_ACL2        , TD(TD_5_9) ,
        //numpad
        TD(TD_1_5)  , TD(TD_2_6) , TD(TD_3_7) , TD(TD_4_8) ,
// QWERTY Row
        KC_TAB          , KC_Q           , KC_W           , KC_E           , KC_R           , KC_T           , KC_Y               , KC_U    , KC_I  , KC_O    , KC_P    , KC_LBRC , KC_RBRC ,
        //middle
        KC_DEL          , KC_ACL0        , KC_PGDOWN           ,
        //numpad
        KC_A           , KC_W           , KC_D         , KC_PPLS           ,
// ASDF Row
        KC_BTN3         , KC_A           , KC_S           , KC_D           , KC_F           , KC_G           , KC_H               , KC_J    , KC_K  , KC_L    , KC_SCLN , KC_QUOT , KC_NUHS , KC_ENT  ,
        //middle
        KC_MS_L            , KC_S           , KC_MS_R           ,
// ZXCV Row
        KC_LSFT         , TD(TD_ATK_ALL) , KC_Z           , KC_X           , KC_C           , KC_V           , KC_B               , KC_N    , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
        //middle
        KC_UP            ,
        //numpad
        KC_P1            , KC_P2           , KC_P3           , KC_PENT           ,
// Space Row
        KC_BTN3         , KC_BTN1        , KC_LALT         , KC_SPC         , KC_RALT        , KC_RGUI       , TO(_LAYER_CHOOSER) , KC_LCTL ,
        //middle
        KC_LEFT     , KC_DOWN        , KC_RIGHT       ,
        //numpad
        KC_P0         , KC_PDOT
        //TD(TD_T_OR_X)
    )

};




