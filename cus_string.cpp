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
   /* https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_string-search_algorithm */
   int strfind(char* haystack, char* needle)
   {
      char* ptr = haystack;
      char* ptrss = needle;
      char* setpoint;

      int index = 0;
      int skip = 0;

      /* While ptr is not '\0'
         (end of string)
         */
      while (*ptr)
      {
         /* Check if haystack char matches first char of the needle */
         if (*ptr == *ptrss)
         {
            /* Compare each subsequent character until either nonmatch or
               end of either string.  
               End of haystack -> return not_found
               End of needle   -> return found index
               nonmatch        -> continue searching
               */
            setpoint = ptr;
            while (*ptr == *ptrss)
            {
               ptrss++;
               ptr++;
               if (!*ptrss) return index;
               if (!*ptr) return -1;
            }
            /* When a nonmatch occurs, move the 
               haystack pointer until the nonmatched char occurs.
               We can skip the next n-amount of indices since we 
               are guaranteed to not find a match before that point.
               */
            while (*ptr != *ptrss)
            {
               ptr++;
               skip++;
               if (!*ptr) return -1;
            }
            ptr = setpoint + skip;
            ptrss = needle;
            index += skip;
         }
         else
         {
            ptr++;
            index++;
         }
         skip = 0;
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