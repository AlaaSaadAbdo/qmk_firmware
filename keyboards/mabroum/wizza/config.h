// Copyright 2023 Alaa Mansour (@AlaaSaadAbdo)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MASTER_RIGHT
// #define SERIAL_DEBUG
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_MODES_ENABLE
#define POINTING_DEVICE_MODES_INVERT_Y
#define POINTING_DRAG_DIVISOR 64
#define POINTING_PRECISION_DIVISOR 4

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin
#define SERIAL_USART_PIN_SWAP

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

#define I2C_DRIVER I2CD1

// SPI config for shift register (and trackball if enabled)
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20

#define PMW33XX_CS_PIN GP21
#define PMW33XX_CPI 800
#define PMW33XX_CS_DIVISOR 8 // needs to be the same as the SHIFTREG_DIVISOR above
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_ROTATION_270_RIGHT
#define POINTING_DEVICE_INVERT_X_RIGHT

/* right */
#define DISPLAY_CS_PIN_RIGHT GP26
#define DISPLAY_RST_PIN_RIGHT GP16
#define DISPLAY_DC_PIN_RIGHT GP15

/*  left */
#define DISPLAY_CS_PIN GP26
#define DISPLAY_RST_PIN GP16
#define DISPLAY_DC_PIN GP15

#define QUANTUM_PAINTER_CONCURRENT_ANIMATIONS 8
#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
#define QUANTUM_PAINTER_NUM_IMAGES 14
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE 128
// #define LCD_ACTIVITY_TIMEOUT 30000

#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PWM_DRIVER PWMD6
#define BACKLIGHT_PWM_CHANNEL 2
#define BACKLIGHT_PIN GP11
#define BACKLIGHT_LEVELS 4
#endif //BACKLIGHT_ENABLE


#define FB_ERM_LRA 1
#define FB_BRAKEFACTOR 3 // For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7
#define FB_LOOPGAIN 1 // For  Low:0, Medium:1, High:2, Very High:3
#define RATED_VOLTAGE 2
#define V_PEAK 2.8
#define V_RMS 2.0
#define F_LRA 150 // resonance freq
#define DRV_GREETING  alert_750ms


#ifdef RGBLIGHT_ENABLE

#define RGB_DI_PIN GP27
#define RGBLED_NUM 20
#define RGBLED_SPLIT { 10, 10 }

#define RGBLIGHT_SPLIT
#define RGBLIGHT_DEFAULT_HUE 180
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 75
#define RGBLIGHT_SLEEP

#endif // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE

#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_DI_PIN GP25

// #define DRIVER_LED_TOTAL 30
#define RGB_MATRIX_LED_COUNT 30
#define RGB_MATRIX_SPLIT { 15, 15 }

#endif /* ifndef RGB_MATRIX_ENABLE */

#define SPLIT_HAPTIC_ENABLE
