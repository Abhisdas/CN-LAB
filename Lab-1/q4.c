/* 4.) Write a program to give an example of using array of structure to passing through function in c. */
#include <stdio.h>
#include <string.h>
struct Student { 
 char name[50];
 int rollNumber; 
};
void displayStudents(struct Student students[], int size) {
 printf("Student Details:\n");
 for (int i = 0; i < size; i++) {
 printf("Name: %s, Roll Number: %d\n", students[i].name, 
students[i].rollNumber);
 } 
} 
int main() {
 struct Student classA[3];
 strcpy(classA[0].name, "Abhishek");
 classA[0].rollNumber = 2565; 
 strcpy(classA[1].name, "Aayush");
 classA[1].rollNumber = 523; 
 strcpy(classA[2].name, "Aarav");
 classA[2].rollNumber = 3574; 
 displayStudents(classA, 3);
 return 0; 
}