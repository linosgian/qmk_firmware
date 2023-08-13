// Copyright 2022 Conor Burns (@Conor-Burns)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 0
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ALT(A)│   S  │CTL(D)│SFT(F)│   G  │   H  │SFT(J)│CTL(K)│   L  │ALT(SEMICOLON│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │    Caps│LT(2, ESC) │ Bksp │ Mute │Space │    LT(1│ENT)│ LT(3│CW TOGG│
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
[0] = LAYOUT(
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,           KC_I,          KC_O,      KC_P,
RALT_T(KC_A),      KC_S,              LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              RSFT_T(KC_J),   LCTL_T(KC_K),  KC_L,      RALT_T(KC_SEMICOLON),
KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,           KC_COMM,       KC_DOT,    KC_SLSH,
                   CW_TOGG,           LT(2, KC_ESC),     KC_BSPC,           KC_MUTE,           KC_SPC,            LT(1, KC_ENT),  LT(3, CW_TOGG)
),
/* 1
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │   (  │   7  │   8  │   9  │  )   │ Null │ Null │ Null │ Null │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   {  │   4  │   5  │   6  │  }   │ Null │  <   │ Null │  >   │ Alt  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   [  │   1  │   2  │   3  │  ]   │ Null │ Null │ Null │   .  │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │  Alt │   0  │      │ Play │ Null │ Null │ Null │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
[1] = LAYOUT(
KC_LPRN,           KC_7,              KC_8,              KC_9,              KC_RPRN,           KC_NO,              KC_NO,         KC_NO,         KC_NO,       KC_NO,
KC_LCBR,           KC_4,              KC_5,              KC_6,              KC_RCBR,           KC_NO,              KC_LABK,       KC_NO,         KC_RABK,     KC_RALT,
KC_LBRC,           KC_1,              KC_2,              KC_3,              KC_RBRC,           KC_NO,              KC_NO,         KC_NO,         KC_DOT,      KC_NO,
                   KC_RALT,           KC_0,              _______,           KC_MPLY,           KC_NO,              KC_NO,         KC_NO
),

[2] = LAYOUT(
KC_NO,            KC_PGDN,              KC_UP,              KC_PGUP,       KC_NO,             _______,            LCTL(KC_TAB),       LSFT(LCTL(KC_PGUP)), _______,    _______,
KC_NO,            KC_LEFT,              KC_DOWN,            KC_RIGHT,      KC_NO,             LGUI(KC_SPC),       LSFT(LCTL(KC_TAB)), LSFT(LCTL(KC_PGDN)), _______,    _______,
KC_NO,            _______,              _______,            _______,       KC_NO,             KC_NO,              KC_NO,              KC_NO,               KC_NO,     KC_NO,
KC_NO,            _______,              _______,            KC_MPLY,       KC_TAB,            KC_NO,              KC_NO
),

/* 3
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  !   │  @   │  #   │  $   │  %   │ Null │ Null │ Null │ Null │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  &   │  *   │   '  │  "   │  _   │ Null │ Shft │ Ctrl │ Alt  │ Gui  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   `  │  ^   │   +  │  -   │  |   │ Null │ Null │ Null │ Alt  │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   =  │  \   │  Null│ Null │      │ Null │ Null │ Null │ Null │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
[3] = LAYOUT(
KC_EXLM,           KC_AT,             KC_HASH,           KC_DLR,            KC_PERC,           KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,
KC_AMPR,           KC_ASTR,           KC_QUOT,           KC_DQUO,           KC_UNDS,           KC_NO,              KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
KC_GRV,            KC_CIRC,           KC_PLUS,           KC_MINS,           KC_PIPE,           KC_NO,              KC_NO,    KC_NO,    KC_ALGR,  KC_NO,
                   KC_EQL,            KC_BSLS,           _______,           KC_NO,             KC_NO,              KC_NO,              KC_NO
)

};
// clang-format on
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [1] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [2] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [3] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
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
