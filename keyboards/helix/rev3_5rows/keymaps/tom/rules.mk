# QMK Standard Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
#   See TOP/keyboards/helix/rules.mk for a list of options that can be set.
#   See TOP/docs/config_options.md for more information.
#
RGBLIGHT_ENABLE = yes   # Enable keyboard RGB underglow
RGBLIGHT_SPLIT = yes
RGB_MATRIX_ENABLE = no
#LED_ANIMATIONS = no        # Helix-specific shortcut for some animations
BOOTLOADER = atmel-dfu
ENCODER_ENABLE = no
NODEBUG = yes
NOPRINT = yes
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = no
MOUSEKEY_ENABLE = no
ENCODER_ENABLE = no

EXTRAFLAGS += -flto # To save memory
