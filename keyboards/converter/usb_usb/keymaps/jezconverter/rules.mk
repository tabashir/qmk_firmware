LTO_ENABLE = yes # Reduces the compiled firmware size

EXTRAKEY_ENABLE = yes # Used for audio control and system control keys
COMBO_ENABLE = no # Used to allow chording of keys to trigger an action
TAP_DANCE_ENABLE = yes # Used to allow multiple taps of a key to perform different actions
MOUSEKEY_ENABLE = yes

# SRC += combo.c tap_dance.c
SRC += tap_dance.c
