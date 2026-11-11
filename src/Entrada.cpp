#include "Entrada.h"

#include <cstring>
#include <iostream>

bool Entrada::lerNumero(int& numero) {
    while (!(std::cin >> numero)) {
        if (std::cin.eof()) return false;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Digite um numero: ";
    }
    std::cin.ignore(10000, '\n');
    return true;
}

bool Entrada::lerNome(char* nome) {
    while (true) {
        std::cin.getline(nome, 100);
        if (std::cin.eof()) return false;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Nome muito longo. Use ate 99 caracteres: ";
        } else if (nome[0] == '\0' || std::strspn(nome, " \t\r") == std::strlen(nome)) {
            std::cout << "O nome nao pode ficar vazio. Digite novamente: ";
        } else {
            return true;
        }
    }
}
