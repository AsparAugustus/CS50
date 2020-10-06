# -*- coding: utf-8 -*-
"""
Created on Sun Sep 13 19:17:52 2020

@author: Calvin
"""

import sys
import csv

# Declaring command line inputs

try:
    database_file = sys.argv[1]
    dna = sys.argv[2]
except Exception as e:
    raise Exception(str(e))

def main():
    with open(database_file, 'r') as csv_file:
        csv_reader = csv.DictReader(csv_file)
        
        
        #get file names from DictReader object and store in a list
        headers = csv_reader.fieldnames
        
        
        #create an empty list to store longest STR counts
        #where [0] = 2nd header of CSV (1st = name)
        str_count = []
        names_list = []
        
        for line in csv_reader:
            names_list.append(line['name'])
            
        #extract string from header and search in genome, by means of only reading
        #from second element to last
        line_iter = iter(headers[1:])
        for row, item in enumerate(line_iter, start=1):
            
                max_repeats = find_max(headers[row])
                #print(max_repeats)
                str_count.append(str(max_repeats))
        
        #This is the part where each person's STR repeats are read:
        #rewind csv file to the start, and forward 1, as to start reading from 2nd row
        csv_file.seek(0)
        csv_nreader = csv.reader(csv_file)
        next(csv_nreader)
        
        
        
        #This is the part where each person's STR are sorted into an appropriate
        #data structure, to be compared against the analysed STR
        found = False
        for line in csv_nreader:
            
            #trim off first column, and assign rest of the elements of STR
            #into a list called STR
            STR = line[1:]
            
            
            
            #If a match is found, print off name of the person and terminate loop
            if compare(STR, str_count) == True:
                found = True
                print(line[0])
                break
            
    #if a match still isn't found, print into stdout      
    if found == False:
        print("No match.")
            

                
def compare(STR, str_count):
    
    #function to compare if person's STR is equal to analysed STR
    #return true if true
    
      if STR == str_count:
          return True
      return False
        

def find_max(s):
    
    sequence = str(s)
    
    file = open(dna, 'r')
    genome = file.read()
    
    length_sequence = len(sequence)
    length_genome = len(genome)
    
    i = 0
    j = length_sequence
    
    max = 0
    
    #search through whole genome
    for x in range(length_genome):
        
        #if found, initalise temp counter
        if genome[i:j] == sequence:
            temp = 0
            
            #look for repeats within the range of STR pattern
            #update start:end each time a match is found,
            #and update temp counter
            
            while genome[i:j] == sequence:
                i += length_sequence
                j += length_sequence
                temp += 1
            
            #if a new maximum repeat is found, update max counter
            if temp > max:
                max = temp
                
                
        else:
            i += 1
            j += 1
    
    return max
            


        
if __name__ == '__main__':
    main()


  