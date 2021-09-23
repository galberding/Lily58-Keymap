#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};


enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
    MY_OTHER_MACRO,
    CYCLE_BUFFER,
    WIN_UP,
    WIN_DOWN,
    WIN_LEFT,
    WIN_RIGHT,
    FAST_MOVE_UP,
    FAST_MOVE_DOWN,
    FAST_MOVE_LEFT,
    FAST_MOVE_RIGHT,
    BUF_LEFT,
    BUF_RIGHT,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | ctrl |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RCTRL, \
  KC_LSPO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                 KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,               KC_ENT, MO(_RAISE), KC_BSPC, KC_RALT	\
		     ),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      | F3   |  F4  |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  UP  |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Left | Down | Right|   $  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  | ctrl |
 * |------+------+------+------+------+------|   [   |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   ' |   _  |   +  |   {  |      | shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_F3, KC_F4, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  XXXXXXX,  XXXXXXX, KC_HOME,  KC_UP,   KC_END, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOTE, KC_UNDS , KC_PLUS, KC_LCBR, KC_RCBR, _______, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |        F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |  \   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                            KC_F6, KC_F7, KC_F8, KC_F9, XXXXXXX, XXXXXXX, \
  _______, _______, BUF_LEFT, WIN_UP, BUF_RIGHT, _______,                     _______, _______, _______, _______, _______, _______, \
  _______,  KC_F2,    WIN_LEFT,   WIN_DOWN,   WIN_RIGHT,   KC_F6,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______,   KC_F8,   XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_BSLS, _______, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | c up |      |      |                    |      | Vol- |      | Vol+ |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | c l  |c down|c r   |      |-------.    ,-------|      | Prev | Play | Next |      |      |
 * |------+------+------+------+------+------|       |    | Ins   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_PGUP, FAST_MOVE_UP, KC_PGDOWN, XXXXXXX,                   XXXXXXX, KC_AUDIO_VOL_DOWN, XXXXXXX, KC_AUDIO_VOL_UP, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, FAST_MOVE_LEFT, FAST_MOVE_DOWN, FAST_MOVE_RIGHT, XXXXXXX,  XXXXXXX, KC_MEDIA_PREV_TRACK,  KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,  XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  /* if (is_keyboard_master()) { */
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  /* } else { */
  /*   oled_write(read_logo(), false); */
  /* } */
    if (!is_keyboard_master()){
      oled_write_ln(read_layer_state(), false);
    }
}
#endif // OLED_DRIVER_ENABLE

void windmove(uint16_t keycode, keyrecord_t *record){
  if (record->event.pressed) {
	// when keycode QMKURL is pressed
 	register_code(KC_LSFT);
	register_code(keycode);
      } else {
            // when keycode QMKURL is released
	unregister_code(KC_LSFT);
	unregister_code(keycode);
      }
}

void switchBuf(uint16_t keycode, keyrecord_t *record){
  if (record->event.pressed) {
	// when keycode QMKURL is pressed
 	register_code(KC_LCTRL);
	register_code(KC_X);
      } else {
            // when keycode QMKURL is released
	unregister_code(KC_LCTRL);
	unregister_code(KC_X);
	tap_code(keycode);
      }
}

void ctrlMove(uint16_t keycode, keyrecord_t *record){
  if (record->event.pressed) {
    // when keycode QMKURL is pressed
    register_code(KC_LCTRL);
    register_code(keycode);
    /* register_code(KC_X); */
  } else {
    // when keycode QMKURL is released
    /* tap_code(keycode); */
    unregister_code(keycode);
    unregister_code(KC_LCTRL);
    /* unregister_code(KC_X); */
  }
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("QMK is the best ZZZZzzzzing ever!");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case QMKURL:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING("https://qmk.fm/\n");
        } else {
            // when keycode QMKURL is released
        }
        break;

    case MY_OTHER_MACRO:
        if (record->event.pressed) {
	  /* SEND_STRING(LSFT(KC_LEFT)); // selects all and copies */
        }
        break;
    case WIN_LEFT:
      windmove(KC_LEFT, record);
      break;
    case WIN_RIGHT:
      windmove(KC_RIGHT, record);
      break;
    case WIN_UP:
      windmove(KC_UP, record);
      break;
    case WIN_DOWN:
      windmove(KC_DOWN, record);
      break;
    case FAST_MOVE_LEFT:
      ctrlMove(KC_LEFT, record);
      break;
    case FAST_MOVE_RIGHT:
      ctrlMove(KC_RIGHT, record);
      break;
    case FAST_MOVE_UP:
      ctrlMove(KC_UP, record);
      break;
    case FAST_MOVE_DOWN:
      ctrlMove(KC_DOWN, record);
      break;
    case BUF_LEFT:
      switchBuf(KC_LEFT, record);
      break;
    case BUF_RIGHT:
      switchBuf(KC_RIGHT, record);
      break;

    }
  return true;
}
