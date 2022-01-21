#include <chrono>

#include <stdio.h>
#include <string.h>

#include "cus_string.h"

void test_function()
{
   /*
   printf("Enter a big string: ");
   char string[100];
   gets_s(string);
   
   printf("Enter a possible substring: ");
   char substring1[100];
   gets_s(substring1);
   */

   char string[] = "bigstringthatmightcontainsomething";
   char substring1[] = "might";

   printf("Attempting to find substring \"%s\" in \"%s\"\n", substring1, string);
   if (cs::strcontains(string, substring1))
   {
      printf("Found substring located at - %d\n", cs::strfind(string, substring1));
   }
   else
   {
      printf("Substring not found.\n");
   }

   char bigString[] = "I'm a big string seperated in two halves";
   char divider[] = "seperated";
   char* substring2 = cs::substring(bigString, cs::strfind(bigString, divider), cs::strlen(bigString));
   char* substring3 = cs::substring(bigString, 0, cs::strfind(bigString, divider) + 1);
   char* repairedstring = cs::strcat(substring3, substring2);

   printf("Half 1     : \"%s\"\n", substring3);
   printf("Half 2     : \"%s\"\n", substring2);
   printf("Full string: \"%s\"\n", repairedstring);
}

void my_string_functions()
{
   char string[] = "bigstringthatmightcontainsomething";
   char substring1[] = "might";
   
   int i = 0;
   int foundIndex = 0;
   while (i < 100000)
   {
      foundIndex = cs::strfind(string, substring1);
      i++;
   }
}

// GNU C
void stdlib_functions()
{
   char string[] = "bigstringthatmightcontainsomething";
   char substring1[] = "might";

   int i = 0;
   int foundIndex = 0;
   while (i < 100000)
   {
      char* ptr = strstr(string, substring1);
      
      /* This additional step finds the ss index by
         subtracting the starting address from the found
         address. */
      foundIndex = ptr - string;

      i++;
   }
}

int main()
{
   test_function();

   auto start = std::chrono::high_resolution_clock::now();
   my_string_functions();
   auto end = std::chrono::high_resolution_clock::now();
   auto cus_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
   auto cus_duration_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

   start = std::chrono::high_resolution_clock::now();
   stdlib_functions();
   end = std::chrono::high_resolution_clock::now();
   auto std_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
   auto std_duration_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
   
   printf("Custom Elapsed time: ");
   printf("[%d microseconds]", cus_duration);
   printf("[%d milliseconds]\n", cus_duration_milliseconds);

   printf("Stdlib Elapsed time: ");
   printf("[%d microseconds]", std_duration);
   printf("[%d milliseconds]", std_duration_milliseconds);

   return 0;
}