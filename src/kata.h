
#ifndef KATA_H
#define KATA_H

typedef struct Kata Kata;

Kata *kata_init_values(char *val1, char *val2);
char *kata_add(Kata * k);
char *kata_sub(Kata * k);
void kata_free(Kata *k);

#endif /* KATA_H */
