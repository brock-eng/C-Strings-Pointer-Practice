#include <stdio.h>
#include <stdlib.h>

#include "cus_string.h"

namespace cs {
   /* Determines the length of the string */
   size_t strlen(char* string)
   {
      char* ptr = string;
      size_t length = 0;

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

   /* Returns a new string concatenated from two input strings */
   char* strcat(char* string, char* append)
   {
      char* catstring = (char*)malloc(strlen(string) + strlen(append));

      int i = 0;

      while (*string)
      {
         *(catstring + i++) = *string++;
      }
      while (*append)
      {
         *(catstring + i++) = *append++;
      }
      *(catstring + i) = '\0';

      return catstring;
   }
}