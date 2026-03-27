# **ReserveSystem**

## O que é o ReserveSystem? ##
O **ReserveSystem** é um pacote gerenciador de reservas de salas para ministração de cursos acadêmicos de modo a permitir a organização sobre o uso de cada sala.


## Quais Problemas o Pacote Resolve? ##
No ambiente acadêmico de universidades como a **FGV**, onde o número de laboratórios com uma capacidade máxima de máquinas é limitada, durante a semana de provas da instituição é necessário ter noção de como distribuir a demanda das disciplinas sem perder o controle, é para situações exatamente como essas que o pacote foi desenvolvido.


## Como ele Funciona? ##
Implementado puramente em **C++**, o sistema funciona de acordo com a demanda.

*"Como assim?"* Simples!

O **usuário** faz o pedido de reserva de uma sala para uma **disciplina** passando para o programa o **dia da semana** que deseja fazer a reserva, **horário inicial e final** do uso da sala e a **quantidade de alunos inscritos** na disciplina.

Ao fazer isso o sistema:
 - Verifica se existe conflito entre esse pedido e alguma reserva já feita
 - Se não houver conflito registra a reserva (*aprovada*)
 - Se houver conflito, o pedido de reserva não é atendido (*rejeitada*)


## Organização do Código ##
 - ReservationRequest.hpp
    Declaração da classe *ReservationRequest*
 - ReservationRequest.cpp
    Implementação da classe *ReservationRequest*
 - list.hpp
    Declaração das Estruturas de Dados usadas para efetuar as reservas
    *struct reserved* (Nós) e *list_reserved* (Lista encadeada)
 - list.cpp
    Implementação das funções de lista encadeada de *list_reserved*
 - ReservationSystem.hpp
    Declaração da classe *ReservationSystem*
 - ReservationSystem.cpp
    Implementação da classe *ReservationSystem* e toda lógica da reserva.

## Como Executar na Minha Máquina? ##
Após baixar o pacote, abra o terminal e execute:
 1. `g++ main.cpp -o reservesystem`
 2. `./reservesystem`

Pronto! Você já estará usando o nosso pacote.


## Exemplo de uso ##
```cpp
#include "ReservationSystem.hpp"


#define SALAS 5

int main (void){
    // Criação do Sistema
    int capacities[SALAS] = {30, 100}; 
    ReservationSystem sistema(SALAS, capacities);


    // Reservas bem sucedidas
    ReservationRequest calculus("Vetorial Calculus", "segunda", 9, 11, 20);
    sistema.reserve(calculus);

    ReservationRequest datastructures("Data Structures", "segunda", 7, 9, 65);
    sistema.reserve(datastructures);
```

## Decisões do Projeto ##
Na **ReservationSystem** optamos por modelar as reservas através de:
 - Sobrecarga de operadores para tornar comparações mais legíveis
 - Inserção ordenada para simplificar a verificação de possíveis conflitos
 - Uso de lista encadeada para facilitar inserções dinâmicas


## Autores ##
**Leonidas Caetano da Silva**, conhecido populamente como *Fernandinho*

**Luiz Antônio Alves de Lima**, conhecido como colega de quarto do *Fernandinho*
