/* Copyright 2015-2017 Jack Humbert
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
// #include "muse.h"

enum preonic_layers { _QWERTY, _LOWER, _RAISE, _ADJUST };

enum preonic_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST };

// save cmd + s
#define KC_SAVE LGUI(KC_S)
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PSTE LGUI(LSFT(KC_V))
// cmd + enter
#define KC_CENT LGUI(KC_ENT)
// cmd + h
#define KC_CH LGUI(KC_H)
// cmd + q
#define KC_CQ LGUI(KC_Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  | Esc  |  \   |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Q  |   W  |   E  |   R  |   T  |  =   |  `   |   Y  |   U  |   I  |   O  |   P  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   A  |   S  |   D  |   F  |   G  |  '   |  -   |   H  |   J  |   K  |   L  |   ;  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   V  |   B  |  [   |  ]   |   N  |   M  |   ,  |   .  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  Alt | Ctrl | GUI  | SFT  |    Space    |    Enter    | Raise| BCSP | SFT  | Del  |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_preonic_grid(KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC, KC_BSLS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_EQL, KC_GRV, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_A, KC_S, KC_D, KC_F, KC_G, KC_QUOT, KC_MINS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LALT, KC_LCTL, LGUI_T(KC_ESC), LSFT_T(KC_LANG2), KC_SPC, KC_SPC, KC_ENT, KC_ENT, RAISE, KC_BSPC, KC_RSFT, KC_DEL),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_preonic_grid(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  |   *  |  )   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   \  |   =  |   /  |   -  |      |      |  ←  |  ↓  |  ↑  |  →  |  _   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |  (   |   )  |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |    TAB      |             |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_preonic_grid(KC_1, KC_2, KC_3, KC_4, KC_5, _______, _______, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV, KC_BSLS, KC_EQL, KC_SLSH, KC_MINUS, _______, _______, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_UNDS, UNDO, CUT, COPY, PSTE, KC_LBRC, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TAB, KC_TAB, _______, _______, _______, _______, _______, _______),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_preonic_grid(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)

};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

static bool     lower_pressed      = false;
static uint16_t lower_pressed_time = 0;
static bool     raise_pressed      = false;
static uint16_t raise_pressed_time = 0;
bool            process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                default_layer_set(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                lower_pressed      = true;
                lower_pressed_time = record->event.time;
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                // AUTO_SHIFTはTAPPING_TERMの二倍の時間待つ
                if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM * 2)) {
                    // AUTO_SHIFT_TIMEOUTより大きければシフトを入れる
                    // example 処理は変わらない
                    register_code(KC_ESC);
                    unregister_code(KC_ESC);
                }
                lower_pressed = false;
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                raise_pressed      = true;
                raise_pressed_time = record->event.time;
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM * 2)) {
                    tap_code16(C(KC_SPC));
                    register_code(KC_LANG1);
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
        default:
            if (record->event.pressed) {
                // reset the flag
                lower_pressed = false;
                raise_pressed = false;
            }
            break;
    }
    return true;
}
