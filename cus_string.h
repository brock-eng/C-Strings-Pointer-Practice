#pragma once

namespace cs {
   size_t strlen(char* string);
   bool strcontains(char* string, char* substring);
   int strfind(char* string, char* substring);
   char* substring(char* string, int start, int end);
   char* strcat(char* string, char* append);
}