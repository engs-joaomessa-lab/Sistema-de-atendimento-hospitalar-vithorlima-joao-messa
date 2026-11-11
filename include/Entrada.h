#ifndef ENTRADA_H
#define ENTRADA_H

// Leitura validada de dados do console. Devolvem false no fim da entrada (EOF).
class Entrada {
public:
    static bool lerNumero(int& numero);
    static bool lerNome(char* nome);
};

#endif
