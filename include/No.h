#ifndef NO_H
#define NO_H

// No encadeado usado pela fila, pela pilha e pela lista de medicos.
struct No {
    char nome[256];
    int urgencia;
    No* prox;
};

#endif
