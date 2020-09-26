// https://www.tutorialspoint.com/cprogramming/c_pointers.htm

#include <stdio.h>

int main () {

   int  var1;
   char var2[10];

   printf("Address of var1 variable: %x\n", &var1  );
   printf("Address of var2 variable: %x\n", &var2  );

   return 0;
}

/*
Address of var1 variable: 44664518
Address of var2 variable: 4466451e
*/
