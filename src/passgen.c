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

/* Our 64 characters for the randstr_alt. Note that this is not the standard
 * base 64 character set: the '/' is replaced with the '$'
 */
const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+$";

// Count null bytes in string
int countnull(unsigned char buffer[], size_t buflen)
{
    int n = 0;
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

/* Generate random string, store in s, slen long. Returns total read random
 * bytes. s will only contain standard printable ASCII characters.
 */
int randstr(unsigned char s[], size_t slen, unsigned int flags)
{
    unsigned char buffer[slen];
    int n = 0, j = 0;

    /* Optimization possibility: instead of getting slen new random
     * bytes each run, decrease this ammount, but make sure that the amount
     * of reads stays minimal.
     */
    while (countnull(s, slen) > 0) {
        bzero(buffer, slen);
        n += getrandom(buffer, slen, flags);
        for (int i = 0; i < slen; i++) {
            /* This if statement defines which ASCII characters will be thrown
             * away, maybe define this in a header file for better customizabilitiy?
             */
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

/* Generate a random string. Instead of throwing away all non-ASCII standard
 * printable characters, it uses a different way to generate a string from the
 * random bytes. This is more CPU intensive, but draws less entropy from /dev/urandom
 * Returns the amount of read random bytes. Afterwards, s will be filled with
 * printable standard ASCII characters.
 */
int randstr_alt(char s[], size_t slen, unsigned int flags)
{
    int blen = slen/8;
    unsigned long buffer[blen];
    int n, j = 0, k = blen - 1;

    bzero(s, slen);
    bzero(buffer, blen);

    n = getrandom(&buffer, sizeof(buffer), flags);
    for (int i = 0; i < blen; i++) {
        printf("%lu\t%lx\t%d\n", buffer[i], buffer[i], i);
    }

    long p = buffer[k];
    if (p < 0)
        p *= -1;
    while (p > 0) {
        printf("%lu\n", p);
        s[j++] = base64_chars[(p % 64)];
        p = p / 64;
        if (p < 100)
            p = buffer[--k];
    }
    printf("%s\n", s);
    return n;
}
