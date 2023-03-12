#pragma once
#include "quantum.h"

typedef struct kb_runtime_config {
    unsigned          lcd_power : 1;
} kb_runtime_config;

extern kb_runtime_config kb_state;

void housekeeping_task_sync(void);

typedef union {
    uint32_t raw;
    struct {
        bool    is_oled_enabled      :1;
        bool    is_caps_word_on      :1;
        bool    pointing_side        :1;
        uint8_t split_pointing_mode  :4;
    };
} user_runtime_config_t;

extern user_runtime_config_t user_state;
