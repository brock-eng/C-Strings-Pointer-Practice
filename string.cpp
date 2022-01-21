#include <stdio.h>

#include <chrono>

/* Determines the length of the string */
int strlen(char* string)
{
   char* ptr = string;
   int length = 1;

   while (*ptr)
   {
      ptr++;
      length++;
   }
   return length;
}

/* Determines if the string contains the substring */
bool strcontains(char* string, char* substring)
{
   char* ptr = string;
   char* ptrss = substring;

   while (*ptr)
   {
      if (*ptr == *ptrss)
      {
         while (*ptr && *ptr == *ptrss)
         {
            ptrss++;
            ptr++;
            if (!*ptrss) return true;
         }
         ptrss = substring;
         ptr--;
      }
      ptr++;
   }
   return false;
}

/* Returns the index of substring or -1 if not found */
int strfind(char* string, char* substring)
{
   char* ptr = string;
   char* ptrss = substring;

   int index = 0;

   while (*ptr)
   {
      if (*ptr == *ptrss)
      {
         while (*ptr && *ptr == *ptrss)
         {
            ptrss++;
            ptr++;
            if (!*ptrss) return index;
         }
         ptrss = substring;
         ptr--;
      }
      ptr++;
      index++;
   }
   return -1;
}

/* Returns the substring between starting and ending indices */
char* substring(char* string, int start, int end)
{
   int len = end - start;
   char* substring = (char*)malloc(len);
   string += start;
   int i = 0;
   while (*string != 0 && i < len)
   {
      *(substring + i) = *string;
      string++;
      i++;
   }
   *(substring + len - 1) = '\0';
   return substring;
}

void function()
{
   char string[] = "bigteststringthatmightcontainthings";
   char* ptr = string;
   char substring1[] = "might";
   
   printf("Found - %d\n", strcontains(string, substring1));
   printf("Located at - %d\n", strfind(string, substring1));
   
   char* substring2 = substring(string, strfind(string, substring1), strlen(string));
   char* substring3 = substring(string, 0, strfind(string, substring1) + 1);

   printf("Substring: \"%s\"\n", substring2);
   printf("Substring: \"%s\"\n", substring3);
}

int main()
{
   auto start = std::chrono::high_resolution_clock::now();
   function();
   auto end = std::chrono::high_resolution_clock::now();
   
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
   printf("Process took %d microseconds.", duration);
   return 0;
}
