#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include <cs50.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //get an average of 3 values and call it average
            float average = round((float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            
            //then assign average to each one of the RGBs
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //convert each value via a pre-made sepia algorithm 
            int sepiaRed = round((float)(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((float)(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((float)(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));
            
            if(sepiaRed > 255)
            {
               sepiaRed = 255;
            }
            
            if(sepiaGreen > 255)
            {
               sepiaGreen = 255;
            }
            
            if(sepiaBlue > 255)
            {
               sepiaBlue = 255;
            }
           
            //then assign average to each one of the RGBs
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, n = width/2; j < n; j++)
        {
            //find pixels on maximal distance apart, flip j values via a temp variable
            
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
            
            
          
        }
    }
    
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temp array to store box blurred pixels 
    RGBTRIPLE temp[height][width];
    

    
    //iterate over every element of array
    for (int h = 0; h < height; h++) //loop vertically
    {

        for (int w = 0; w < width; w++) //loop horizontally
        {
            //declare variables, the sum of all added RGBT colours
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            int counter = 0;
            
            //calculate average of each elements of surrounding 3x3 box
            for (int BlurH = h - 1; BlurH < h + 2 && BlurH < height; BlurH++)
            {
                if(BlurH < 0)
                {
                    BlurH = 0;
                }
                
                 for (int BlurW = w - 1 ; BlurW < w + 2 && BlurW < width; BlurW++)
                {
                       if(BlurW < 0)
                       {
                           BlurW = 0;
                       }
                       
                      sumBlue += image[BlurH][BlurW].rgbtBlue;
                      sumGreen += image[BlurH][BlurW].rgbtGreen;
                      sumRed += image[BlurH][BlurW].rgbtRed;
                      counter ++;
                       
                }
            }
            
            //find average of sums and assign them to array
            temp[h][w].rgbtBlue = round((float)sumBlue / counter);
            temp[h][w].rgbtGreen = round((float)sumGreen / counter);
            temp[h][w].rgbtRed = round((float)sumRed / counter);
            
            
        }
    }
    
    //iterate over every element of array and transfer values over
    for (int h = 0; h < height; h++) //loop vertically
    {

        for (int w = 0; w < width; w++) //loop horizontally
        {
    
            image[h][w].rgbtBlue = temp[h][w].rgbtBlue;
            image[h][w].rgbtGreen = temp[h][w].rgbtGreen;
            image[h][w].rgbtRed = temp[h][w].rgbtRed;
        }
    }
    
    
    
    return;
}