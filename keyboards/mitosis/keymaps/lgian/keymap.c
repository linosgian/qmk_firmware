#include QMK_KEYBOARD_H

//Tap Dance Declarations
enum {
  TD_LPRN_RPRN = 0,
  TD_LCBR_RCBR,
  TD_LBRC_RBRC,
  TD_LT_GT,
  TD_PSCR_PSCRW,
};

//Tap Dance Definitions
//Single tap for opening brackets, double tap for closing brackets
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LPRN_RPRN]  = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [TD_LCBR_RCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [TD_LBRC_RBRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [TD_LT_GT]      = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),
  [TD_PSCR_PSCRW] = ACTION_TAP_DANCE_DOUBLE(KC_PSCR, LCTL(KC_PSCR)),
};

//In Layer declaration, add tap dance item in place of a key code
enum mitosis_layers
  {
   _xQ, // qwerty
   _xN, // numbers
   _xF  // functions
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   *  q    w      e      r      t        ||        y     u    i     o     p
   *  a    s      d      f      g        ||        h     j    k     l     ;
   *  z    x      c      v      b        ||        n     m    ,     .     /
   *        `     FΝ2   esc    ctrl      ||        tab    enter     =    '
   *       c+sh  shift  alt    bksp      ||        space  FN1    shift   \
   */
  [_xQ] = LAYOUT(
      KC_Q,    KC_W,            KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,      KC_O,     KC_P,
      KC_A,    KC_S,            KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,      KC_L,     KC_SCLN,
      KC_Z,    KC_X,            KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM,   KC_DOT,   KC_SLSH,
      /*,   */ KC_GRV,          MO(_xF), KC_ESC,  KC_LCTL,     KC_TAB,  KC_ENT,  KC_EQL,   KC_QUOT,
      /*,   */ LCTL(KC_LSFT),   KC_LSFT, KC_LALT, KC_BSPC,     KC_SPC,  MO(_xN), KC_LSFT,   KC_BSLS),
  /*
   *  !     @      up     -     _        ||     +    7     8     9    *
   *  #    left   down  right   $        ||     ?    4     5     6    |
   *  []    ()     {}    <>     &        ||     "    1     2     3    0
   *        `     FΝ2   esc    ctrl      ||     tab    enter     =    '
   *       c+sh  shift  alt    bksp      ||     space  FN1    shift   \
   */
  [_xN] = LAYOUT(
      KC_EXLM,          KC_AT,              KC_UP,              KC_MINS,        KC_UNDS,    KC_PLUS, KC_7,    KC_8,    KC_9,     KC_ASTR,
      KC_HASH,          KC_LEFT,            KC_DOWN,            KC_RIGHT,       KC_DLR,     KC_QUES, KC_4,    KC_5,    KC_6,     KC_PIPE,
      TD(TD_LCBR_RCBR), TD(TD_LPRN_RPRN),   TD(TD_LBRC_RBRC),   TD(TD_LT_GT),   KC_AMPR,    KC_DQUO, KC_1,    KC_2,    KC_3,     KC_0,
      /*,   */ _______, _______, _______, _______,     _______, _______, _______, _______,
      /*,   */ _______, _______, _______, _______,     _______, _______, _______, _______),
  /*
   *  lock pgdown  up   pgup   pscr      ||     vol+    F7    F8    F9    F10
   *  #    left   down  right  lang      ||     vol-    F4    F5    F6    F11
   *  []    ()     {}    <>    nop       ||     mute    F1    F2    F3    F12
   *        `     FΝ2   esc    ctrl      ||     tab    enter     %    ^
   *       c+sh  shift  alt    bksp      ||     space  FN1    shift   ~
   */
  [_xF] = LAYOUT(
      RGUI(KC_L), KC_PGDOWN,   KC_UP,   KC_PGUP,  TD(TD_PSCR_PSCRW),     KC_VOLU, KC_F7,   KC_F8,   KC_F9,    KC_F10,
      KC_HASH, KC_LEFT,     KC_DOWN, KC_RIGHT, RGUI(KC_SPC),      KC_VOLD, KC_F4,   KC_F5,   KC_F6,    KC_F11,
      KC_RBRC, KC_BSLS,     KC_LPRN, KC_RPRN,  _______,     KC_MUTE, KC_F1,   KC_F2,   KC_F3,    KC_F12,
      /*,   */ _______,   _______, _______, _______,     _______, _______, KC_PERC, KC_CIRC,
      /*,   */ _______,   _______, _______, _______,     _______, _______, _______, KC_TILD),
};

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  switch (layer) {
  case _xQ:
    set_led_off;
    break;
  case _xN:
    set_led_magenta;
    break;
  case _xF:
    set_led_yellow;
    break;
  default:
    break;
  }
};
