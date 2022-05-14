# Helix notes

Build command:
make helix/rev3_5rows:tom:dfu-split-left
make helix/rev3_5rows:tom:dfu-split-right

When updating the keymap:
# TODO: I could replace this with a script that does both steps
1. Use this command to generate keymap.c from the .json
 file:
qmk json2c 'FILE_NAME_HERE.json' > keymap.c
2. Add "#include <rgb_layers.h>" to the keymap.c file
