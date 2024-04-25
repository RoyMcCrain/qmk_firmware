#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "naginata.h"
#include "keymap_japanese.h"
NGKEYS naginata_keys;

enum layers {
    _ASTARTE,
    _NAGINATA,
    _LOWER,
    _RIGHT,
    _RAISE,
    _ADJUST,
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
    V_Q,
    QUOT,
    SCLN,
    BSLS,
    GRV,
    MINS,
    EQL,
    WH_D,
    WH_U,
};

#define SLP  LGUI(KC_L)

#define V_SV LSFT(KC_V)
#define V_CJ LCTL(KC_J)
// Mission Control
#define MC LGUI(KC_TAB)
#define N_LEFT LSFT(KC_LEFT)
#define N_RGHT LSFT(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Astarte
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   P  |   U  |   Y  |   ,  |XXXXXX|XXXXXX|   J  |   D  |   H  |   G  |   W  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   I  |   O  |   E  |   A  |   .  |XXXXXX|XXXXXX|   K  |   T  |   N  |   S  |   R  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   '  |   C  |   ;  |XXXXXX|XXXXXX|   M  |   L  |   F  |   B  |   V  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  | ALT  | Ctrl |Lower |Space |XXXXXX|XXXXXX| ENT  | Raise| BCSP |  SHT |  MC  |
 * `-----------------------------------------------------------------------------------'
 */

    [_ASTARTE] = LAYOUT_ortho_4x12(
        KC_Q,    KC_P,    KC_U,    KC_Y,  KC_COMM, KC_NO,  KC_NO,  KC_J,   KC_D,  KC_H,    KC_G,    KC_W,
        KC_I,    KC_O,    KC_E,    KC_A,  KC_DOT,  KC_NO,  KC_NO,  KC_K,   KC_T,  KC_N,    KC_S,    KC_R,
        KC_Z,    KC_X,    QUOT,    KC_C,  SCLN,    KC_NO,  KC_NO,  KC_M,   KC_L,  KC_F,    KC_B,    KC_V,
        KC_LGUI, KC_LALT, CONTROL, LOWER, KC_SPC,  KC_NO,  KC_NO,  KC_ENT, RAISE, KC_BSPC, KC_RSFT, MC
    ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      | PSTE | UNDO | COPY |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  ;q  |  ;w  |  ZZ  |      |      | C V  |  S v |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  ENT |      | DEL  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_LOWER] = LAYOUT_ortho_4x12(
        _______, PSTE,    UNDO,    COPY,    _______,  _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     _______, _______, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
        _______, _______, V_Q,     V_W,     V_WQ,     _______, _______, V_CJ,    V_SV,    N_LEFT,  N_RGHT,   _______,
        _______, _______, _______, _______, _______,  _______, _______, GENT,    _______, KC_DEL,  _______,  _______
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
    [_RAISE] = LAYOUT_ortho_4x12(
        JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC,  _______, _______, JP_CIRC, JP_AMPR, JP_ASTR, KC_RALT, MC,
        BSLS,    GRV,     EQL,     JP_SLSH, MINS,     _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, JP_UNDS, JP_LPRN, JP_LBRC,  _______, _______, JP_RBRC, JP_RPRN, RTLF,    TPBM,    _______,
        _______, _______, _______, _______, KC_TAB,   _______, _______, _______, _______, _______, _______, _______
    ),

    [_RIGHT] = LAYOUT_ortho_4x12(
        _______, _______, _______, _______, _______, _______, _______, _______, KC_TAB,  KC_RALT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, WH_D,    WH_U,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______
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
    [_ADJUST] = LAYOUT_ortho_4x12(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
        _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  SLP,     _______, _______, _______, WH_D,    WH_U,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NAGINATA] = LAYOUT_ortho_4x12(
        NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,    _______, _______,  NG_Y,     NG_U,    NG_I,    NG_O,    NG_P,
        NG_A,    NG_S,    NG_D,    NG_F,    NG_G,    _______, _______,  NG_H,     NG_J,    NG_K,    NG_L,    NG_SCLN,
        NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,    _______, _______,  NG_N,     NG_M,    NG_COMM, NG_DOT , NG_SLSH,
        _______, _______, _______, _______, NG_SHFT, _______, _______,  NG_SHFT2, _______, _______, _______, _______
    )

};

/*
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |1.RHT |1.RHT |      |      |      |      |3.NAGI|3.NAGI|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |0.ENT |      |      |      |      |0.ENT |      |      |      |
 * |      |      |      |      |      |      |      |      |2.SENT|2.SENT|      |      |

 * `-----------------------------------------------------------------------------------'
 */
enum combos {
    C_ENTER,
    C_SENTER,
    C_N_SENTER,
    C_RIGHT,
    C_NAGINATA,
    C_XXX,
};

const uint16_t PROGMEM enter_combo[] = {KC_C, KC_L, COMBO_END};
const uint16_t PROGMEM senter_combo[] = {KC_L, KC_F, COMBO_END};
const uint16_t PROGMEM n_senter_combo[] = {NG_M, NG_COMM, COMBO_END};
const uint16_t PROGMEM right_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM naginata_combo[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM xxx_combo[] = {NG_J, NG_K, COMBO_END};
combo_t key_combos[] = {
    [C_ENTER] = COMBO(enter_combo, KC_ENT),
    [C_SENTER] = COMBO(senter_combo, S(KC_ENT)),
    [C_N_SENTER] = COMBO(n_senter_combo, S(KC_ENT)),
    [C_RIGHT] = COMBO(right_combo, MO(_RIGHT)),
    [C_XXX] = COMBO_ACTION(xxx_combo),
    [C_NAGINATA] = COMBO_ACTION(naginata_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case C_NAGINATA:
        case C_XXX:
            if (pressed) {
                if (!naginata_state()) {
                    naginata_on();
                } else {
                    naginata_off();
                    naginata_on();
                }
            }
        break;
    }
}

void matrix_init_user(void) {
    uint16_t ngonkeys[] = {};
    uint16_t ngoffkeys[] = {};
    set_naginata(_NAGINATA, ngonkeys, ngoffkeys);
}

// uint32_t last_keypress = 0;
// void matrix_scan_user(void) {
//     // *秒間キーが押されていなかったら薙刀式を解除する
//     if (timer_elapsed32(last_keypress) > 15000) {
//         if (naginata_state()) {
//             naginata_off();
//         }
//     }
// }

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
       // last_keypress = timer_read32();
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
                // AUTO_SHIFTはTAPPING_TERMの二倍の時間待つ
                if (lower_pressed && (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM)) {
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
                if (control_pressed && (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM)) {
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
                    register_code16(G(KC_Z));
                } else {
                    register_code16(C(KC_Z));
                }
            } else {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    unregister_code16(G(KC_Z));
                } else {
                    unregister_code16(C(KC_Z));
                }
            }
            return false;
        case CUT:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code16(G(KC_X));
                } else {
                    register_code16(C(KC_X));
                }
            } else {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    unregister_code16(G(KC_X));
                } else {
                    unregister_code16(C(KC_X));
                }
            }
            return false;
        case COPY:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code16(G(KC_C));
                } else {
                    register_code16(C(KC_C));
                }
            } else {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    unregister_code16(G(KC_C));
                } else {
                    unregister_code16(C(KC_C));
                }
            }
            return false;
        case PSTE:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code16(G(KC_V));
                } else {
                    register_code16(C(KC_V));
                }
            } else {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    unregister_code16(G(KC_V));
                } else {
                    unregister_code16(C(KC_V));
                }
            }
            return false;
        case GENT:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code16(G(KC_ENT));
                } else {
                    register_code16(C(KC_ENT));
                }
            } else {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    unregister_code16(G(KC_ENT));
                } else {
                    unregister_code16(C(KC_ENT));
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
        case QUOT:
            if (record->event.pressed) {
                pressed_time = record->event.time;
            } else {
                if (TIMER_DIFF_16(record->event.time,pressed_time) > AUTO_SHIFT_TIMEOUT) {
                    tap_code16(JP_DQUO);
                } else {
                    tap_code16(JP_QUOT);
                }
            }
            return false;
        case SCLN:
            if (record->event.pressed) {
                pressed_time = record->event.time;
            } else {
                if (TIMER_DIFF_16(record->event.time,pressed_time) > AUTO_SHIFT_TIMEOUT) {
                    tap_code16(JP_COLN);
                } else {
                    tap_code16(JP_SCLN);
                }
            }
            return false;
        case BSLS:
            if (record->event.pressed) {
                pressed_time = record->event.time;
            } else {
                if (TIMER_DIFF_16(record->event.time,pressed_time) > AUTO_SHIFT_TIMEOUT) {
                    tap_code16(S(KC_INT3));
                } else {
                    if (host_os == OS_MACOS || host_os == OS_IOS) {
                        tap_code16(JP_YEN);
                    } else {
                        tap_code16(KC_INT1);
                    }
                }
            }
            return false;
        case GRV:
            if (record->event.pressed) {
                pressed_time = record->event.time;
            } else {
                if (TIMER_DIFF_16(record->event.time,pressed_time) > AUTO_SHIFT_TIMEOUT) {
                    tap_code16(JP_TILD);
                } else {
                    tap_code16(JP_GRV);
                }
            }
            return false;
        case MINS:
            if (record->event.pressed) {
                pressed_time = record->event.time;
            } else {
                if (TIMER_DIFF_16(record->event.time,pressed_time) > AUTO_SHIFT_TIMEOUT) {
                    tap_code16(JP_UNDS);
                } else {
                    tap_code16(JP_MINS);
                }
            }
            return false;
        case EQL:
            if (record->event.pressed) {
                pressed_time = record->event.time;
            } else {
                if (TIMER_DIFF_16(record->event.time,pressed_time) > AUTO_SHIFT_TIMEOUT) {
                    tap_code16(JP_PLUS);
                } else {
                    tap_code16(JP_EQL);
                }
            }
            return false;
        case WH_D:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code16(KC_WH_U);
                } else {
                    register_code16(KC_WH_D);
                }
            } else {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    unregister_code16(KC_WH_U);
                } else {
                    unregister_code16(KC_WH_D);
                }
                naginata_off();
            }
            return false;
        case WH_U:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code16(KC_WH_D);
                } else {
                    register_code16(KC_WH_U);
                }
            } else {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    unregister_code16(KC_WH_D);
                } else {
                    unregister_code16(KC_WH_U);
                }
                naginata_off();
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
        }
    return true;
}
