#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "naginata.h"
NGKEYS naginata_keys;

enum layer_number {
    _ASTARTE,
    _NAGINATA,
    _LOWER,
    _RIGHT,
    _RAISE,
    _ADJUST
};

enum keycodes {
    ASTARTE = NG_SAFE_RANGE,
    LOWER,
    RAISE,
    CONTROL,
    ADJUST,
    TPBM,
    RTLF,
    UNDO,
    CUT,
    COPY,
    PSTE,
    GENT,
    V_W,
    V_WQ,
    V_Q
};

#define SLP  LGUI(KC_L)

#define V_SV LSFT(KC_V)
#define V_CJ LCTL(KC_J)
// Mission Control
#define MC LGUI(KC_TAB)
#define N_LEFT LSFT(KC_LEFT)
#define N_RGHT LSFT(KC_RGHT)
#define RGT MO(_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Astarte
     * ,-----------------------------------             -----------------------------------.
     * |   Q  |   P  |   U  |   Y  |   ,  |             |   J  |   D  |   H  |   G  |   W  |
     * |------+------+------+------+------+             +------+------+------+------+------|
     * |   I  |   O  |   E  |   A  |   .  |             |   K  |   T  |   N  |   S  |   R  |
     * |------+------+------+------+------+             +------+------+------+------+------|
     * |   Z  |   X  |   '  |   C  |   ;  |             |   M  |   L  |   F  |   B  |   V  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |             | Ctrl |Lower |Space |Space | ENT  | ENT  | Raise| BCSP |             |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |                           |Lower |Space |Space | XXX  | XXX  | XXX  |             |
     * `-----------------------------------------------------------------------------------'
     */
    [_ASTARTE] = LAYOUT(
        XXXXXXX, KC_Q,    KC_P,    KC_U,    KC_Y,  KC_COMM,                         KC_J,   KC_D,  KC_H,    KC_G,    KC_W, XXXXXXX,
        XXXXXXX, KC_I,    KC_O,    KC_E,    KC_A,  KC_DOT,                          KC_K,   KC_T,  KC_N,    KC_S,    KC_R, XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_QUOT, KC_C,  KC_SCLN,                         KC_M,   KC_L,  KC_F,    KC_B,    KC_V, XXXXXXX,
                 KC_LGUI, CONTROL, LOWER, KC_SPC,  KC_MS_BTN1, KC_MS_BTN2, KC_ENT, RAISE, KC_BSPC, KC_LALT,
                                                KC_PGUP, KC_MS_BTN3, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
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
    [_LOWER] = LAYOUT(
        XXXXXXX, _______, PSTE,    UNDO,    COPY,    _______,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  XXXXXXX,
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    XXXXXXX,
        XXXXXXX, _______, _______, V_Q,     V_W,     V_WQ,                       V_CJ,    V_SV,    N_LEFT,  N_RGHT,   _______, XXXXXXX,
                 _______, _______, _______, _______,  _______, _______, GENT,    _______, KC_DEL,  _______,
                                                KC_PGUP, KC_MS_BTN3, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
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
    [_RAISE] = LAYOUT(
        XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_RALT, MC,      XXXXXXX,
        XXXXXXX, KC_BSLS, KC_GRV,  KC_EQL,  KC_SLSH, KC_MINUS,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, XXXXXXX,
        XXXXXXX, _______, _______, KC_UNDS, KC_LPRN, KC_LBRC,                    KC_RBRC, KC_RPRN, RTLF,    TPBM,    _______, XXXXXXX,
                 _______, _______, _______, KC_TAB,   _______, _______, _______, _______, _______, _______,
                                                KC_PGUP, KC_MS_BTN3, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_RIGHT] = LAYOUT(
        XXXXXXX, _______, _______, _______, _______, _______,                   _______, MC,      _______, _______, _______, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______,                   _______, KC_WH_D, KC_WH_U, _______, _______, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, KC_BTN2, KC_BTN1, _______, _______,
                                                KC_PGUP, KC_MS_BTN3, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
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
    [_ADJUST] = LAYOUT(
       XXXXXXX,  _______, _______, _______, _______, _______,                   _______, MC,      _______, _______, _______, XXXXXXX,
       XXXXXXX,  _______, _______, KC_BTN2, KC_BTN1, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, XXXXXXX,
       XXXXXXX,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  SLP,                       _______, KC_WH_D, KC_WH_U, _______, _______, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                                KC_PGUP, KC_MS_BTN3, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAGINATA] = LAYOUT(
        XXXXXXX, NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,                       NG_Y,     NG_U,    NG_I,    NG_O,    NG_P,    XXXXXXX,
        XXXXXXX, NG_A,    NG_S,    NG_D,    NG_F,    NG_G,                       NG_H,     NG_J,    NG_K,    NG_L,    NG_SCLN, XXXXXXX,
        XXXXXXX, NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,                       NG_N,     NG_M,    NG_COMM, NG_DOT,  NG_SLSH, XXXXXXX,
                 _______, _______, _______, _______, NG_SHFT, _______, _______,  NG_SHFT2, _______, _______,
                                                KC_PGUP, KC_MS_BTN3, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

/*
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |1.RHT |1.RHT |      |      |      |      |2.NAGI|2.NAGI|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   '  |0.ENT |      |      |      |      |0.ENT |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
enum combos {
    C_ENTER,
    C_RIGHT,
    // C_NAGINATA,
};

const uint16_t PROGMEM enter_combo[] = {KC_C, KC_L, COMBO_END};
const uint16_t PROGMEM right_combo[] = {KC_A, KC_E, COMBO_END};
// const uint16_t PROGMEM naginata_combo[] = {KC_T, KC_N, COMBO_END};
combo_t key_combos[] = {
  [C_ENTER] = COMBO(enter_combo, KC_ENT),
  [C_RIGHT] = COMBO(right_combo, MO(_RIGHT)),
  // [C_NAGINATA] = COMBO_ACTION(naginata_combo),
};

// void process_combo_event(uint16_t combo_index, bool pressed) {
//     switch(combo_index) {
//         case C_NAGINATA:
//             if (pressed) {
//                 if (!naginata_state()) {
//                     naginata_on();
//                 }
//             }
//         break;
//     }
// }

void matrix_init_user(void) {
    uint16_t ngonkeys[] = {};
    uint16_t ngoffkeys[] = {};
    set_naginata(_NAGINATA, ngonkeys, ngoffkeys);
}

uint32_t last_keypress = 0;
void matrix_scan_user(void) {
    // *秒間キーが押されていなかったら薙刀式を解除する
    if (timer_elapsed32(last_keypress) > 10000) {
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
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
                    if (naginata_state()) {
                        naginata_off();
                    }
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
        case UNDO:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(G(KC_Z));
                } else {
                    tap_code16(C(KC_Z));
                }
            }
            return false;
        case CUT:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(G(KC_X));
                } else {
                    tap_code16(C(KC_X));
                }
            }
            return false;
        case COPY:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(G(KC_C));
                } else {
                    tap_code16(C(KC_C));
                }
            }
            return false;
        case PSTE:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(G(KC_V));
                } else {
                    tap_code16(C(KC_V));
                }
            }
            return false;
        case GENT:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(G(KC_ENT));
                } else {
                    tap_code16(C(KC_ENT));
                }
                naginata_off();
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
