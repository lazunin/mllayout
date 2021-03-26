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

enum custom_keycodes
{
    EN_RU = ML_SAFE_RANGE,  // switch between EN and RU layers and send appropriate OS input language key sequences
    //Q_SHIFT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [EN_LO] = LAYOUT_moonlander(
	KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EXLM,                                        KC_QUOTE,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
	KC_PSCREEN,     KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_SLASH,                                       KC_DOT,         KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
	KC_LSHIFT,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_BSLASH,                                      KC_COMMA,       KC_H,           KC_J,           KC_K,           KC_L,           KC_TRANSPARENT, KC_TRANSPARENT, 
	TT(EN_HI),      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TT(EN_HI),          
	EN_RU,          KC_LCTRL,       KC_LALT,        KC_LEFT,        KC_RIGHT,       KC_LGUI,                                                                        KC_ENTER,       KC_UP,          KC_DOWN,        KC_RALT,        KC_RCTRL,       TG(4),          
	                                                                                KC_SPACE,       KC_TAB,         MO(4),                          MO(4),          KC_DELETE,      KC_BSPACE
  ),
  [EN_HI] = LAYOUT_moonlander(
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_QUES,                                        KC_DQUO,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS,        
	KC_TRANSPARENT, LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T),     KC_TRANSPARENT,                                 KC_COLN,        LSFT(KC_Y),     LSFT(KC_U),     LSFT(KC_I),     LSFT(KC_O),     LSFT(KC_P),     KC_TRANSPARENT, 
	KC_TRANSPARENT, LSFT(KC_A),     LSFT(KC_S),     LSFT(KC_D),     LSFT(KC_F),     LSFT(KC_G),     KC_TRANSPARENT,                                 KC_SCOLON,      LSFT(KC_H),     LSFT(KC_J),     LSFT(KC_K),     LSFT(KC_L),     KC_TRANSPARENT, KC_TRANSPARENT, 
	KC_TRANSPARENT, LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     LSFT(KC_B),                                                                     LSFT(KC_N),     LSFT(KC_M),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
	                                                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [RU_LO] = LAYOUT_moonlander(
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_EXLM,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_MINS,        
	KC_TRANSPARENT, RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          RU_IE,          RU_SLSH,                                        RU_DOT,         RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          RU_HA,          
	KC_TRANSPARENT, RU_EF,          RU_YERU,        RU_VE,          RU_A,           RU_PE,          RU_BSLS,                                        RU_COMM,        RU_ER,          RU_O,           RU_EL,          RU_DE,          RU_ZHE,         RU_E,           
	TT(RU_HI),      RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                                                           RU_TE,          RU_SOFT,        RU_BE,          RU_YU,          RU_HARD,        TT(RU_HI),          
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
	                                                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [RU_HI] = LAYOUT_moonlander(
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_QUES,                                        RU_DQUO,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_UNDS,        
	KC_TRANSPARENT, LSFT(RU_SHTI),  LSFT(RU_TSE),   LSFT(RU_U),     LSFT(RU_KA),    LSFT(RU_IE),    KC_TRANSPARENT,                                 RU_COLN,        LSFT(RU_EN),    LSFT(RU_GHE),   LSFT(RU_SHA),   LSFT(RU_SHCH),  LSFT(RU_ZE),    LSFT(RU_HA),    
	KC_TRANSPARENT, LSFT(RU_EF),    LSFT(RU_YERU),  LSFT(RU_VE),    LSFT(RU_A),     LSFT(RU_PE),    KC_TRANSPARENT,                                 RU_SCLN,        LSFT(RU_ER),    LSFT(RU_O),     LSFT(RU_EL),    LSFT(RU_DE),    LSFT(RU_ZHE),   LSFT(RU_E),     
	KC_TRANSPARENT, LSFT(RU_YA),    LSFT(RU_CHE),   LSFT(RU_ES),    LSFT(RU_EM),    LSFT(RU_I),                                                                     LSFT(RU_TE),    LSFT(RU_SOFT),  LSFT(RU_BE),    LSFT(RU_YU),    LSFT(RU_HARD),  KC_TRANSPARENT, 
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
	                                                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SYMB] = LAYOUT_moonlander(
	KC_PLUS,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_ASTR,                                        KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
	KC_MINUS,       KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_F12,         
	KC_EQUAL,       KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_INSERT,      
	KC_LSHIFT,      KC_PERC,        KC_AMPR,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RSHIFT,      
	KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_LABK,        KC_RABK,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
	                                                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// Blue for EN, green for RU, dim colors for base layouts, 
// brighter whiter colors for shifted layouts;
// dim red color for SYM
const uint8_t BK_LO = 0;    // baseline r, g, b for non-shifted keys
const uint8_t BK_HI = 63;   // baseline r, g, b for shifted keys
const uint8_t LT_LO = 127;  // the color component value for non-shifted layer
const uint8_t LT_HI = 255;  // the color component value for shifted layer
void set_layer_color(int layer)
{
    uint8_t r = BK_LO, g = BK_LO, b = BK_LO;
    if ((layer == EN_HI) || (layer == RU_HI))
    {
        r = BK_HI; g = BK_HI; b = BK_HI;
    }
    switch(layer)
    {
        case EN_LO: b = LT_LO; break;
        case EN_HI: b = LT_HI; break;
        case RU_LO: g = LT_LO; break;
        case RU_HI: g = LT_HI; break;
        case SYMB:  r = LT_LO; break;
    }
    rgb_matrix_set_color_all(r, g, b);
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
    case EN_RU:
        if (record->event.pressed)
        {
            register_code(KC_LCTRL);    // begin our OS input language changing sequence
    		register_code(KC_LSHIFT);
            if (IS_LAYER_OFF(RU_LO))    // we're on EN_* now - change to RU_*
            {
                //layer_off(EN_LO);     // keep EN_LO active for its unique characters?
                layer_on(RU_LO);        // turn on the Russian layer
                tap_code(KC_2);         // and send '2' to switch to second OS language
                if (IS_LAYER_ON(EN_HI)) // if our EN layer in its 'shifted' state - move that to our RU layer
                {
                    layer_off(EN_HI);
                    layer_on(RU_HI);
                }
            }
            else if (IS_LAYER_ON(RU_LO))    // we're on RU_* now - change to EN_*
            {
                layer_off(RU_LO);           // turn off basic RU layer
                tap_code(KC_1);             // switch OS to its first language
                if (IS_LAYER_ON(RU_HI))     // transfer the 'shift' state to EN
                {
                    layer_off(RU_HI);
                    layer_on(EN_HI);
                }
            }
            unregister_code(KC_LSHIFT);     // release Ctrl and Shift
    		unregister_code(KC_LCTRL);
            break;
        }
    /*case TT(EN_HI):                         // to keep Shift pressed
    case TT(RU_HI):
        if (record->event.pressed)          // press Shift
        {
            register_code(KC_LSHIFT);
        }
        else                                // release Shift
        {
            unregister_code(KC_LSHIFT);
        }*/
  }
  return true;
}
