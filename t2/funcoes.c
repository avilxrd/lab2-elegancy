#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void calcular(int *rec, const char *string) {
    memset(rec, 0, 128 * sizeof(int));
    while(*string) rec[(unsigned char) *(string++)]++;
}