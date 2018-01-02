/* 
   This program implements a user definied array with functions
   to insert, delete and list all elements.
   
   Made with Debian GNU/Linux and Atom
   http://www.debian.org
   http://atom.io
   
   Rodrigo Viana de Oliveira
   roviol at gmail com
   11/19/2017

   Este programa implementa um vetor com tamanho definido 
   pelo usuário (vide #define TAM 3) com funções para incluir,
   localizar, excluir e listar todos os elementos cadastrados.
     
   Desenvolvido com Debian GNU/Linux e Atom
   http://www.debian.org
   http://atom.io
   
   Rodrigo Viana de Oliveira
   roviol at gmail com
   19/11/2017
*/


#include <iostream>
#include <cstdlib>
#include <locale.h>

using namespace std;

#define TAM 3 // Defina aqui o tamanho da turma

struct Turma {
    float n1, n2, media;
    int matricula;
};

// Declaracao das variaveis globais
Turma aluno[TAM];
int opcao = 9999, pesquisa, achei = 0;

// Funcao para exibir o menu
void Menu() {
    //system("clear"); // So funciona em sistemas Linux
    cout << "\t\t= = =   M E N U   P R I N C I P A L   = = =\n\n";
    cout << "\t1 - Inserir aluno\n";
    cout << "\t2 - Pesquisar\n";
    cout << "\t3 - Imprimir turma\n";
    cout << "\t4 - Excluir aluno\n\n";
    cout << "\tDigite a opção (ou 0 para encerrar): ";
    cin >> opcao;
}

// Funcao para inserir alunos
void Inserir() {
    //system("clear"); // So funciona em sistemas Linux
    cout << "\n\t\t - - -   Inserir alunos   - - -\n\n";
    for (int i = 0; i < TAM; i++) {
        cout << "Matrícula: ";
        cin >> aluno[i].matricula;
        do {
            cout << "Nota 1: ";
            cin >> aluno[i].n1;
            if (aluno[i].n1 < 0 || aluno[i].n1 > 10) cout << "\n\tDigite notas entre 0 e 10.\n\n";
        } while (aluno[i].n1 < 0 || aluno[i].n1 > 10); // Somente aceita notas entre 0 e 10
        do {
            cout << "Nota 2: ";
            cin >> aluno[i].n2;
            if (aluno[i].n2 < 0 || aluno[i].n2 > 10) cout << "\n\tDigite notas entre 0 e 10.\n\n";
        } while (aluno[i].n2 < 0 || aluno[i].n2 > 10); // Somente aceita notas entre 0 e 10
        aluno[i].media = (aluno[i].n1 + aluno[i].n2) / 2;
        cout << '\n';
    }
}

// Funcao para pesquisar alunos
void Pesquisar() {
    //system("clear"); // So funciona em sistemas Linux
    achei = 0;
    if (aluno[0].matricula == 0) {
        cout << "\n\tNão há alunos cadastrados\n\n";
    }
    else {
        cout << "\n\t\t- - -   Localizar aluno   - - -\n\n";
        while (achei == 0) {
            cout << "Informe a matrícula: ";
            cin >> pesquisa;
            for (int i = 0; i < TAM; i++) {
                if (pesquisa == aluno[i].matricula) {
                    cout << "Nota 1: " << aluno[i].n1 << '\n';
                    cout << "Nota 2: " << aluno[i].n2 << '\n';
                    cout << "Média: " << aluno[i].media << '\n';
                    i = TAM;
                    achei = 1;

                }
            }
            if (achei != 1) {
                cout << "Matrícula não encontrada!";
                cout << "\n\n";
            }
        }
    }
}

// Funcao para exibir todos os alunos cadastrados
void Imprimir() {
    //system("clear"); // So funciona em sistemas Linux
    achei = 0;

    if (aluno[0].matricula == 0) {
        cout << "\n\tNão há alunos cadastrados\n\n";
    }
    else {
        cout << "\t\t- - -   Alunos cadastrados   - - -\n\n";
        for (int i = 0; i < TAM; i++) {
            if (aluno[i].matricula != 0) {
                cout << "Matrícula: " << aluno[i].matricula << '\n';
                cout << "Nota 1: " << aluno[i].n1 << '\n';
                cout << "Nota 2: " << aluno[i].n2 << '\n';
                cout << "Média: " << aluno[i].media << '\n';
                cout << "-------------------------------\n\n";
                achei++;
            }
        }
    }
}

void Excluir() {
    int pesq = 0, achei = 0;
    //system("clear"); // So funciona em sistemas Linux
    if (aluno[0].matricula == 0) {
        cout << "\n\tNão há alunos cadastrados\n\n";
    }
    else {
        cout << "\n\t\t- - -   Excluir aluno   - - -\n\n";
        while (achei == 0) {
            cout << "Informe a matrícula a ser excluída: ";
            cin >> pesq;
            for (int i = 0; i < TAM; i++) {
                if (pesq == aluno[i].matricula) {
                    for (int j = (i+1); j <= TAM; j++) {
                        aluno[i].matricula = aluno[j].matricula;
                        aluno[i].n1 = aluno[j].n1;
                        aluno[i].n2 = aluno[j].n2;
                        aluno[i].media = aluno[j].media;

                        aluno[j].matricula = 0;
                        i++;
                    }
                    achei = 1;
                }
            }
            if (achei != 1) {
                cout << "Matrícula não encontrada!";
                cout << "\n\n";
            }
            else {
            	cout << "Matrícula excluída com sucesso.";
            	cout << "\n\n";
			}
        }
    }
}

// Funcao principal
int main() {
	setlocale(LC_ALL, ""); // Windows e suas frescuras...

    while (opcao != 0) {
        Menu();
        switch (opcao) {
            case 1:
                Inserir();
                break;
            case 2:
                Pesquisar();
                break;
            case 3:
                Imprimir();
                break;
            case 4:
                Excluir();
                break;
            default:
                cout << '\n';
                if (opcao != 0) { cout << "Opção inválida.\n\n"; };
        }
    }

    cout << '\n';
    cout << "\t\t* * *   I'll see you on the dark side of the moon   * * *\n\n";
    return 0;
}
