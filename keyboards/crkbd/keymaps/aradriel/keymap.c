/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

// #include <stdio.h>
#include QMK_KEYBOARD_H

enum layers {
  _HOME, // home base
  _NUMPADSYM, // numbers and Symbols
  _ARROWPADFUNC,// arrow pad and functions
  _ADJUST, // setup
};

//Tap Dance declarations
enum {
    TD_LSFT_CAPS,
    TD_RSFT_ESC,
    TD_WIN_APPMN,
    TD_LALT_RALT,
    TD_QUOT_GRV,
    TD_NTIL_ACUT,
    TD_LABK_RABK,
    TD_LPRN_RPRN,
    TD_LBRC_RBRC,
    TD_LCBR_RCBR,
    TD_EXLM_IEXL,
    TD_QUES_IQUE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_HOME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------------------------.
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,             KC_P,         KC_BSPC,
  //                                                                                                                                              <-
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+------------------+----------------|
       KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, TD(TD_NTIL_ACUT), TD(TD_QUOT_GRV),
  //                                                                                                                        ñ   ´              '   "
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+------------------+----------------|
TD(TD_LSFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,           KC_SLSH, TD(TD_RSFT_ESC),
  //                                                                                                 , ;      . :                - _
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+------------------+----------------|
                         TD(TD_WIN_APPMN), MO(_NUMPADSYM),  KC_SPC,     KC_ENT, MO(_ARROWPADFUNC), TD(TD_LALT_RALT)
                     //`------------------------------------------'  `-----------------------------------'

  ),

  [_NUMPADSYM] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------------------.                    ,-----------------------------------------------------.
ALGR(KC_MINS),        ALGR(KC_Q),          KC_HASH,           KC_DLR,         KC_PERC, LSFT(KC_6),                    KC_PPLS,   KC_P7,   KC_P8,   KC_P9, KC_PAST, KC_BSPC,
  //       \                @               #                   $                 %       &                               +         7        8        9      *      <-
  //|--------+------------------+-----------------+-----------------+-----------------+--------|                    |--------+--------+--------+--------+--------+--------|
ALGR(KC_RBRC), TD(TD_LABK_RABK), TD(TD_LPRN_RPRN), TD(TD_LBRC_RBRC), TD(TD_LCBR_RCBR), KC_GRV,                        KC_PMNS,   KC_P4,   KC_P5,   KC_P6, KC_PSLS, ALGR(KC_QUOT),
  //      ~              < >               ( )              [ ]                { }        |                               -         4        5        6      /        ^
  //|--------+------------------+----------------+-----------------+------------------+--------|                    |--------+--------+--------+--------+--------+--------|
 ALGR(KC_GRV),     LSFT(KC_GRV),    ALGR(KC_NUHS),   TD(TD_EXLM_IEXL), TD(TD_QUES_IQUE), LSFT(KC_LBRC),                 KC_P0,   KC_P1,   KC_P2,   KC_P3,  LSFT(KC_0), XXXXXXX,
  //      ¬                °                 `               ! ¡               ? ¿        ¨                              0        1         2        3      =
  //|--------+------------------+---------------+-----------------+-------------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                      TD(TD_WIN_APPMN), _______,  KC_SPC,     KC_ENT, MO(_ADJUST), TD(TD_LALT_RALT)
                                                                           //`--------------------------'  `--------------------------'
  ),

  [_ARROWPADFUNC] = LAYOUT_split_3x6_3(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
TD(TD_LALT_RALT),   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                       KC_INS, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     //                                                                              Insert PrintScreen
     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_LCTL,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                      KC_HOME, KC_DEL,  KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
    //
     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_LSFT,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      KC_END, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                               TD(TD_WIN_APPMN), MO(_ADJUST),  KC_SPC,     KC_ENT, _______, _______
                                        //`--------------------------'  `--------------------------'
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 TD(TD_WIN_APPMN), _______,  KC_SPC,     KC_ENT, _______, TD(TD_LALT_RALT)
                                      //`--------------------------'  `--------------------------'
  )
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Left Shift, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    // Tap once for Right Shift, twice for Escape
    [TD_RSFT_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_ESC),
    // Tap once for Left Windows, twice for Application (Windows Context Menu Key)
    [TD_WIN_APPMN] = ACTION_TAP_DANCE_DOUBLE(KC_LWIN, KC_APP),
    // Tap once for KC_LALT, twice for KC_RALT
    [TD_LALT_RALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),

    // Tap once for ', twice for "
    [TD_QUOT_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_2)),
    // Tap once for ñ, twice for ´
    [TD_NTIL_ACUT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_LBRC),
    // Tap once for <, twice for >
    [TD_LABK_RABK] = ACTION_TAP_DANCE_DOUBLE(KC_NUBS, LSFT(KC_NUBS)),
    // Tap once for (, twice for )
    [TD_LPRN_RPRN] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_8), LSFT(KC_9)),
    // Tap once for [, twice for ]
    [TD_LBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_QUOT), LSFT(KC_NUHS)),
    // Tap once for {, twice for }
    [TD_LCBR_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_NUHS),
    // Tap once for !, twice for ¡
    [TD_EXLM_IEXL] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_1), LSFT(KC_EQL)),
    // Tap once for ?, twice for ¿
    [TD_QUES_IQUE] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_MINS), KC_EQL),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Home"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Num&Sym"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("ArrPad&Func"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
