#ifndef MENU_H
#define MENU_H

#include "Hospital.h"

// Interface de console: exibe o menu e trata cada opcao.
class Menu {
private:
    Hospital hospital;

    void exibir() const;
    bool opcaoCadastrarPaciente();
    bool opcaoCadastrarMedico();
    void opcaoAtender();
    void opcaoConsultarFila() const;
    void opcaoUltimoAtendimento() const;

public:
    void executar();
};

#endif
