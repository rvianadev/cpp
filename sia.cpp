/*
    Faça um programa para Exibir

    1 - Adicionar aluno
    2 - Adicionar nota

    Sabendo que o aluno deve estar cadastrado. O sistema perguntará qual a
    matrícula do aluno, localizar essa matrícula na memória e logo depois
    permitir a entrada das notas de AV1, AV2 e AV3.

    3 - Exibir os alunos com média superior a 7.
    4 - Sair do programa

*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    float nota1 = 0.0, nota2 = 0.0, nota3 = 0.0, media = 0.0;
};

int main() {
    int cont = 0, opcao = 0, mat = 0, qtAlunos = 0, qtNotas = 0, codMat = 0, alunoSuper = 0;
    Aluno aluno[5];

    while (opcao != 4) {
        cout << endl;
        cout << "\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n";
        cout << "\t\t\t _______   _________   _______\n";
        cout << "\t\t\t(  ____ \\  \\__   __/  (  ___  )\n";
        cout << "\t\t\t| (    \\/     ) (     | (   ) |\n";
        cout << "\t\t\t| (_____      | |     | (___) |\n";
        cout << "\t\t\t(_____  )     | |     |  ___  |\n";
        cout << "\t\t\t      ) |     | |     | (   ) |\n";
        cout << "\t\t\t/\\____) |  ___) (___  | )   ( |\n";
        cout << "\t\t\t\\_______)  \\_______/  |/     \\|\n";
        cout << endl;
        cout << "\t\t\t SISTEMA DE INCLUSÃO DE ALUNOS" << endl;
        cout << "\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n";
        cout << endl;
        cout << "1 - Cadastrar aluno\n";
        cout << "2 - Cadastrar nota\n";
        cout << "3 - Exibir alunos com média superior a 7\n";
        cout << "4 - Sair\n";
        cout << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1:
                cout << "\t\t* * *   CADASTRO DE ALUNOS   * * *" << endl;
                if (qtAlunos < 5) {
                    cout << "ALUNO (" << (codMat + 1) << ") de 5\n";
                    cout << "---------\n";
                    cout << "Nome: ";
                    cin >> aluno[codMat].nome;
                    aluno[codMat].matricula = (codMat + 1);
                    cout << "Matrícula: " << aluno[codMat].matricula;
                    cout << endl << endl;
                    qtAlunos += 1;
                    codMat += 1;
                }
                else {
                    cout << endl;
                    cout << " Impossível cadastrar mais alunos.\n";
                }
                break;
            case 2:
                cout << endl;
                cout << "--------------------------------------------------------------------\n";
                cout << "\t\t* * *   CADASTRO DE NOTAS   * * *" << endl;
                if (qtAlunos == 0) {
                    cout << "\n";
                    cout << "Não há alunos cadastrados.\n";
                    cout << "Use a opção 1 para cadastrar alunos.\n";
                    cout << "--------------------------------------------------------------------\n";
                    cout << endl;
                }
                else {
                    cout << "Informe a matrícula do aluno: ";
                    cin >> mat;
                    for (cont = 0; cont < 5; cont++) {
                        if (mat == aluno[cont].matricula) {
                            cout << "Aluno: " << aluno[cont].nome << endl;
                            cout << "Informe a nota da AV1: ";
                            cin >> aluno[cont].nota1;
                            cout << "Informe a nota da AV2: ";
                            cin >> aluno[cont].nota2;
                            cout << "Informe a nota da AV3: ";
                            cin >> aluno[cont].nota3;
                            aluno[cont].media = (aluno[cont].nota1 + aluno[cont].nota2 + aluno[cont].nota3) / 3;
                            cout << endl;
                            qtNotas += 1;
                            cont = 5;
                        }
                        else {
                            if (cont == 4) {
                                cout << "Matrícula inexistente!" << endl;
                            }
                        }
                    }

                }
                break;
            case 3:
                cout << endl;
                cout << "--------------------------------------------------------------------\n";
                cout << "\t\t* * *   ALUNOS COM MÉDIA MAIOR QUE 7.0   * * *" << endl;
                if (qtAlunos == 0) {
                    cout << "\n";
                    cout << "Impossível mostrar as médias.\n";
                    cout << "Use a opção 1 para cadastrar alunos.\n";
                    cout << "Em seguida, use a opção 2 para cadastrar as notas.\n";
                    cout << "--------------------------------------------------------------------\n";
                    cout << endl;
                }
                else {
                    if (qtNotas == 0) {
                        cout << "\n";
                        cout << "Não há notas cadastradas.\n";
                        cout << "Use a opção 2 para cadastrar as notas.\n";
                        cout << "--------------------------------------------------------------------\n";
                        cout << endl;
                    }
                    else {
                        for (cont = 0; cont < 5; cont++) {
                            if (aluno[cont].media > 7) {
                                cout << "\n";
                                cout << "---------------------------------------" << endl;
                                cout << "Aluno: " << aluno[cont].nome << endl;
                                cout << "Matrícula: " << aluno[cont].matricula << endl;
                                cout << "Média: " << aluno[cont].media << endl;
                                cout << "---------------------------------------" << endl;
                                alunoSuper += 1;
                            }
                            else {
                                if (alunoSuper == 0) {
                                    cout << "\n";
                                    cout << "Não há alunos com média acima de 7.0\n";
                                    cout << "--------------------------------------------------------------------\n";
                                    cont = 5;
                                }
                            }
                        }
                    }
                }
                break;
            case 4:
                break;
            case 666:
                cout << "- = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - =\n";
                cout << "\t G N U / L I N U X    S E J A    L O U V A D O ! ! !\n";
                cout << "- = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - =\n";
            default:
                cout << endl;
                cout << "--------------------------------------------------------------------\n";
                cout << "\t\t\t OPÇÃO INVÁLIDA !!!\n";
                cout << "--------------------------------------------------------------------\n";
        }
    }
cout << endl;
cout << "F I M    D O    P R O G R A M A";
cout << endl;
return 0;
}
