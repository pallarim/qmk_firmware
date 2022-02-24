// Copyright 2022 Minna Pallari (@pallarim)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "keymap_finnish.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  CALCX,
  FNON,
};

enum unicode_names {
    BEER,
    BEERS
};

const uint32_t PROGMEM unicode_map[] = {
    [BEER]  = 0x1F37A,  // 🍺
    [BEERS] = 0x1F37B   // 🍻
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  TODO:
 * ┌───┬───┬───┬───┬───┬───┬───┬     ┌───┬───┬───┬───┬───┬───┬───┐
 * │ESC│ § | 1 │ 2 │ 3 │ 4 │ 5 │     │ 6 │ 7 │ 8 │ 9 │ 0 │ + │BS │
 * ├───|───|───|───|───|───|───|     │───|───|───|───|───|───|───|
 * │Rai│TAB| Q │ W │ E │ R │ T │     │ Y │ U │ I │ O │ P │ ´ │ ¨ │
 * ├───|───|───|───|───|───|───|     │───|───|───|───|───|───|───|
 * │Lwr│CPS│ A │ S │ D │ F │ G │     │ H │ J │ K │ L │ Ö │ Ä │ENT│
 * ├───|───|───|───|───|───|───|     │───|───|───|───|───|───|───|
 * │SFT│ < │ Z │ X │ C │ V │ B │     │ N │ M │ , │ . │ - │UP | ' |
 * ├───|───|───|───|───|───|───|     │───|───|───|───|───|───|───|
 * │CTR│FN │WIN│ALT│BER│  SPC  │     │  SPC  │AGR│CTR│LF │DN │RG │
 * └───┴───┴───┴───┴───┴───┴───┴     └───┴───┴───┴───┴───┴───┴───┘
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_ESC,  KC_GRV , KC_1   , KC_2   , KC_3   ,          KC_4   , KC_5   ,    KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , FI_PLUS, KC_BSPC ,
    RAISE,   KC_TAB , KC_Q   , KC_W   , KC_E   ,          KC_R   , KC_T   ,    KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , FI_ACUT, FI_DIAE,
    LOWER,   KC_CAPS, KC_A   , KC_S   , KC_D   ,          KC_F   , KC_G   ,    KC_H   , KC_J   , KC_K   , KC_L   , FI_ODIA, FI_ADIA, KC_ENT ,
    KC_LSFT, FI_LABK, KC_Z   , KC_X   , KC_C   ,          KC_V   , KC_B   ,    KC_N   , KC_M   , KC_COMM, KC_DOT , FI_MINS, KC_UP,   FI_QUOT ,
    KC_LCTL, ADJUST,  KC_LGUI, KC_LALT, XP(BEER, BEERS),  KC_SPC , KC_SPC ,    KC_SPC , KC_SPC , KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */

  [_LOWER] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   -  |   =  |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |ISO # |ISO / |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , KC_NUHS, KC_NUBS, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),

/*
 * ┌────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Mute│CAL| F1│F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│DEL│
 * ├────|───|───|───|───|───|───|───|───|───|───|───|───|───|
 * │MSel|   |My │Ma │Prv│Nxt│ 7 │ 8 │ 9 │ - │   │Prn│F12│   │
 * │    |   |Cmp│il │   │   │   │   │   │   │   │Scr│   │   │
 * ├────|───|───|───|───|───|───|───|───|───|───|───|───|───|
 * │Prev|   │   │   │   │   │ 4 │ 5 │ 6 │ + │RST│   │   │   │
 * │    |   │ Å │   │STP│PLY│   │   │   │   │   │   │   │   │
 * ├────|───|───|───|───|───|───|───|───|───|───|───|───|───|
 * │    │Mte│   │App│Vo-│Vo+│ 1 │ 2 │ 3 │ENT│   │   |PG |   │
 * │    │   │   │   │   │   │   │   │   │   │   │   |UP |   │
 * ├────|───|───|───|───|───|───|───|───|───|───|───|───|───|
 * │qwer│FN │RGB│   │       │ 0     │ . │ENT│ENT│UCR│PGD│UCM│
 * └────┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 */

  [_ADJUST] = LAYOUT_ortho_5x14(  
    KC_MUTE, CALCX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_DEL,
    KC_MSEL, KC_NO,   KC_MYCM, KC_MAIL, _______, KC_MPRV, KC_MNXT, KC_P7, KC_P8, KC_P9,   KC_MINS, _______, KC_F12,  _______, 
    FNON,    KC_NO,   FI_ARNG, _______, _______, KC_MSTP, KC_MPLY, KC_P4, KC_P5, KC_P6,   KC_PLUS, RESET,   _______, _______,
    _______, KC_MUTE, _______, KC_APP,  _______, KC_VOLD, KC_VOLU, KC_P1, KC_P2, KC_P3,   KC_PENT, _______, KC_PGUP, _______,
    QWERTY,  _______, _______, KC_NO,   _______, _______, KC_NO,   KC_P0, KC_NO, KC_PDOT, KC_PENT, UC_RMOD, KC_PGDN, UC_MOD
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case FNON:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
    case CALCX:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r") SS_DELAY(500) "calc\n" SS_DELAY(1000) "1337");
        break;
      }
  }
  return true;
}
