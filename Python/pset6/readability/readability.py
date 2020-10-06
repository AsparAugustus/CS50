import cs50
import re

text = input("Text here: ")


# Define the three functions

# Find any letters in the alphabet, add to letters counter
def find_letters():
    letters = 0
    pattern = re.compile(r'[a-zA-Z]')
    matches = pattern.finditer(text)

    for match in matches:
        letters += 1

    return(letters)

#Find any words - with the pattern of one or more spaces with a letter
#immedately after, count starts from 1.    
def find_words():
    words = 1
    pattern = re.compile(r'[\s]+["]?[a-zA-Z]')
    matches = pattern.finditer(text)

    for match in matches:
        words += 1

    return(words)

#Find snetences - with the pattern of any amount of letters with a period,
#exclaimation or a question mark.    
def find_sentences():
    sentences = 0
    pattern = re.compile(r'[a-zA-Z]+[.|!|?]')
    matches = pattern.finditer(text)

    for match in matches:
        sentences += 1

    return(sentences)
    
letters = find_letters()
words = find_words()
sentences = find_sentences()

# index = 0.0588 * L - 0.296 * S - 15.8
# L is average of letters per 100 words
# S is average number of sentences per 100 words

L = letters/words*100
S = sentences/words*100

index1 = (0.0588 * L) - (0.296 * S) - 15.8
index = round((0.0588 * L) - (0.296 * S) - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")





