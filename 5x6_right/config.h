/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS                 12
#define MATRIX_COLS                 6

#define DIODE_DIRECTION             COL2ROW

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW          0
#define BOOTMAGIC_LITE_COLUMN       0

#define BOOTMAGIC_LITE_ROW_LEFT 6
#define BOOTMAGIC_LITE_COLUMN_LEFT 5

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2
#define EE_HANDS
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000

/* POINTING DEVICE */
#define SPLIT_POINTING_ENABLE 
#define POINTING_DEVICE_RIGHT
#define ROTATIONAL_TRANSFORM_ANGLE  -30
// #define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_Y
#define PMW33XX_CPI 1200
