#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_russian.h"

enum layers
{
    EN_LO,
    RU_LO,
    SYMB
};

enum custom_keycodes
{
    EN_RU = ML_SAFE_RANGE,  // switch between EN and RU layers and send appropriate OS input language key sequences
    
    // Defining custom key codes to keep the punctuation marks matching 
    // between the English and Russian layouts
    
                            // English
    SP_DOT_COLN,            // .:
    SP_COMMA_SCOLON,        // ,;
    SP_EXLM_QUES,           // !?
    
                            // Russian
    SP_RU_EXLM_QUES,        // !? (Shift-1, Shift-7)
    SP_RU_QUO_DQUO,         // '" (EN -> KC_QUOTE -> RU, Shift-2)
    SP_RU_DOT_COLN,         // .: (RU_DOT, Shift-6)
    SP_RU_COM_SCLN          // ,; (Shift-dot, Shift-4)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [EN_LO] = LAYOUT_moonlander(
	KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           SP_EXLM_QUES,                                   KC_QUOTE,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
	KC_PSCREEN,     KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_SLASH,                                       SP_DOT_COLN,    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
	KC_LSHIFT,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_BSLASH,                                      SP_COMMA_SCOLON,KC_H,           KC_J,           KC_K,           KC_L,           KC_TRANSPARENT, KC_TRANSPARENT, 
	KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RSHIFT,          
	EN_RU,          KC_LCTRL,       KC_LALT,        KC_LEFT,        KC_RIGHT,       KC_LGUI,                                                                        KC_ENTER,       KC_UP,          KC_DOWN,        KC_RALT,        KC_RCTRL,       TG(SYMB),          
	                                                                                KC_SPACE,       KC_TAB,         MO(SYMB),                       MO(SYMB),       KC_DELETE,      KC_BSPACE
  ),
  [RU_LO] = LAYOUT_moonlander(
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, SP_RU_EXLM_QUES,                                SP_RU_QUO_DQUO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_MINS,        
	KC_TRANSPARENT, RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          RU_IE,          RU_SLSH,                                        SP_RU_DOT_COLN, RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          RU_HA,          
	KC_TRANSPARENT, RU_EF,          RU_YERU,        RU_VE,          RU_A,           RU_PE,          RU_BSLS,                                        SP_RU_COM_SCLN, RU_ER,          RU_O,           RU_EL,          RU_DE,          RU_ZHE,         RU_E,           
	KC_TRANSPARENT, RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                                                           RU_TE,          RU_SOFT,        RU_BE,          RU_YU,          RU_HARD,        KC_TRANSPARENT,          
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

bool is_shifted(void)
{
    return (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT));
}

bool is_lshifted(void)
{
    return (get_mods() & MOD_BIT(KC_LSHIFT));
}

bool is_rshifted(void)
{
    return (get_mods() & MOD_BIT(KC_RSHIFT));
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
    uint8_t v = LT_LO;
    if (is_shifted())
    {
        r = BK_HI; g = BK_HI; b = BK_HI; v = LT_HI;
    }
    switch(layer)
    {
        case EN_LO: b = v; break;
        case RU_LO: g = v; break;
        case SYMB:  r = v; break;
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

void tap_shifted(uint16_t keycode)
{
    register_code(KC_LSHIFT);
    tap_code(keycode);
    unregister_code(KC_LSHIFT);
}

void tap_unshifted(uint16_t keycode)
{
    uint16_t l = is_lshifted();
    uint16_t r = is_rshifted();
    
    if (l) unregister_code(KC_LSHIFT);
    if (r) unregister_code(KC_RSHIFT);
    tap_code(keycode);
    if (l) register_code(KC_LSHIFT);
    if (r) register_code(KC_RSHIFT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
    switch (keycode)
    {
        //////////////////////////////////////////////////////////
        // Non-standard lower-upper pairs for English
        
        // this works, but not repeating key while held
        case SP_EXLM_QUES:      // ! -> ?
            if (record->event.pressed)
            {
                if (is_shifted()) tap_code(KC_SLASH);  // shifted slash == question
                else tap_shifted(KC_1);                 // shifted 1 == exclamation
            }
            return false;
        
        case SP_DOT_COLN:       // dot -> colon
            if (record->event.pressed)
            {
                if (is_shifted()) tap_code(KC_SCOLON); // shifted semicolon == colon
                else tap_code(KC_DOT);                  // non-shifted dot
                
            }
            return false;
        
        
       case SP_COMMA_SCOLON:   // comma -> semicolon
            if (record->event.pressed)
            {
                if (is_shifted()) tap_unshifted(KC_SCOLON); // non-shifted semicolon
                else tap_code(KC_COMMA);                    // non-shifted comma
            }
            return false;
       
       
       //////////////////////////////////////////////////////////
       // Non-standard lower-upper pairs for Russian
       
       case SP_RU_EXLM_QUES:                            // ! -> ?
            if (record->event.pressed)
            {
                if (is_shifted()) tap_code(KC_7);       // shifted 1 == !
                else tap_shifted(KC_1);                 // shifted 7 == ?
                
            }
            return false;
       
       case SP_RU_QUO_DQUO:                            // ' -> "
            if (record->event.pressed)
            {
                if (is_shifted()) tap_code(KC_2);      // shifted 2 == "
                else
                {
                    register_code(KC_LCTRL);
            	    register_code(KC_LSHIFT);
                    tap_code(KC_1);
                    unregister_code(KC_LSHIFT);
            	    unregister_code(KC_LCTRL);
            	    
            	    tap_code(KC_QUOT);
            	    
            	    register_code(KC_LCTRL);
            	    register_code(KC_LSHIFT);
                    tap_code(KC_2);
                    unregister_code(KC_LSHIFT);
            	    unregister_code(KC_LCTRL);
                }
            }
            return false;
            
       case SP_RU_DOT_COLN:                            // . -> :
            if (record->event.pressed)
            {
                if (is_shifted()) tap_code(KC_6);      // shifted 6 == :
                else tap_code(RU_DOT);
                
            }
            return false;
       
       case SP_RU_COM_SCLN:                             // , -> ;
            if (record->event.pressed)
            {
                if (is_shifted()) tap_code(KC_4);       // shifted 4 == ;
                else tap_shifted(RU_DOT);               // shifted . == ,
                
            }
            return false;
            
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
                }
                else if (IS_LAYER_ON(RU_LO))    // we're on RU_* now - change to EN_*
                {
                    layer_off(RU_LO);           // turn off basic RU layer
                    tap_code(KC_1);             // switch OS to its first language
                }
                unregister_code(KC_LSHIFT);     // release Ctrl and Shift
            	unregister_code(KC_LCTRL);
                break;
            }
    }
    return true;
}
