 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H


extern uint8_t is_master;

enum custom_keycodes {
    SPC_LGUI = SAFE_RANGE  // Custom keycode
};
enum layers {
    _QWERTY = 0,
    _NUMBER,
    _MOVE,
    _SYMBOL
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | RALT/|   S  |LCTL/ |   F  |   G  |-------.    ,-------|   H  |   J  |LCTL/ |   L  |RALT/ |      |
 * |      |   A  |      |   D  |      |      |       |    |       |      |      |   K  |      |   ;  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | OSM  |LT(2/ / Bspc /       \ Spc  \  |LT(1/ |SPC/  |      |
 *                   |      | LSFT | ESC) |       /         \      \ | ENT) | LGUI |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_QWERTY] = LAYOUT(
  XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,
  XXXXXXX, KC_Q,            KC_W,    KC_E,         KC_R,    KC_T,                      KC_Y,    KC_U,         KC_I,    KC_O,    KC_P,              XXXXXXX,
  XXXXXXX, RALT_T(KC_A),    KC_S,    LCTL_T(KC_D), KC_F,    KC_G,                      KC_H,    KC_J,         LCTL_T(KC_K), KC_L, RALT_T(KC_SCLN), XXXXXXX,
  XXXXXXX, KC_Z,            KC_X,    KC_C,         KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,         KC_COMM, KC_DOT,  KC_SLSH,           XXXXXXX,
                             XXXXXXX, OSM(MOD_LSFT), LT(2,KC_ESC), KC_BSPC, KC_SPC,  LT(1,KC_ENT), SPC_LGUI, XXXXXXX
),

/*  NUMBER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   (  |   7  |   8  |   9  |   )  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   {  |   4  |   5  |   6  |   }  |-------.    ,-------|      |   <  |      |   >  | RALT |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   [  |   1  |   2  |   3  |   ]  |-------|    |-------|      |      |      |   .  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |   ~  |   0  / _____ /       \ Mply \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMBER] = LAYOUT(
  XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,      XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LPRN,   KC_7,     KC_8,         KC_9,    KC_RPRN,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LCBR,   KC_4,     KC_5,         KC_6,    KC_RCBR,                   XXXXXXX, KC_LABK, _______, KC_RABK, KC_RALT, XXXXXXX,
  XXXXXXX, KC_LBRC,   KC_1,     KC_2,         KC_3,    KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,  XXXXXXX, XXXXXXX,
                       XXXXXXX, KC_TILDE,      KC_0,    _______, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX
),

/* MOVE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | PgDn |  Up  | PgUp |      |                    |      |C-Tab |      |CS-PgU|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Left | Down | Rght |      |-------.    ,-------|G-Spc |CS-Tab| LCTL |CS-PgD|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      / _____ /       \ Tab  \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_MOVE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                   XXXXXXX,      XXXXXXX,            XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_PGDN,  KC_UP,    KC_PGUP,  XXXXXXX,                   XXXXXXX,      LCTL(KC_TAB),       XXXXXXX, LSFT(LCTL(KC_PGUP)), XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_LEFT,  KC_DOWN,  KC_RIGHT, XXXXXXX,                   LGUI(KC_SPC), LSFT(LCTL(KC_TAB)), KC_LCTL, LSFT(LCTL(KC_PGDN)), XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, _______,  _______,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,            XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX,
                    XXXXXXX,  XXXXXXX,  _______,  _______, KC_MPLY, KC_TAB,  XXXXXXX,      XXXXXXX
),

/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   &  |   *  |   '  |   "  |   _  |-------.    ,-------|      | LSFT | LCTL | LALT | LGUI |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   `  |   ^  |   +  |   -  |   |  |-------|    |-------|      |      |      | ALGR |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |   =  |   \  / _____ /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMBOL] = LAYOUT(
  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_AMPR,  KC_ASTR,  KC_QUOT,  KC_DQUO,  KC_UNDS,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  XXXXXXX, KC_GRV,   KC_CIRC,  KC_PLUS,  KC_MINS,  KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX,
                     XXXXXXX,  KC_EQL,   KC_BSLS,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
};

// Rotary encoder related code
/* #ifdef ENCODER_ENABLE */
/* bool encoder_update_user(uint8_t index, bool clockwise) { */
/*   if (index == 0) { // Encoder on master side */
/*     if(IS_LAYER_ON(_RAISE)) { // on Raise layer */
/*       // Cursor control */
/*       if (clockwise) { */
/*           tap_code(KC_MNXT); */
/*       } else { */
/*           tap_code(KC_MPRV); */
/*       } */
/*     } */
/*     else { */
/*       if (clockwise) { */
/*           tap_code(KC_VOLU); */
/*       } else { */
/*           tap_code(KC_VOLD); */
/*       } */
/*     } */
/*   } */
/*   else if (index == 1) { // Encoder on slave side */
/*     if(IS_LAYER_ON(_LOWER)) { // on Lower layer */
/*       // */
/*       if (clockwise) { */
/*           tap_code(KC_RIGHT); */
/*       } else { */
/*           tap_code(KC_LEFT); */
/*       } */
/*     } */
/*     else { */
/*       if (clockwise) { */
/*           tap_code(KC_DOWN); */
/*       } else { */
/*           tap_code(KC_UP); */
/*       } */
/*     } */
/*   } */
/*     return true; */
/* } */
/* #endif */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t spc_timer = 0;

    switch (keycode) {
        case SPC_LGUI:
            if (record->event.pressed) {
                spc_timer = timer_read();  // Start timer when key is pressed
                layer_on(3);  // Activate Layer 3 immediately on hold
            } else {
                if (timer_elapsed(spc_timer) < TAPPING_TERM-70) {
                    // If released quickly → TAP (LGUI + SPC)
                    register_code(KC_LGUI);
                    tap_code(KC_SPC);
                    unregister_code(KC_LGUI);
                    layer_off(3);  // Ensure the layer turns off
                } else {
                    // If held → Keep Layer 3 active, turn off on release
                    layer_off(3);
                }
            }
            return false; // Prevent default behavior

        default:
            return true;
    }
}
