#include QMK_KEYBOARD_H
// 薙刀式
#include "naginata.h"
NGKEYS naginata_keys;

enum planck_layers {
  _ASTARTE,
  _NAGINATA,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum planck_keycodes {
  ASTARTE = NG_SAFE_RANGE,
  LOWER,
  RAISE,
  CONTROL,
  ADJUST,
  TPBM,
  RTLF,
  V_W,
  V_WQ,
  V_Q,
};

#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PSTE LGUI(KC_V)
#define GENT LGUI(KC_ENT)
// ctl+[ (esc)
#define AESC RCS(KC_LBRC)
#define V_SV LSFT(KC_V)
#define V_CV LCTL(KC_V)
#define V_CD LCTL(KC_D)
#define V_CU LCTL(KC_U)
// Mission Control
#define MC LCTL(KC_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Astarte
   * ,-----------------------------------------------------------------------------------.
   * |   Q  |   P  |   U  |   Y  |   ,  |      |      |   J  |   D  |   H  |   G  |   W  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   I  |   O  |   E  |   A  |   .  |      |      |   K  |   T  |   N  |   S  |   R  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   Z  |   X  |   '  |   C  |   ;  |      |      |   M  |   L  |   F  |   B  |   V  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | GUI  | ALT  | Ctrl |Lower |Space |      |      | ENT  | Raise| BCSP |  SFT |  DEL |
   * `-----------------------------------------------------------------------------------'
   */
  [_ASTARTE] = LAYOUT_ortho_4x12(
      KC_Q,    KC_P,    KC_U,    KC_Y,  KC_COMM, KC_TAB,  KC_ESC,  KC_J,   KC_D,  KC_H,    KC_G,    KC_W,
      KC_I,    KC_O,    KC_E,    KC_A,  KC_DOT,  KC_LGUI, KC_ENT,  KC_K,   KC_T,  KC_N,    KC_S,    KC_R,
      KC_Z,    KC_X,    KC_QUOT, KC_C,  KC_SCLN, KC_LALT, KC_RSFT, KC_M,   KC_L,  KC_F,    KC_B,    KC_V,
      KC_LGUI, KC_LALT, CONTROL, LOWER, KC_SPC,  KC_SPC,  KC_ENT,  KC_ENT, RAISE, KC_BSPC, KC_LSFT, KC_DEL
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |      | PSTE | UNDO | COPY |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | COPY |  ;q  |  ;w  |  ZZ  |      |      | C V  |   V  |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  ENT |      | DEL  |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_4x12(
      _______, PSTE,    UNDO,    COPY,    _______,  _______, _______, _______, _______, _______, _______,  _______,
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     _______, _______, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
      _______, COPY,    V_Q,     V_W,     V_WQ,     _______, _______, V_CV,    V_SV,    _______, _______,  _______,
      _______, _______, _______, _______, _______,  _______, GENT,    GENT,    _______, KC_DEL,  _______,  _______
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  | TPBM | RTLF |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   \  |   `  |   =  |   /  |   -  |      |      |   ←  |   ↓  |   ↑  |   →  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |   _  |   (  |   [  |      |      |   ]  |  )   | C d  | C u  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | TAB  |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12(
      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, TPBM,    RTLF,
      KC_BSLS, KC_GRV,  KC_EQL,  KC_SLSH, KC_MINUS, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      _______, _______, KC_UNDS, KC_LPRN, KC_LBRC,  _______, _______, KC_RBRC, KC_RPRN, V_CD,    V_CU,    _______,
      _______, _______, AESC,    _______, KC_TAB,   KC_TAB,  _______, _______, _______, _______, _______, _______
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |       |      |      |      |      |      |      |      |      |      |      |      |
   * |-------+------+------+------+------+------+------+------+------+------+------+------|
   * |       |      |CLICK2|CLICK |      |      |      |   ←  |  ↓   |  ↑   |   →  |      |
   * |-------+------+------+------+------+------+------+------+------+------+------+------|
   * |       |      |      |      |      |      |      |      |      |      |      |      |
   * |-------+------+------+------+------+------+------+------+------+------+------+------|
   * |       |      |      |      |      |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_ortho_4x12(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
      _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
      KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______, _______, _______, MC,      _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NAGINATA] = LAYOUT_ortho_4x12(
      NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,    _______, _______,  NG_Y,     NG_U,    NG_I,    NG_O,    NG_P,
      NG_A,    NG_S,    NG_D,    NG_F,    NG_G,    _______, _______,  NG_H,     NG_J,    NG_K,    NG_L,    NG_SCLN,
      NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,    _______, _______,  NG_N,     NG_M,    NG_COMM, NG_DOT , NG_SLSH,
      _______, _______, _______, _______, NG_SHFT, NG_SHFT, NG_SHFT2, NG_SHFT2, _______, _______, _______, _______
  )

};

void matrix_init_user(void) {
  // 薙刀式
  uint16_t ngonkeys[] = {};
  uint16_t ngoffkeys[] = {};
  set_naginata(_NAGINATA, ngonkeys, ngoffkeys);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

static bool lower_pressed = false;
static bool raise_pressed = false;
static bool control_pressed = false;
static uint16_t pressed_time = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ASTARTE:
      if (record->event.pressed) {
        default_layer_set(_ASTARTE);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        pressed_time = record->event.time;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        // AUTO_SHIFTはTAPPING_TERMの二倍の時間待つ
        if (lower_pressed && (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM * 2)) { 
          naginata_off();
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        pressed_time = record->event.time;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (raise_pressed && (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM * 2)) { 
          naginata_on();
        }
        raise_pressed = false;
      }
      return false;
      break;
    case CONTROL:
      if (record->event.pressed) {
        control_pressed = true;
        pressed_time = record->event.time;
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
        if (control_pressed && (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM * 2)) { 
          // 日本語にしてからeisuにする
          naginata_off();
          tap_code16(KC_ESC);
        }
        control_pressed = false;
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
    case RTLF:
        if (record->event.pressed) {
            pressed_time = record->event.time;
        } else {
            if (TIMER_DIFF_16(record->event.time,pressed_time) > AUTO_SHIFT_TIMEOUT) {
                tap_code16(C(KC_A));
            } else {
                tap_code16(C(KC_E));
            }
        }
        return false;
        break;
    case TPBM:
        if (record->event.pressed) {
            pressed_time = record->event.time;
        } else {
            if (TIMER_DIFF_16(record->event.time,pressed_time) > AUTO_SHIFT_TIMEOUT) {
                tap_code16(G(KC_DOWN));
            } else {
                tap_code16(G(KC_UP));
            }
        }
        return false;
        break;
    case V_W:
        if (record->event.pressed) {
          SEND_STRING(";w\n");
        }
        return false;
        break;
    case V_WQ:
        if (record->event.pressed) {
          SEND_STRING("ZZ\n");
        }
        return false;
        break;
    case V_Q:
        if (record->event.pressed) {
          SEND_STRING(";q\n");
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
      break;
  }

  return true;
}
