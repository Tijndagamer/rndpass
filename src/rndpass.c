/*
 * rndpass.c
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

#include "rndpass.h"
#include "passgen.h"


int main(int argc, char *argv[])
{
    int opt, len = 25;
    bool verbose = false;

    mode = NORMAL;
    while ((opt = getopt(argc, argv, "l:vaVeh")) != -1) {
        switch (opt) {
            case 'l':
                len = atoi(optarg) + 1;
                break;
            case 'v':
                verbose = true;
                break;
            case 'a':
                mode = ALTERNATIVE;
                break;
            case 'V':
                mode = VERSION;
                break;
            case 'e':
                mode = EXTENDED;
                break;
            case 'h':
                mode = HELP;
                break;
            default:
                fprintf(stderr, "Usage: %s [-l len] [-aevV]\n", argv[0]);
        }
    }

    switch (mode) {
        case NORMAL:
            normal(verbose, len, false);
            break;
        case ALTERNATIVE:
            alternative(verbose, len);
            break;
        case EXTENDED:
            normal(verbose, len, true);
            break;
        case VERSION:
            printf("%s", version_info);
            break;
        case HELP:
            printf("%s", help_text);
            break;
        default:
            fprintf(stderr, "Illegal mode specified\n");
    }
}

/* Normal operation using randstr. Limits to a more limited set of ASCII
 * printable characters if ext is false, uses all ASCII printable characters
 * when ext is true.
 */
void normal(bool verbose, int len, bool ext)
{
    int n;
	unsigned char buffer[len];
	n = randstr(buffer, sizeof(buffer), 0, ext);
	if (verbose)
		printf("%d random bytes read\n", n);
	printf("%s\n", buffer);
}

/* Using randstr_alt (WIP) */
void alternative(bool verbose, int len)
{
    int n;
	if (verbose)
		printf("Using alternative character conversion\n");
	char buffer[len];
	n = randstr_alt(buffer, len, 0);
	printf("%d random bytes read\n", n);
}
