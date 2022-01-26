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

   /* Returns a copy of a given string */
   char* strcopy(char* string)
   {
      size_t size = strlen(string);
      char* copy = (char*)malloc(size);
      while (*string)
      {
         *copy = *string;
         copy++;
         string++;
      }
      *(copy) = '\0';
      return (copy - size);
   }

   /* Returns the index of substring or -1 if not found */
   int strfind(char* string, char* substring)
   {
      char* ptr = string;
      char* ptrss = substring;
      char* setpoint;

      int index = 0;

      while (*ptr)
      {
         if (*ptr == *ptrss)
         {
            setpoint = ptr;
            while (*ptr && *ptr == *ptrss)
            {
               ptrss++;
               ptr++;
               if (!*ptrss) return index;
            }
            ptrss = substring;
            ptr = setpoint;
         }
         ptr++;
         index++;
      }
      return -1;
   }

   /* Determines if the string contains the substring */
   bool strcontains(char* string, char* substring)
   {
      return strfind(string, substring) > -1 ? true : false;
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
      *(substring + len) = '\0';
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

   
   const int TOUPPERCASE = -32;

   /* converts given string to uppercase */
   char* strupp(char* string)
   {
      char* upp = strcopy(string);
      while (*upp)
      {
         if ((char)*upp >= 'a' && (char)*upp <= 'z')
         {
            *upp += TOUPPERCASE;
         }
         upp++;
      }
      return upp - strlen(string);
   }

   char* strrep(char* string, char* text, char* replacement, int startingIndex = 0, int endingIndex = -1)
   {
      char* rv = new char('n');
      return rv;
   }
}