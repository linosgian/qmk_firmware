// Copyright 2022 Conor Burns (@Conor-Burns)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

/* default setup after eeprom reset */
// #define RGBLIGHT_DEFAULT_SAT 232
// #define RGBLIGHT_DEFAULT_VAR 100
// #define RGBLIGHT_DEFAULT_SPD 2
// #define RGBLED_NUM 1
// #define SPLIT_USB_TIMEOUT_POLL 10
// #define SPLIT_WATCHDOG_ENABLE
// #define SPLIT_WATCHDOG_TIMEOUT 2500
// #define SERIAL_USART_TX_PIN GP0
/* VBUS detect pin */
// #define USB_VBUS_PIN GP19
#define SELECT_SOFT_SERIAL_SPEED 0
#define SERIAL_PIO_USE_PIO0
// #define USE_SERIAL
// #define MASTER_LEFT
#define EE_HANDS
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 5000
// #define SERIAL_USART_SPEED 29000
#define WS2812_PIO_USE_PIO1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led which blinks when entering the bootloader

#define SERIAL_DEBUG

//RDY = GP20
//RST = GP23
//SDA = GP2
//SCL = GP3