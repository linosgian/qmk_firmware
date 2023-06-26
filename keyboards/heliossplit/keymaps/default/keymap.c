// Copyright 2022 Conor Burns (@Conor-Burns)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,     KC_Y,      KC_U,      KC_I,      KC_O,      KC_P, 
    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,     KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN, 
    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,     KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH, 
               KC_LALT,   KC_LGUI,   KC_SPC,    KC_MUTE,  KC_ENT,    KC_BSPC,   KC_RGUI
)
};
// clang-format on
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    //[_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    //[_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    //[_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
    setPinOutput(GP25);
    writePinHigh(GP25);
    debug_keyboard=true;
    // debug_mouse=true;
}
