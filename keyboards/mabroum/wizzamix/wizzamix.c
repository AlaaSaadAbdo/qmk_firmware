#include "quantum.h"
#include "wizzamix.h"
#include "display.h"
#include "super_tab.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif // ifdef RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { {
    {     4,     3,     2,     1,      0 },
    {     5,     6,     7,     8,      9 },
    {     13,    12,    11,    10,     14 },
    {     19,    18,    17,    16,     15 },
    {     20,    21,    22,    23,     24 },

    {     25,   26,    27,    28,      29 },
    {     34,   33,    32,    31,      30 },
    {     39,   35,    36,    37,      38 },
    {     40,   41,    42,    43,      44 },
    {     49,   48,    47,    46,      45 }

}, {
    {2,1},{25,0},{48,2},{63,10},{77,20},{72,31},{56,21},{40,13},{18,10},{0,12},{15,22},{32,24},{38,31},
    {51,44},{58,53},

    {0,0},{0,0},{0,0},{0,0},{0,0},
    {0,0},{0,0},{0,0},{0,0},{0,0},

    {0,0},{0,0},{0,0},{0,0},{0,0},
    {0,0},{0,0},{0,0},{0,0},{0,0},

    {164,53},{180,44},
    {185,31},{200,24},{217,22},{224,12},{204,10},{185,13},{169,21},{155,31},{160,20},{174,10},{189,2},{212,0},{237,1}
}, {
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4,
    1, 1,

    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

    1, 1,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4,
} };

#endif /* ifndef RGB_MATRIX_ENABLE */

#include "qp.h"
#include "qp_lvgl.h"

kb_runtime_config kb_state;

static painter_device_t display;

void keyboard_post_init_user(void) {
  /* debug_enable=true; */
  /* debug_matrix=false; */
  /* debug_keyboard=false; */
  /* debug_mouse=true; */

  if (is_keyboard_left()) {
    display = qp_st7789_make_spi_device(200, 320, DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, 8, 3);
    qp_set_viewport_offsets(display, 0, 34);
    qp_init(display, QP_ROTATION_270); // Initialise the display
    qp_power(display, true);
    qp_rect(display, 0, 0, 319, 171, 0, 0, 0, true);
  } else {
    display = qp_st7789_make_spi_device(200, 320, DISPLAY_CS_PIN_RIGHT, DISPLAY_DC_PIN_RIGHT, DISPLAY_RST_PIN_RIGHT, 8, 3);
    qp_set_viewport_offsets(display, 0, 34);
    qp_init(display, QP_ROTATION_270); // Initialise the display
    qp_power(display, true);
    qp_rect(display, 0, 0, 319, 171, 0, 0, 0, true);
  }

  backlight_level_noeeprom(1);
  if (qp_lvgl_attach(display)) {     // Attach LVGL to the display
    wait_ms(50);
    display_init();
  }

  pointing_device_set_cpi_on_side(true, 100); //Set cpi on left side to a low value for slower scrolling.
  pointing_device_set_cpi_on_side(false, 800); //Set cpi on right side to a reasonable value for mousing.
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
