#ifndef LISTA_MEDICOS_H
#define LISTA_MEDICOS_H

#include "No.h"

// Lista encadeada de medicos (rodizio: quem atende volta ao final).
class ListaMedicos {
private:
    No* inicio;

public:
    ListaMedicos();
    ~ListaMedicos();

    void adicionarMedico(const char* nome);
    bool chamarMedico(char* nome);
    void percorrer() const;
};

#endif
