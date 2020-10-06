#include <stdio.h>
#include <cs50.h>

int collatz(int n);
int i = 0;

int main(void)
{
    int num = get_int("Integer input: ");
    printf("\n");

    int n = num;

    
    
    collatz(num);

    
}

int collatz (int n)
{
    
    
             if(n == 1)
             {
                printf("Steps: %i\n", i);
              return 1;
             }
    
             if(n % 2 == 0)
            {
              printf("%i\n", n);    
              i++;
              return collatz(n / 2);
             
            }
             else
            {
              printf("%i\n", n);
             i++;
                return collatz(n * 3 + 1);
        
              }
             
         
         
 }
    
    

