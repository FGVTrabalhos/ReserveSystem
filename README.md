# **ReserveSystem**

## O que é o ReserveSystem? ##
O **ReserveSystem** é um pacote gerenciador de reservas de salas para ministração de cursos acadêmicos de modo a permitir a organização sobre o uso de cada sala.

## Como ele Funciona? ##

O **usuário** faz o pedido de reserva de uma sala para uma **disciplina**, informando ao sistema o dia da semana da reserva, **horário inicial e final** do uso da sala e a **quantidade de alunos inscritos** na disciplina.

Ao fazer isso o sistema:
 - Verifica se existe conflito entre esse pedido e alguma reserva já feita
 - Se não houver conflito registra a reserva (*aprovada*)
 - Se houver conflito ou se a reserva for inválida, o pedido de reserva não é atendido (*rejeitada*)


## Organização do Código ##
 - ReservationRequest
    Classe *ReservationRequest* que formaliza uma reserva.
 - list
    Declaração das Estruturas de Dados usadas para efetuar as reservas
 - ReservationSystem
    Classe *ReservationSystem*, que contém a lógica da reserva.

## Instruções de compilação e execução##

Para compilar o projeto:

```shell make```

Para executar:

```shell ./reservation_system```

## Decisões do Projeto ##
Na **ReservationSystem** optamos por modelar as reservas através de:
 - Inserção ordenada para simplificar a verificação de possíveis conflitos
 - Uso de lista encadeada para facilitar inserções dinâmicas


## Autores ##
**Leonidas Caetano da Silva** e **Luiz Antônio Alves de Lima**.
