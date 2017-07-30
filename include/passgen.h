/*                                                                             
 * passgen.h                                                                   
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

#ifndef PASSGEN_h
#define PASSGEN_h

#define _GNU_SOURCE

#include <unistd.h>
#include <linux/random.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

const char base64_chars[64];
int countnull(unsigned char buffer[], size_t buflen);
int getrandom(void *buffer, size_t buflen, unsigned int flags);
int randstr(unsigned char s[], size_t slen, unsigned int flags, bool ext);
int randstr_alt(char s[], size_t slen, unsigned int flags);

#endif
