#include QMK_KEYBOARD_H
#include "taipo.h"


//Glodigit Default Keymap v1.0

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE   0
#define _TAIPO  1

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
     _______,    KC_Q, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______   \
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

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(_TAIPO)) {
        return taipo_process_record_user(keycode, record);
    }  else {
        return true;
    }
};

void matrix_scan_user(void) {
    taipo_matrix_scan_user();
}

