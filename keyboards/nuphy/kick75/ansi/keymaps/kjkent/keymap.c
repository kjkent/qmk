#include QMK_KEYBOARD_H

#if defined(DEBUG)
#include "print.h"
#endif

// USE 'MAC' POSITION ON REAR TOGGLE FOR THIS KEYMAP TO WORK
//
// NuPhy has assigned Mac to L0 and Win to L2 in keyboard code
// TODO: Remove Mac/Win, consider other uses for toggle?
//
// Number of keymap and encoder layers must match!
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    KC_ESC,   KC_BRID,  KC_BRIU,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,   KC_MUTE,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_PGDN,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,
    MO(1),    KC_LALT,  KC_LGUI,                           KC_SPC,                            _______,  _______,            KC_LEFT,  KC_DOWN,  KC_RIGHT
),

// FN-layer
[1] = LAYOUT(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   _______,
    _______,  LNK_BLE1, LNK_BLE2, LNK_BLE3, LNK_RF,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_END,
    RGB_TOG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  DEV_RESET,SLEEP_MODE,BAT_SHOW,_______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    MO(2),    _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SPD,  RGB_SPI,  _______,  _______,            RGB_VAI,
    _______,  _______,  _______,                           _______,                           _______,  _______,            RGB_MOD,  RGB_VAD,  RGB_HUI
),

// FN+Shift
[2] = LAYOUT(
    QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  RGB_TEST, _______,  _______,  _______,  _______,  SIDE_SPD, SIDE_SPI, _______,  _______,            SIDE_VAI,
    _______,  _______,  _______,                           _______,                           _______,  _______,            SIDE_MOD, SIDE_VAD, SIDE_HUI
),

// Unused, blank template
[3] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,                           _______,                           _______,  _______,            _______,  _______,  _______
)
};

#if defined(ENCODER_MAP_ENABLE)
// Number of keymap and encoder layers must match!
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

void keyboard_post_init_user(void) {
    #if defined(DEBUG)
    debug_enable = true;
    debug_keyboard = true;
    debug_matrix = true;
    debug_mouse = true;
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #if defined(DEBUG)
    uprintf("Key: %s, col: %2u, row: %2u, pressed: %u", get_keycode_string(keycode), record->event.key.col, record->event.key.row, record->event.pressed;
    #endif

    return true;
}
