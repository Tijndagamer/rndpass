/*
 * rndpass.h
 * This file is part of rndpass.
 *
 * Copyright (c) 2017 Martijn (MrTijn/Tijndagamer)
 *
 * rndpass is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rndpass is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rndpass.  If not, see <http://www.gnu.org/licenses/>.*
 */

#ifndef RNDPASS_h
#define RNDPASS_h

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <error.h>
#include <strings.h>

const char *version_info = "rndpass 0.1\nCopyright (c) 2017 Martijn (MrTijn/Tijndagamer\nLicense GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n";
enum { NORMAL, ALTERNATIVE, VERSION, EXTENDED } mode;

// Function for operating modes
void normal(bool verbose, int len);
void alternative(bool verbose, int len);
//void version(void);
//void extended(void);

int main(int argc, char *argv[]);

#endif
