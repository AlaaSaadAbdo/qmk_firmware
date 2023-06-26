MAB_CIRQUE_BOTH = yes

ifeq ($(strip $(MAB_CIRQUE_BOTH)), yes)
   OPT_DEFS += -DMCU_HELIOS
endif
