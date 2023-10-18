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
//#define ONESHOT_TAP_TOGGLE

#define TAIPO_FLAVOR_POSH
#define TAIPO_TAP_TIMEOUT 150
#define ONESHOT_TIMEOUT 500

#undef  DEBOUNCING_DELAY //gateron clears are too sensitive
#define DEBOUNCING_DELAY 36

#define FORCE_NKRO
