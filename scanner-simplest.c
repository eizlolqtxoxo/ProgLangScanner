/* scanner-simplest.c --- 
 * 
 * Filename: scanner-simplest.c
 * Description: 
 * Author: Serge Kruk
 * Maintainer: 
 * Created: Wed Jan 23 11:44:43 2013 (-0500)
 * Version: 
 * Last-Updated: Wed Jan 23 12:09:13 2013 (-0500)
 *           By: Serge Kruk
 *     Update #: 15
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

int main(int argc, char **argv){
  int rc;
  while ((rc=yylex())){
    switch (rc){
    case NUMBER:
      printf("We recognized a number of value %d\n", number);
      break;
    case STRING:
      printf("We recognized a string of value %s\n", string);
      break;
    case '+':
      printf ("+\n");
      break;
    case DIV:
      printf ("DIV");
      break;
    case ERROR:
      printf("ERROR");
      break;
    case ID:
      printf("ID");
      break;
    case READ:
      printf("READ");
      break;
    case WRITE:
      printf("WRITE");
      break;
    }
  }
  return 0;
}

int yylex(){
  int c;
  while ((c=getchar()) == ' ' || c == '\t')
    ;                      /* Do nothing */

  if (c == EOF)
    return 0;

  if (isdigit(c)){
    ungetc(c,stdin);
    scanf("%d", &number);
    return NUMBER;
  } else if (c=='+'||c=='-'||c=='/'||c=='*'||c=='('||c==')'){
    return c;
  } else if (c==':'){
      c=getchar();
      if (c=='=')
        return ASSIGN;
  } else if (c=='/'){
      c=getchar();
      if (c=='*'){
        c=getchar();
        }while (c != '*'){
          c=getchar();
          }if (c== '*'){
            c=getchar();
            }if (c== '/'){
              return 0;
            }
      }if (c=='\\'){
        c=getchar();
        }if (c=='n'){
          return 0;
      }else {
        return DIV;
  } else if (c=='.'){
      if(isdigit(getchar())){
        while (isdigit(getchar()));
        return NUMBER;
      } else {
          return ERROR;
      }
  } else if (isdigit(c)){
      int seen_point=0;
      int cont=1;
      while(cont){
        c=getchar();
        if (isdigit(c))
          continue;
        else if (c=='.' && !seen_point)
          seen_point=1;
        else 
          cont=0;
      }
        return NUMBER;
    /*else if (c==[0-9]){
      c=getchar();
      while (c==[0-9]){
        c=getchar();
          }if (c=='.'){
            c=getchar();
            }if (c==[0-9]){
              getchar();
            }else{
              break;
      return NUMBER;
      */
  } else if (isalpha(c)){
    if (c=='r' &&
        next_is('e') &&
        next_is('a') &&
        next_is('d'))
      return READ;
    if (c=='w' &&
        next_is('r') &&
        next_is('i') &&
        next_is('t') &&
        next_is('e'))
      return WRITE;
    while (isalnum(getchar()));
    return ID;
  } else {
    ungetc(c,stdin);
    scanf("%s", string);
    return STRING;
  }

}
/* scanner-simplest.c ends here */

/* make ./scanner-simplest in the directory
add new assignments to scanner-lex.c */