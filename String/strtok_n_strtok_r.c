/*** difference between strtok and strtok_r ********/

/* We know strtok uses static pointer inside to trace the starting location for tokenization.
 * For details check out how strtok() works.
 * char* strtok(char* str, const char* delim)
 *
 * We know static and global values are very dangerous in multithreaded environment.
 * Suppose two threads are parallely using the strtok with different strings or with same strings. It will
 * produce undefined behaviour or program will crash in many cases.
 *
 * strtok_r (strtok re-eterant) is perfect solution for this. We need to pass the save pointer from outside 
 * to this function so it can be used in multithreaded environment successfully.
 *
 * Example is in below program.
 *
 * Note: strtok_r can be used in nested forloop fot strtok_r. Say for example:
 * for(token = strtok_r(str, ",", &saveptr); token != NULL; token = strtok_r(NULL, ",", &saveptr) {
 *    .....
 *    for(token2 = strtok_r(str2, ",", &save2ptr); token2 != NULL; token_2 = strtok_r(NULL, ",", &save2ptr) {
 *    }
 * }
 *
 * Note: strtok is very dangerous in nested for loop similar to above scenario, it will give unpredected behavuor
 * or can lead to crash. The only reason is static pointer what it uses inside the function.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   char str[] = "Hello world!  Mr. Nikhil";
   char *saveptr = NULL;
   char *token = NULL;

   token = strtok_r(str, " ", &saveptr);
   while(token != NULL) {
     printf("%s\n", token);
     token = strtok_r(NULL, " ", &saveptr);
   }
   return 0;
}
