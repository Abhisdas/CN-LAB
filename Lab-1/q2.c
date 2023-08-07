 /*2.) Write a program to swap two strings which are accepted to commandline 
argument in c. */

#include <stdio.h>
#include <string.h>
void swapStrings(char **str1, char **str2) {
 char *temp = *str1; 
 *str1 = *str2; 
 *str2 = temp; 
} 
int main(int argc, char *argv[]) {
 if (argc < 3) {
 printf("Usage: %s string1 string2\n", argv[0]);
 return 1; 
 } 
 printf("Before swapping: str1 = %s, str2 = %s\n", argv[1], argv[2]);
 swapStrings(&argv[1], &argv[2]);
 printf("After swapping: str1 = %s, str2 = %s\n", argv[1], argv[2]);
 return 0; 
} 