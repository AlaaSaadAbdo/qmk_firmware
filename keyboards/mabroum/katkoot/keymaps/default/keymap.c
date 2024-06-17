// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keyboards/mabroum/keys.h"
#include "keyboards/mabroum/mab_pointing.h"


#define SNIPING SNIPING_MODE
#define SNP_TOG SNIPING_MODE_TOGGLE
#define DRGSCRL DRAGSCROLL_MODE
#define DRG_TOG DRAGSCROLL_MODE_TOGGLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_2x3(
        KC_BTN3,   KC_BTN1,   SNP_TOG,
        DRG_TOG,   KC_BTN2,   KC_MUTE
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mab_process_pointing_keys(keycode, record);
    return true;
}

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0]  =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};

/* void keyboard_post_init_user(void) { */
/*   // Customise these values to desired behaviour */
/*   debug_enable=true; */
/*   debug_matrix=true; */
/*   debug_keyboard=true; */
/*   debug_mouse=true; */
/* } */

