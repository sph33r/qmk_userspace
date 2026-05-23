ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
KEYBOARD_SHARED_EP = yes
