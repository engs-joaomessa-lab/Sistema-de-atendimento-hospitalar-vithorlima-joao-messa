#include "Menu.h"

#include <iostream>

#include "Entrada.h"

void Menu::exibir() const {
    std::cout << "\n=== Atendimento Hospitalar ===\n"
              << "1 - Cadastrar paciente\n"
              << "2 - Cadastrar medico\n"
              << "3 - Atender proximo paciente\n"
              << "4 - Consultar frente e tamanho da fila\n"
              << "5 - Listar medicos\n"
              << "6 - Consultar ultimo atendimento\n"
              << "7 - Imprimir historico\n"
              << "0 - Sair\nOpcao: ";
}

// As opcoes que leem dados devolvem false se a entrada acabou (EOF).
bool Menu::opcaoCadastrarPaciente() {
    char nome[256];
    int urgencia;
    std::cout << "Nome do paciente: ";
    if (!Entrada::lerNome(nome)) return false;
    std::cout << "Urgencia (1=baixa, 2=media, 3=alta): ";
    if (!Entrada::lerNumero(urgencia)) return false;
    if (!Hospital::urgenciaValida(urgencia)) {
        std::cout << "Urgencia invalida. Paciente nao cadastrado.\n";
    } else {
        hospital.cadastrarPaciente(nome, urgencia);
        std::cout << "Paciente cadastrado.\n";
    }
    return true;
}

bool Menu::opcaoCadastrarMedico() {
    char nome[256];
    std::cout << "Nome do medico: ";
    if (!Entrada::lerNome(nome)) return false;
    hospital.cadastrarMedico(nome);
    std::cout << "Medico cadastrado.\n";
    return true;
}

void Menu::opcaoAtender() {
    char registro[256];
    switch (hospital.atenderProximo(registro, sizeof(registro))) {
        case Hospital::FILA_VAZIA:
            std::cout << "Fila vazia.\n";
            break;
        case Hospital::SEM_MEDICO:
            std::cout << "Nenhum medico cadastrado. Paciente continua na fila.\n";
            break;
        case Hospital::ATENDIDO:
            std::cout << registro << "\n";
            break;
    }
}

void Menu::opcaoConsultarFila() const {
    const No* primeiro = hospital.proximoPaciente();
    if (primeiro == nullptr) {
        std::cout << "Fila vazia.\n";
    } else {
        std::cout << "Proximo: " << primeiro->nome
                  << " | Urgencia: " << primeiro->urgencia << "\n";
    }
    std::cout << "Pacientes na fila: " << hospital.tamanhoFila() << "\n";
}

void Menu::opcaoUltimoAtendimento() const {
    const No* ultimo = hospital.ultimoAtendimento();
    if (ultimo == nullptr) std::cout << "Historico vazio.\n";
    else std::cout << ultimo->nome << "\n";
}

void Menu::executar() {
    int opcao;
    while (true) {
        exibir();
        if (!Entrada::lerNumero(opcao) || opcao == 0) break;

        if (opcao == 1) {
            if (!opcaoCadastrarPaciente()) break;
        } else if (opcao == 2) {
            if (!opcaoCadastrarMedico()) break;
        } else if (opcao == 3) {
            opcaoAtender();
        } else if (opcao == 4) {
            opcaoConsultarFila();
        } else if (opcao == 5) {
            hospital.listarMedicos();
        } else if (opcao == 6) {
            opcaoUltimoAtendimento();
        } else if (opcao == 7) {
            hospital.imprimirHistorico();
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
    std::cout << "Sistema encerrado.\n";
}
