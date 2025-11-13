#include "tapdances.h"

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