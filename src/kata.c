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

char *kata_add(Kata * k)
{
    free(k->outputArray);  // Make sure to free up previously used memory
    k->outputArray = malloc(strlen(k->val1)+strlen(k->val2)); // allocating needed memory for this addition
    
    strcpy(k->outputArray, k->val1);
    strcat(k->outputArray, k->val2); // Concatenate both values
    
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
