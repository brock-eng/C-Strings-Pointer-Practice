#include <chrono>

#include <stdio.h>
#include <string.h>

#include "cus_string.h"

void test_function()
{
   // Copy a string
   char stringToCopy[] = "Test string to be copied '%#$";
   char* copiedString = cs::strcopy(stringToCopy);
   printf("Original: %s\nCopy: %s\n", stringToCopy, copiedString);

   // Substring
   char string[] = "xxx";
   char substring1[] = "aaa";
   printf("Attempting to find substring \"%s\" in \"%s\"\n", substring1, string);
   if (cs::strcontains(string, substring1))
      printf("Found substring located at - %d\n", cs::strfind(string, substring1));
   else
      printf("Substring not found.\n");

   char bigString[] = "I'm a big string seperated in two halves";
   char divider[] = "seperated";
   char stringTest[] = "word";

   // Testing string lengths
   int strLength2 = cs::strlen(stringTest); // 4
   printf("Length 4  : %d \n", strLength2);
   int strlength = cs::strlen(bigString); // 40
   printf("Length 40 : %d \n", strlength);


   // Substring / strfind testing
   char* half1 = cs::substring(bigString, 0, cs::strfind(bigString, divider));
   char* half2 = cs::substring(bigString, cs::strfind(bigString, divider), cs::strlen(bigString));
   char* repairedstring = cs::strcat(half1, half2);

   printf("Half 1     : \"%s\"\n", half1);
   printf("Half 2     : \"%s\"\n", half2);
   printf("Full string: \"%s\"\n\n", repairedstring);

   // Uppercase converter
   char lowercase[] = "here's a string";
   char* uppercase = cs::strupp(lowercase);

   printf("Lowercase string: %s\n", lowercase);
   printf("Uppercase string: %s\n", uppercase);


}

void my_string_functions()
{
   int numChars = 1000000;
   char* bigstring = (char*)malloc(numChars * sizeof(char));
   for (int i = 0; i < numChars - 1; i++)
   {
      if (i == numChars / 2) bigstring[i] = 'x';
      else
         bigstring[i] = 'a';
   }
   bigstring[numChars - 1] = 'b';

   char substring1[] = "x";
   
   int i = 0;
   int foundIndex = 0;
   while (i < 100)
   {
      foundIndex = cs::strfind(bigstring, substring1);
      i++;
   }
}

// GNU C
void stdlib_functions()
{
   int numChars = 1000000;
   char* bigstring = (char*)malloc(numChars * sizeof(char));
   for (int i = 0; i < numChars - 1; i++)
   {
      if (i == numChars / 2) bigstring[i] = 'x';
      else
         bigstring[i] = 'a';
   }
   bigstring[numChars - 1] = 'b';

   char substring1[] = "x";

   int i = 0;
   int foundIndex = 0;
   while (i < 100)
   {
      char* ptr = strstr(bigstring, substring1);
      
      /* This additional step finds the ss index by
         subtracting the starting address from the found
         address. */
      foundIndex = ptr - bigstring;

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