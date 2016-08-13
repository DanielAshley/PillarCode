#include <string.h>
#include <stdlib.h>
#include "kata.h"

struct Kata
{
    char *val1;
    char *val2;
    char *outputArray;
};

Kata *kata_init_values(char *val1, char *val2)
{
    Kata *k = malloc(sizeof(Kata));
    if(k == NULL)
    {
        return NULL;
    }

    k->val1 = malloc(50);
    k->val2 = malloc(50);

    k->val1 = val1;
    k->val2 = val2;
    return k;
}

char *kata_convert_IIIII_to_V(char * inputArray)
{
    char searchFor[6] = "IIIII";
    char *savedEnding;
    int pos_text = 0;
    int pos_search = 0;
    int len_search = 5;
    int len_text = strlen(inputArray);

    for (pos_text = 0; pos_text <= (len_text - len_search + pos_search); ++pos_text)
    {
        if(inputArray[pos_text] == searchFor[pos_search])
        {
            ++pos_search;
            if(pos_search == len_search) // match for IIIII found
            {
		savedEnding = malloc(len_text - (len_search-1));
		strcpy(savedEnding,"V") ;
		strcat(savedEnding, inputArray+5);
                return savedEnding;
            }
        }
        else
        {
           pos_text -= pos_search;
           pos_search = 0;
        }
    }
    return inputArray;
}

/*
//Work in Progress
char *kata_substitute_subtractives(char * val)
{
    char * outArray = malloc(50);
    char * tempArray = malloc(10);

    int pos_text = 0;
    int len_text = strlen(val);

    for (pos_text = 0; pos_text < len_text; pos_text++)
    {
printf("1: pos_text: %d,    len_text: %d,    tempArray: %s,    outArray: %s", pos_text, len_text, tempArray, outArray);

//	    sprintf(tempArray, "%d", val[pos_text]);
	    strncpy(tempArray, val+pos_text, 1);
	    strcat(outArray, tempArray);
printf("2: pos_text: %d,    len_text: %d,    tempArray: %s,    outArray: %s", pos_text, len_text, tempArray, outArray);

    } 
printf("3: pos_text: %d,    len_text: %d,    tempArray: %s,    outArray: %s", pos_text, len_text, tempArray, outArray);

    return outArray;
}
*/


char *kata_arrang_concatenated_input(Kata * k)
{
    char * outArray = malloc(strlen(k->outputArray));
    
    if((k->val1[0] == 'I') && (k->val2[0] == 'V'))
    {
        strcpy(outArray, k->val2);
        strcat(outArray, k->val1); // Concatenate both values
    }
    else
    { 
        strcpy(outArray, k->val1);
        strcat(outArray, k->val2); // Concatenate both values
    }

    return outArray;
}


char *kata_add(Kata * k)
{
    free(k->outputArray);  // Make sure to free up previously used memory
    k->outputArray = malloc(50); // allocating needed memory for this addition

//Work in Progress
//    k->val1 = kata_substitute_subtractives(k->val1);
//    k->val2 = kata_substitute_subtractives(k->val2);
//    char *tempVal1 = kata_substitute_subtractives(k->val1);
//    char *tempVal2 = kata_substitute_subtractives(k->val2);
//    strcpy(k->val1, tempVal1);
//    strcpy(k->val2, tempVal2);
    

    k->outputArray = kata_arrang_concatenated_input(k);
    
    if(strcmp(k->outputArray, "IIII") == 0)
    {
        free(k->outputArray);
        k->outputArray = "IV";
    }
    k->outputArray = kata_convert_IIIII_to_V(k->outputArray);
    return k->outputArray;
}

void kata_free(Kata *k)
{
    free(k);
    return;
}
