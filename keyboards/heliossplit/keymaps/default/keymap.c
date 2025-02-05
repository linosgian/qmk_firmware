#include QMK_KEYBOARD_H
// clang-format off
enum layer_number {
    _QWERTY = 0,
    _NUMBER,
    _MOVE,
    _SYMBOL
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 0
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ALT(A)│   S  │CTL(D)│SFT(F)│   G  │   H  │SFT(J)│CTL(K)│   L  │ALT(SEMICOLON│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Caps │LT(2, ESC) │ Bksp │ Mute │Space │    LT(1│ENT)│ LT(3│CW TOGG│
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
[_QWERTY] = LAYOUT(
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,           KC_I,          KC_O,      KC_P,
RALT_T(KC_A),      KC_S,              LCTL_T(KC_D),      KC_F,      KC_G,              KC_H,              KC_J,   LCTL_T(KC_K),  KC_L,      RALT_T(KC_SEMICOLON),
KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,           KC_COMM,       KC_DOT,    KC_SLSH,
                   OSM(MOD_LSFT),           LT(2, KC_ESC),     KC_BSPC,           KC_MUTE,           KC_SPC,            LT(1, KC_ENT),  LT(3, LGUI(KC_SPC))
),
/* 1
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │   (  │   7  │   8  │   9  │  )   │ Null │ Null │ Null │ Null │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   {  │   4  │   5  │   6  │  }   │ Null │  <   │ Null │  >   │ Alt  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   [  │   1  │   2  │   3  │  ]   │ Null │ Null │ Null │   .  │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │  ~   │   0  │      │ Play │ Null │ Null │ Null │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */

[_NUMBER] = LAYOUT(
KC_LPRN,           KC_7,              KC_8,              KC_9,              KC_RPRN,           KC_NO,              KC_NO,         KC_NO,         KC_NO,       KC_NO,
KC_LCBR,           KC_4,              KC_5,              KC_6,              KC_RCBR,           KC_NO,              KC_LABK,       KC_NO,         KC_RABK,     KC_RALT,
KC_LBRC,           KC_1,              KC_2,              KC_3,              KC_RBRC,           KC_NO,              KC_NO,         KC_NO,         KC_DOT,      KC_NO,
                   KC_TILDE,          KC_0,              _______,           KC_MPLY,           KC_NO,              KC_NO,         KC_NO
),

[_MOVE] = LAYOUT(
KC_NO,            KC_PGDN,              KC_UP,              KC_PGUP,       KC_NO,             _______,            LCTL(KC_TAB),       _______, LSFT(LCTL(KC_PGUP)),    _______,
KC_NO,            KC_LEFT,              KC_DOWN,            KC_RIGHT,      KC_NO,             LGUI(KC_SPC),       LSFT(LCTL(KC_TAB)), KC_LCTL, LSFT(LCTL(KC_PGDN)),    _______,
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
[_SYMBOL] = LAYOUT(
KC_EXLM,           KC_AT,             KC_HASH,           KC_DLR,            KC_PERC,           KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,
KC_AMPR,           KC_ASTR,           KC_QUOT,           KC_DQUO,           KC_UNDS,           KC_NO,              KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
KC_GRV,            KC_CIRC,           KC_PLUS,           KC_MINS,           KC_PIPE,           KC_NO,              KC_NO,    KC_NO,    KC_ALGR,  KC_NO,
                   KC_EQL,            KC_BSLS,           _______,           KC_NO,             KC_NO,              KC_NO,              KC_NO
)

};
// clang-format on
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [_NUMBER] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [_MOVE]   =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [_SYMBOL] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
};

void keyboard_post_init_user(void) {
    //debug_enable = true;
    //debug_matrix = true;
    setPinOutput(GP25);
    writePinHigh(GP25);
    //debug_keyboard=true;
    // debug_mouse=true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3,KC_SPC):
            if (record->tap.count && record->event.pressed) {
				register_code(KC_LGUI);
                tap_code(KC_SPC);
				unregister_code(KC_LGUI);
				return false;
			}
			break;
    }
    return true;
}
