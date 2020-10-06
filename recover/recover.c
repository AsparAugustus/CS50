#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>


#define DATA 512 //to eliminate magic numbers

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    
    if (file == NULL)
    {
        printf("File does not exist.\n");
        return 1;
    }
    
    char filename[8];
    
    typedef unsigned char BYTE; //to define one byte chars BYTE
    BYTE buffer[DATA]; //to declare array of BYTEs with size DATA
    
    FILE* img; //temporary file to write to
    
    int counter = 0;
    
    //while(!feof(file)) not sure if it works
    while(fread(buffer, sizeof(buffer), 1, file) == 1)
    {
        //if JPEG signature found
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(counter > 0)
            {
                fclose(img);
            }
            
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            fwrite(buffer, sizeof(buffer), 1, img);
            counter++;
        }
        else //no JPEG signature found
        {
            if(counter > 0) //if already found, continue writing
            {
                fwrite(buffer, sizeof(buffer), 1, img);
            }
            
            //if JPEG not found yet, do nothing
        }
        
     
    }
    

    fclose(file);
    
    
    fclose(img);
    
    return 0;
    
}


