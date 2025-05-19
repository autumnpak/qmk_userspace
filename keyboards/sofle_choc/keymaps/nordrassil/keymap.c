/* Copyright 2023 Brian Low
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

#include "oled.c"

//#include "combos/keymap_combo.h"

enum custom_keycodes {
  LMAGIC = SAFE_RANGE,
  RMAGIC,
};

//layers
#define NDRSL    TO(0)
#define QWERTY   TO(1)
#define STENO    TO(2)
#define TYPING   TO(3)
#define GAME     TO(4)

#define NUM_DEL  LT(5, KC_DEL)
#define NAV MO(6)
 
// Homerow mods and layers
//#define HRL_A LT(4,  KC_A) 
#define HRM_A LSFT_T(KC_A) 
#define HRM_E LCTL_T(KC_E)
#define HRM_I LGUI_T(KC_I)
#define HRM_H LALT_T(KC_H)
//#define HRM_X LALT_T(KC_X)
 
//#define HRL_D LT(3,  KC_D)
#define HRM_D RSFT_T(KC_D)
#define HRM_R RCTL_T(KC_R)
#define HRM_S RGUI_T(KC_S)
#define HRM_L RALT_T(KC_L)
//#define HRM_V RALT_T(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LCMD | LALT | /Enter  /       \Space \  | RALT | RCMD | RGUI | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
    [0] = LAYOUT(   //nordrassil layer
        STENO,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    QWERTY,
        KC_ESC,   KC_Q,   KC_Y,    KC_O,    KC_U,    KC_MINS,                     KC_J,     KC_G,     KC_N,    KC_W,    KC_K,    KC_BSPC,
        KC_TAB,   HRM_H,  HRM_I,   HRM_E,   HRM_A,   KC_DOT,                      KC_P,     HRM_D,    HRM_R,   HRM_S,   HRM_L,   KC_Z,
        KC_LSFT,  KC_X,   KC_SLSH, KC_QUOT, KC_COMM, KC_SCLN, KC_MUTE,   KC_MPLY, KC_B,     KC_C,     KC_M,    KC_F,    KC_F,    KC_RSFT,
                          KC_LCTL, KC_ESC,  KC_BSPC, KC_SPC,  LMAGIC,    RMAGIC,  KC_T,     KC_ENT,   KC_APP,  KC_RCTL
    ),
    [1] = LAYOUT(   //vanilla layer
        NDRSL,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    STENO,
        KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY, KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LCTL, KC_LGUI, KC_LCMD, KC_LALT, KC_ENT,    KC_SPC,  KC_RALT,  KC_RCMD,  KC_RGUI, KC_RCTL
    ),
    [2] = LAYOUT(   //steno layer
        QWERTY,   STN_N1,  STN_N2, STN_N3,  STN_N4,  STN_N5,                      STN_N6,   STN_N7,   STN_N8,  STN_N9,  STN_NA,  NDRSL,
        KC_NO,    STN_N1,  STN_N2, STN_N3,  STN_N4,  STN_N5,                      STN_N6,   STN_N7,   STN_N8,  STN_N9,  STN_NA,  STN_NB,
        KC_NO,    STN_S1,  STN_TL, STN_PL,  STN_HL,  STN_ST1,                     STN_ST3,  STN_FR,   STN_PR,  STN_LR,  STN_TR,  STN_DR,
        KC_NO,    STN_S2,  STN_KL, STN_WL,  STN_RL,  STN_ST2, KC_NO,     KC_NO,   STN_ST4,  STN_RR,   STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                           KC_NO,  KC_NO,   STN_O,   STN_A,   STN_O,     STN_E,   STN_U,    STN_E,    KC_NO,   KC_NO
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
