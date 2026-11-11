#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <cstddef>

#include "Fila.h"
#include "ListaMedicos.h"
#include "No.h"
#include "Pilha.h"

// Regras de negocio do atendimento, sem menu nem leitura de dados.
class Hospital {
public:
    enum ResultadoAtendimento { ATENDIDO, FILA_VAZIA, SEM_MEDICO };

private:
    Fila pacientes;
    Pilha historico;
    ListaMedicos medicos;

public:
    static bool urgenciaValida(int urgencia);

    void cadastrarPaciente(const char* nome, int urgencia);
    void cadastrarMedico(const char* nome);

    // Em caso de sucesso, devolve em `registro` a linha gravada no historico.
    ResultadoAtendimento atenderProximo(char* registro, std::size_t tamanho);

    const No* proximoPaciente() const;
    int tamanhoFila() const;
    const No* ultimoAtendimento() const;
    void listarMedicos() const;

    // Imprime do mais recente para o mais antigo, preservando o historico.
    void imprimirHistorico();
};

#endif
