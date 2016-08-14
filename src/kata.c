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

char *kata_check_special_case(char * inputArray, char * specialCase, char * conversionValue)
{
    char *savedEnding = malloc(strlen(inputArray)); 

    int pos_text = 0;
    int pos_search = 0;
    int len_search = strlen(specialCase);
    for (pos_text = 0; pos_text < strlen(inputArray); ++pos_text)
    {
        if(inputArray[pos_text] == specialCase[pos_search])
        {
            ++pos_search;
            if(pos_search == len_search) // match for special case found
            {
		for(pos_search = 0; pos_search < (pos_text+1-len_search); pos_search++)
                {
                    savedEnding[pos_search] = inputArray[pos_search];
                }
                savedEnding[pos_search] = '\0';
		strcat(savedEnding,conversionValue);
		strcat(savedEnding, (inputArray+pos_search+len_search));
                savedEnding[strlen(inputArray)-(len_search-strlen(conversionValue))] = '\0';
                //printf("inputArray: %s    savedEnding: %s\n", inputArray, savedEnding);
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

char *kata_convert_low_to_high(char * inputArray)
{
    char *savedEnding = malloc(strlen(inputArray));

    savedEnding = kata_check_special_case(inputArray, "VV", "X");
    savedEnding = kata_check_special_case(savedEnding, "VIIII", "IX");
    savedEnding = kata_check_special_case(savedEnding, "IIIII", "V");
    savedEnding = kata_check_special_case(savedEnding, "IIII", "IV");

    if(strcmp(inputArray,savedEnding) == 0)
        return inputArray;
    else
        return kata_convert_low_to_high(savedEnding); 
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

//printf("outputArray: %s\n", k->outputArray);

    k->outputArray = kata_convert_low_to_high(k->outputArray);
    return k->outputArray;
}

void kata_free(Kata *k)
{
    free(k);
    return;
}
