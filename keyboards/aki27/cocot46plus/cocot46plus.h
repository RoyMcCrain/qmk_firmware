/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

#define LAYOUT( \
    A00, A01, A02, A03, A04, A05,                 B05, B04, B03, B02, B01, B00, \
    A10, A11, A12, A13, A14, A15,                 B15, B14, B13, B12, B11, B10, \
    A20, A21, A22, A23, A24, A25,                 B25, B24, B23, B22, B21, B20, \
              A30, A31, A32, A33, A35,      B35,  B33, B32, B31, B30, \
                                  A42, A34, A45,  B42, B34, B45 \
   ) \
  { \
    { A00,   A01,   A02,   A03,   A04,   A05 }, \
    { A10,   A11,   A12,   A13,   A14,   A15 }, \
    { A20,   A21,   A22,   A23,   A24,   A25 }, \
    { A30,   A31,   A32,   A33,   A34,   A35 }, \
    { KC_NO, KC_NO, A42, KC_NO, KC_NO,   A45 }, \
    { B00,   B01,   B02,   B03,   B04,   B05 }, \
    { B10,   B11,   B12,   B13,   B14,   B15 }, \
    { B20,   B21,   B22,   B23,   B24,   B25 }, \
    { B30,   B31,   B32,   B33,   B34,   B35 },  \
    { KC_NO, KC_NO, B42, KC_NO, KC_NO,   B45 }  \
  }


typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_idx;
        uint8_t scrl_div;
        uint8_t rotation_angle;
        int8_t scrl_inv;
        bool scrl_mode;
        report_mouse_t last_mouse;
    };
} cocot_config_t;



extern cocot_config_t cocot_config;

enum cocot_keycodes {

    COCOT_SAFE_RANGE = SAFE_RANGE,
    CPI_SW,
    SCRL_SW,
    ROT_R15,
    ROT_L15,
    SCRL_MO,
    SCRL_TO,
    SCRL_IN,

};

#define CPI_SW 0x5DA7
// トラックボールのCPIを変更します。
// デフォルトのファームウェアでは、押すたびに500→750→1000→1250→500…という順番でCPIが変わります。
#define SCRL_SW 0x5DA8
// スクロールモードにおけるセンサーの感度を変更します。数値が大きいほどスクロール量が小さくなります。
#define ROT_R15 0x5DA9
// マウスセンサーのＹ軸を時計回りに15度回転させます。
#define ROT_L15 0x5DAA
// マウスセンサーのＹ軸を反時計回りに15度回転させます。
#define SCRL_MO 0x5DAB
// 押されている間スクロールモードになります。
#define SCRL_TO 0x5DAC
// 押すたびにスクロールモードとマウスモードを切り替えます。
#define SCRL_IN 0x5DAD
// スクロール方向を反転させます。

bool encoder_update_user(uint8_t index, bool clockwise);
bool encoder_update_kb(uint8_t index, bool clockwise);
bool cocot_get_scroll_mode(void);
void cocot_set_scroll_mode(bool mode);

void render_logo(void);
void oled_write_layer_state(void);
