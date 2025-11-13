#pragma once

#include QMK_KEYBOARD_H

enum tap_dance {
    TAP_DANCE_BOOTLOADER = 0,
    TAP_DANCE_RESET
};

// Tap dance to put the keyboard in bootloader mode.
void td_fn_boot(tap_dance_state_t *state, void *user_data);

// Tap dance to reset the keyboard.
void td_fn_reboot(tap_dance_state_t *state, void *user_data);