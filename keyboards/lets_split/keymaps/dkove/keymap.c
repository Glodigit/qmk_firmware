#include QMK_KEYBOARD_H


//DkOuvE Default Keymap v0.1

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LVL1 3
#define _FUNCTION 4
#define _PLOVER 10

#define L1  OSM(_LVL1)
#define FN  MO(_FUNCTION)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LVL1,
  PLOVER,
  FUNCTION,
  EXT_PLV
};



// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR  LCTL(LSFT(KC_ESC))
#define ADTIME  LALT(LSFT(KC_T))
#define INDENT  LSFT(LALT(KC_RIGHT))
#define DEDENT  LSFT(LALT(KC_LEFT))

#define XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------  ------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ?  |  '   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   !  |Shift |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Ctrl |  FN  | GUI  | Alt  |Space |Enter |  |Level1| Bksp | Left |  Up  | Down |Right |
 * `------------------------------------------  ------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,        KC_Q,   KC_W,    KC_E,     KC_R,   KC_T,   KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,     KC_BSPC,       \
  KC_ESC,        KC_A,   KC_S,    KC_D,     KC_F,   KC_G,   KC_H,   KC_J,       KC_K,    KC_L,    KC_QUES,  KC_QUOTE,      \
  OSM(MOD_LSFT), KC_Z,   KC_X,    KC_C,     KC_V,   KC_B,   KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_EXLM,  OSM(MOD_RSFT), \
  KC_LCTL,         FN,   KC_LGUI, KC_LALT,  KC_SPC, KC_ENT, L1,     KC_BSPC,    KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT        \
),

/* LVL1
 * ,------------------------------------------  ------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |  |   ^  |   &  |   *  |   (  |   )  |Sleep |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Caps |  \   |   [  |   ]  |   {  |   }  |  |   :  |   ;  |   -  |   +  |   =  |  /   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |  |......|      |      | Vol- | Vol+ | Mute |
 * `------------------------------------------  ------------------------------------------'
 */
[_LVL1] = LAYOUT( \
  XXXX,          KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_SLEP, \
  XXXX,          KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXX   , \
  KC_CAPS,       KC_BSLS,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_COLN, KC_SCLN, KC_MINS, KC_PPLS, KC_EQL,  KC_SLSH, \
  OSM(MOD_LCTL), XXXX,     XXXX,    XXXX,    XXXX,    XXXX,    _______, XXXX,    XXXX,    KC_VOLD, KC_VOLU, KC_MUTE  \
),

/* Function Layer
 * ,------------------------------------------  ------------------------------------------.
 * |Plover|      |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |Reset | Ctl+1| Ctl+2| Ctl+3| Ctl+4| Ctl+5|  | Ctl+6| Ctl+7| Ctl+8| Ctl+9| Ctl+0| F12  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |BRI-DN|  Dim |  |Bright|BRI-UP|Dedent|AdTime|      |Indent|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |......|      |      |      |      |  | Del  |      | Home | pgup | pgdn | End  |
 * `------------------------------------------  ------------------------------------------'
 */
[_FUNCTION] = LAYOUT( \
  PLOVER , XXXX,      KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     RESET,     KC_F11, \
  RESET  , LCTL(KC_1),LCTL(KC_2),LCTL(KC_3),LCTL(KC_4),LCTL(KC_5),LCTL(KC_6),LCTL(KC_7),LCTL(KC_8),LCTL(KC_9),LCTL(KC_0),KC_F12, \
  XXXX   , XXXX,      XXXX,      XXXX,      RGB_VAD,   KC_BRID,   KC_BRIU,   RGB_VAI,   DEDENT,    ADTIME,    XXXX,      INDENT, \
  XXXX   , _______,   XXXX,      XXXX,      XXXX,      XXXX,      KC_DEL,    XXXX,      KC_HOME,   KC_PGUP,   KC_PGDN,   KC_END  \
),


/* Plover layer (http://opensteno.org)
 * ,------------------------------------------  ------------------------------------------.
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |      |  |      |   E  |   U  |      |      |      |
 * `------------------------------------------  ------------------------------------------'
 */

[_PLOVER] = LAYOUT ( \
  XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX   , \
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX  \
),
};


void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LVL1:
      if (record->event.pressed) {
        //add backlight code here
        //rgblight_setrgb(0x00, 0x00, 0xFF);
      } else {
        //turn off backlight
        //rgblight_setrgb(0x00, 0x00, 0x00);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        layer_off(_LVL1);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
