#include "ListaMedicos.h"

#include <cstring>
#include <iostream>

ListaMedicos::ListaMedicos() : inicio(nullptr) {}

ListaMedicos::~ListaMedicos() {
    char nome[256];
    while (chamarMedico(nome)) {}
}

void ListaMedicos::adicionarMedico(const char* nome) {
    No* novo = new No;
    strcpy(novo->nome, nome);
    novo->urgencia = 0;
    novo->prox = nullptr;
    if (inicio == nullptr) {
        inicio = novo;
    } else {
        No* atual = inicio;
        while (atual->prox != nullptr) atual = atual->prox;
        atual->prox = novo;
    }
}

bool ListaMedicos::chamarMedico(char* nome) {
    if (inicio == nullptr) return false;
    No* antigo = inicio;
    strcpy(nome, antigo->nome);
    inicio = inicio->prox;
    delete antigo;
    return true;
}

void ListaMedicos::percorrer() const {
    if (inicio == nullptr) std::cout << "Nenhum medico cadastrado.\n";
    No* atual = inicio;
    while (atual != nullptr) {
        std::cout << atual->nome << "\n";
        atual = atual->prox;
    }
}
