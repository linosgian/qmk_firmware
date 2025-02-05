// Copyright 2022 Conor Burns (@Conor-Burns)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

/* VBUS detect pin */
#define USB_VBUS_PIN GP19
#define SELECT_SOFT_SERIAL_SPEED 0
#define SERIAL_PIO_USE_PIO0
// #define MASTER_LEFT
#define EE_HANDS
/* #define SPLIT_USB_DETECT */
/* #define SPLIT_USB_TIMEOUT 5000 */
#define WS2812_PIO_USE_PIO1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led which blinks when entering the bootloader

#define SERIAL_DEBUG


//Miryoku
//

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 190


// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
//#define QUICK_TAP_TERM 0
/* #define HOLD_ON_OTHER_KEY_PRESS */
#define PERMISSIVE_HOLD
// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
