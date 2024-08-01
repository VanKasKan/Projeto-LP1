# Clínica Odonto (Sistema de gestão de agendamento odontologico)

Esse repositorio foi criado como aprendizado de c++ na materia de Linguagem de programação 1 (LP I) como avaliação da segunda unidade.

Neste projeto deverá ser implementado o respectivo sistema utilizando c++ com o tema proposto. O projeto deve conter:

- Um sistema para agendamentos
- Registros de pacientes
- Historico médico
- Faturamento em um consultorio médico
- GUI (opcional)

Adicionamos também ao projeto:

- Sistema de cadastro de usuarios

## Main

Main será usado apenas como menu de base para o projeto. Nele esta instanciado o objeto newEntry da classe Operações que será usado para chamar as funcionalidades do projeto e um doWhile com switch para que a funcionalidade seja escolhida pelo usuario.

As funcionalidades são citadas em "Projetos".

## Classes (user e agendamentos)

As classes users e agendamentos são criadas nos arquivos user.cpp e agendamentos.cpp. Elas criam os objetos base que utilizamos durante o projeto usando seus respectivos getters e construtores.

## Operações

A classe operações é onde todas as funcionalidades estam inseridas, em sí esta classe é utilizada como objeto apenas para que as funções sejam chamadas no arquivo Main.

Esta classe possui vetores que funcionam como banco de dados, funções auxiliares e as funcionalidades do projeto.

### funções auxiliares

| nome da função |      Funcionalidade           |
|----------------|-------------------------------|
|consume_BD_cadastro | Responsavel por capturar os dados do banco de usuarios cadastrados|
|consume_BD_petsAgenda | Responsavel por capturar os dados do banco de agendamentos|
|tipoConsulta | Define o valor da consulta baseada em seu tipo|
|mostrarHorarios | Mostra os horarios disponiveis para o dia especifico|

### Vetores

|                |      Funcionalidade           |
|----------------|-------------------------------|
|petsAgenda | Irá agir como banco de dados para os agendamentos |
|users | Irá agir como banco de dados para o cadastro de usuario |
|datas | Irá agir como bando de dados paras as datas utilizadas |
|horariosDisponiveis | Irá agir como bando de dados paras os horarios utilizados |

### funcionalidades

| nome da função |      Funcionalidade           |
|----------------|-------------------------------|
|addUser | Cadastra um novo usuario ao banco de dados |
|agendar | Cria um novo agendamento e salva no banco de dados |
|registroDeUsuarios | Mostra todos os usuarios que estam cadastrados |
|historicoMedico | Mostra todos os agendamentos feito por apenas um usuario |
|faturamento | Mostra o faturamento anual e mensal da clinica |
