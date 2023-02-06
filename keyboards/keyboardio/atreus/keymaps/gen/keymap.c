// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include <twpair_on_jis.h>

enum layer_names {
    _QW,
    _RS,
    _LW,
};

#define ALT LALT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,   KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_INT5, KC_INT4, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_LGUI, KC_LCTL,KC_RSFT, MO(_LW), KC_SPC,  KC_CAPS, XXXXXXX, KC_ENT,  MO(_RS), KC_BSPC, ALT,     KC_DEL
  ),

  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    _______, _______, _______, KC_HOME, KC_END,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    KC_GRV,  KC_BSLS, KC_EQL,  KC_QUOT, KC_MINUS, _______, _______, KC_LBRC, KC_RBRC, KC_PGDN, KC_PGUP, _______,
    _______, _______, _______, _______, KC_TAB,   _______, _______, _______, _______, _______, _______, _______
  ),

  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_DEL,  _______,  _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      if (!twpair_on_jis(keycode, record)) {
          return false;
      } else {
          return true;
      }
  }
}
