#include QMK_KEYBOARD_H
#include "dlip.h"


//Glodigit Keymap

#define _BASE   0
#define _TAIPO  1
#define _FN 5

#define XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Test layer
 * ,------------------------------------------  ------------------------------------------.
 * |RESET |  Z   |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |TAIPO |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  Q   |      |      |      |      |  |      |      |      |      |      |      |
 * `------------------------------------------  ------------------------------------------'
*/
[_BASE] = LAYOUT_ortho_4x12( \
     QK_BOOT,    KC_Z, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  \
  TG(_TAIPO), _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  \
     _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  \
     _______,    KC_Q, _______, _______, _______, TG(_FN),     _______, _______, _______, _______, _______, _______   \
),

/* Taipo Layer
 * ,------------------------------------------  ------------------------------------------.
 * |      |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|  |XXXXXX|XXXXXX|XXXXXX|XXXXXX| TAB  | ESC  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | TAIPO| TR   | TM   | TI   |XXXXXX|XXXXXX|  |XXXXXX|XXXXXX| TI   | TM   | TR   | TAIPO|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | TP   | BR   | BM   | BI   |XXXXXX|XXXXXX|  |XXXXXX|XXXXXX| BI   | BM   | BR   | TP   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | LP   |XXXXXX|XXXXXX| IT   | OT   |      |  |      | IT   | OT   |XXXXXX|XXXXXX| LP   |
 * `------------------------------------------  ------------------------------------------'
*/
[_TAIPO] = LAYOUT_ortho_4x12( \
     _______, _______,    XXXX,    XXXX,     XXXX,    XXXX,     XXXX,      XXXX,   XXXX,   XXXX,   KC_TAB, KC_ESCAPE,  \
  TG(_TAIPO),  TP_TLR,  TP_TLM,   TP_TLI,    XXXX,    XXXX,     XXXX,      XXXX,   TP_TRI, TP_TRM, TP_TRR, TG(_TAIPO), \
      TP_TLP,  TP_BLR,  TP_BLM,   TP_BLI,    XXXX,    XXXX,     XXXX,      XXXX,   TP_BRI, TP_BRM, TP_BRR, TP_TRP,     \
      TP_BLP,    XXXX,    XXXX,   TP_LIT,  TP_LOT, _______,     _______,   TP_ROT, TP_RIT, XXXX,   XXXX,   TP_BRP      \
),

/* Test function layer
 * ,------------------------------------------  ------------------------------------------.
 * |RESET |  W   |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |TAIPO |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  X   |      |      |      |      |  |      |      |      |      |      |      |
 * `------------------------------------------  ------------------------------------------'
*/
[_FN] = LAYOUT_ortho_4x12( \
     QK_BOOT,    KC_W, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  \
  TG(_TAIPO), _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  \
     _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  \
     _______,    KC_X, _______, _______, _______, TG(_FN),     _______, _______, _______, _______, _______, _______   \
),

};

void matrix_scan_user(void) {
  #ifdef TAIPO_ENABLE
  if (get_highest_layer(layer_state) == _TAIPO) {
    taipo_matrix_scan_user();
  }
  #endif
};

#ifdef TAIPO_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (get_highest_layer(layer_state) == _TAIPO) {
        switch (keycode)
        {
        case TP_TLP ... TP_ROT:
          return taipo_process_record_user(keycode, record);
          break;
        
        default:
          return true;
          break;
        }
        
    } else {
        return true;
    }
};
#endif
