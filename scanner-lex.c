/* scanner-lex.c --- 
 * 
 * Filename: scanner-lex.c
 * Description: 
 * Author: Serge Kruk
 * Maintainer: 
 * Created: Wed Jan 23 12:37:05 2013 (-0500)
 * Version: 
 * Last-Updated: Wed Jan 23 12:48:30 2013 (-0500)
 *           By: Serge Kruk
 *     Update #: 5
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301, USA.
 */

/* Code: */
#include <stdio.h>
#include <stdlib.h>
/* A couple of globals */
int lineno = 0;
int number;
char string[100];
#define NUMBER 1
#define STRING 2
#define ASSIGN 3
#define DIV 4
#define ERROR 5
#define ID 6
#define READ 7
#define WRITE 8

int yywrap(){
}
int main(int argc, char **argv){
  int rc;
  while ((rc=yylex())){
    switch (rc){
    case NUMBER:
      printf("At line %d, we recognized a number of value %d\n", lineno, number);
      break;
    case STRING:
      printf("At line %d, we recognized a string of value %s\n", lineno, string);
      break;
    }
  }
  return 0;
}


/* scanner-lex.c ends here */
