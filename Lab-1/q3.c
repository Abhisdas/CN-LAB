 /*3 Write a program to use structure and access the structure member to a 
structure pointer in c. (declare any structure and those structure must have 
structure member and 2-3 variable) */

#include <stdio.h>
struct Person { 
 char name[50];
 int age; 
 float height; 
};
int main() {
 struct Person person1 = {"Abhishek", 21, 180.5};
 struct Person *ptrPerson = &person1; 
 printf("Name: %s\n", ptrPerson->name);
 printf("Age: %d\n", ptrPerson->age);
 printf("Height: %.2f\n", ptrPerson->height);
 return 0; 
} 