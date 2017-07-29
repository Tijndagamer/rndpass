/*                                                                             
 * passgen.c                                                                   
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

#include "passgen.h"

// Count null bytes in string
int countnull(unsigned char buffer[], size_t buflen)
{
    int n = 0;
    //int len = sizeof(buffer);
    for (int i = 0; i < buflen; i++) {
        if (buffer[i] == '\0')
            ++n;
    }

    return n;
}

// Wrapper for getrandom syscall
int getrandom(void *buffer, size_t buflen, unsigned int flags)
{
    return syscall(SYS_getrandom, buffer, buflen, flags);    
}

// Generate random string, store in s, slen long. Returns total read random
// bytes. s will only contain standard printable ASCII characters.
int randstr(unsigned char s[], size_t slen, unsigned int flags)
{
    unsigned char buffer[slen];
    int n = 0, j = 0;

    // Optimization possibility: instead of getting slen new random
    // bytes each run, decrease this ammount, but make sure that the amount
    // of reads stays minimal.
    while (countnull(s, slen) > 0) {
        bzero(buffer, slen);
        n += getrandom(buffer, slen, flags);
        for (int i = 0; i < slen; i++) {
            if (buffer[i] > 32 && buffer [i] < 127) {
                s[j++] = buffer[i];
                if (j >= slen)
                    break;
            }
        }
    }
    // Make sure that the string is null terminated.
    s[slen-1] = '\0';

    return n;
}
