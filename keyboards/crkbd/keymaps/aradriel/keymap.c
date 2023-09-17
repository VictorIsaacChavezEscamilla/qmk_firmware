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
TD(TD_LALT_RALT),   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                       KC_INS, KC_PSCR, KC_APP, XXXXXXX, XXXXXXX, XXXXXXX,
     //                                                                              Insert PrintScreen Menu
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
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_space(void) {
    static const char PROGMEM space_text[] = {
        0x05, 0x05, 0x05, 0x05, 0x05, 0};
    oled_write_P(space_text, false);
}

void render_separator_bottom(void) {
    static const char PROGMEM separator[] = {
        0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0};
    oled_write_P(separator, false);
}

void render_separator_up(void) {
    static const char PROGMEM separator[] = {
        0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0};
    oled_write_P(separator, false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    static const char PROGMEM corne_text[] = {
        0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(corne_text, false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x05, 0x94, 0x95, 0x96, 0x05,
        0x05, 0xb4, 0xb5, 0xb6, 0x05,
        0x05, 0xd4, 0xd5, 0xd6, 0x05, 0};
    static const char PROGMEM raise_layer[] = {
        0x05, 0x97, 0x98, 0x99, 0x05,
        0x05, 0xb7, 0xb8, 0xb9, 0x05,
        0x05, 0xd7, 0xd8, 0xd9, 0x05, 0};
    static const char PROGMEM lower_layer[] = {
        0x05, 0x9a, 0x9b, 0x9c, 0x05,
        0x05, 0xba, 0xbb, 0xbc, 0x05,
        0x05, 0xda, 0xdb, 0xdc, 0x05, 0};
    static const char PROGMEM adjust_layer[] = {
        0x05, 0x9d, 0x9e, 0x9f, 0x05,
        0x05, 0xbd, 0xbe, 0xbf, 0x05,
        0x05, 0xdd, 0xde, 0xdf, 0x05, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if (layer_state_is(_NUMPADSYM)) {
        oled_write_P(lower_layer, false);
    } else if (layer_state_is(_ARROWPADFUNC)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_status_main(void) {
    render_space();
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {

    static const char PROGMEM horde_logo[] = {
        0x05, 0x01, 0x02, 0x03, 0x04,
        0x20, 0x21, 0x22, 0x23, 0x24,
        0x40, 0x41, 0x42, 0x43, 0x44,
        0x60, 0x61, 0x62, 0x63, 0x64,
        0x05, 0x06, 0x07, 0x08, 0x09, 0};

    static const char PROGMEM horde_text[] = {
        0x05, 0x3b, 0x1c, 0x1d, 0x05,
        0x05, 0x05, 0x05, 0x05, 0x05,
        0x05, 0x3c, 0x3d, 0x1f, 0x05,
        0x05, 0x05, 0x05, 0x05, 0x05,
        0x3d, 0x1c, 0x1d, 0x3e, 0x1f, 0};

    render_separator_up();
    render_space();
    oled_write_P(horde_logo, false);
    render_space();
    oled_write_P(horde_text, false);
    render_space();
    render_separator_bottom();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}
#endif // OLED_DRIVER_ENABLE

#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_user(void) {
    oled_off();
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    oled_on();
    rgb_matrix_set_suspend_state(false);
}

#endif
