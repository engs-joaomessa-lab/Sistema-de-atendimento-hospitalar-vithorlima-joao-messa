#ifndef FILA_H
#define FILA_H

#include "No.h"

// Fila (FIFO) de pacientes, com lista encadeada manual.
class Fila {
private:
    No* inicio;
    No* fim;

public:
    Fila();
    ~Fila();

    void enqueue(const char* nome, int urgencia);
    bool dequeue(char* nome, int& urgencia);
    const No* frente_peak() const;
    int tamanho() const;
};

#endif
