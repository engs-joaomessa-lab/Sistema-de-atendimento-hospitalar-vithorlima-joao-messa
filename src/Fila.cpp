#include "Fila.h"

#include <cstring>

Fila::Fila() : inicio(nullptr), fim(nullptr) {}

Fila::~Fila() {
    char nome[256];
    int urgencia;
    while (dequeue(nome, urgencia)) {}
}

void Fila::enqueue(const char* nome, int urgencia) {
    No* novo = new No;
    strcpy(novo->nome, nome);
    novo->urgencia = urgencia;
    novo->prox = nullptr;
    if (fim == nullptr) {
        inicio = novo;
    } else {
        fim->prox = novo;
    }
    fim = novo;
}

bool Fila::dequeue(char* nome, int& urgencia) {
    if (inicio == nullptr) return false;
    No* antigo = inicio;
    strcpy(nome, antigo->nome);
    urgencia = antigo->urgencia;
    inicio = inicio->prox;
    if (inicio == nullptr) fim = nullptr;
    delete antigo;
    return true;
}

const No* Fila::frente_peak() const {
    return inicio;
}

int Fila::tamanho() const {
    int total = 0;
    No* atual = inicio;
    while (atual != nullptr) {
        total++;
        atual = atual->prox;
    }
    return total;
}
