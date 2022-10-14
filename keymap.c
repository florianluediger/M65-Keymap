#include QMK_KEYBOARD_H
#include "keymap_german_mac_iso.h"

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QW]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LWR] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [_RSE] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_ADJ] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
};
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT_ortho_5x13(
       KC_ESC  , DE_1   , DE_2    , DE_3   , DE_4    , DE_5  , DE_6   , DE_7   , DE_8   , DE_9   , DE_0   , DE_SS   , KC_BSPC ,
       KC_TAB  , DE_Q   , DE_W    , DE_E   , DE_R    , DE_T  , DE_Z   , DE_U   , DE_I   , DE_O   , DE_P   , DE_UDIA , _______ ,
       MO(_RSE), DE_A   , DE_S    , DE_D   , DE_F    , DE_G  , DE_H   , DE_J   , DE_K   , DE_L   , DE_ODIA, DE_ADIA , KC_ENT  ,
       KC_LSFT , DE_LABK, DE_Y    , DE_X   , DE_C    , DE_V  , DE_B   , DE_N   , DE_M   , DE_COMM, DE_DOT , DE_MINS , KC_RSFT ,
       MO(_LWR), KC_LCTL, KC_LALT , KC_LGUI, _______ , KC_SPC, _______, KC_LGUI, KC_RALT, KC_UP  , KC_DOWN, KC_LEFT , KC_RGHT),

    [_RSE] = LAYOUT_ortho_5x13(
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,       _______,      _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  DE_BSLS,    DE_PIPE,    _______,       _______,      _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  DE_LCBR,  DE_LBRC,    DE_RBRC,    DE_RCBR,       _______,      _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  DE_PLUS,  DE_HASH,    _______,    _______,       _______,      _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,       _______,      _______),

  [_LWR] = LAYOUT_ortho_5x13(
    _______,    _______,  _______,  _______,  KC_KP_SLASH,  KC_KP_SLASH,  KC_KP_ASTERISK,  KC_KP_MINUS,  _______,    _______,    _______,       _______,      KC_DELETE,
    _______,    _______,  _______,  _______,  KC_KP_7    ,  KC_KP_8    ,  KC_KP_9       ,  KC_KP_PLUS ,  _______,    _______,    _______,       _______,      _______  ,
    _______,    _______,  _______,  _______,  KC_KP_4    ,  KC_KP_5    ,  KC_KP_6       ,  KC_KP_PLUS ,  _______,    _______,    _______,       _______,      _______  ,
    _______,    _______,  _______,  _______,  KC_KP_1    ,  KC_KP_2    ,  KC_KP_3       ,  KC_KP_ENTER,  _______,    _______,    _______,       _______,      _______  ,
    _______,    _______,  _______,  _______,  _______    ,  KC_KP_0    ,  KC_KP_DOT     ,  KC_KP_ENTER,  _______,    _______,    _______,       _______,      _______  ),

  [_ADJ] = LAYOUT_ortho_5x13(
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,       _______,      _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,       _______,      _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,       _______,      _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,       _______,      _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,       _______,      _______),
};

bool led_update_user(led_t led_state) {
    // Disable the default LED update code, so that lock LEDs could be reused to show layer status.
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {

    switch (get_highest_layer(state)) {
    case _RSE:
        led_rse(true);
        led_lwr(false);
        break;
    case _LWR:
        led_lwr(true);
        led_rse(false);
        break;
    default: //  for any other layers, or the default layer
        led_rse(false);
        led_lwr(false);
        break;
    }
    return state;
}
