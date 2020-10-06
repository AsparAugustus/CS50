#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int shift(char c);

string error_message = "Usage: ./vigenere keyword\n";

int main(int argc, string argv[])

{
    //check if argv has an input
    if(argv[1] == NULL)
    
         {
             printf("%s", error_message);
               return 1;
          }
          
    //assign length of argv[1] to variable
    int key_length = strlen(argv[1]);


    

    //check numbers of arguments
    if(argc == 2)
       {   
        //loop for strings of argv
        for(int i = 0; i < key_length; i++)
       { 
            //check if each char in argv is alphabetical        
             int isalpha = isalpha(argv[1][i]);

                if(isalpha != 0)
                { 
                //if alpha
                //do nothing
                }
                else
                    {
                        printf("%s", error_message);
                        return 1;
                    }
          
        
       }
        
    }
    else
    {
        printf("%s", error_message);
        return 1;
    }
    

    string plain_text = get_string("Input plain text: ");

    //find out length of plain_text

    int plaintext_length = strlen(plain_text);

    //allocate another slot for plaintext, ready to be converted to cipher

    string cipher_text = plain_text;
    printf("ciphertext: ");
    

            //iterate over each char of plain_text
            for(int i = 0, j = 0; i < plaintext_length; i++)
             {
                int key = shift(argv[1][j]);

                int n, x;

                //check if each character is upper or lower case
                n = isupper(cipher_text[i]);
                if(n != 0 )
                {
                    n = 65;
                }
                else
                {   
                    n = 97;
                }

                 //shift plaintext in ciphertext entry to ints

                x = isalpha(plain_text[i]);
            if(x != 0)
             {
                 cipher_text[i] = (shift(cipher_text[i]) + key) % 26 + n;

                 j = (j + 1) % key_length;
                 printf("%c", cipher_text[i]);
             }
             else
                    {
                        printf("%c", plain_text[i]);
                    }

                  }
                  printf("\n");
        }   

int shift(char c)
    {
        //check for uppercase
        if(c >= 65 && c <= 90)
       { 
         c -= 65;        
       }
        if(c >= 97 && c <= 122)
       {
        c -= 97;
         }
         else
         {
             //
         }

     return c;
    
    }

