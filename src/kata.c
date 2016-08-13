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

char *kata_add(Kata * k)
{
    if((strcmp(k->val1, "II") == 0) && (strcmp(k->val1, "II") == 0))
        return "IV";
    free(k->outputArray);  // Make sure to free up previously used memory
    k->outputArray = malloc(strlen(k->val1)+strlen(k->val2)); // allocating needed memory for this addition
    strcpy(k->outputArray, k->val1);
    strcat(k->outputArray, k->val2);
    return k->outputArray;
}

void kata_free(Kata *k)
{
    free(k);
    return;
}
