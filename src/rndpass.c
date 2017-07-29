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
    unsigned char buffer[64];
    bzero(buffer, sizeof(buffer));
    printf("%d random bytes read\n" , randstr(buffer, sizeof(buffer), 0));
    for (int i = 0; i < 64; i++) {
        printf("%d\t%c\n", buffer[i], buffer[i]);
    }
}
