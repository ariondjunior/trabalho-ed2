#ifndef NO_H_
#define NO_H_

#include "cliente.h"

typedef struct no {
    Cliente info;
    struct no *prox;
} No;

#endif /* NO_H_ */