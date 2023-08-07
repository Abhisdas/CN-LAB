
/* 1.) write a program to swap two numbers using call byreference in c.*/
#include <stdio.h>
void swap(int *a, int *b) {
 int temp = *a; 
 *a = *b; 
 *b = temp; 
} 
int main() {
 int num1, num2; 
 printf("Enter two numbers: ");
 scanf("%d %d", &num1, &num2);
 printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
 swap(&num1, &num2);
 printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
 return 0; 
} 





 
