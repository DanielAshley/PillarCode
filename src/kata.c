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
                return savedEnding;
            }
        }
        else
        {
           pos_text -= pos_search;
           pos_search = 0;
        }
    }

    free(savedEnding);
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
    
    if(strcmp(inputArray,savedEnding) == 0)
    {
        return inputArray;
    }
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
    
    if(strcmp(inputArray,savedEnding) == 0)
    {
        return inputArray;
    }
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

                return savedEnding;
            }
        }
        else
        {
           pos_text -= pos_search;
           pos_search = 0;
        }
    }

    free(savedEnding);
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
    {
        return val;
    }
    else
        return kata_substitute_subtractives(savedEnding); 
}

char *kata_search_for_char(char * input, char * searchChar)
{
    char * outArray = malloc(20);
    char * pch;

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
    char * pch;

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

    free(savedArray);
    return outArray;
}



char *kata_search_and_remove_val2(char * inputVal, char removeVal)
{
    char * outArray = malloc(20);
    char * pch;
    int pos = 0;

    strcpy(outArray,inputVal);

    pch=strchr(inputVal,removeVal);
    pos = strlen(outArray)-strlen(pch);
    memmove(outArray+pos, pch+1, 10);

    return outArray;
}

char *kata_search_and_remove_val1(char * inputVal, char removeVal)
{
    char * outArray = malloc(30);
    char * pch;
    strcpy(outArray, inputVal);
    int pos = 0;
    int removed = 0;

    if(removeVal == 'I') // Checking if I removal is requested
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
                        pch=strchr(inputVal,'C');
                        if(pch==NULL)
                        {
                            pch=strchr(inputVal,'D');
                            if(pch==NULL)
                            {
                                pch=strchr(inputVal,'M');
                		if(pch==NULL)
                		{
                                    return "";   
      			        }
        		        else
         		        { 
        		            pos = strlen(outArray)-strlen(pch);
         		            memmove(outArray+pos, "DD", 10);
         		            memmove(outArray+pos+2, pch+1, 20);
           		        } 
                            }
                            else
                            { 
                                pos = strlen(outArray)-strlen(pch);
                                memmove(outArray+pos, "CCCCC", 10);
                                memmove(outArray+pos+5, pch+1, 20);    
                            }    
                        }
                        else
                        { 
                            pos = strlen(outArray)-strlen(pch);
                            memmove(outArray+pos, "LL", 10);
                            memmove(outArray+pos+2, pch+1, 20);
                        }
                    }
                    else
                    { 
                        pos = strlen(outArray)-strlen(pch);
                        memmove(outArray+pos, "XXXXX", 10);
                        memmove(outArray+pos+5, pch+1, 20);
                    }
                }
                else
                { 
                    pos = strlen(outArray)-strlen(pch);
                    memmove(outArray+pos, "VV", 10);
                    memmove(outArray+pos+2, pch+1, 20);
                }
            }
            else
            { 
                pos = strlen(outArray)-strlen(pch);
                memmove(outArray+pos, "IIIII", 10);
                memmove(outArray+pos+5, pch+1, 20);
            }
        }
        else
        {
            pos = strlen(outArray)-strlen(pch);
            memmove(outArray+pos, pch+1, 20);
            removed = 1;
        }
    }

    else if(removeVal == 'V') // Checking if V removal is requested
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
                    pch=strchr(inputVal,'C');
                    if(pch==NULL)
                    {
                        pch=strchr(inputVal,'D');
                        if(pch==NULL)
                        {
                            pch=strchr(inputVal,'M');
                            if(pch==NULL)
                            {            
                                return ""; 
                            }
                            else
                            { 
                                pos = strlen(outArray)-strlen(pch);
                                memmove(outArray+pos, "DD", 10);
                                memmove(outArray+pos+2, pch+1, 20);
                            }       
                        }
                        else
                        { 
                            pos = strlen(outArray)-strlen(pch);
                            memmove(outArray+pos, "CCCCC", 10);
                            memmove(outArray+pos+5, pch+1, 20);
                        }    
                    }
                    else
                    { 
                        pos = strlen(outArray)-strlen(pch);
                        memmove(outArray+pos, "LL", 10);
                        memmove(outArray+pos+2, pch+1, 20);
                    }   
                }
                else
                { 
                    pos = strlen(outArray)-strlen(pch);
                    memmove(outArray+pos, "XXXXX", 10);
                    memmove(outArray+pos+5, pch+1, 20);
                }
            }
            else
            {
                pos = strlen(outArray)-strlen(pch);
                memmove(outArray+pos, "VV", 10);
                memmove(outArray+pos+2, pch+1, 20);
            }
        }
        else
        {
            pos = strlen(outArray)-strlen(pch);
            memmove(outArray+pos, pch+1, 20);
            removed = 1;
        }
    }

    else if(removeVal == 'X') // Checking if X removal is requested
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
                        pch=strchr(inputVal,'D');
                        if(pch==NULL)
                        {
                            pch=strchr(inputVal,'M');
                            if(pch==NULL)
                            {
                                return ""; 
                            }
                            else
                            { 
                                pos = strlen(outArray)-strlen(pch);
                                memmove(outArray+pos, "DD", 10);
                                memmove(outArray+pos+2, pch+1, 20);
                            }     
                        }
                        else
                        { 
                            pos = strlen(outArray)-strlen(pch);
                            memmove(outArray+pos, "CCCCC", 10);
                            memmove(outArray+pos+5, pch+1, 20);
                        }                
                    }
                    else
                    { 
                        pos = strlen(outArray)-strlen(pch);
                        memmove(outArray+pos, "LL", 10);
                        memmove(outArray+pos+2, pch+1, 20);
                    } 
            }
            else
            { 
                 pos = strlen(outArray)-strlen(pch);
                memmove(outArray+pos, "XXXXX", 10);
                memmove(outArray+pos+5, pch+1, 20);
            }
        }
        else
        {
            pos = strlen(outArray)-strlen(pch);
            memmove(outArray+pos, pch+1, 20);
            removed = 1;
        }
    }

    else if(removeVal == 'L') // Checking if L removal is requested
    {
        pch=strchr(inputVal,removeVal);
        if(pch==NULL)
        {
                pch=strchr(inputVal,'C');
                if(pch==NULL)
                {
                    pch=strchr(inputVal,'D');
                    if(pch==NULL)
                    {
                        pch=strchr(inputVal,'M');
                        if(pch==NULL)
                        {
                            return ""; 
                        }
                        else
                        { 
                            pos = strlen(outArray)-strlen(pch);
                            memmove(outArray+pos, "DD", 10);
                            memmove(outArray+pos+2, pch+1, 20);
                        }    
                    }
                    else
                    { 
                        pos = strlen(outArray)-strlen(pch);
                        memmove(outArray+pos, "CCCCC", 10);
                        memmove(outArray+pos+5, pch+1, 20);
                    } 
                }
                else
                { 
                    pos = strlen(outArray)-strlen(pch);
                    memmove(outArray+pos, "LL", 10);
                    memmove(outArray+pos+2, pch+1, 20);
                } 
        }
        else
        {
            pos = strlen(outArray)-strlen(pch);
            memmove(outArray+pos, pch+1, 20);
            removed = 1;
        }
    }

    else if(removeVal == 'C') // Checking if C removal is requested
    {
        pch=strchr(inputVal,removeVal);
        if(pch==NULL)
        {
                pch=strchr(inputVal,'D');
                if(pch==NULL)
                {
                    pch=strchr(inputVal,'M');
                    if(pch==NULL)
                    {
                        return "";         
                    }
                    else
                    { 
                        pos = strlen(outArray)-strlen(pch);
                        memmove(outArray+pos, "DD", 10);
                        memmove(outArray+pos+2, pch+1, 20);
                    }  
                }
                else
                { 
                    pos = strlen(outArray)-strlen(pch);
                    memmove(outArray+pos, "CCCCC", 10);
                    memmove(outArray+pos+5, pch+1, 20);
                } 
        }
        else
        {
            pos = strlen(outArray)-strlen(pch);
            memmove(outArray+pos, pch+1, 20);
            removed = 1;
        }
    }

    else if(removeVal == 'D') // Checking if D removal is requested
    {
        pch=strchr(inputVal,removeVal);
        if(pch==NULL)
        {
                pch=strchr(inputVal,'M');
                if(pch==NULL)
                {
                    return "";
                }
                else
                { 
                    pos = strlen(outArray)-strlen(pch);
                    memmove(outArray+pos, "DD", 10);
                    memmove(outArray+pos+2, pch+1, 20);
                } 
        }
        else
        {
            pos = strlen(outArray)-strlen(pch);
            memmove(outArray+pos, pch+1, 20);
            removed = 1;
        }
    }

    else if(removeVal == 'M') // Checking if M removal is requested
    {
        pch=strchr(inputVal,removeVal);
        if(pch==NULL)
        {
            return "";
        }
        else
        {
            pos = strlen(outArray)-strlen(pch);
            memmove(outArray+pos, pch+1, 20);
            removed = 1;
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

    int main_count = 0;
    int pos_count = 0;

    for(main_count = 0; main_count < 10; main_count++)
    {
        tempVal1 = kata_arrang_concatenated_input(tempVal1, "");
        tempVal1 = kata_convert_low_to_high(tempVal1);
        for(pos_count = strlen(tempVal2); pos_count > 0; pos_count--)
        {
            if(tempVal2[pos_count-1] == 'I')
            {
                tempVal2 = kata_search_and_remove_val2(tempVal2, 'I');
                tempVal1 = kata_search_and_remove_val1(tempVal1, 'I');
                pos_count = strlen(tempVal2);
            }
        }

        for(pos_count = strlen(tempVal2); pos_count > 0; pos_count--)
        {
            if(tempVal2[pos_count-1] == 'V')
            {
                tempVal2 = kata_search_and_remove_val2(tempVal2, 'V');
                tempVal1 = kata_search_and_remove_val1(tempVal1, 'V');
                pos_count = strlen(tempVal2);
            }
        }

        for(pos_count = strlen(tempVal2); pos_count > 0; pos_count--)
        {
	    if(tempVal2[pos_count-1] == 'X')
            {
                tempVal2 = kata_search_and_remove_val2(tempVal2, 'X');
                tempVal1 = kata_search_and_remove_val1(tempVal1, 'X');
                pos_count = strlen(tempVal2);
            }
        }

        for(pos_count = strlen(tempVal2); pos_count > 0; pos_count--)
        {
            if(tempVal2[pos_count-1] == 'L')
            {
                tempVal2 = kata_search_and_remove_val2(tempVal2, 'L');
                tempVal1 = kata_search_and_remove_val1(tempVal1, 'L');
                pos_count = strlen(tempVal2);
            }
        }

        for(pos_count = strlen(tempVal2); pos_count > 0; pos_count--)
        {
            if(tempVal2[pos_count-1] == 'C')
            {
                tempVal2 = kata_search_and_remove_val2(tempVal2, 'C');
                tempVal1 = kata_search_and_remove_val1(tempVal1, 'C');
                pos_count = strlen(tempVal2);
            }
        }

        for(pos_count = strlen(tempVal2); pos_count > 0; pos_count--)
        {
	    if(tempVal2[pos_count-1] == 'D')
            {
                tempVal2 = kata_search_and_remove_val2(tempVal2, 'D');
                tempVal1 = kata_search_and_remove_val1(tempVal1, 'D');
                pos_count = strlen(tempVal2);
            }
        }

        for(pos_count = strlen(tempVal2); pos_count > 0; pos_count--)
        {
	    if(tempVal2[pos_count-1] == 'M')
            {
                tempVal2 = kata_search_and_remove_val2(tempVal2, 'M');
                tempVal1 = kata_search_and_remove_val1(tempVal1, 'M');
                pos_count = strlen(tempVal2);
            }
        }
    }


    if(strlen(tempVal2) != 0)
    {
        free(tempVal2);
        free(tempVal1);
        return "";
    }
    else
    {
        free(tempVal2); 
        return tempVal1;
    }
}

char *kata_sub_checker(Kata * k)
{
    
    k->val1 = kata_substitute_subtractives(k->val1);
    k->val2 = kata_substitute_subtractives(k->val2);
    char * outputArray = malloc(20);
    outputArray = kata_remove_like_values(k->val1, k->val2);
    outputArray = kata_arrang_concatenated_input(outputArray, "");
    outputArray = kata_convert_low_to_high(outputArray);
    outputArray = kata_substitute_subtractives_back(outputArray);
    return outputArray;
}

char *kata_check_if_value_is_greater_than_max(char * val, char * max)
{
    Kata * test_Kata = malloc(sizeof(Kata));
    char * savedValue = malloc(20);

    test_Kata = kata_init_values(max, val);
    savedValue = kata_sub_checker(test_Kata);
    
    kata_free(test_Kata);
    return savedValue;
}


char *kata_add(Kata * k)
{
    if(strcmp(kata_check_if_value_is_greater_than_max(k->val1, "MMMM"),"") == 0)
        return "";

    if(strcmp(kata_check_if_value_is_greater_than_max(k->val2, "MMMM"),"") == 0)
        return "";    

    k->val1 = kata_substitute_subtractives(k->val1);
    k->val2 = kata_substitute_subtractives(k->val2);
    char * outputArray = malloc(20);
    outputArray = kata_arrang_concatenated_input(k->val1, k->val2);
    outputArray = kata_convert_low_to_high(outputArray);
    outputArray = kata_substitute_subtractives_back(outputArray);

    if(strcmp(kata_check_if_value_is_greater_than_max(outputArray, "MMMM"),"") == 0)
    {
        free(outputArray);
        return "";
    }
    return outputArray;
}

char *kata_sub(Kata * k)
{
    if(strcmp(kata_check_if_value_is_greater_than_max(k->val1, "MMMM"),"") == 0)
        return "";

    if(strcmp(kata_check_if_value_is_greater_than_max(k->val2, "MMMM"),"") == 0)
        return "";    

    k->val1 = kata_substitute_subtractives(k->val1);
    k->val2 = kata_substitute_subtractives(k->val2);
    char * outputArray = malloc(20);
    outputArray = kata_remove_like_values(k->val1, k->val2);
    outputArray = kata_arrang_concatenated_input(outputArray, "");
    outputArray = kata_convert_low_to_high(outputArray);
    outputArray = kata_substitute_subtractives_back(outputArray);

    if(strcmp(kata_check_if_value_is_greater_than_max(outputArray, "MMMM"),"") == 0)
    {
        free(outputArray);
        return "";
    }
    return outputArray;
}

void kata_free(Kata *k)
{
    free(k);
    return;
}
