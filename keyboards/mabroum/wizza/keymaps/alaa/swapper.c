#include "swapper.h"

uint32_t swapper_timer = 0;

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
                swapper_timer = timer_read32();
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // unregister alt after a timer
            if (timer_elapsed32(swapper_timer) > 1000 ) {
                unregister_code(cmdish);
            }
        }
    } else if (*active) {
        unregister_code(cmdish);
        *active = false;
    }
}
