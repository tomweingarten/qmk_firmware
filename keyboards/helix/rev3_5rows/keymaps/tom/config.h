/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// place overrides here
#undef TAPPING_TERM
#undef TAPPING_FORCE_HOLD

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define NO_ACTION_ONESHOT

// I'd rather use EE_HANDS, but it doesn't seem to work and the right half of my keyboard's USB is busted anyway
#define MASTER_LEFT
//#define EE_HANDS
#undef SPLIT_HAND_MATRIX_GRID
#undef SPLIT_HAND_MATRIX_GRID_LOW_IS_RIGHT
#undef SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#undef SPLIT_LED_STATE_ENABLE
#undef SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE

#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 200 // TODO: Play with this
#define RGBLIGHT_SLEEP
// NB: RGBLED_SPLIT is already set by helix
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_GRADIENT + 1
#define RGBLIGHT_DEFAULT_HUE 208  // Out of 255
#define RGBLIGHT_DEFAULT_SAT 255  // Out of 255
#define RGBLIGHT_DEFAULT_VAL 100  // Out of 255
#define RGBLIGHT_LAYERS
//#define RGBLIGHT_LAYERS_RETAIN_VALUES

#undef OLED_TIMEOUT
#define OLED_TIMEOUT 60000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 10

// WPM_SMOOTHING ...

// Enable individual animations to save memory
#undef RGB_ANIMATIONS
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_SNAKE

// Static gradient settings are in oled_display.c 
#define RGBLIGHT_EFFECT_STATIC_GRADIENT

#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM  14
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH   7
#define RGBLIGHT_EFFECT_KNIGHT_OFFSET  	50

#define RGBLIGHT_LED_MAP { \
  5, 4, 3, 2, 1, 0, \
  12, 13, 14, 15, 16, 17, \
  29, 28, 27, 26, 25, 24, \
  36, 37, 38, 39, 40, 41, 42, \
  56, 55, 54, 53, 52, 51, 50, \
  6, 7, 8, 9, 10, 11, \
  23, 22, 21, 20, 19, 18, \
  30, 31, 32, 33, 34, 35, \
  49, 48, 47, 46, 45, 44, 43, \
  57, 58, 59, 60, 61, 62, 63 \
}

/*#define RGBLIGHT_LED_MAP { \
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, \
  12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, \
  24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, \
  36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, \
  50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63}*/
  

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT