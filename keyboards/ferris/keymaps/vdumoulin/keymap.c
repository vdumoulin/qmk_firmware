// Vincent Dumoulin's Ferris Sweep keyboard layout.

#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "tapdances.h"

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define LOWER MO(_LOWER)               // Momentarily toggle the _LOWER layer
#define RAISE MO(_RAISE)               // Momentarily toggle the _RAISE layer

enum keycodes {
    OS_LSFT = SAFE_RANGE,
    OS_LCTL,
    OS_LALT,
    OS_LGUI,
};

#define ENT_SFT LSFT_T(KC_ENT)         // Enter on tap, shift on hold
#define SPC_SFT LSFT_T(KC_SPC)         // Space on tap, shift on hold

#define HM_A LGUI_T(KC_A)              // Home row mods
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_J LSFT_T(KC_J)
#define HM_K LCTL_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_QUOT LGUI_T(KC_QUOT)

#define P_SCR G(S(KC_5))               // Print screen on macOS (cmd-shift-5)
#define ITERM C(KC_GRV)                // Toggle iTerm

#define BOOT TD(TAP_DANCE_BOOTLOADER)  // Put keyboard in bootloader mode
#define RESET TD(TAP_DANCE_RESET)      // Reset keyboard

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,      KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        HM_A    , HM_S    , HM_D    , HM_F    , KC_G    ,      KC_H    , HM_J    , HM_K    , HM_L    , HM_QUOT ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,      KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      RAISE   , SPC_SFT ,      OS_LCTL , LOWER
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
    [_LOWER] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,      KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_LBRC , KC_RBRC , KC_MINS , KC_UNDS , KC_EQL  ,      ITERM   , OS_LSFT , OS_LCTL , OS_LALT , OS_LGUI ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_BSLS , KC_PIPE , KC_GRV  , KC_TILD , KC_PLUS ,      XXXXXXX , KC_COLN , KC_SCLN , KC_LCBR , KC_RCBR ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      _______ , _______ ,      XXXXXXX , _______
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
    [_RAISE] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,      KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        OS_LGUI , OS_LALT , OS_LCTL , OS_LSFT , ITERM   ,      KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_ENT  ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_DEL  , KC_BSPC , KC_SPC  , KC_TAB  , XXXXXXX ,      KC_HOME , KC_PGDN , KC_PGUP , KC_END  , KC_ESC  ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      _______ , XXXXXXX ,      _______ , _______
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
    [_ADJUST] = LAYOUT_split_3x5_2(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┐    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,      KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        DM_PLY1 , DM_REC1 , DM_REC2 , DM_PLY2 , DM_RSTP ,      KC_MPRV , KC_BRID , KC_BRIU , KC_MNXT , KC_MPLY ,
    //├─────────┼─────────┼─────────┼─────────┼─────────┤    ├─────────┼─────────┼─────────┼─────────┼─────────┤
        RESET   , P_SCR   , KC_F11  , KC_F12  , XXXXXXX ,      XXXXXXX , KC_VOLD , KC_VOLU , KC_MUTE , BOOT    ,
    //└─────────┴─────────┴─────────┼─────────┼─────────┤    ├─────────┼─────────┴─────────┴─────────┴─────────┘
                                      _______ , XXXXXXX ,      XXXXXXX , _______
    //                              └─────────┴─────────┘    └─────────┴─────────┘
    ),
};

tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_BOOTLOADER] = ACTION_TAP_DANCE_FN(td_fn_boot),
    [TAP_DANCE_RESET] = ACTION_TAP_DANCE_FN(td_fn_reboot),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LOWER:
        case RAISE:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LOWER:
        case RAISE:
        case KC_LSFT:
        case OS_LSFT:
        case OS_LCTL:
        case OS_LALT:
        case OS_LGUI:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_gui_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(&os_shft_state, KC_LSFT, OS_LSFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_LCTL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_LALT, keycode, record);
    update_oneshot(&os_gui_state, KC_LGUI, OS_LGUI, keycode, record);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
