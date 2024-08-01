// Bibliotecas necessarias para o uso de entradas/saidas, sistema de arquivos e vetores
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Chamada dos arquivos usados no projeto
#include "appointment.cpp"
#include "user.cpp"

using namespace std;

class Operacoes{
private:
    fstream file;

    // Vetores
    vector<Appointment> newAppointment;
    vector<User> users;

    vector<string> datas;
    vector<vector<bool>> horariosDisponiveis;
public:
    //// Definições de funções que seram usadas
    //Funções auxiliares
    void consume_BD_user();
    void consume_BD_appointment();
    double tipoConsulta(string c);
    void mostrarHorarios(string data);

    //Funcionalidades
    void addUser();
    void agendar();
    void registroDeUsuarios();
    void historicoMedico();
    void faturamento();
};

// Func auxiliar responsavel por carregar o banco de dados em um vector do aplicativo
// Percorre todo o arquivo BD_cadastros, atualizando-o no banco de dados da aplicação (Vetor users)
void Operacoes ::consume_BD_user(){
    string Email, Name, Cpf, primeiraLinha;

    file.open("BD_user.txt", ios ::in);
    getline(file, primeiraLinha);
    file.close();

    if(primeiraLinha.empty()){
        cout << "Impossivel acessar o BD_user!" << endl;
        return;
    } else {
        file.open("BD_user.txt", ios ::in);
    
        while(true){
            getline(file, Email , '*');
            getline(file, Name, '*');
            getline(file, Cpf, '\n');

            if(file.eof()){
                break;
            } 

            users.push_back(User(Email, Name, Cpf));
        }

        file.close();
    }
}

// Func auxiliar responsavel por carregar o banco de dados em um vector do aplicativo
// Percorre todo o arquivo BD_agenda, atualizando-o no banco de dados da aplicação (Vetor newAppointment)
void Operacoes ::consume_BD_appointment(){
    string ID, Name, Cpf, add_consulta, ageStr, fatStr, Data, horarioStr, primeiraLinha;
    int Age, Horario;
    double Fat;

    file.open("BD_appointment.txt", ios ::in);
    getline(file, primeiraLinha);
    file.close();

    if(primeiraLinha.empty()){
        cout << "Impossivel acessar o BD_appointment!" << endl;
        return;
    } else {
        file.open("BD_appointment.txt", ios ::in);
    
        while(true){
            getline(file, ID , '*');
            getline(file, Name, '*');
            getline(file, Cpf, '*');
            getline(file, ageStr, '*');
            getline(file, add_consulta, '*');
            getline(file, fatStr, '*');
            getline(file, Data, '*');
            getline(file, horarioStr, '\n');

            Age = stoi(ageStr);
            Horario = stoi(horarioStr);
            Fat = tipoConsulta(add_consulta);

            if(file.eof()){
                break;
            } 

            bool dataExists = false;
            //Verifica se a data já existe no arquivo
            for (size_t i = 0; i < datas.size(); ++i) {
                if (datas[i] == Data) {
                    //Se a data e horário existem, remove ele dos horários disponíveis
                    horariosDisponiveis[i][Horario - 1] = false;
                    dataExists = true;
                    break;
                }
            }
            
            //Se não existe, adiciona o horário como disponível
            if (!dataExists) {
                datas.push_back(Data);
                horariosDisponiveis.push_back(vector<bool>(5, true));
                horariosDisponiveis.back()[Horario - 1] = false;
            }

            newAppointment.push_back(Appointment(ID, Name, Cpf, Age, add_consulta, Fat, Data, Horario));
        }

        file.close();
    }
}

// Func auxiliar responsavel por atribuir um valor especifico de acordo com a consulta o paciente terá
// Atribui um valor de acordo com a string c digitada e retorna esse valor
double Operacoes ::tipoConsulta(string c){
    if(c == "limpeza"){
        return 100.00;
    } else if(c == "manutencao"){
        return 125.00;
    } else if(c == "restauracao"){
        return 150.00;
    } else if(c == "extracao"){
        return 200.00;
    }else if(c == "clareamento"){
        return 250.00;
    } else if(c == "canal") {
        return 400.00;
    } else if(c == "triagem") {
        return 00.00;
    } else {
        return 00.00;
    }
}

void Operacoes ::mostrarHorarios(string data) {
    cout << "Horarios disponíveis para a data " << data << ":" << endl;
    vector<bool> horarios(5, true);

    //percorre o vetor para encontrar a data correspondente
    for (size_t i = 0; i < datas.size(); ++i) {
        if (datas[i] == data) {
            horarios = horariosDisponiveis[i];
            break;
        }
    }

    //Exibe os horários disponíveis  
    if (horarios[0]) cout << "1 - 09:00h" << endl;
    if (horarios[1]) cout << "2 - 11:00h" << endl;
    if (horarios[2]) cout << "3 - 13:00h" << endl;
    if (horarios[3]) cout << "4 - 15:00h" << endl;
    if (horarios[4]) cout << "5 - 17:00h" << endl;
}

// Função responsavel por cadastrar um usuario no banco de dados
// Captura os valores digitados com getline
// Salva os valores de usuario no arquivo banco de dados, e adiciona o valor tambem no final do vetor
void Operacoes ::addUser(){
    string Email, Name, Cpf;

    cout << "Digite seu Email!" << endl;
    getline(cin, Email);
    cout << "Digite o seu nome!" << endl;
    getline(cin, Name);
    cout << "Digite o seu cpf! " << endl;
    getline(cin, Cpf);

    file.open("BD_user.txt", ios ::out | ios ::app);
    file << Email << "*" << Name << "*" << Cpf << endl;
    file.close();

    users.push_back(User(Email, Name, Cpf));

    cout << "Novo cadastro concluido! " << endl;
}

void Operacoes ::agendar(){
    string email, cpf, name, consulta, data;
    int age, horario;
    double fat;

    cout << "Digite o email do usuario!" << endl;
    getline(cin, email);
    cout << "Digite o Cpf do usuario!" << endl;
    getline(cin, cpf);

    for(int i=0; i < int(users.size()); i++){
        if(email == users[i].getEmail() && cpf == users[i].getCpf()){
            cout << "Digite o nome do paciente!" << endl;
            getline(cin, name);
            // cout << "Digite o seu cpf!" << endl;
            // getline(cin, cpf);
            cout << "Qual a idade do paciente?" << endl;
            cin >> age;
            cin.ignore();
            cout << "Qual sera o tipo da sua consulta?" << endl;
            cout << "Limpeza - Manutencao - Restauracao - Extracao - Clareamento - Canal - Triagem" << endl;
            getline(cin, consulta);
            transform(consulta.begin(), consulta.end(), consulta.begin(),::tolower); 
            cout << "Digite a data para o agendamento dd/mm: " << endl;
            getline(cin, data);

            mostrarHorarios(data);

            while (horario < 0 || horario > 4){
            cout << "Selecione o horario (1-5): ";
            cin >> horario;
            cin.ignore();

            horario -= 1;
            if (horario < 0 || horario > 4){
                cout << "Horario Invalido!" << endl;
            } ;
            };

            bool dataExiste = false;
            for (size_t i = 0; i < datas.size(); ++i) {
                if (datas[i] == data) {
                    //Verifica se o horário selecionado é válido
                    if (horariosDisponiveis[i][horario]) {
                        horariosDisponiveis[i][horario] = false;
                        cout << "Horario agendado com sucesso!" << endl;
                    } else {
                        cout << "Horario indisponivel. Por favor, escolha outro horario." << endl;
                    }
                    dataExiste = true;
                    break;
                }
            }

            if (!dataExiste) {
                //Se a data não existir, adiciona ela ao arquivo.
                datas.push_back(data);
                horariosDisponiveis.push_back(vector<bool>(5, true));
                horariosDisponiveis.back()[horario] = false;
                cout << "Horario agendado com sucesso!" << endl;
            }

            horario += 1;

            fat = tipoConsulta(consulta);

            file.open("BD_appointment.txt", ios ::out | ios ::app);
            file << email << "*" << name << "*" << cpf << "*" << age << "*" << consulta << "*" << fat << "*"<< data << "*" << horario << endl;
            file.close();

            newAppointment.push_back(Appointment(email, name, cpf, age, consulta, fat, data, horario));
        }
    }
}

// Func responsavel por mostrar todos os usuarios cadastrados
// Usa um for para imprimir a lista que está inserida no vetor de usuarios(users)
void Operacoes ::registroDeUsuarios(){
    for(int i=0; i < int(users.size()); i++){
        cout << "---------------------------" << endl;
        cout << users[i].getEmail() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getCpf() << endl;
    }
    cout << "---------------------------" << endl;
    cout << endl;
}

// Func responsavel por apresentar o historico medico de um paciente (Mostra todos os agendamentos de um paciente por ID)
// Procura o paciente pelo ID no vetor de agendamentos(newAppointment) pelo ID, caso o agendamento estaja com o ID do paciente
// Mostra-rá o resultado na tela
void Operacoes ::historicoMedico(){
    string checkIdExists;
    cout << "Digite email do usuario! " << endl;
    getline(cin, checkIdExists);

    for(int i=0; i < int(newAppointment.size()); i++){
        if(checkIdExists == newAppointment[i].getID()){
            cout << "---------------------------" << endl;
            cout << "Email: " << newAppointment[i].getID() << endl;
            cout << "Nome: " << newAppointment[i].getName() << endl;
            cout << "CPF: " << newAppointment[i].getCpf() << endl;
            cout << "Consulta: " << newAppointment[i].getConsulta() << endl;
            cout << "Idade: " << newAppointment[i].getAge() << endl;
            cout << "Custo: " << newAppointment[i].getIncome() << endl;
            cout << "Data: " << newAppointment[i].getData() << endl;
            cout << "Horario: " << newAppointment[i].getHorario() << endl;
        }
    }
    cout << "---------------------------" << endl;
    cout << endl;
}

// Func responsavel por mostrar FATURAMENTO MENSAL/ANUAL
// For que percorre o vetor de agendamentos(newAppointment) pegando todos o valores de income e somando em um valor total.
void Operacoes ::faturamento(){
    double income = 0;

    for(int i=0; i < int(newAppointment.size()); i++){
        income += newAppointment[i].getIncome();
    }

    cout << "----------------------" << endl;
    cout << "Faturamento anual: " << income << endl;
    cout << "Faturamento mesal: " << income/12 << endl;
    cout << "----------------------" << endl;
    cout << endl;
}
