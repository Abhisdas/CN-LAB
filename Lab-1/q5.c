/* 5 Write a program to implement the nested structure with a suitable example in c.*/
#include <stdio.h>
struct Date { 
 int day; 
 int month; 
 int year; 
};
struct Student { 
 char name[50];
 struct Date joinDate; 
};
int main() {
 struct Student std = {"Abhishek Das", {14, 8, 2021}};
 printf("Student Name: %s\n", std.name);
 printf("Join Date: %d-%d-%d\n", std.joinDate.day, std.joinDate.month, 
std.joinDate.year);
 return 0; 
} 