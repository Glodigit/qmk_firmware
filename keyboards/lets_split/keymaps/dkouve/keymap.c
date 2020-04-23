#include QMK_KEYBOARD_H


//DkOuvE Default Keymap v1.0

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY   0
#define _LVL1     1
#define _FUNCTION 2
#define _PLOVER   3
#define _SKETCH   4
#define _ASSEMBLE 5
#define _NMBERPAD 6

#define L1  OSL(_LVL1)
#define FN  MO(_FUNCTION)

#define FUSION TO(_SKETCH)
#define SKETCH TO(_SKETCH) //I know it's reduntant but it's more readable.
#define ASSMBL TO(_ASSEMBLE)
#define PADtg TG(_NMBERPAD)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  //LVL1,
  PLOVER,
  //FUNCTION,
  EXT_PLV,
  //ASSMBL,
  //SKETCH,
  //PAD,
  EXT_F360
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
 * | Esc  |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Ctrl |  FN  | GUI  | Alt  |Level1|Space |  | Bksp |Enter | Left |  Up  | Down |Right |
 * `------------------------------------------  ------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,        KC_Q,   KC_W,    KC_E,     KC_R,   KC_T,           KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,     KC_BSPC,       \
  KC_ESC,        KC_A,   KC_S,    KC_D,     KC_F,   KC_G,           KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_QUOTE,      \
  OSM(MOD_LSFT), KC_Z,   KC_X,    KC_C,     KC_V,   KC_B,           KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  OSM(MOD_RSFT), \
  KC_LCTL,         FN,   KC_LGUI, KC_LALT,  L1     ,KC_SPC,         KC_BSPC,KC_ENT, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT        \
),

/* LVL1
 * ,------------------------------------------  ------------------------------------------.
 * |      |   !  |   @  |   £  |   $  |   %  |  |   ^  |   &  |   *  |   (  |   )  |Sleep |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Caps |  \   |   [  |   ]  |   {  |   }  |  |      |      |   -  |   +  |   =  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |  |      |      |      | Vol- | Vol+ | Mute |
 * `------------------------------------------  ------------------------------------------'
 */
[_LVL1] = LAYOUT( \
  XXXX,          KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_SLEP, \
  XXXX,          KC_1,     KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXX   , \
  KC_CAPS,       KC_BSLS,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,      XXXX   , XXXX,    KC_MINS, KC_PPLS, KC_EQL,  XXXX,    \
  OSM(MOD_LCTL), XXXX,     XXXX,    XXXX,    XXXX,    XXXX,         XXXX   , XXXX,    XXXX,    KC_VOLD, KC_VOLU, KC_MUTE  \
),

/* Function Layer
 * ,------------------------------------------  ------------------------------------------.
 * |Reset |      |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      | Ctl+1| Ctl+2| Ctl+3| Ctl+4| Ctl+5|  | Ctl+6| Ctl+7| Ctl+8| Ctl+9| Ctl+0| F12  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |BRI-DN|BRI-UP|  |ScDim |ScBri |Dedent|AdTime|      |Indent|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |......|      |      |Fusion|Plover|  | Del  |      | Home | pgup | pgdn | End  |
 * `------------------------------------------  ------------------------------------------'
 */
[_FUNCTION] = LAYOUT( \
  RESET  , XXXX,      KC_F2,     KC_F3,     KC_F4,     KC_F5,           KC_F6,     KC_F7,     KC_F8,     KC_F9,     RESET,     KC_F11,   \
  XXXX   , LCTL(KC_1),LCTL(KC_2),LCTL(KC_3),LCTL(KC_4),LCTL(KC_5),      LCTL(KC_6),LCTL(KC_7),LCTL(KC_8),LCTL(KC_9),LCTL(KC_0),KC_F12,   \
  XXXX   , XXXX,      XXXX,      XXXX,      RGB_VAD,   RGB_VAI,         KC_BRID,  KC_BRIU,      DEDENT,    ADTIME,    XXXX,      INDENT, \
  XXXX   , _______,   XXXX,      XXXX,      FUSION,    PLOVER,          KC_DEL,    XXXX,      KC_HOME,   KC_PGUP,   KC_PGDN,   KC_END    \
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
  XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX   , \
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX,     XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX  \
),



/* Fusion 360 Sketch layer
 * ,------------------------------------------
 * |  TAB |SFT+Q |SFT+W |SFT+E | 123  |ASSMBL|
 * |------+------+------+------+------+------|
 * |  ESC |SFT+A |SFT+S |SFT+D |SFT+F |  O   |
 * |------+------+------+------+------+------|
 * | Exit |SFT+Z |SFT+X |SFT+| |SFT+V |  P   |
 * |------+------+------+------+------+------|
 * |      |  R   |  C   |  L   |  D   |  X   |
 * `------------------------------------------
 */
// The P key and ; are swapped in registry
[_SKETCH] = LAYOUT ( \
  KC_TAB,   LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E),      PADtg,      ASSMBL,      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, \
  KC_ESC,   LSFT(KC_A), LSFT(KC_S), LSFT(KC_D),      LSFT(KC_F), KC_O,        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, \
  EXT_F360, LSFT(KC_Z), LSFT(KC_X), LSFT(KC_BSLASH), LSFT(KC_V), KC_SCLN,     XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, \
  XXXX,     KC_R,       KC_C,       KC_L,            KC_D,       KC_X,        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX  \
),



/* Fusion 360 Assemble layer
 * ,------------------------------------------
 * |  TAB |      |      |      |  123 |SKETCH|
 * |------+------+------+------+------+------|
 * |  ESC |  A   |  S   |      |  F   |  Q   |
 * |------+------+------+------+------+------|
 * | Exit |  C   |  V   |SFT+C |SFT+J |      |
 * |------+------+------+------+------+------|
 * |  CTL |  ALT |  Z   |      |  J   |  E   |
 * `------------------------------------------
 */

[_ASSEMBLE] = LAYOUT ( \
  KC_TAB,   XXXX,    XXXX,  XXXX,       PADtg,      SKETCH,      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, \
  KC_ESC,   KC_A,    KC_S,  XXXX,       KC_F,       KC_Q,        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, \
  EXT_F360, KC_C,    KC_V,  LSFT(KC_C), LSFT(KC_J), XXXX,        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, \
  KC_LCTL , KC_LALT, KC_Z,  XXXX,       KC_J,       KC_E,        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX  \
),


/* Fusion 360 Numberpad layer
 * ,------------------------------------------
 * |  TAB |  D   |  (   |  )   | ...  | bksp |
 * |------+------+------+------+------+------|
 * |  ESC |  1   |  2   |  3   |  4   |  5   |
 * |------+------+------+------+------+------|
 * | Exit |  6   |  7   |  8   |  9   |  0   |
 * |------+------+------+------+------+------|
 * | <--  | -->  |  /   |  *   |  -   |  +   |
 * `------------------------------------------
 */

[_NMBERPAD] = LAYOUT ( \
  KC_TAB,   KC_D,    KC_LPRN, KC_RPRN, PADtg,   KC_BSPC,     XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, \
  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, \
  EXT_F360, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, \
  KC_LEFT , KC_RIGHT,KC_SLSH, KC_ASTR, KC_MINS, KC_PPLS,     XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX  \
),
};



void matrix_init_user() {
    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
    rgblight_enable();
    rgblight_increase_val();
}

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  if (old_layer != new_layer) {
    switch (new_layer) {
      case _QWERTY:
        //rgblight_setrgb(0x22, 0x22, 0x22);
        rgblight_enable(); //allows rgb brightness controls to work on layer
        break;
        case _FUNCTION:
            rgblight_setrgb(0x00, 0x00, 0x20);
            break;
        case _LVL1:
            rgblight_setrgb(0x20, 0x10, 0x00); //nice golden shade of yellow
            break;
        case _PLOVER:
            rgblight_setrgb(0x10, 0x00, 0x20);
            break;
        case _SKETCH:
            rgblight_setrgb(0x24, 0x06, 0x00); //Orange
            // middle white
            rgblight_setrgb_at(0x10, 0x10, 0x10, 7);
            rgblight_setrgb_at(0x10, 0x10, 0x10, 8);
            rgblight_setrgb_at(0x10, 0x10, 0x10, 9);
            break;
        case _NMBERPAD:
            rgblight_setrgb(0x24, 0x06, 0x00); //Orange
            //middle blue like function laer
            rgblight_setrgb_at(0x04, 0x04, 0x18, 7);
            rgblight_setrgb_at(0x04, 0x04, 0x18, 8);
            rgblight_setrgb_at(0x04, 0x04, 0x18, 9);
            break;
        case _ASSEMBLE:
            rgblight_setrgb(0x24, 0x06, 0x00); //Orange
            //middle lilac
            rgblight_setrgb_at(0x11, 0x04, 0x11, 7);
            rgblight_setrgb_at(0x11, 0x04, 0x11, 8);
            rgblight_setrgb_at(0x11, 0x04, 0x11, 9);
        break;
    }

    //one of the leds is slightly defective, so make that one black.
    //other one is for symmetry
    //rgblight_setrgb_at(0x00, 0x00, 0x00, 2);
    //rgblight_setrgb_at(0x00, 0x00, 0x00, 31);


    old_layer = new_layer;
  }

  #endif //RGBLIGHT_ENABLE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
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
    case EXT_F360:
      if (record->event.pressed) {
        layer_off(_SKETCH);
        layer_off(_ASSEMBLE);
        layer_off(_NMBERPAD);
      }
      return false;
      break;
  }
  return true;
}
