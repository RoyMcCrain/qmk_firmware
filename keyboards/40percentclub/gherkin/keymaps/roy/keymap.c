#include QMK_KEYBOARD_H

#define _DVORAK 0
#define _LOWER 1
#define _DLOWER 2
#define _SLOWER 3
#define _RAISE 4
#define _DRAISE 5
#define _SRAISE 6

#define CTL_SPC     C(KC_SPC)
// save cmd + s
#define KC_SAVE LGUI(KC_S)
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PSTE LGUI(KC_V)
// cmd + enter
#define KC_CENT LGUI(KC_ENT)
// cmd + h
#define KC_CH LGUI(KC_H)
// cmd + q
#define KC_CQ LGUI(KC_Q)

enum gherkin_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER_K,
  DLOWER_X,
  SLOWER_J,
  RAISE_M,
  DRAISE_B,
  SRAISE_W
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_ortho_3x10(
    KC_QUOT, KC_COMM, KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,    KC_C,     KC_R,   KC_L,
    KC_A,    KC_O,    KC_E,     KC_U,     KC_I,     KC_D,     KC_H,    KC_T,     KC_N,   KC_S,
    KC_SCLN, KC_Q,    SLOWER_J, LOWER_K,  DLOWER_X, DRAISE_B, RAISE_M, SRAISE_W, KC_V,   KC_Z
  ),

  [_LOWER] = LAYOUT_ortho_3x10(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, _______, LOWER_K, _______, KC_ENT,  CTL_SPC, KC_BSPC, _______, _______
  ),

  [_DLOWER] = LAYOUT_ortho_3x10(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    UNDO,    CUT,     COPY,    PSTE,    KC_LPRN, KC_RPRN, KC_CH,   KC_CQ,   KC_ASTR, KC_PLUS,
    _______, _______, _______, _______, _______, KC_CENT, _______, KC_DEL,  _______, _______
  ),

  [_SLOWER] = LAYOUT_ortho_3x10(
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,     KC_R,    KC_L,
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,     KC_N,    KC_S,
    _______, _______, _______, _______, _______, KC_LGUI, KC_LCTL, KC_LALT,  _______, _______
  ),

  [_RAISE] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_GRV,  KC_BSLS, KC_EQL,  KC_SLSH, KC_MINUS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS,
    KC_LALT, KC_LGUI, KC_LCTL, KC_ESC,  KC_SPC,   _______, RAISE_M, _______, _______, _______
  ),

  [_DRAISE] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    UNDO,    CUT,     COPY,    PSTE,    KC_LBRC,  KC_RBRC, KC_RGUI, KC_RGUI, KC_RGUI, KC_RGUI,
    _______, _______, _______, _______, KC_TAB, _______, _______, _______, _______, _______
  ),

  [_SRAISE] = LAYOUT_ortho_3x10(
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,     KC_N,    KC_S,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,     KC_V,    KC_Z,
    _______, _______, KC_LALT, KC_LCTL, KC_LGUI, _______, _______, _______,  _______, _______
  ),
};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}

static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool d_lower_pressed = false;
static uint16_t d_lower_pressed_time = 0;
static bool s_lower_pressed = false;
static uint16_t s_lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;
static bool d_raise_pressed = false;
static uint16_t d_raise_pressed_time = 0;
static bool s_raise_pressed = false;
static uint16_t s_raise_pressed_time = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        default_layer_set(_DVORAK);
      }
      return false;
    case LOWER_K:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
        // AUTO_SHIFTはTAPPING_TERMの二倍の時間待つ
        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM * 2)) { 
          // AUTO_SHIFT_TIMEOUTより大きければシフトを入れる
          if (TIMER_DIFF_16(record->event.time,lower_pressed_time) > AUTO_SHIFT_TIMEOUT) {
            register_code(KC_RSFT);
            register_code(KC_K);
            unregister_code(KC_K);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_K);
            unregister_code(KC_K);
          }
        }
        lower_pressed = false;
      }
      return false;
      break;
    case DLOWER_X:
      if (record->event.pressed) {
        d_lower_pressed = true;
        d_lower_pressed_time = record->event.time;
        layer_on(_DLOWER);
      } else {
        layer_off(_DLOWER);
        // AUTO_SHIFTはTAPPING_TERMの二倍の時間待つ
        if (d_lower_pressed && (TIMER_DIFF_16(record->event.time, d_lower_pressed_time) < TAPPING_TERM * 2)) { 
          // AUTO_SHIFT_TIMEOUTより大きければシフトを入れる
          if (TIMER_DIFF_16(record->event.time,d_lower_pressed_time) > AUTO_SHIFT_TIMEOUT) {
            register_code(KC_RSFT);
            register_code(KC_X);
            unregister_code(KC_X);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_X);
            unregister_code(KC_X);
          }
        }
        d_lower_pressed = false;
      }
      return false;
      break;
    case SLOWER_J:
      if (record->event.pressed) {
        s_lower_pressed = true;
        s_lower_pressed_time = record->event.time;
        layer_on(_SLOWER);
      } else {
        layer_off(_SLOWER);
        // AUTO_SHIFTはTAPPING_TERMの二倍の時間待つ
        if (s_lower_pressed && (TIMER_DIFF_16(record->event.time, s_lower_pressed_time) < TAPPING_TERM * 2)) { 
          // AUTO_SHIFT_TIMEOUTより大きければシフトを入れる
          if (TIMER_DIFF_16(record->event.time,s_lower_pressed_time) > AUTO_SHIFT_TIMEOUT) {
            register_code(KC_RSFT);
            register_code(KC_J);
            unregister_code(KC_J);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_J);
            unregister_code(KC_J);
          }
        }
        s_lower_pressed = false;
      }
      return false;
      break;
    case RAISE_M:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
        // AUTO_SHIFTはTAPPING_TERMの二倍の時間待つ
        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM * 2)) { 
          // AUTO_SHIFT_TIMEOUTより大きければシフトを入れる
          if (TIMER_DIFF_16(record->event.time,raise_pressed_time) > AUTO_SHIFT_TIMEOUT) {
            register_code(KC_RSFT);
            register_code(KC_M);
            unregister_code(KC_M);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_M);
            unregister_code(KC_M);
          }
        }
        raise_pressed = false;
      }
      return false;
      break;
    case DRAISE_B:
      if (record->event.pressed) {
        d_raise_pressed = true;
        d_raise_pressed_time = record->event.time;
        layer_on(_DRAISE);
      } else {
        layer_off(_DRAISE);
        // AUTO_SHIFTはTAPPING_TERMの二倍の時間待つ
        if (d_raise_pressed && (TIMER_DIFF_16(record->event.time, d_raise_pressed_time) < TAPPING_TERM * 2)) { 
          // AUTO_SHIFT_TIMEOUTより大きければシフトを入れる
          if (TIMER_DIFF_16(record->event.time,d_raise_pressed_time) > AUTO_SHIFT_TIMEOUT) {
            register_code(KC_RSFT);
            register_code(KC_B);
            unregister_code(KC_B);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_B);
            unregister_code(KC_B);
          }
        }
        d_raise_pressed = false;
      }
      return false;
      break;
    case SRAISE_W:
      if (record->event.pressed) {
        s_raise_pressed = true;
        s_raise_pressed_time = record->event.time;
        layer_on(_SRAISE);
      } else {
        layer_off(_SRAISE);
        // AUTO_SHIFTはTAPPING_TERMの二倍の時間待つ
        if (s_raise_pressed && (TIMER_DIFF_16(record->event.time, s_raise_pressed_time) < TAPPING_TERM * 2)) { 
          // AUTO_SHIFT_TIMEOUTより大きければシフトを入れる
          if (TIMER_DIFF_16(record->event.time,s_raise_pressed_time) > AUTO_SHIFT_TIMEOUT) {
            register_code(KC_RSFT);
            register_code(KC_W);
            unregister_code(KC_W);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_W);
            unregister_code(KC_W);
          }
        }
        s_raise_pressed = false;
      }
      return false;
      break;
    default:
        if (record->event.pressed) {
            // reset the flag
            lower_pressed = false;
            d_lower_pressed = false;
            s_lower_pressed = false;
            raise_pressed = false;
            d_raise_pressed = false;
            s_raise_pressed = false;
        }
        break;
  }
  return true;
}
