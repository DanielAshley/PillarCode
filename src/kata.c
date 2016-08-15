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

    savedEnding = kata_check_special_case(inputArray, "DD", "M");
    savedEnding = kata_check_special_case(inputArray, "CCCCC", "D");
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
    
    savedEnding = kata_check_special_case(inputArray, "DCCCC", "CM");
    savedEnding = kata_check_special_case(savedEnding, "CCCC", "CD");
    savedEnding = kata_check_special_case(savedEnding, "LXXXX", "XC");
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
    savedEnding = kata_check_subtractives(val, "CM", "DCCCC");
    savedEnding = kata_check_subtractives(savedEnding, "CD", "CCCC");
    savedEnding = kata_check_subtractives(savedEnding, "XC", "LXXXX");
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

char *kata_arrang_concatenated_input(char * val1, char * val2)
{
    char * outArray = malloc(20);
    char * savedArray = malloc(20);
    char * pch = malloc(20);

    outArray[0] = '\0';
    savedArray[0] = '\0';

    savedArray = kata_search_for_char(val1, "M");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val2, "M");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val1, "D");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val2, "D");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val1, "C");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val2, "C");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val1, "L");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val2, "L");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val1, "X");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val2, "X");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val1, "V");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val2, "V");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val1, "I");
    strcat(outArray, savedArray);
    savedArray = kata_search_for_char(val2, "I");
    strcat(outArray, savedArray);
    //printf("Concat val strings  -  outArray: %s\n", outArray);
    return outArray;
}



char *kata_search_and_remove_val2(char * inputVal, char removeVal)
{
    char * outArray = malloc(20);
    char * pch = malloc(20);
    int pos = 0;

    strcpy(outArray,inputVal);

    pch=strchr(inputVal,removeVal);
    pos = strlen(outArray)-strlen(pch);
    memmove(outArray+pos, pch+1, 10);
    //printf("HERE-SR-val2  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);

    return outArray;
}

char *kata_search_and_remove_val1(char * inputVal, char removeVal)
{
    char * outArray = malloc(20);
    char * pch = malloc(20);
    strcpy(outArray, inputVal);
    int pos = 0;
    int removed = 0;

    if(removeVal == 'I')
    {
        pch=strchr(inputVal,removeVal);
        if(pch==NULL)
        {
            pch=strchr(inputVal,'V');
            if(pch==NULL)
            {
                pch=strchr(inputVal,'X');
                if(pch==NULL)
                {
                    pch=strchr(inputVal,'L');
                    if(pch==NULL)
                    {
                            
                    }
                    else
                    { 
                        pos = strlen(outArray)-strlen(pch);
                        memmove(outArray+pos, "XXXXX", 10);
                        //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
                        memmove(outArray+pos+5, pch+1, 10);
                        //printf("HERE-SR-val1 - L -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
                    }
                }
                else
                { 
                    pos = strlen(outArray)-strlen(pch);
                    memmove(outArray+pos, "VV", 10);
                    //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
                    memmove(outArray+pos+2, pch+1, 10);
                    //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
                }
            }
            else
            { 
                pos = strlen(outArray)-strlen(pch);
                memmove(outArray+pos, "IIIII", 10);
                //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
                memmove(outArray+pos+5, pch+1, 10);
                //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
            }
        }
        else
        {
            pos = strlen(outArray)-strlen(pch);
            memmove(outArray+pos, pch+1, 10);
            removed = 1;
            //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
        }
    }

    if(removeVal == 'V')
    {
        pch=strchr(inputVal,removeVal);
        if(pch==NULL)
        {
            pch=strchr(inputVal,'X');
            if(pch==NULL)
            {
                pch=strchr(inputVal,'L');
                if(pch==NULL)
                {
                        
                }
                else
                    memmove(outArray+strlen(outArray)-1, "IIII", 5);
            }
            else
            {
                pos = strlen(outArray)-strlen(pch);
                memmove(outArray+pos, "VV", 10);
                //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
                memmove(outArray+pos+2, pch+1, 10);
                //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
            }
        }
        else
        {
            pos = strlen(outArray)-strlen(pch);
            memmove(outArray+pos, pch+1, 10);
            removed = 1;
            //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
        }
    }

    if(removeVal == 'X')
    {
        pch=strchr(inputVal,removeVal);
        if(pch==NULL)
        {
            pch=strchr(inputVal,'L');
            if(pch==NULL)
            {
                pch=strchr(inputVal,'C');
                if(pch==NULL)
                {
                        
                }
                else
                    memmove(outArray+strlen(outArray)-1, "IIII", 5);
            }
            else
            {
                pos = strlen(outArray)-strlen(pch);
                memmove(outArray+pos, "VV", 10);
                //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
                memmove(outArray+pos+2, pch+1, 10);
                //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
            }
        }
        else
        {
            pos = strlen(outArray)-strlen(pch);
            memmove(outArray+pos, pch+1, 10);
            removed = 1;
            //printf("HERE-SR-val1  -  inputVal: %s    pch: %s    outArray: %s\n", inputVal, pch, outArray);
        }
    }

    if(!removed)
        return kata_search_and_remove_val1(outArray, removeVal);
    else
        return outArray;
}


char *kata_remove_like_values(char * val1, char * val2)
{
    char * tempVal1 = malloc(20);
    char * tempVal2 = malloc(20);

    strcpy(tempVal1,val1);
    strcpy(tempVal2,val2);

    int pos_count = 0;
    for(pos_count = strlen(tempVal2); pos_count > 0; pos_count--)
    {
	    //printf("HERE0  -  tempVal2[pos_count]: %c    strlen(tempVal2): %d\n", tempVal2[pos_count-1], strlen(tempVal2) );
        if(tempVal2[pos_count-1] == 'I')
        {
	    //printf("HERE1\n");
            tempVal2 = kata_search_and_remove_val2(tempVal2, 'I');
            tempVal1 = kata_search_and_remove_val1(tempVal1, 'I');
            pos_count = 0;
     	    //printf("HERE4  -  tempVal1: %s\n", tempVal1);
        }
    }

    for(pos_count = strlen(tempVal2); pos_count > 0; pos_count--)
    {
	    //printf("HERE0  -  tempVal2[pos_count]: %c    strlen(tempVal2): %d\n", tempVal2[pos_count-1], strlen(tempVal2) );
        if(tempVal2[pos_count-1] == 'V')
        {
	    //printf("HERE1\n");
            tempVal2 = kata_search_and_remove_val2(tempVal2, 'V');
            tempVal1 = kata_search_and_remove_val1(tempVal1, 'V');
            pos_count = 0;
     	    //printf("HERE4  -  tempVal1: %s\n", tempVal1);
        }
    }

    for(pos_count = strlen(tempVal2); pos_count > 0; pos_count--)
    {
	if(tempVal2[pos_count-1] == 'X')
        {
            //printf("HERE0  -  tempVal2[pos_count-1]: %c    strlen(tempVal2): %d\n", tempVal2[pos_count-1], strlen(tempVal2) );
        
	    //printf("HERE1\n");
            tempVal2 = kata_search_and_remove_val2(tempVal2, 'X');
            tempVal1 = kata_search_and_remove_val1(tempVal1, 'X');
            pos_count = 0;
     	    //printf("HERE4  -  tempVal1: %s\n", tempVal1);
        }
    }

    //printf("tempVal1: %s    tempVal2: %s\n", tempVal1, tempVal2);
    if(strlen(tempVal2) != 0)
    {
        tempVal1 = kata_arrang_concatenated_input(tempVal1, "");
        tempVal1 = kata_convert_low_to_high(tempVal1);
        return kata_remove_like_values(tempVal1, tempVal2);
    }
    else
        return tempVal1;
}

char *kata_add(Kata * k)
{
    k->val1 = kata_substitute_subtractives(k->val1);
    k->val2 = kata_substitute_subtractives(k->val2);
    k->outputArray = kata_arrang_concatenated_input(k->val1, k->val2);
    k->outputArray = kata_convert_low_to_high(k->outputArray);
    k->outputArray = kata_substitute_subtractives_back(k->outputArray);
    return k->outputArray;
}

char *kata_sub(Kata * k)
{
    k->val1 = kata_substitute_subtractives(k->val1);
    k->val2 = kata_substitute_subtractives(k->val2);
    k->outputArray = kata_remove_like_values(k->val1, k->val2);
    k->outputArray = kata_arrang_concatenated_input(k->outputArray, "");
    k->outputArray = kata_convert_low_to_high(k->outputArray);
    k->outputArray = kata_substitute_subtractives_back(k->outputArray);
    return k->outputArray;
}

void kata_free(Kata *k)
{
    free(k);
    return;
}
