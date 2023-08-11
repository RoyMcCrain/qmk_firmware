#include QMK_KEYBOARD_H
#include "os_detection.h"
// 薙刀式
#include "naginata.h"
NGKEYS naginata_keys;

enum planck_layers {
    _ASTARTE,
    _NAGINATA,
    _LOWER,
    _LOWER_MAC,
    _RAISE,
    _ADJUST
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
  V_Q
};

#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PSTE LCTL(KC_V)
#define GENT LCTL(KC_ENT)
#define SLP  LGUI(KC_L)

#define MUNDO LGUI(KC_Z)
#define MCUT LGUI(KC_X)
#define MCOPY LGUI(KC_C)
#define MPSTE LGUI(KC_V)
#define MGENT LGUI(KC_ENT)
// ctl+[ (esc)
#define AESC RCS(KC_LBRC)
#define V_SV LSFT(KC_V)
#define V_CJ LCTL(KC_J)
// Mission Control
#define MC LGUI(KC_TAB)
#define N_LEFT LSFT(KC_LEFT)
#define N_RGHT LSFT(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Astarte
   * ,-----------------------------------------------------------------------------------.
   * |   Q |   P  |   U  |   Y  |   ,  |      |      |   J  |   D  |   H  |   G  |   W  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   I  |   O  |   E  |   A  |   .  |      |      |   K  |   T  |   N  |   S  |   R  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   Z  |   X  |   '  |   C  |   ;  |      |      |   M  |   L  |   F  |   B  |   V  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | GUI  | SFT  | Ctrl |Lower |Space |      |      | ENT  | Raise| BCSP |  ALT |  DEL |
   * `-----------------------------------------------------------------------------------'
   */
  [_ASTARTE] = LAYOUT_planck_grid(
      KC_Q,    KC_P,    KC_U,    KC_Y,  KC_COMM, KC_TAB,  KC_ESC,  KC_J,   KC_D,  KC_H,    KC_G,    KC_W,
      KC_I,    KC_O,    KC_E,    KC_A,  KC_DOT,  KC_LGUI, KC_ENT,  KC_K,   KC_T,  KC_N,    KC_S,    KC_R,
      KC_Z,    KC_X,    KC_QUOT, KC_C,  KC_SCLN, KC_LALT, KC_RSFT, KC_M,   KC_L,  KC_F,    KC_B,    KC_V,
      KC_LGUI, KC_LSFT, CONTROL, LOWER, KC_SPC,  KC_SPC,  KC_ENT,  KC_ENT, RAISE, KC_BSPC, KC_LALT, KC_PSCR
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |      | PSTE | UNDO | COPY |      |      |      |  F6  |  F7  |  F8  |  F9  | F10  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |  ;q  |  ;w  |  ZZ  |      |      | C j  |  S v |  S ← |  S → |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |G ENT |      | DEL  |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_grid(
      _______, PSTE,    UNDO,    COPY,    _______,  _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     _______, _______, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
      _______, _______, V_Q,     V_W,     V_WQ,     _______, _______, V_CJ,    V_SV,    N_LEFT,  N_RGHT,   _______,
      _______, _______, _______, _______, _______,  _______, GENT,    GENT,    _______, KC_DEL,  _______,  _______
  ),

  [_LOWER_MAC] = LAYOUT_planck_grid(
      _______, MPSTE,   MUNDO,   MCOPY,   _______,  _______, _______, LCTL(KC_J), LCTL(KC_K), LCTL(KC_SCLN),   LCTL(KC_L),  KC_F10,
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     _______, _______, KC_6,       KC_7,       KC_8,    KC_9,     KC_0,
      _______, _______, V_Q,     V_W,     V_WQ,     _______, _______, V_CJ,       V_SV,       N_LEFT,  N_RGHT,   _______,
      _______, _______, _______, _______, _______,  _______, MGENT,   MGENT,      _______,    KC_DEL,  _______,  _______
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  | RALT |  MC  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   \  |   `  |   =  |   /  |   -  |      |      |   ←  |   ↓  |   ↑  |   →  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |   _  |   (  |   [  |      |      |   ]  |  )   | RTLF | TPBM |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | TAB  |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_planck_grid(
      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_RALT, MC,
      KC_BSLS, KC_GRV,  KC_EQL,  KC_SLSH, KC_MINUS, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      _______, _______, KC_UNDS, KC_LPRN, KC_LBRC,  _______, _______, KC_RBRC, KC_RPRN, RTLF,    TPBM,    _______,
      _______, AESC,    _______, _______, KC_TAB,   KC_TAB,  _______, _______, _______, _______, _______, _______
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |       |      |      |      |      |      |      |      |      |      |      |      |
   * |-------+------+------+------+------+------+------+------+------+------+------+------|
   * |       |      |CLICK2|CLICK |      |      |      |   ←  |   ↓  |   ↑  |   →  |      |
   * |-------+------+------+------+------+------+------+------+------+------+------+------|
   * |       |      |      |      |      |      |      |      |      |      |      |      |
   * |-------+------+------+------+------+------+------+------+------+------+------+------|
   * |       |      |      |      |      |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_planck_grid(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   RESET,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
      _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
      KC_F11,  KC_F12,  KC_F13,  KC_F14,  SLP,     _______, _______, _______, MC,      _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NAGINATA] = LAYOUT_planck_grid(
      NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,    _______, _______,  NG_Y,     NG_U,    NG_I,    NG_O,    NG_P,
      NG_A,    NG_S,    NG_D,    NG_F,    NG_G,    _______, _______,  NG_H,     NG_J,    NG_K,    NG_L,    NG_SCLN,
      NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,    _______, _______,  NG_N,     NG_M,    NG_COMM, NG_DOT,  NG_SLSH,
      _______, _______, _______, _______, NG_SHFT, NG_SHFT, NG_SHFT2, NG_SHFT2, _______, _______, _______, _______
  )

};

void matrix_init_user(void) {
    uint16_t ngonkeys[] = {};
    uint16_t ngoffkeys[] = {};
    set_naginata(_NAGINATA, ngonkeys, ngoffkeys);
}

uint32_t last_keypress = 0;
void matrix_scan_user(void) {
  // 2.5秒間キーが押されていなかったら薙刀式を解除する
  if (timer_elapsed32(last_keypress) > 2500) {
    if (naginata_state()) {
        naginata_off();
    }
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

static uint16_t host_os;
void keyboard_post_init_user(void) {
  wait_ms(400);
  host_os = detected_host_os();
}

static bool lower_pressed = false;
static bool raise_pressed = false;
static bool control_pressed = false;
static uint16_t pressed_time = 0;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // キー操作を監視する
        last_keypress = timer_read32();
    }
    switch (keycode) {
        case ASTARTE:
            if (record->event.pressed) {
                default_layer_set(_ASTARTE);
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                lower_pressed = true;
                pressed_time = record->event.time;
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    layer_on(_LOWER_MAC);
                    update_tri_layer(_LOWER_MAC, _RAISE, _ADJUST);
                } else {
                    layer_on(_LOWER);
                    update_tri_layer(_LOWER, _RAISE, _ADJUST);
                }
            } else {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    layer_off(_LOWER_MAC);
                    update_tri_layer(_LOWER_MAC, _RAISE, _ADJUST);
                } else {
                    layer_off(_LOWER);
                    update_tri_layer(_LOWER, _RAISE, _ADJUST);
                }
                // AUTO_SHIFTはTAPPING_TERMの2倍の時間待つ
                if (lower_pressed && (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM * 2)) {
                    naginata_off();
                }
                lower_pressed = false;
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                raise_pressed = true;
                pressed_time = record->event.time;
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                if (raise_pressed && (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM * 1.2)) {
                    naginata_on();
                }
                raise_pressed = false;
            }
            return false;
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
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case RTLF:
            if (record->event.pressed) {
                pressed_time = record->event.time;
            } else {
                if (TIMER_DIFF_16(record->event.time,pressed_time) > AUTO_SHIFT_TIMEOUT) {
                    tap_code16(KC_HOME);
                } else {
                    tap_code16(KC_END);
                }
            }
            return false;
        case TPBM:
            if (record->event.pressed) {
                pressed_time = record->event.time;
            } else {
                if (TIMER_DIFF_16(record->event.time,pressed_time) > AUTO_SHIFT_TIMEOUT) {
                    tap_code16(C(KC_HOME));
                } else {
                    tap_code16(C(KC_END));
                }
            }
            return false;
        case V_W:
            if (record->event.pressed) {
              SEND_STRING(";w\n");
            }
            return false;
        case V_WQ:
            if (record->event.pressed) {
              SEND_STRING("ZZ\n");
            }
            return false;
        case V_Q:
            if (record->event.pressed) {
              SEND_STRING(";q\n");
            }
            return false;
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
