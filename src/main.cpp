#include <iostream>
#include <vector>
#include <string>
#include "operacoes.cpp"

using namespace std;

int main(){ 
    // Linha responsavel por instanciar uma classe de operações
    Operacoes newEntry = Operacoes();

    // Leitura inteiro do bando de dados para que nenhuma informação seja perdida ao fechar 
    newEntry.consume_BD_user();
    newEntry.consume_BD_appointment();

    // Inteiro para que um decisão no menu seja tomada
    int escolha;

    // Menu criado com doWhile e switch
    do{
        cout << "Aperte 1 para criar um novo usuario!" << endl;
        cout << "Aperte 2 para criar um agendamento novo!" << endl;
        cout << "Aperte 3 para mostrar o registro de usuarios do sistema!" << endl;
        cout << "Aperte 4 para ver o historico medico de um paciente!" << endl;
        cout << "Apete 5 para ver a media mensal e anual da sua clinica!" << endl;
        cout << "Aperte 6 to exit!" << endl;
        cin >> escolha;
        cin.ignore();

        switch (escolha){
        case 1:
            newEntry.addUser();
            break;
        case 2:
            newEntry.agendar();
            break;
        case 3:
            newEntry.registroDeUsuarios();
            break;
        case 4:
            newEntry.historicoMedico();
            break;
        case 5:
            newEntry.faturamento();
            break;
        case 6:
            cout << "Obrigado por usar nosso sistema de gerenciamento de agendamentos!!" << endl;
            break;
        }
    } while (escolha!=6);

    return 0;
}