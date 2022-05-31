/*
 * Carlysse Nycole Castro
 * CS 320
 * Summer 2021
 */

#include <stdio.h>

int inputArrSize = 0;
int charArrSize = 0;

struct FREQ_COUNT {
    // characters
    char charInInput;
    // counts
    int charFreq;
};
 typedef struct FREQ_COUNT fq_c;

 // Counts frequency of characters in a given string.
 // Input: pointer to beginning of string.
 // Output:
 // Shows the results of the given frequency count.
 // Input: a fq_c object with the data to display.
 // Screen Output:
 // 'a' -- 4
 // 'l' -- 1
 // '.' -- 4
void countCharFrequency(char*, char*);

// Gets all existing chars from the input text from user
// and stores it in a char array
char* getCharsInTxt(char*);

// Gets the array size of the user's input text/string
void getInputArrSize(char*);

 // Gets the line of input text from the user to use in the frequency count.
 // Returns: pointer to beginning of the user input.
 char* getTextFromUser();


 void countCharFrequency(char* toProcess, char* charInArr) {
     /* initializes array of FreqCount structs */
     fq_c FreqCount[500];
     /* Contains user input string */
     char *userInput = toProcess;
     /* Contains individual characters that exist in input string */
     char *charInTxt = charInArr;
     char currentChar;

     printf("\n");
     printf("       ~ R E S U L T S ~ \n");
     /* outer for loop: loops through charInArr array */
     for (int k = 0; k < charArrSize; k++) {
         currentChar = charInTxt[k];
         /* stores char in FreqCount struct */
         FreqCount[k].charInInput = currentChar;
         FreqCount[k].charFreq = 0;

         /* inner loop: counts how many occurrences of each char exists in string */
         printf("character frequency for: '%c' -- ", FreqCount[k].charInInput);
         for (int n = 0; n < inputArrSize; n++) {
             if (userInput[n] == charInTxt[k]) {
                 /* stores char frequency in FreqCount struct */
                 FreqCount[k].charFreq++;
             }
         }
         printf("%d\n", FreqCount[k].charFreq);
     }
     printf("\n");
     printf("Complete.\n");
 }

 char* getTextFromUser() {
     char userText[1000000];
     printf("Enter text to analyze: \n");
     fgets(userText, 1000000, stdin);
     char *ptrUserText = userText;
     return ptrUserText;
 }

 char* getCharsInTxt(char* toProcess) {
     /* initializes individual char array */
     static char charInArr[500];
     char *userInput = toProcess;
     int currIndex = 1;
     /* Tracks if char is found in array or not */
     int foundInArr;

     charInArr[0] = userInput[0];
     /* outer loop: loops through user input text */
     for (int i = 0; i < inputArrSize; i++) {
         foundInArr = 0;

         /* inner loop: loops through individual character array*/
         for (int j = 0; j < currIndex; j++) {
             /* if statement: determines whether char is already in the array */
             if (charInArr[j] == userInput[i]) {
                 foundInArr = 1;
             }
         }
         /* adds character to charArray if it doesn't exist in it already */
         if (foundInArr == 0) {
             charInArr[currIndex] = userInput[i];
             currIndex++;
         }
     }

     /* quick determination of charInArr size */
     int size = 0;
     for(int x = 0; x < currIndex; x++) {
         size++;
     }
     charArrSize = size;

     return charInArr;
 }

 void getInputArrSize(char* inputTxtArr) {
    char *pInput;
    for (pInput = inputTxtArr; *pInput != '\0'; pInput++) {
        inputArrSize++;
    }
    inputArrSize--;
}

 // Director for the program.
int main() {
    char *userInput = getTextFromUser();
    getInputArrSize(userInput);
    char *charInTxt = getCharsInTxt(userInput);
    countCharFrequency(userInput, charInTxt);
    return 0;
 }

