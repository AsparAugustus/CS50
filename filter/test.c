#include <stdio.h>
#include "helpers.h"
#include <cs50.h>

int main(void)
{
   int x = get_int("type in number here and it will get divded by 2: \n");
   x = x/2;
   
   printf("%i", x);
    
}