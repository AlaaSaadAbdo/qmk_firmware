// Copyright 2024 Alaa Mansour (@AlaaSaadAbdo)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// SPI config for shift register (and trackball if enabled)
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP2
#define SPI_MOSI_PIN GP3
#define SPI_MISO_PIN GP4

#define PMW33XX_CS_PIN GP1
#define PMW33XX_CPI 300
#define PMW33XX_CS_DIVISOR 8 // needs to be the same as the SHIFTREG_DIVISOR above
// #define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_INVERT_X

#define MAB_DRAGSCROLL_BUFFER_SIZE 20
#define MAB_DRAGSCROLL_DPI 150
