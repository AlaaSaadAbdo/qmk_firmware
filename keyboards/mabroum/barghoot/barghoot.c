#include "quantum.h"
#include "barghoot.h"
#include "display.h"
#include "qp.h"
#include "qp_lvgl.h"
#include "super_tab.h"

kb_runtime_config kb_state;

static painter_device_t display;

void keyboard_post_init_user(void) {
  /* debug_enable=true; */
  /* debug_matrix=false; */
  /* debug_keyboard=false; */
  /* debug_mouse=true; */

  display = qp_st7789_make_spi_device(200, 320, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 8, 3);
  qp_set_viewport_offsets(display, 0, 34);
  qp_init(display, QP_ROTATION_270); // Initialise the display
  qp_power(display, true);
  qp_rect(display, 0, 0, 319, 171, 0, 0, 0, true);

  if (qp_lvgl_attach(display)) {     // Attach LVGL to the display
    wait_ms(50);
    display_init();
  }
  rgblight_enable();
  backlight_enable();
}

void suspend_power_down_user(void) {
  #ifdef BACKLIGHT_ENABLE
    backlight_level_noeeprom(0);
  #endif // ifdef BACKLIGHT_ENABLE
}

void suspend_wakeup_init_user(void) {
  #ifdef BACKLIGHT_ENABLE
    backlight_level_noeeprom(1);
  #endif // ifdef BACKLIGHT_ENABLE
}

void housekeeping_task_user(void) {
  lvgl_event_triggers();

  if (keymap_config.swap_lctl_lgui) {
  unregister_super_tab(KC_LGUI);
  } else {
    unregister_super_tab(KC_LALT);
  }

}

void board_init(void) {}
