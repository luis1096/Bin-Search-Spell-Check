/*
 * spell checks list of English words given in their correct forms in the ﬁle 
 * entitled “dictionary.txt”
 */

/* 
 * File:   main.c
 * Author: luisq
 *
 * Created on August 2, 2020
 */

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int binsearch(char* dictionaryWords[], int listSize, char* keyword)
{
    int mid,low = 0, high = listSize - 1;
    while(high >= low)
    {
        mid = (low + high)/2;
        if(strcmp(dictionaryWords[mid],keyword) < 0)
        low = mid + 1;
        else if(strcmp(dictionaryWords[mid],keyword) > 0)
        high = mid - 1;
        else
        return mid;
    }
    return -1;
}

int spellCheck(char* word, char* dictionaryFileName)
{
    //opening file pointer and reading file
    FILE* filePointer = fopen(dictionaryFileName, "r");
    FILE* tempFilePointer = fopen(dictionaryFileName, "r");
    int size = 0;//words in dictionary.txt
    char temp[50];
    
    while(!feof(tempFilePointer))//while not end of file
    {
        fscanf(tempFilePointer, "%s", &temp);//reads word from file to temp
        size++;//increment dictionary size
    }
    char* dictionaryWords[size];//array of dictionary.txt words
    
    for(int i = 0; !feof(filePointer); i++)//while not end of file
    {
       fscanf(filePointer, "%s", &temp);//reads word from file to temp
       dictionaryWords[i] = malloc(sizeof(temp) + 1);//allocate memory for word
       strcpy(dictionaryWords[i], temp);//copying temp to array of words
    }
    fclose(filePointer);//close file
    //if binSearch == -1, word does not exist (spelled wrong) 
    if(binsearch(dictionaryWords, size, word) == -1)
    {
        return 0;
    } 
    else//word exists (spelled correct)
    {
        return 1;
    }
}
