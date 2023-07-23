#include QMK_KEYBOARD_H

/* 
 * MAKE SURE THE LAYER INDICES BELOW MATCH WHAT'S LISTED FOR OLED SCREEN
 *
 * Layers from `lib/layer_state_reader_vim.c`
 * #define L_INSERT 0
 * #define L_NORMAL 1
 * #define L_SHFT_NORMAL 2
 * #define L_VISUAL 3
 * #define L_MOVE_TOP 4
 * #define L_FUNCTION 5
 * #define L_QUICK_MOVE 6
 * #define L_PAGE_SCROLL 7
 */

enum layer_number {
  _INS = 0,
  _NRML,
  _SFT_NRML,
  _VSUAL,
  _MV_TP,
  _FNCTN,
  _QK_MV,
  _PG_SCRL
};

/* 

 INSERT (LAYER <INDEX>)

 LAYOUT TEMPLATE WITH ALL BLANKS

   *     ,-----------------------------------------.                        ,-----------------------------------------.
   *     |      |      |      |      |      |      |                        |      |      |      |      |      |      |
   *     |------+------+------+------+------+------|                        |------+------+------+------+------+------|
   *     |      |      |      |      |      |      |                        |      |      |      |      |      |      |
   *     |------+------+------+------+------+------|                        |------+------+------+------+------+------|
   *     |      |      |      |      |      |      |-------.        ,-------|      |      |      |      |      |      |
   *     |------+------+------+------+------+------|       |        |       |------+------+------+------+------+------|
   *     |      |      |      |      |      |      |-------|        |-------|      |      |      |      |      |      |
   *     `-----------------------------------------/       /         \      \-----------------------------------------'
   *                       |      |      |      | /       /           \      \  |      |      |      |
   *                       |      |      |      |/       /             \      \ |      |      |      |
   *                       `----------------------------'               '------''--------------------'

  LAYOUT MATRIX WITH ALL BLANKS
  
  [_LAYER_NAME] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                             KC_NO,  KC_NO,  KC_NO,  KC_NO,           KC_NO,  KC_NO,  KC_NO,  KC_NO
  ),

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* INSERT (LAYER 0)
   *      ,-----------------------------------------.                        ,-----------------------------------------.
   *      |  `   |   1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  | BKSP |
   *      |------+------+------+------+------+------|                        |------+------+------+------+------+------|
   *      | Tab  |   Q  |   W  |   E  |   R  |   T  |                        |   Y  |   U  |   I  |   O  |   P  | DEL  |
   *      |------+------+------+------+------+------|                        |------+------+------+------+------+------|
   *      |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.        ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
   *      |------+------+------+------+------+------|  FN   |        | RSHFT |------+------+------+------+------+------|
   *      |LSHFT |   Z  |   X  |   C  |   V  |   B  |-------|        |-------|   N  |   M  |   ,  |   .  |   /  |ENTER |
   *      `-----------------------------------------/       /         \      \-----------------------------------------'
   *                        | LCTL | LALT | LGUI | / QUICK /           \SPACE \  | ESC  | LGUI | RCTL |
   *                        |      |      |      |/  MOVE /             \      \ |      |      |      |
   *                        `----------------------------'               '------''--------------------'
   */
  [_INS] = LAYOUT(
    KC_GRV,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    TG(_NRML), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(_FNCTN),  KC_RSFT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
                          KC_LCTL, KC_LALT, KC_LGUI, MO(_QK_MV),       KC_SPC, KC_ESC, KC_RGUI, KC_RCTL
  ),

  /* NORMAL (LAYER 1)
   *                          ,-----------------------------------------.                                ,-----------------------------------------.
   *                          |      |      |      |      |      |      |                                |      |      |      |      |      |      |
   *                          |------+------+------+------+------+------|                                |------+------+------+------+------+------|
   *                          |INSERT|      |WD END|WD END|      |      |                                |      |      |INSERT|      |      |      |
   *                          |------+------+------+------+------+------|                                |------+------+------+------+------+------|
   *                          |SFT NM|      |      |      |      |MV TOP|-------.                ,-------|RIGHT | DOWN |  UP  |RIGHT |      |      |
   *                          |------+------+------+------+------+------|       |                |SFT NM|------+------+------+------+------+------|
   *                          |      |      |      |      |VISUAL|WD BEG|-------|                |-------| RSFT |      |      |      |      |      |
   *                          `-----------------------------------------/       /                 \      \-----------------------------------------'
   *                                            |PG SCL|      |      | /       /                   \      \  |INSERT|      |PG SCL|
   *                                            |      |      |      |/       /                     \      \ |      |      |      |
   *                                            `----------------------------'                       '------''--------------------'
   */
  [_NRML] = LAYOUT(
    KC_NO,         KC_NO,  KC_NO,          KC_NO,         KC_NO,         KC_NO,                                 KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,
    KC_NO,       KC_NO,  RALT(KC_RGHT),  RALT(KC_RGHT), KC_NO,         KC_NO,                                 KC_NO,   KC_NO,   TO(_INS),  KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,  KC_NO,          KC_NO,         KC_NO,         OSL(_MV_TP),                           KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT, KC_NO,   KC_NO,
    MO(_SFT_NRML),         KC_NO,  KC_NO,          KC_NO,         TO(_VSUAL),    RALT(KC_LEFT), KC_NO,   MO(_SFT_NRML), KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,
                                                      MO(_PG_SCRL), KC_NO,  KC_NO,  KC_NO,             KC_NO,  TO(_INS),  KC_NO,  MO(_PG_SCRL)
  ),

  /* SHIFT NORMAL (LAYER 2)
   *             ,-----------------------------------------.                     ,-----------------------------------------.
   *             |      |      |      |      |LN END|      |                     |LN BEG|      |      |      |      |      |
   *             |------+------+------+------+------+------|                     |------+------+------+------+------+------|
   *             |      |      |      |      |      |      |                     |      |      |      |      |      |      |
   *             |------+------+------+------+------+------|                     |------+------+------+------+------+------|
   *             |      |      |      |      |      |BOTTOM|-------.     ,-------|      |      |      |      |      |      |
   *             |------+------+------+------+------+------|       |     |       |------+------+------+------+------+------|
   *             |      |      |      |      |      |      |-------|     |-------|      |      |      |      |      |      |
   *             `-----------------------------------------/       /      \      \-----------------------------------------'
   *                               |      |      |      | /       /        \      \  |      |      |      |
   *                               |      |      |      |/       /          \      \ |      |      |      |
   *                               `----------------------------'            '------''--------------------'
   */
  [_SFT_NRML] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGUI(KC_RGHT), KC_NO,                   LGUI(KC_LEFT), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,                   KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         RGUI(KC_DOWN),           KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,  KC_NO,   KC_NO,  KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                   KC_NO,  KC_NO,  KC_NO,  KC_NO,           KC_NO,  KC_NO,  KC_NO,  KC_NO
  ),

  /* VISUAL (LAYER 3)
   *                       ,-----------------------------------------.                                ,-----------------------------------------.
   *                       |      |      |      |      |SLT LE|      |                                |SLT LB|      |      |      |      |      |
   *                       |------+------+------+------+------+------|                                |------+------+------+------+------+------|
   *                       |      |      |SLT WD|SLT WE|      |      |                                |      |      |INSERT|      |      |      |
   *                       |------+------+------+------+------+------|                                |------+------+------+------+------+------|
   *                       |      |      |      |      |      |      |-------.                ,-------|SLT LF|SLT DN|SLT UP|SLT RT|      |      |
   *                       |------+------+------+------+------+------|       |                |       |------+------+------+------+------+------|
   *                       |      |      |      |      |      |SLT WB|-------|                |-------|      |      |      |      |      |      |
   *                       `-----------------------------------------/       /                 \      \-----------------------------------------'
   *                                         |      |      |      | /       /                   \      \  |NORMAL|      |      |
   *                                         |      |      |      |/       /                     \      \ |      |      |      |
   *                                         `----------------------------'                       '------''--------------------'
   */
  [_VSUAL] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,               KC_NO,                LSFT(LGUI(KC_RGHT)), KC_NO,                                 LSFT(LGUI(KC_LEFT)),  KC_NO,           KC_NO,          KC_NO,           KC_NO,   KC_NO,
    KC_NO,   KC_NO,   LSFT(LALT(KC_RGHT)), LSFT(LALT(KC_RGHT)),  KC_NO,               KC_NO,                                 KC_NO,                KC_NO,           TO(_INS),       KC_NO,           KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,               KC_NO,                KC_NO,               KC_NO,                                 LSFT(KC_LEFT),        LSFT(KC_DOWN),   LSFT(KC_UP),    LSFT(KC_RGHT),   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,               KC_NO,                KC_NO,               LSFT(LALT(KC_LEFT)), KC_NO,    KC_NO,  KC_NO,                KC_NO,           KC_NO,          KC_NO,           KC_NO,   KC_NO,
                                                                             KC_NO,  KC_NO,  KC_NO,  KC_NO,                KC_NO,  TO(_NRML),   KC_NO,  KC_NO
  ),

  /* MOVE TOP (LAYER 4)
   *       ,-----------------------------------------.                        ,-----------------------------------------.
   *       |      |      |      |      |      |      |                        |      |      |      |      |      |      |
   *       |------+------+------+------+------+------|                        |------+------+------+------+------+------|
   *       |      |      |      |      |      |      |                        |      |      |      |      |      |      |
   *       |------+------+------+------+------+------|                        |------+------+------+------+------+------|
   *       |      |      |      |      |      | TOP  |-------.        ,-------|      |      |      |      |      |      |
   *       |------+------+------+------+------+------|       |        |       |------+------+------+------+------+------|
   *       |      |      |      |      |      |      |-------|        |-------|      |      |      |      |      |      |
   *       `-----------------------------------------/       /         \      \-----------------------------------------'
   *                         |      |      |      | /       /           \      \  |      |      |      |
   *                         |      |      |      |/       /             \      \ |      |      |      |
   *                         `----------------------------'               '------''--------------------'
   */
  [_MV_TP] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   LGUI(KC_UP),                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                  KC_NO,  KC_NO,  KC_NO,  KC_NO,           KC_NO,  KC_NO,  KC_NO,  KC_NO
  ),

  /* FUNCTION (LAYER 5)
   *   ,-----------------------------------------.                          ,-----------------------------------------.
   *   |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |                          |  F6  |  F7  |  F8  |  F9  | F10  | PLAY |
   *   |------+------+------+------+------+------|                          |------+------+------+------+------+------|
   *   |      |      |      |      |      |      |                          |      |      |INSERT|      |      | NEXT |
   *   |------+------+------+------+------+------|                          |------+------+------+------+------+------|
   *   |      |      |      |      |      |      |-------.          ,-------|      |      |      |      |      | VOL+ |
   *   |------+------+------+------+------+------|       |          |       |------+------+------+------+------+------|
   *   |      |      |      |      |      |      |-------|          |-------|      |      |      |      |      | VOL- |
   *   `-----------------------------------------/       /           \      \-----------------------------------------'
   *                     |      |      |      | /       /             \      \  |NORMAL|      |      |
   *                     |      |      |      |/       /               \      \ |      |      |      |
   *                     `----------------------------'                 '------''--------------------'
   */
  [_FNCTN] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_MPLY,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   TO(_INS), KC_NO,   KC_NO,   KC_MNXT,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_VOLU,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_VOLD,
                             KC_NO,  KC_NO,  KC_NO,  KC_NO,           KC_NO,  TO(_NRML),  KC_NO,  KC_NO
  ),

  /* QUICK MOVE (LAYER 6)
   *                    ,-----------------------------------------.                                            ,-----------------------------------------.
   *                    |      |      |      |      |LN END|      |                                            |LN BEG|      |      |  -   |  +   | BSPC |
   *                    |------+------+------+------+------+------|                                            |------+------+------+------+------+------|
   *                    |      |      |WD END|WD END|      |      |                                            |      |      |INSERT|  [   |  ]   | BSLS |
   *                    |------+------+------+------+------+------|                                            |------+------+------+------+------+------|
   *                    |      |      |      |      |      |      |-------.                            ,-------|RIGHT | DOWN |  UP  |RIGHT |      |      |
   *                    |------+------+------+------+------+------|       |                            | RSFT  |------+------+------+------+------+------|
   *                    | LSFT |      |      |      |      |WD BEG|-------|                            |-------|      |      |      |      |      |      |
   *                    `-----------------------------------------/       /                             \      \-----------------------------------------'
   *                                      | LCTL | LAlt | LGUI | /       /                               \      \  |NORMAL| RGUI | RCTL |
   *                                      |      |      |      |/       /                                 \      \ |      |      |      |
   *                                      `----------------------------'                                   '------''--------------------'
   */
  [_QK_MV] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,           KC_NO,         RGUI(KC_RGHT), KC_NO,                                LGUI(KC_LEFT), KC_NO,   KC_NO,    KC_MINS, KC_EQL, KC_BSPC,
    KC_NO,   KC_NO,   RALT(KC_RGHT),   RALT(KC_RGHT), KC_NO,         KC_NO,                                KC_NO,         KC_NO,   TO(_INS), KC_LBRC, KC_RBRC, KC_BSLS,
    KC_NO,   KC_NO,   KC_NO,           KC_NO,         KC_NO,         KC_NO,                                KC_LEFT,       KC_DOWN, KC_UP,    KC_RGHT, KC_NO,   KC_NO,
    KC_LSFT, KC_NO,   KC_NO,           KC_NO,         KC_NO,         RALT(KC_LEFT),  KC_NO,       KC_RSFT, KC_NO,         KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
                                                  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_NO,                KC_NO, TO(_NRML), KC_RGUI, KC_RCTL
  ),

  /* PAGE SCROLL (LAYER 7)
   * ,-----------------------------------------.                           ,-----------------------------------------.
   * |      |      |      |      |      |      |                           |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                           |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                           |      |PG UP |INSERT|      |      |      |
   * |------+------+------+------+------+------|                           |------+------+------+------+------+------|
   * |      |      |      |PG DN |      |      |-------.           ,-------|      |      |      |      |      |      |
   * |------+------+------+------+------+------|       |           |       |------+------+------+------+------+------|
   * |      |      |      |      |      |      |-------|           |-------|      |      |      |      |      |      |
   * `-----------------------------------------/       /            \      \-----------------------------------------'
   *                   |      |      |      | /       /              \      \  |NORMAL|      |      |
   *                   |      |      |      |/       /                \      \ |      |      |      |
   *                   `----------------------------'                  '------''--------------------'
   */
  [_PG_SCRL] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,         KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,         KC_PGUP, TO(_INS), KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_PGDN, KC_NO,   KC_NO,                   KC_NO,         KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,         KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
                             KC_NO,  KC_NO,  KC_NO,  KC_NO,           KC_NO, TO(_NRML), KC_NO,  KC_NO
  ),


};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_blank_line(void);
const char *read_layer_state(void);
const char *read_mode_icon(bool swap);

// Key logging to screen
void set_key(uint16_t keycode, keyrecord_t *record);
const char *read_key(void);
// const char *read_keylogs(void);

// Logo of Lily58
// const char *read_logo(void);

// RGB and other utilities
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_blank_line(), false);
    oled_write_ln(read_key(), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    // Originally just the Lily Log was used here
    // oled_write(read_logo(), false);

    // Let's do the OS mode wit logo instead
    oled_write_ln(read_blank_line(), false);
    oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
  }
    return false;
}
#endif // OLED_ENABLE

// This is to log the key pressed to the OLED screen
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef OLED_ENABLE
      set_key(keycode, record);
    #endif
    // set_timelog();
  }
  return true;
}
