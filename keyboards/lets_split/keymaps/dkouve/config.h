/*
This is the c configuration file for the keymap

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

 // place overrides here
#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 34 //5 + 7 + 5 on 3 sides of each case
#define RGBLED_SPLIT {17, 17}
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 127 //Just so that I don't max out power useage.

//#define ONESHOT_TAP_TOGGLE

#undef  DEBOUNCING_DELAY //gateron clears are too sensitive
#define DEBOUNCING_DELAY 5
