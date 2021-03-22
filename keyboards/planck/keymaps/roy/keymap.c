#include QMK_KEYBOARD_H
// 薙刀式
#include "naginata.h"
NGKEYS naginata_keys;
// 薙刀式

enum planck_layers {
  _DVORAK,
  _NAGINATA,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum planck_keycodes {
  DVORAK = NG_SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  CONTROL
};

// save cmd + s
#define KC_SAVE LCTL(KC_S)
#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PSTE LCTL(KC_V)
// cmd + enter
#define KC_CENT LCTL(KC_ENT)
// cmd + h
#define KC_CH LCTL(KC_H)
// cmd + q
#define KC_CQ LCTL(KC_Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   '  |   ,  |   .  |   P  |   Y  |      |      |   F  |   G  |   C  |   R  |   L  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   O  |   E  |   U  |   I  |      |      |   D  |   H  |   T  |   N  |   S  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ;  |   Q  |   J  |   K  |   X  |      |      |   B  |   M  |   W  |   V  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  | Alt  | Ctrl |Lower |Space |      |      | ENT  | Raise| BCSP |  SFT |  DEL |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_QUOT, KC_COMM, KC_DOT,   KC_P,    KC_Y,   KC_TAB,  KC_DEL,   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
    KC_A,    KC_O,    KC_E,     KC_U,    KC_I,   KC_LGUI, KC_CENT,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
    KC_SCLN, KC_Q,    KC_J,     KC_K,    KC_X,   KC_LALT, KC_RSFT,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
    KC_LGUI, KC_LALT, CONTROL,  LOWER,   KC_SPC, KC_SPC,  KC_ENT,   KC_ENT,  RAISE,   KC_BSPC, KC_RSFT, KC_DEL
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   '  |   ,  |   .  |   /  |   -  |      |      |  cmd |cmd+h |cmd+q |   *  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  ENT |      | DEL  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, _______, _______, KC_SLSH, KC_MINUS,_______, _______, KC_RGUI, KC_RALT,  KC_TAB,  KC_ASTR, KC_PLUS,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,     KC_8,    KC_9,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, _______, _______,  KC_ENT, KC_ENT,  _______,  KC_BSPC, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  |   *  |  )   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   \  |   =  |   /  |   -  |      |      |  ←  |  ↓  |  ↑  |  →  |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   [  |      |      |   ]  | CMD  | CMD  | CMD  | CMD  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | TAB  |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_GRV,  KC_BSLS, KC_EQL,  KC_SLSH, KC_MINUS, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS,
    UNDO,    CUT,     COPY,    KC_LPRN, KC_LBRC,  _______, _______, KC_RBRC, KC_RPRN, KC_RALT, KC_RGUI, KC_RGUI,
    _______, _______, _______, _______, KC_TAB,   KC_TAB,  _______, _______, _______, _______, _______, _______ 
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |       |      |      |      |      |      |      |      |      |      |      |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |CLICK2|CLICK |      |      |      |  ←  |  ↓  |  ↑  |  →  |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |      |      |      |      |      |      |      |      |      |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    UNDO,    CUT,     COPY,    PSTE,    _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* NAGINATA
 * ,-----------------------------------------------------------------------------------.
 * |       |      |      |      |      |      |      |      |      |      |      |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |CLICK2|CLICK |      |      |      |  ←  |  ↓  |  ↑  |  →  |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |      |      |      |      |      |      |      |      |      |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAGINATA] = LAYOUT_planck_grid(
    NG_Q   , NG_W   , NG_E   , NG_R   , NG_T   , _______, _______, NG_Y   , NG_U   , NG_I   , NG_O   , NG_P   ,
    NG_A   , NG_S   , NG_D   , NG_F   , NG_G   , _______, _______, NG_H   , NG_J   , NG_K   , NG_L   , NG_SCLN,
    NG_Z   , NG_X   , NG_C   , NG_V   , NG_B   , _______, _______, NG_N   , NG_M   , NG_COMM, NG_DOT , NG_SLSH,
    _______, _______, _______, _______, NG_SHFT, NG_SHFT, NG_SHFT, NG_SHFT, _______, _______, _______, _______
)

};

void matrix_init_user(void) {
  // 薙刀式
  uint16_t ngonkeys[] = {};
  uint16_t ngoffkeys[] = {};
  set_naginata(_NAGINATA, ngonkeys, ngoffkeys);
  // 薙刀式
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;
static bool control_pressed = false;
static uint16_t control_pressed_time = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        default_layer_set(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        // AUTO_SHIFTはTAPPING_TERMの二倍の時間待つ
        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM * 2)) { 
          register_code(KC_LANG1);
          tap_code16(S(C(KC_SPC)));
          naginata_off();
          // AUTO_SHIFT_TIMEOUTより大きければシフトを入れる
          // example 処理は変わらない
          // if (TIMER_DIFF_16(record->event.time,lower_pressed_time) > AUTO_SHIFT_TIMEOUT) {
          //   register_code(KC_ESC);
          //   unregister_code(KC_ESC);
          // } else {
          //   register_code(KC_ESC);
          //   unregister_code(KC_ESC);
          // }
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM * 2)) { 
          register_code(KC_LANG2);
          tap_code16(C(KC_SPC));
          naginata_on();
        }
        raise_pressed = false;
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case CONTROL:
      if (record->event.pressed) {
        control_pressed = true;
        control_pressed_time = record->event.time;
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
        if (control_pressed && (TIMER_DIFF_16(record->event.time, control_pressed_time) < TAPPING_TERM * 2)) { 
          tap_code16(KC_ESC);
          tap_code16(S(C(KC_SPC)));
          naginata_off();
        }
        control_pressed = false;
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        // reset the flag
        lower_pressed = false;
        raise_pressed = false;
        control_pressed = false;
      }
      // 薙刀式
      if (!process_naginata(keycode, record)) {
        return false;
      }
      // 薙刀式
      break;
  }

  return true;
}
