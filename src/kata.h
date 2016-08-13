
#ifndef KATA_H
#define KATA_H

typedef struct Kata Kata;

Kata *kata_init_values(char *val1, char *val2);
char *kata_convert_IIIII_to_V(char * outputArray);
char *kata_substitute_subtractives(char * val);
char *kata_arrang_concatenated_input(Kata * k);
char *kata_add(Kata * k);
void kata_free(Kata *k);

#endif /* KATA_H */
