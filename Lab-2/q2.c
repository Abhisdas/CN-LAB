/*C program to find the architecture is Big or Little endian. */

#include <stdio.h>

int main ()
{

unsigned int x = 0x76513210; 
char *c = (char*) &x; 
printf ("*c is: 0x%x\n", *c);

if (*c == 0x10)

{

printf ("Underlying architecture is little endian. \n");
}

else {

printf ("Underlying arhitecture is big endian. \n");
}


return 0;
}