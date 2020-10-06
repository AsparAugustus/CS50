def RepresentsInt(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False
        
def invalid_input_prompt():
    print("Invalid height input.", end ="\n")
    
##def delete_previous_line():
##    CURSOR_UP_ONE = '\x1b[1A'
##    ERASE_LINE = '\x1b[2K'
##    print(CURSOR_UP_ONE)
##    print(ERASE_LINE)
##        print(ERASE_LINE)

not_valid_input = True
while not_valid_input == True:
    height = input("Enter the height of pyramid: ")
    if RepresentsInt(height) == False:
        invalid_input_prompt()
        continue
    elif int(height) not in range(1, 7):
        invalid_input_prompt()
        continue
    else:
        height = int(height)
        not_valid_input = False

#print pyramid, with spaces equals to the amount of height in decrements
#and with increasing hashes, starting from the values of 0 to height
for i in range(height + 1):
    spaces = height - i
    print(" "*spaces, end = "")
    print("#"*i, end = "")
    print("  ", end="")
    print("#"*i)
    
