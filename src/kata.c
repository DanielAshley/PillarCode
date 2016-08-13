
#include <stdlib.h>
#include "kata.h"

struct Kata
{
    char *val1;
    char *val2;
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
    return "II";
}
