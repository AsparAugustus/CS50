#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <ctype.h>

bool valid_triangle(float x, float y, float z);

int main(void)
{
    
    
    valid_triangle(4, 4, 6);
}

bool valid_triangle(float x, float y, float z)
{
    if(x <= 0 || y <= 0 || z <= 0)
    {
        return false;
        printf("false");
    }
    
    if(x + y <= z || x + z <= y || y + z <= x)
    {
          printf("false");
        return false;
      
    }
      printf("true");
    return true;
}