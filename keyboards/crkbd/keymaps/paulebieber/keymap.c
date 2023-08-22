#include QMK_KEYBOARD_H

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6
};

//Tap dance enums, custom keys
enum{
  ALT_OSL1 = 0,
};

//Base layer switches
enum BaseLayers{
    CODING = 0,
    GAMING,
    MAC
};

enum BaseLayers currentBase;

enum custom_keycodes {
    KC_CODING = SAFE_RANGE,
    KC_GAMING,
    KC_MAC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----ü---|
    KC_ESC, MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F,   KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,   KC_ENT, KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----ö---|
      KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+---,----+---.----+----_---+----ä---|
                                        KC_LGUI, KC_LSFT, TD(ALT_OSL1),  KC_BSPC, KC_SPC, KC_MPLY),
                                      //`--------------------------'  `--------------------------'

  [1] = LAYOUT_split_3x6_3(
  //-----------------------------------------------------.                    ,-----------------------------------------------------.
RALT(KC_Q), LSFT(KC_6), LSFT(KC_8), LSFT(KC_9), KC_EXLM, LSFT(KC_MINS),         LSFT(KC_0), KC_7,   KC_8,   KC_9,   KC_PSLS, KC_PAST,
  //|--------+--------+---(----+----)---+---!----+---?----|                    |----=---+----7---+----8---+---9----+----/----+---*----|
TO(0), KC_LCTL, RALT(KC_8), RALT(KC_9), KC_BSLS, LSFT(KC_2), LSFT(KC_5), KC_4,   KC_5,   KC_6,   KC_PMNS,  KC_PPLS,
  //|--------+--------+---[----+---]----+--------+--------|                    |----%---+----4---+----5---+----6---+----+---+---------|
KC_NUBS, LSFT(KC_NUBS), RALT(KC_7), RALT(KC_0), RALT(KC_RBRC), LSFT(KC_BSLS),       KC_0,    KC_1,     KC_2,   KC_3,   KC_DOT,   KC_GRV,
  //|----<---+--->----+---{----+----}---+--------+---'----+--------|  |--------+--------+--------+--------+--------+--------+---------|
                                        TO(2), KC_LSFT, KC_RALT,       KC_BSPC, KC_SPC, KC_NO),
                                      //`--------------------------'  `--------------------------'

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,                        KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(0), KC_LCTL,   KC_MRWD, KC_MPLY, KC_MFFD,  KC_MUTE,                    KC_LEFT, KC_DOWN , KC_UP, KC_RIGHT, KC_ENT, KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, LSFT(KC_4),  KC_MINS, KC_CODING,   KC_GAMING,   KC_MAC,             RALT(KC_NUBS), RALT(KC_MINS), RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI, KC_LSFT, KC_LALT,     KC_BSPC,  KC_SPC , KC_NO),
                                      //`--------------------------'  `--------------------------'

  //Gaming
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----ü---|
    KC_LSFT,     KC_A,   KC_S,    KC_D,      KC_F,   KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,   KC_UP, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----ö---|
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,  KC_COMM,  KC_LEFT, KC_DOWN, KC_RIGHT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+---,----+---.----+----_---+----ä---|
                                        KC_LCTL, KC_SPC, KC_SPC,       KC_LGUI, KC_CODING, KC_MPLY),
                                      //`--------------------------'  `--------------------------'

  //Mac special char layer
  [4] = LAYOUT_split_3x6_3(
  //-----------------------------------------------------.                    ,-----------------------------------------------------.
RALT(KC_Q), LSFT(KC_6), LSFT(KC_8), LSFT(KC_9), KC_EXLM, KC_MINS,               LSFT(KC_0), KC_7,   KC_8,   KC_9,   KC_PSLS, KC_PAST,
  //|--------+--------+---(----+----)---+---!----+---?----|                    |----=---+----7---+----8---+---9----+----/----+---*----|
TO(0),  MOD_LCTL, RALT(KC_5), RALT(KC_6), KC_BSLS, LSFT(KC_2),               LSFT(KC_5), KC_4,   KC_5,   KC_6,   KC_PMNS,  KC_PPLS,
  //|--------+--------+---[----+---]----+--------+--------|                    |----%---+----4---+----5---+----6---+----+---+---------|
KC_GRV, LSFT(KC_GRV), RALT(KC_8), RALT(KC_9), RALT(KC_RBRC), LSFT(KC_BSLS),       KC_0,    KC_1,     KC_2,   KC_3,   KC_DOT,   KC_NUBS,
  //|----<---+--->----+---{----+----}---+--------+---'----+--------|  |--------+--------+--------+--------+--------+--------+---------|
                                        TO(2), KC_LSFT, KC_RALT,       KC_BSPC, KC_SPC, KC_NO),
                                      //`--------------------------'  `--------------------------'
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =  { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)},
    [1] =  { ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN)},
    [2] =  { ENCODER_CCW_CW(RGB_VAI, RGB_VAD)},
    [3] =  { ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN)},
    [4] =  { ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN)},
};
#endif

int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->pressed) return SINGLE_HOLD;
    else return SINGLE_TAP;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8;
}

static tap alttap_state = {
  .is_press_action = true,
  .state = 0
};

void alt_finished (tap_dance_state_t *state, void *user_data) {
  alttap_state.state = cur_dance(state);
  switch (alttap_state.state) {
    case SINGLE_TAP:
            if(currentBase != MAC){
                set_oneshot_layer(1, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
            }else{
                set_oneshot_layer(4, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
            }
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP:
            if(currentBase != MAC){
                set_oneshot_layer(1, ONESHOT_START); set_oneshot_layer(1, ONESHOT_PRESSED); break;
            }else{
                set_oneshot_layer(4, ONESHOT_START); set_oneshot_layer(4, ONESHOT_PRESSED); break;
            }
    case DOUBLE_HOLD: register_code(KC_LALT); layer_on(1); break;
  }
}

void alt_reset (tap_dance_state_t *state, void *user_data) {
  switch (alttap_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: break;
    case DOUBLE_HOLD:
            if(currentBase != MAC){
                layer_off(1); unregister_code(KC_LALT); break;
            }else{
                layer_off(4); unregister_code(KC_LALT); break;
            }
  }
  alttap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [ALT_OSL1]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,alt_finished, alt_reset),
};

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
  /* Sit */
  static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                 {
                                                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                 },

                                                 /* 'sit2', 32x22px */
                                                 {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

  /* Walk */
  static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                  {
                                                      0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                  },

                                                  /* 'walk2', 32x22px */
                                                  {
                                                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                  }};

  /* Run */
  static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                 {
                                                     0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                 },

                                                 /* 'run2', 32x22px */
                                                 {
                                                     0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                 }};

  /* animation */
  void animate_luna(void) {
    /* clear */
    oled_set_cursor(LUNA_X, LUNA_Y - 1);
    oled_write("     ", false);

    oled_set_cursor(LUNA_X, LUNA_Y);

    /* switch frame */
    current_frame = (current_frame + 1) % 2;

    if (current_wpm <= MIN_WALK_SPEED) {
      oled_write_raw_P(sit[current_frame], ANIM_SIZE);

    } else if (current_wpm <= MIN_RUN_SPEED) {
      oled_write_raw_P(walk[current_frame], ANIM_SIZE);

    } else {
      oled_write_raw_P(run[current_frame], ANIM_SIZE);
    }
  }

#    if OLED_TIMEOUT > 0
  /* the animation prevents the normal timeout from occuring */
  if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
    oled_off();
    return;
  } else {
    oled_on();
  }
#    endif

  /* animation timer */
  if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
    anim_timer = timer_read32();
    animate_luna();
  }
}

// Key debugging info
uint8_t  last_row;
uint8_t  last_col;

static void set_keylog(uint16_t keycode, keyrecord_t *record) {
    last_row = record->event.key.row;
    last_col = record->event.key.col;
}

static const char *depad_str(const char *depad_str, char depad_char) {
    while (*depad_str == depad_char)
        ++depad_str;
    return depad_str;
}

static void oled_render_keylog(void) {
    const char *last_row_str = get_u8_str(last_row, ' ');
    oled_write_P(PSTR(" "), false);
    oled_write(depad_str(last_row_str, ' '), false);
    oled_write_P(PSTR("x"), false);
    const char *last_col_str = get_u8_str(last_col, ' ');
    oled_write(depad_str(last_col_str, ' '), false);
    oled_write_P(PSTR("  "), false);
}

static void print_status_narrow(void) {
  /* Print current mode */
  oled_set_cursor(0, 0);

  /* Print current layer */
  switch(currentBase){
      case CODING:
          oled_write(" CODE", false);
          break;
      case GAMING:
          oled_write(" GAME", false);
          break;
      case MAC:
          oled_write(" MAC ", false);
          break;
  }

  oled_set_cursor(0, 1);

  switch (get_highest_layer(layer_state)) {
    case 0:
    case 3:
      oled_write(" Base ", false);
      break;
    case 2:
      oled_write(" Syst", false);
      break;
    case 1:
    case 4:
      oled_write(" $&>!", false);
      break;
    default:
      oled_write("Undef", false);
  }

  oled_set_cursor(0, 5);
  oled_render_keylog();

  /* wpm counter */
  uint8_t n = get_current_wpm();
  char    wpm_str[4];
  oled_set_cursor(0, 10);
  wpm_str[3] = '\0';
  wpm_str[2] = '0' + n % 10;
  wpm_str[1] = '0' + (n /= 10) % 10;
  wpm_str[0] = '0' + n / 10;
  oled_write(wpm_str, false);

  oled_set_cursor(0, 11);
  oled_write("  wpm", false);
  render_luna(0, 13);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
  current_wpm = get_current_wpm();
  print_status_narrow();
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case KC_MAC:
            if (record->event.pressed) {
                currentBase = MAC;
                set_single_persistent_default_layer(0);
                layer_move(0);
            }
            return false;
        case KC_GAMING:
            if (record->event.pressed) {
                currentBase = GAMING;
                set_single_persistent_default_layer(3);
                layer_move(3);
            }
            return false;
        case KC_CODING:
            if (record->event.pressed) {
                currentBase = CODING;
                set_single_persistent_default_layer(0);
                layer_move(0);
            }
            return false;
    }
    return true;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case KC_TRNS:
        case KC_NO:
            /* Always cancel one-shot layer when another key gets pressed */
            if (record->event.pressed && is_oneshot_layer_active())
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            return true;
        default:
            return true;
    }
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return true;
}

void keyboard_pre_init_user(void){
    currentBase = CODING;
    set_single_persistent_default_layer(0);
    layer_move(0);
}
