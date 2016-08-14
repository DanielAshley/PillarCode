#include <stdio.h>
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

    k->val1 = malloc(20);
    k->val2 = malloc(20);
    k->outputArray = malloc(20);

    k->outputArray[0] = '\0';
    k->val1 = val1;
    k->val2 = val2;
    return k;
}

char *kata_convert_low_to_high(char * inputArray)
{
    int len_text = strlen(inputArray);

    char searchFor[6] = "VIIII";
    char *savedEnding;
    int pos_text = 0;
    int pos_search = 0;
    int len_search = 5;

    for (pos_text = 0; pos_text < len_text; ++pos_text)
    {
        if(inputArray[pos_text] == searchFor[pos_search])
        {
            ++pos_search;
            if(pos_search == len_search) // match for IIII (ie:IV) found
            {
		savedEnding = malloc(len_text - (len_search-1));
		strcpy(savedEnding,"IX");
		strcat(savedEnding, inputArray+5);
                printf("inputArray: %s    savedEnding: %s\n", inputArray, savedEnding);
                return kata_convert_low_to_high(savedEnding);
            }
        }
        else
        {
           pos_text -= pos_search;
           pos_search = 0;
        }
    }

    strcpy(searchFor,"IIIII") ;
    pos_text = 0;
    pos_search = 0;
    len_search = 5;

    for (pos_text = 0; pos_text < len_text; ++pos_text)
    {
        if(inputArray[pos_text] == searchFor[pos_search])
        {
            ++pos_search;
            if(pos_search == len_search) // match for IIIII (ie:V) found
            {
		savedEnding = malloc(len_text - (len_search-1));
		strcpy(savedEnding,"V") ;
		strcat(savedEnding, inputArray+5);
                printf("inputArray: %s    savedEnding: %s\n", inputArray, savedEnding);
                return kata_convert_low_to_high(savedEnding);
            }
        }
        else
        {
           pos_text -= pos_search;
           pos_search = 0;
        }
    }


    strcpy(searchFor,"IIII") ;
    pos_text = 0;
    pos_search = 0;
    len_search = 4;
    
    for (pos_text = 0; pos_text < len_text; ++pos_text)
    {
        if(inputArray[pos_text] == searchFor[pos_search])
        {
            ++pos_search;
            if(pos_search == len_search) // match for IIII (ie:IV) found
            {
		savedEnding = malloc(len_text - (len_search-1));
		strcpy(savedEnding,"IV");
		strcat(savedEnding, inputArray+4);
                printf("inputArray: %s    savedEnding: %s\n", inputArray, savedEnding);
                return kata_convert_low_to_high(savedEnding);
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


char *kata_substitute_subtractives(char * val)
{
    char searchFor[3] = "IV";
    char *savedEnding = malloc(strlen(val));
    int pos_text = 0;
    int pos_search = 0;
    int len_search = 2;
    int len_text = strlen(val);
    int extraSpace = 0;

    for (pos_text = 0; pos_text < len_text; ++pos_text)
    {
        savedEnding[pos_text+extraSpace] = val[pos_text];
        if(val[pos_text] == searchFor[pos_search])
        {
            ++pos_search;
            if(pos_search == len_search) // match for IV found
            {
                extraSpace = 2;
                savedEnding[pos_text] = 'I';
                savedEnding[pos_text+1] = 'I';
                savedEnding[pos_text+2] = 'I';
                pos_search = 0;
            }
        }
        else
        {
           pos_search = 0;
        }
    }
    savedEnding[pos_text+extraSpace] = '\0';
    return savedEnding;
}


char *kata_arrang_concatenated_input(Kata * k)
{
    char * outArray = malloc(strlen(k->outputArray));
    char * pch = malloc(strlen(k->outputArray));
    char * characterV = "V";
    char * characterI = "I";

    outArray[0] = '\0';

    pch=strchr(k->val1,'V');
    while(pch!=NULL)
    {
        strcat(outArray, characterV);
        pch=strchr(pch+1,'V');
    }
    
    pch=strchr(k->val2,'V');
    while(pch!=NULL)
    {
        strcat(outArray, characterV);
        pch=strchr(pch+1,'V');
    }

    pch=strchr(k->val1,'I');
    while(pch!=NULL)
    {
        strcat(outArray, characterI);
        pch=strchr(pch+1,'I');
    }
    
    pch=strchr(k->val2,'I');
    while(pch!=NULL)
    {
        strcat(outArray, characterI);
        pch=strchr(pch+1,'I');
    }

    free(pch);
    return outArray;
}


char *kata_add(Kata * k)
{
    k->val1 = kata_substitute_subtractives(k->val1);
    k->val2 = kata_substitute_subtractives(k->val2);

    k->outputArray = kata_arrang_concatenated_input(k);
    k->outputArray = kata_convert_low_to_high(k->outputArray);
    return k->outputArray;
}

void kata_free(Kata *k)
{
    free(k);
    return;
}
