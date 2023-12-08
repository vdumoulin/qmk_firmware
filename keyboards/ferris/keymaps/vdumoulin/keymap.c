// Vincent Dumoulin's Ferris Sweep keyboard layout.
#include QMK_KEYBOARD_H
#define FORCE_NKRO

enum layers {
  _BASE,
  _NAV,
  _MOUSE,
  _MEDIA,
  _NUM,
  _SYM,
  _FUN,
};

/* Home row mods */
#define KC_GUIA LGUI_T(KC_A)
#define KC_ALTS LALT_T(KC_S)
#define KC_CTLD LCTL_T(KC_D)
#define KC_SFTF LSFT_T(KC_F)
#define KC_SFTJ LSFT_T(KC_J)
#define KC_CTLK LCTL_T(KC_K)
#define KC_ALTL LALT_T(KC_L)
#define KC_GUOT LGUI_T(KC_QUOT)
#define KC_ALTX RALT_T(KC_X)
#define KC_ADOT RALT_T(KC_DOT)

/* Copy, paste, etc. */
#define KC_MCPY LGUI(KC_C)
#define KC_MPST LGUI(KC_V)
#define KC_MCUT LGUI(KC_X)
#define KC_MUND LGUI(KC_Z)
#define KC_MRDO LGUI(LSFT(KC_Z))

/* Layer toggling */
#define KC_SPCT LT(_NAV, KC_SPC)
#define KC_TABT LT(_MOUSE, KC_TAB)
#define KC_BSPT LT(_NUM, KC_BSPC)
#define KC_ENTT LT(_SYM, KC_ENT)

/* Combos */
enum combos {
  SPACE_TAB_MEDIA,
  ENTER_BACKSPACE_FUN,
};

const uint16_t PROGMEM space_tab_combo[] = {KC_SPCT, KC_TABT, COMBO_END};
const uint16_t PROGMEM enter_backspace_combo[] = {KC_BSPT, KC_ENTT, COMBO_END};

combo_t key_combos[] = {
  [SPACE_TAB_MEDIA] = COMBO(space_tab_combo, LT(_MEDIA, KC_ESC)),
  [ENTER_BACKSPACE_FUN] = COMBO(enter_backspace_combo, LT(_FUN, KC_DEL)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_GUIA, KC_ALTS, KC_CTLD, KC_SFTF, KC_G,        KC_H,    KC_SFTJ, KC_CTLK, KC_ALTL, KC_GUOT,
        KC_Z,    KC_ALTX, KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_ADOT, KC_SLSH,
                                   KC_SPCT, KC_TABT,     KC_ENTT, KC_BSPT
    ),
	[_NAV] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_MRDO, KC_MPST, KC_MCPY, KC_MCUT, KC_MUND,
        KC_GUIA, KC_ALTS, KC_CTLD, KC_SFTF, XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG,
        XXXXXXX, KC_ALTX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   _______, XXXXXXX,     XXXXXXX, XXXXXXX
    ),
	[_MOUSE] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_MRDO, KC_MPST, KC_MCPY, KC_MCUT, KC_MUND,
        KC_GUIA, KC_ALTS, KC_CTLD, KC_SFTF, XXXXXXX,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
        XXXXXXX, KC_ALTX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
                                   XXXXXXX, _______,     KC_BTN2, KC_BTN1
	),
	[_MEDIA] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_BRIU, KC_BRID, XXXXXXX, XXXXXXX,
        KC_GUIA, KC_ALTS, KC_CTLD, KC_SFTF, XXXXXXX,     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
        XXXXXXX, KC_ALTX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______,     KC_MSTP, KC_MPLY
	),
	[_NUM] = LAYOUT_split_3x5_2(
        KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,      XXXXXXX, KC_SFTJ, KC_CTLK, KC_ALTL, KC_GUOT,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,     XXXXXXX, XXXXXXX, XXXXXXX, KC_ADOT, XXXXXXX,
                                   KC_0,    KC_MINS,     XXXXXXX, _______
	),
	[_SYM] = LAYOUT_split_3x5_2(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,     XXXXXXX, KC_SFTJ, KC_CTLK, KC_ALTL, KC_GUOT,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,     XXXXXXX, XXXXXXX, XXXXXXX, KC_ADOT, XXXXXXX,
                                   KC_RPRN, KC_UNDS,     _______, XXXXXXX
	),
	[_FUN] = LAYOUT_split_3x5_2(
        KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX,     XXXXXXX, KC_SFTJ, KC_CTLK, KC_ALTL, KC_GUOT,
        KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, KC_ADOT, XXXXXXX,
                                   XXXXXXX, XXXXXXX,     _______, _______
	),
};
