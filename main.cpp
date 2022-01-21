#include <chrono>

#include <stdio.h>

#include "cus_string.h"

void test_function()
{
   printf("Enter a big string: ");
   char string[100];
   gets_s(string);
   
   printf("Enter a possible substring: ");
   char substring1[100];
   gets_s(substring1);

   printf("Attempting to find substring \"%s\" in \"%s\"\n", substring1, string);
   if (strcontains(string, substring1))
   {
      printf("Found substring\n");
      printf("Located at - %d\n", strfind(string, substring1));
   }
   else
   {
      printf("Substring not found.\n");
   }

   char bigString[] = "I'm a  big string seperated in two halves";
   char divider[] = "seperated";
   char* substring2 = substring(bigString, strfind(bigString, divider), strlen(bigString));
   char* substring3 = substring(bigString, 0, strfind(bigString, divider) + 1);

   printf("Substring2: \"%s\"\n", substring3);
   printf("Substring3: \"%s\"\n", substring2);
}

int main()
{
   auto start = std::chrono::high_resolution_clock::now();
   test_function();
   auto end = std::chrono::high_resolution_clock::now();

   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
   auto duration_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
   printf("Elapsed time: ");
   printf("[% d microseconds]", duration);
   printf("[%d milliseconds]", duration_milliseconds);
   return 0;
}