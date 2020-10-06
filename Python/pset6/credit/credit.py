from cs50 import get_string
import re

is_number = False
while is_number == False:
    number = get_string("Number: \n")
    try:
        int(number)
        is_number = True
    except:
        pass
    

length = len(number)

double = []

# insert each string into list
for i in range(0, length):
    double.append(number[i])

#make a copy of the list
num_list = double.copy()

#multiply every other character by 2, starting from second-to-last digit, and stored in double array
#set end range as -1, otherwise it would stop at 0
for i in range(length-2, -1, -2):
    double[i] = (int(number[i])*2)
    
    if len(str(double[i])) > 1:
        ##add the 2 digits together
        double[i] = int(str(double[i])[0]) + int(str(double[i])[1])


result = list( map(int, double))
str_result = str(sum(result))

if str_result[1] == "0":
    if (length == 15 and num_list[0] == '3' and num_list[1] in ['4', '7']):
        print("AMEX")
    elif (length == 16 and num_list[0] == '5' and num_list[1] in ['1', '2', '3', '4', '5']):
        print("MASTERCARD")
    elif (length in range(13, 17) and num_list[0] == '4'):
        print("VISA")
    
else:
    print("INVALID")
        