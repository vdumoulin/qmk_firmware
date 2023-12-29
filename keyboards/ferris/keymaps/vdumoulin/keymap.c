// Vincent Dumoulin's Ferris Sweep keyboard layout.
//
// Reuses Miryoku (QWERTY, vi navigation) layout conventions with a few
// simplifications and tweaks:
//
//   * No Button layer and no Extra and Tap alternate base layers.
//   * Double-tap buttons are modified to have the following functionalities
//     (index to pinkie, {left,right} hand): DM_PLY{1,2} (single-tap), DM_RSTP
//     (single-tap), DM_REC{1,2} (single-tap), QK_REBOOT QK_BOOT.
//   * No layer-lock additional functionality.
//   * No RGB or bluetooth functionalities in the Media layer; the index and
//     middle fingers in the top row control screen brightness instead.

#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _SYM,
  _NUM,
  _EXT,
};

/* Home row mods */
#define KC_GUIA LGUI_T(KC_A)
#define KC_ALTS LALT_T(KC_S)
#define KC_CTLD LCTL_T(KC_D)
#define KC_CTLK LCTL_T(KC_K)
#define KC_ALTL LALT_T(KC_L)
#define KC_GUOT LGUI_T(KC_QUOT)

/* One-shot mods */
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

/* Layer toggling */
#define LA_SYM MO(_SYM)
#define LA_NUM MO(_NUM)

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
        KC_GUIA , KC_ALTS , KC_CTLD , KC_F    , KC_G    ,      KC_H    , KC_J    , KC_CTLK , KC_ALTL , KC_GUOT ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,      KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      LA_NUM  , KC_SPC  ,      KC_LSFT , LA_SYM
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
    [_SYM] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_LPRN , KC_LBRC , KC_LCBR , KC_LABK , OS_LCTL ,      OS_LSFT , KC_RABK , KC_RCBR , KC_RBRC , KC_RPRN ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,      KC_CIRC , KC_AMPR , KC_ASTR , KC_BSLS , KC_SCLN ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_GRV  , KC_TILD , KC_PLUS , KC_UNDS , OS_LGUI ,      OS_LALT , KC_MINS , KC_EQL  , KC_PIPE , KC_COLN ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      _______ , _______ ,      _______ , _______
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
    [_NUM] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_ESC  , KC_F7   , KC_F8   , KC_F9   , OS_LCTL ,      OS_LSFT , KC_7    , KC_8    , KC_9    , KC_BSPC ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_TAB  , KC_F4   , KC_F5   , KC_F6   , KC_F10  ,      KC_0    , KC_4    , KC_5    , KC_6    , KC_ENT  ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        CW_TOGG , KC_F1   , KC_F2   , KC_F3   , OS_LGUI ,      OS_LALT , KC_1    , KC_2    , KC_3    , KC_DEL  ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      _______ , _______ ,      _______ , _______
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
    [_EXT] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_BRID , KC_BRIU , KC_VOLD , KC_VOLU , KC_MUTE ,      DM_RSTP , DM_PLY1 , DM_PLY2 , DM_REC1 , DM_REC2 ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        OS_LGUI , OS_LALT , OS_LCTL , OS_LSFT , KC_F12  ,      KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , TD(TBO) ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_MSTP , KC_MPRV , KC_MNXT , KC_MPLY , KC_F11  ,      KC_HOME , KC_PGDN , KC_PGUP , KC_END  , TD(TRE) ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      _______ , _______ ,      _______ , _______
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _SYM, _NUM, _EXT);
}
