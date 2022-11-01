# spin-keymap
My custom keymap for my DMQDesigns SPIN Macropad


# Setup instructions

1. Install QMK
  - `pacman -Syy qmk`
2. Setup inside qmk folder
  - `mkdir qmk_firmware && cd qmk_firmware && qmk setup
3. Clone this repo to `keyboards/dmqdesign/spin/keymaps/dmarshall`
4. Test compile
  - `make dmqdesign/spin:dmarshall`
5. Unplug macropad
6. Press and hold reset button under USB port and plug back in
7. Flash firmware: `qmk flash -kb dmqdesign/spin -km dmarshall`