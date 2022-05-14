#include <layer_defs.h>

#undef RGBLIGHT_MAX_LAYERS
#define RGBLIGHT_MAX_LAYERS 5 // can increase up to 32 but more = slower

/*
  Left            Right
00 .... 05      32 .... 37
06 .... 11      38 .... 43
12 .... 17      44 .... 49
18 ..... 24    50 ..... 56
25 ..... 31    57 ..... 63
*/

const rgblight_segment_t PROGMEM my_blackout_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 64, HSV_BLACK}       // Black out the background
);
//const rgblight_segment_t PROGMEM my_transparent_layer[] = { { RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0 } };

const rgblight_segment_t PROGMEM my_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {33, 2, HSV_TEAL},
    {39, 3, HSV_CYAN},
    {42, 1, HSV_TEAL},
    {45, 3, HSV_CYAN},
    {48, 1, HSV_TEAL},
    {52, 3, HSV_CYAN},
    {60, 1, HSV_CYAN},
    {61, 1, HSV_TEAL}
);
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 6, HSV_BLUE},
    {13, 5, HSV_BLUE},
    {18, 7, HSV_BLUE},
    {38, 5, HSV_BLUE},
    {44, 6, HSV_BLUE},
    {50, 2, HSV_BLUE},
    {54, 2, HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 6, HSV_PURPLE},
    {13, 5, HSV_PURPLE},
    {18, 6, HSV_PURPLE},
    {38, 6, HSV_PURPLE},
    {44, 6, HSV_PURPLE},
    {51, 1, HSV_PURPLE},
    {54, 2, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_WHITE},
    {7, 1, HSV_WHITE},
    {12, 1, HSV_WHITE},
    {15, 3, HSV_WHITE},
    {32, 5, HSV_WHITE},
    {44, 1, HSV_WHITE},
    {48, 1, HSV_RED},
    {53, 4, HSV_WHITE},
    {60, 4, HSV_WHITE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_blackout_layer,
    my_lower_layer,
    my_raise_layer,
    my_adjust_layer,
    my_numpad_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.num_lock);
//     return true;
// }

layer_state_t default_layer_state_set_user(layer_state_t state) {
    //rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(0, true);
    return state;
}

void clear_rgb_layers(void) {
	rgblight_set_layer_state(0, true);
	rgblight_set_layer_state(1, false);
	rgblight_set_layer_state(2, false);
	rgblight_set_layer_state(3, false);
	rgblight_set_layer_state(4, false);
} 

layer_state_t layer_state_set_user(layer_state_t state) {
	clear_rgb_layers();
    switch (get_highest_layer(state)) {
		case _QWERTY:
			rgblight_set_layer_state(0, false);
			//rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT);
			rgblight_mode(RGBLIGHT_DEFAULT_MODE);
			//rgblight_mode(RGBLIGHT_MODE_BREATHING);
			rgblight_sethsv(RGBLIGHT_DEFAULT_HUE, RGBLIGHT_DEFAULT_SAT, RGBLIGHT_DEFAULT_VAL);
			break;
		case _LOWER:
			rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
			rgblight_set_layer_state(1, true);
			break;
		case _RAISE:
			rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
			rgblight_set_layer_state(2, true);
			break;
		case _ADJUST:
			rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
			rgblight_set_layer_state(3, true);
			break;
		case _NUMPAD:
			rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
			rgblight_set_layer_state(4, true);
			break;
		case _GAMING:
			rgblight_set_layer_state(0, false);
			rgblight_sethsv(0, 255, 100);
			rgblight_mode(RGBLIGHT_MODE_KNIGHT);
			break;
		default:
			rgblight_set_layer_state(0, true);
		    break;
	}
    return state;
}