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
                //printf("Special Cases  -  inputArray: %s    savedEnding: %s\n", inputArray, savedEnding);
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

    savedEnding = kata_check_special_case(inputArray, "LL", "C");
    savedEnding = kata_check_special_case(savedEnding, "XXXXX", "L");
    savedEnding = kata_check_special_case(savedEnding, "VV", "X");
    savedEnding = kata_check_special_case(savedEnding, "IIIII", "V");
    
    //printf("Special Cases  -  inputArray: %s    savedEnding: %s\n", inputArray, savedEnding);
    if(strcmp(inputArray,savedEnding) == 0)
        return inputArray;
    else
        return kata_convert_low_to_high(savedEnding); 
}

char *kata_substitute_subtractives_back(char * inputArray)
{
    char *savedEnding = malloc(strlen(inputArray));
    
    savedEnding = kata_check_special_case(inputArray, "LXXXX", "XC");
    savedEnding = kata_check_special_case(savedEnding, "XXXX", "XL");
    savedEnding = kata_check_special_case(savedEnding, "VIIII", "IX");
    savedEnding = kata_check_special_case(savedEnding, "IIII", "IV");
    
    //printf("Substitute Subtractives Back -  inputArray: %s    savedEnding: %s\n", inputArray, savedEnding);
    if(strcmp(inputArray,savedEnding) == 0)
        return inputArray;
    else
        return kata_convert_low_to_high(savedEnding); 
}

char *kata_check_subtractives(char * inputArray, char * specialCase, char * conversionValue)
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
                //printf("Subtractives  -  inputArray: %s    savedEnding: %s\n", inputArray, savedEnding);
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
char *kata_substitute_subtractives(char * val)
{
    char *savedEnding = malloc(strlen(val));
    savedEnding = kata_check_subtractives(val, "XC", "LXXXX");
    savedEnding = kata_check_subtractives(savedEnding, "XL", "XXXX");
    savedEnding = kata_check_subtractives(savedEnding, "IX", "VIIII");
    savedEnding = kata_check_subtractives(savedEnding, "IV", "IIII");


    if(strcmp(val,savedEnding) == 0)
        return val;
    else
        return kata_substitute_subtractives(savedEnding); 
}

char *kata_search_for_char(char * input, char * searchChar)
{
    char * outArray = malloc(20);
    char * pch = malloc(20);

    outArray[0] = '\0';

    pch=strchr(input,searchChar[0]);
    while(pch!=NULL)
    {
        strcat(outArray, searchChar);
        pch=strchr(pch+1, searchChar[0]);
    }
    return outArray;
}

char *kata_arrang_concatenated_input(Kata * k)
{
    char * outArray = malloc(strlen(k->outputArray));
    char * savedArray = malloc(20);
    char * pch = malloc(strlen(k->outputArray));

    outArray[0] = '\0';
    savedArray[0] = '\0';

    savedArray = kata_search_for_char(k->val1, "C");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(k->val2, "C");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(k->val1, "L");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(k->val2, "L");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(k->val1, "X");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(k->val2, "X");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(k->val1, "V");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(k->val2, "V");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(k->val1, "I");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(k->val2, "I");
    strcat(outArray, savedArray);
    //printf("Concat val strings  -  outArray: %s\n", outArray);
    return outArray;
}


char *kata_add(Kata * k)
{
    k->val1 = kata_substitute_subtractives(k->val1);
    k->val2 = kata_substitute_subtractives(k->val2);

//printf("val1: %s    val2: %s\n", k->val1, k->val2);

    k->outputArray = kata_arrang_concatenated_input(k);

//printf("outputArray: %s\n", k->outputArray);

    k->outputArray = kata_convert_low_to_high(k->outputArray);
    k->outputArray = kata_substitute_subtractives_back(k->outputArray);
    return k->outputArray;
}

void kata_free(Kata *k)
{
    free(k);
    return;
}
