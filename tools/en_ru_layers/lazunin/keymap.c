#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_russian.h"

enum layers
{
    EN_LO,
    EN_HI,
    RU_LO,
    RU_HI,
    SYMB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [EN_LO] = LAYOUT_moonlander(
	KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EXLM,                                        KC_QUOTE,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
	KC_PSCREEN,     KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_SLASH,                                       KC_DOT,         KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
	KC_LSHIFT,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_BSLASH,                                      KC_COMMA,       KC_H,           KC_J,           KC_K,           KC_L,           KC_TRANSPARENT, KC_TRANSPARENT, 
	TT(1),          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TT(1),          
	TG(2),          KC_LCTRL,       KC_LALT,        KC_LEFT,        KC_RIGHT,       KC_LGUI,                                                                        KC_ENTER,       KC_UP,          KC_DOWN,        KC_RALT,        KC_RCTRL,       TG(4),          
	                                                                                KC_SPACE,       KC_TAB,         MO(4),                          MO(4),          KC_DELETE,      KC_BSPACE
  ),
  [EN_HI] = LAYOUT_moonlander(
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_QUES,                                        KC_DQUO,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS,        
	KC_TRANSPARENT, LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T),     KC_TRANSPARENT,                                 KC_COLN,        LSFT(KC_Y),     LSFT(KC_U),     LSFT(KC_I),     LSFT(KC_O),     LSFT(KC_P),     KC_TRANSPARENT, 
	KC_TRANSPARENT, LSFT(KC_A),     LSFT(KC_S),     LSFT(KC_D),     LSFT(KC_F),     LSFT(KC_G),     KC_TRANSPARENT,                                                                 KC_SCOLON,      LSFT(KC_H),     LSFT(KC_J),     LSFT(KC_K),     LSFT(KC_L),     KC_TRANSPARENT, KC_TRANSPARENT, 
	KC_TRANSPARENT, LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     LSFT(KC_B),                                     LSFT(KC_N),     LSFT(KC_M),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [RU_LO] = LAYOUT_moonlander(
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_EXLM,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_MINS,        
	KC_TRANSPARENT, RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          RU_IE,          RU_SLSH,                                        RU_DOT,         RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          RU_HA,          
	KC_TRANSPARENT, RU_EF,          RU_YERU,        RU_VE,          RU_A,           RU_PE,          RU_BSLS,                                                                        RU_COMM,        RU_ER,          RU_O,           RU_EL,          RU_DE,          RU_ZHE,         RU_E,           
	TT(3),          RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                           RU_TE,          RU_SOFT,        RU_BE,          RU_YU,          RU_HARD,        TT(3),          
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [RU_HI] = LAYOUT_moonlander(
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_QUES,                                        RU_DQUO,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_UNDS,        
	KC_TRANSPARENT, LSFT(RU_SHTI),  LSFT(RU_TSE),   LSFT(RU_U),     LSFT(RU_KA),    LSFT(RU_IE),    KC_TRANSPARENT,                                 RU_COLN,        LSFT(RU_EN),    LSFT(RU_GHE),   LSFT(RU_SHA),   LSFT(RU_SHCH),  LSFT(RU_ZE),    LSFT(RU_HA),    
	KC_TRANSPARENT, LSFT(RU_EF),    LSFT(RU_YERU),  LSFT(RU_VE),    LSFT(RU_A),     LSFT(RU_PE),    KC_TRANSPARENT,                                                                 RU_SCLN,        LSFT(RU_ER),    LSFT(RU_O),     LSFT(RU_EL),    LSFT(RU_DE),    LSFT(RU_ZHE),   LSFT(RU_E),     
	KC_TRANSPARENT, LSFT(RU_YA),    LSFT(RU_CHE),   LSFT(RU_ES),    LSFT(RU_EM),    LSFT(RU_I),                                     LSFT(RU_TE),    LSFT(RU_SOFT),  LSFT(RU_BE),    LSFT(RU_YU),    LSFT(RU_HARD),  KC_TRANSPARENT, 
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SYMB] = LAYOUT_moonlander(
	KC_PLUS,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_ASTR,                                        KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
	KC_MINUS,       KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_F12,         
	KC_EQUAL,       KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_INSERT,      
	KC_LSHIFT,      KC_PERC,        KC_AMPR,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RSHIFT,      
	KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_LABK,        KC_RABK,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void set_layer_color(int layer)
{
    switch(layer)
    {
        case EN_LO: 
            rgb_matrix_set_color_all(0, 0, 127);
            break;
        case EN_HI: 
            rgb_matrix_set_color_all(63, 63, 255);
            break;
        case RU_LO: 
            rgb_matrix_set_color_all(0, 127, 0);
            break;
        case RU_HI: 
            rgb_matrix_set_color_all(63, 255, 63);
            break;
        case SYMB: 
            rgb_matrix_set_color_all(127, 0, 0);
            break;
    }
}

void rgb_matrix_indicators_user(void) 
{
  if (g_suspend_state || keyboard_config.disable_layer_led) return;
  
  uint8_t lstate = biton32(layer_state);
  if ( (lstate >= EN_LO) && (lstate <= SYMB)) set_layer_color(lstate);
  else
  {
      if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
  switch (keycode)
  {
	case TG(2):
		if (record->event.pressed)
		{
			// if we are on layer2, we should be on 2nd input language,
			// send Ctrl+Shift+1 to switch to 1st input language, and 
			// vice versa
			register_code(KC_LCTRL);
			register_code(KC_LSHIFT);
			if (IS_LAYER_ON(2)) tap_code(KC_1);
			else tap_code(KC_2);
			unregister_code(KC_LSHIFT);
			unregister_code(KC_LCTRL);
		}
		break;
  }
  return true;
}

