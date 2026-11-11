#include "Hospital.h"

#include <cstdio>
#include <iostream>

bool Hospital::urgenciaValida(int urgencia) {
    return urgencia >= 1 && urgencia <= 3;
}

void Hospital::cadastrarPaciente(const char* nome, int urgencia) {
    pacientes.enqueue(nome, urgencia);
}

void Hospital::cadastrarMedico(const char* nome) {
    medicos.adicionarMedico(nome);
}

Hospital::ResultadoAtendimento Hospital::atenderProximo(char* registro,
                                                        std::size_t tamanho) {
    if (pacientes.frente_peak() == nullptr) return FILA_VAZIA;

    char medico[256];
    if (!medicos.chamarMedico(medico)) return SEM_MEDICO;

    char nome[256];
    int urgencia;
    pacientes.dequeue(nome, urgencia);
    std::snprintf(registro, tamanho,
                  "Paciente: %.99s | Urgencia: %d | Medico: %.99s",
                  nome, urgencia, medico);
    historico.push(registro);
    medicos.adicionarMedico(medico);
    return ATENDIDO;
}

const No* Hospital::proximoPaciente() const { return pacientes.frente_peak(); }
int Hospital::tamanhoFila() const { return pacientes.tamanho(); }
const No* Hospital::ultimoAtendimento() const { return historico.peek(); }
void Hospital::listarMedicos() const { medicos.percorrer(); }

void Hospital::imprimirHistorico() {
    if (historico.peek() == nullptr) {
        std::cout << "Historico vazio.\n";
        return;
    }
    Pilha auxiliar;
    char registro[256];
    std::cout << "--- Historico (mais recente primeiro) ---\n";
    while (historico.pop(registro)) {
        std::cout << registro << "\n";
        auxiliar.push(registro);
    }
    while (auxiliar.pop(registro)) {
        historico.push(registro);
    }
}
