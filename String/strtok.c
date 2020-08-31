/***** read only string gives vore dump with strtok **************/
/** strtok have a static pointer to point the beginning of the string after extracting each token.
 * after extracting each token it appends with '\0' .
 *
 * Note: We can implement our own string tokenizer with help of static pointer.
 * char* mystrtok(char* str, const char * del)
 * {
 *   static char* ptr = NULL;
 *   if(str != NULL) {   // string came first time, assign ptr to string
 *      ptr = str;
 *      // return (dynamic array containing the first token)
 *      // append char after token (del) as '\0'
 *      // move the static pointer to beginning of the next token
 *   } else {            // NULL came to receive next token.
 *      // return (dynamic array containing the token)
 *      // append char after token (del) as '\0'
 *      // move the static pointer to beginning of the next token       
 *   }
 *   Note: We can achieve it with array of delimeter also for multi delimeter tokenizing
 * }
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void DoIt(char* str)
{
   printf("incomin string is: %s\n", str);
   char str2[30]={0};
   snprintf(str2, sizeof(str2), "%s", str);  
   char* token = NULL;
   char del[2]=",";
   token = strtok(str2, del);  // if we'll use str direct here instead of str2 then core dump will happen
   while(token != NULL) {
      printf("%s\n", token);
      token = strtok(NULL, del);
   }
   printf("string after tokenizing: %s\n", str2);
   return; 
}

int main()
{
  char* str = "hello, nikhil, how, are, you";
  DoIt(str);
  return 0;
}

// strcpy, strncpy, snprintf
