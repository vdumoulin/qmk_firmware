// Vincent Dumoulin's Ferris Sweep keyboard layout.

#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _SYM,
  _NUM,
  _EXT,
};

/* Home row mods */
#define _G_A LGUI_T(KC_A)
#define _A_S LALT_T(KC_S)
#define _C_D LCTL_T(KC_D)
#define _S_F LSFT_T(KC_F)
#define _S_J LSFT_T(KC_J)
#define _C_K LCTL_T(KC_K)
#define _A_L LALT_T(KC_L)
#define _G_QUOT LGUI_T(KC_QUOT)

/* One-shot mods */
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

/* Layer toggling */
#define OS_SYM OSL(_SYM)
#define OS_NUM OSL(_NUM)

/* Tap-dance */
enum tap_dance {
  TBO,
  TRE
};

void td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

void td_fn_reboot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    soft_reset_keyboard();
  }
}

tap_dance_action_t tap_dance_actions[] = {
  [TBO] = ACTION_TAP_DANCE_FN(td_fn_boot),
  [TRE] = ACTION_TAP_DANCE_FN(td_fn_reboot),
};

/* Keymap */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,      KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        _G_A    , _A_S    , _C_D    , _S_F    , KC_G    ,      KC_H    , _S_J    , _C_K    , _A_L    , _G_QUOT ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,      KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      OS_NUM  , KC_SPC  ,      OS_LSFT , OS_SYM
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
    [_SYM] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_LPRN , KC_LBRC , KC_LCBR , KC_LABK , OS_LGUI ,      OS_LCTL , KC_RABK , KC_RCBR , KC_RBRC , KC_RPRN ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,      KC_CIRC , KC_AMPR , KC_ASTR , KC_BSLS , KC_SCLN ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_GRV  , KC_TILD , KC_PLUS , KC_UNDS , OS_LSFT ,      OS_LALT , KC_MINS , KC_EQL  , KC_PIPE , KC_COLN ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      _______ , _______ ,      _______ , _______
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
    [_NUM] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_ESC  , KC_F7   , KC_F8   , KC_F9   , OS_LGUI ,      OS_LCTL , KC_7    , KC_8    , KC_9    , KC_BSPC ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_TAB  , KC_F4   , KC_F5   , KC_F6   , KC_F10  ,      KC_0    , KC_4    , KC_5    , KC_6    , KC_ENT  ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        CW_TOGG , KC_F1   , KC_F2   , KC_F3   , OS_LSFT ,      OS_LALT , KC_1    , KC_2    , KC_3    , KC_DEL  ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      _______ , _______ ,      _______ , _______
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
    [_EXT] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_VOLD , KC_VOLU , KC_MUTE , KC_F11  , KC_F12  ,      KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , KC_BRIU ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        DM_RSTP , DM_PLY1 , DM_PLY2 , DM_REC1 , DM_REC2 ,      KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_BRID ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        TD(TRE) , KC_MPRV , KC_MNXT , KC_MSTP , KC_MPLY ,      KC_HOME , KC_PGDN , KC_PGUP , KC_END  , TD(TBO) ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      _______ , _______ ,      _______ , _______
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _SYM, _NUM, _EXT);
}
