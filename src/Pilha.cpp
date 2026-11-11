#include "Pilha.h"

#include <cstring>

Pilha::Pilha() : topo(nullptr) {}

Pilha::~Pilha() {
    char nome[256];
    while (pop(nome)) {}
}

void Pilha::push(const char* nome) {
    No* novo = new No;
    strcpy(novo->nome, nome);
    novo->urgencia = 0;
    novo->prox = topo;
    topo = novo;
}

bool Pilha::pop(char* nome) {
    if (topo == nullptr) return false;
    No* antigo = topo;
    strcpy(nome, antigo->nome);
    topo = topo->prox;
    delete antigo;
    return true;
}

const No* Pilha::peek() const {
    return topo;
}
