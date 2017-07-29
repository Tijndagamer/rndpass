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
    int n;

    n = getrandom(buffer, slen, flags);

    for (int i = 0; i < slen; i++) {
        if (buffer[i] > 32 && buffer[i] < 127) {
            // Character is printable, add to s
            s[i] = buffer[i];
        }
    }

    return n;
}
