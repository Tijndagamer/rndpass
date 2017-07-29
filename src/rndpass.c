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
    int opt, n, len = 25;
    bool verbose = false;

    while ((opt = getopt(argc, argv, "l:v")) != -1) {
        switch (opt) {
            case 'l':
                len = atoi(optarg) + 1;
                break;
            case 'v':
                verbose = true;
                break;
            default:
                error(-1, 0, "Usage: %s [-l len]", argv[0]);
        }
    }
    unsigned char buffer[len];
    bzero(buffer, len);
    n = randstr(buffer, sizeof(buffer), 0);
    if (verbose)
        printf("%d random bytes read\n", n);
    printf("%s", buffer);
}
