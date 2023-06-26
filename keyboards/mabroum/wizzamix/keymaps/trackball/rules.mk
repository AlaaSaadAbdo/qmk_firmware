MAB_TRACKBALL_BOTH = yes

ifeq ($(strip $(MAB_TRACKBALL_BOTH)), yes)
   OPT_DEFS += -DMCU_HELIOS
endif
