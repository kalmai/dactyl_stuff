/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "tractyl_manuform.h"

#include "elite_c.h"

#include "quantum.h"

#define XXX KC_NO

// row, column
// clang-format off
#define LAYOUT_5x6_right(\
      L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
      L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
      L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
      L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
      L40, L41, L42, L43, L44, L45,                               R41, R42, R43, R44, R45, \
                L52, L53, L54, L55,                               R51, R52, R53            \
      ) { \
      { L05, L04, L03, L02, L01, L00 }, \
      { L15, L14, L13, L12, L11, L10 }, \
      { L25, L24, L23, L22, L21, L20 }, \
      { L35, L34, L33, L32, L31, L30 }, \
      { L45, L44, L43, L42, L41, L40 }, \
      { L55, L54, L53, L52, XXX, XXX }, \
  \
      { R05, R04, R03, R02, R01, R00 }, \
      { R15, R14, R13, R12, R11, R10 }, \
      { R25, R24, R23, R22, R21, R20 }, \
      { R35, R34, R33, R32, R31, R30 }, \
      { R45, R44, R43, R42, R41, XXX }, \
      { XXX, XXX, R53, R52, R51, XXX } \
}
// clang-format on
