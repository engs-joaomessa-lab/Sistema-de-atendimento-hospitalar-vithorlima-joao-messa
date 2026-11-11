#ifndef PILHA_H
#define PILHA_H

#include "No.h"

// Pilha (LIFO) usada no historico de atendimentos.
class Pilha {
private:
    No* topo;

public:
    Pilha();
    ~Pilha();

    void push(const char* nome);
    bool pop(char* nome);
    const No* peek() const;
};

#endif
