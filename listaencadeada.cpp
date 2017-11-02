/* Este programa implementa uma lista encadeada simples
   com funcoes para incluir elemento, localizar elemento,
   excluir elemento e listar todos os elementos cadastrados
   Rodrigo Viana
   roviol at gmail com
   02/11/2017
*/


#include <iostream>
#include <cstdlib>
using namespace std;

// Declaracao da struct
struct Alunos {
    int matricula;
    float nota1, nota2, media;
    Alunos *proximo;
} *inicio, *fim;

// Prototipos das funcoes
void criarListaPreencherLista (Alunos *&inicio, Alunos *&fim, int mat, float n1, float n2);
void imprimirLista (Alunos *&inicio);
void localizarMatricula(Alunos *&inicio);
void excluirMatricula(Alunos *&inicio, Alunos *&fim);

// Declaracao de variaveis globais
int mat = 1;
int achei = 0;
float nota1, nota2;
int total = 0;

void menu() {
    int opcao = 0;

    while (opcao != 5) {

        cout << "\t\t-----------------------------------------\n";
        cout << "\t\t  C A D A S T R O    D E    A L U N O S\n";
        cout << "\t\t-----------------------------------------\n\n";
        cout << "\t (1) Incluir aluno\n";
        cout << "\t (2) Localizar aluno\n";
        cout << "\t (3) Imprimir turma\n";
        cout << "\t (4) Apagar aluno\n";
        cout << "\t (5) Sair\n\n";
        cout << "\t Opção: ";
        cin >> opcao;

        // Sem o if abaixo nao eh possivel voltar ao menu de inclusao
        // apos este ter sido chamado pela primeira vez
        if (opcao == 1) mat = 1;

        switch (opcao) {
            case 1:
                while (mat != 0) {
                    system("clear");
                    cout << "\n\t---------------\n";
                    cout << "\t Inserir aluno\n";
                    cout << "\t---------------\n";
                    cout << "\n\t* Informe matrícula igual a 0 para voltar ao menu principal *\n";
                    cout << "\n\t Matrícula: ";
                    cin >> mat;
                    if (mat == 0) { // Se matricula igual a zero, interrompe o laco
                        cout << '\n';
                        break;
                    }
                    else {
                        cout << "\n\t Nota 1: ";
                        cin >> nota1;
                        cout << "\n\t Nota 2: ";
                        cin >> nota2;
                        criarListaPreencherLista(inicio, fim, mat, nota1, nota2);
                    }
                }
                break;
            case 2:
                localizarMatricula(inicio);
                break;
            case 3:
                imprimirLista(inicio);
                break;
            case 4:
                excluirMatricula(inicio, fim);
                break;
            case 5:
                cout << "\nI'll see you on the dark side of the moon.\n\n";
                break;
            default:
                cout << "\n\n\t\t\t\t--------------\n";
                cout << "\t\t\t\tOPÇÃO INVÁLIDA\n";
                cout << "\t\t\t\t--------------\n\n";
        }
    }
}

void criarListaPreencherLista (Alunos *&inicio, Alunos *&fim, int mat, float n1, float n2) {
    Alunos *a;
    // Testa se a lista esta vazia
    if (inicio == fim && inicio == NULL) {
        inicio = new Alunos;
        inicio->matricula = mat;
        inicio->nota1 = n1;
        inicio->nota2 = n2;
        inicio->media = (n1 + n2) / 2;
        inicio->proximo = NULL;
        fim = inicio;
        total++;
    }
    // Se nao vazia, entao inclui novo registro
    else {
        a = new Alunos;
        fim->proximo = a;
        a->matricula = mat;
        a->nota1 = n1;
        a->nota2 = n2;
        a->media = (n1 + n2) / 2;
        a->proximo = NULL;
        fim = a;
        total++;
    }
    cout << "\n\t" << total << " registro(s).\n";
}

void imprimirLista (Alunos *&inicio) {
    Alunos *b, *endereco, *endProx, *endInicio, *endFim;
    b = inicio;
    //int controle = 0;
    //int contador = total;

    endereco = b;
    endInicio = inicio;
    endFim = fim;

    if (inicio == NULL && fim == NULL) {
        cout << "\n\t Não há alunos cadastrados.\n\n";
    }
    else {
        cout << "\n\t--------------------\n";
        cout << "\t Alunos cadastrados\n";
        cout << "\t--------------------\n\n";
        while (b != fim) {
            endereco = b;
            cout << "\t  Endereço:\t " << endereco << endl;
            cout << "\t  Matrícula:\t " << b->matricula << endl;
            cout << "\t  Nota 1:\t " << b->nota1 << endl;
            cout << "\t  Nota 2:\t " << b->nota2 << endl;
            cout << "\t  Média:\t " << b->media << endl;
            cout << "\t  Próximo nó:\t " << b->proximo << endl;
            cout << "\t ..............................\n\n";
            b = b->proximo;

        }

        endereco = b;
        cout << "\t  Endereço:\t " << endereco << endl;
        cout << "\t  Matrícula:\t " << b->matricula << endl;
        cout << "\t  Nota 1:\t " << b->nota1 << endl;
        cout << "\t  Nota 2:\t " << b->nota2 << endl;
        cout << "\t  Média:\t " << b->media << endl;
        cout << "\t  Próximo nó:\t " << b->proximo << endl;
        cout << "\t ..............................\n\n";

        cout << "\t Total: " << total << "\n";
        cout << "\t Endereço de INÍCIO: " << endInicio << "\n";
        cout << "\t Endereço de FIM: " << endFim << "\n\n";
    }
}

void localizarMatricula(Alunos *&inicio) {
    Alunos *c, *endereco;
    int achei = 0;
    int mat;
    c = inicio;
    endereco = c;

    if (inicio == NULL && fim == NULL) {
        cout << "\n\t Não há alunos cadastrados.\n\n";
    }
    else {
        system("clear");
        cout << "\n\t---------------\n";
        cout << "\t Localizar aluno\n";
        cout << "\t---------------\n";
        cout << "\n Matrícula: ";
        cin >> mat;
        while (c != fim) {
            if (c->matricula == mat) {
                achei = 1;
                cout << "\n ................................\n";
                cout << "  Endereço:\t " << endereco << '\n';
                cout << "  Matrícula:\t " << c->matricula << '\n';
                cout << "  Nota 1:\t " << c->nota1 << '\n';
                cout << "  Nota 2:\t " << c->nota2 << '\n';
                cout << "  Média:\t " << c->media << "\n";
                cout << "  Próximo nó:\t " << c->proximo << '\n';
                cout << " ................................\n\n";
            }
            c = c->proximo;
        }

        if (mat == fim->matricula) {
            achei = 1;
            cout << "\n ................................\n";
            cout << "  Endereço:\t " << endereco << '\n';
            cout << "  Matrícula:\t " << c->matricula << '\n';
            cout << "  Nota 1:\t " << c->nota1 << '\n';
            cout << "  Nota 2:\t " << c->nota2 << '\n';
            cout << "  Média:\t " << c->media << "\n";
            cout << "  Próximo nó:\t " << c->proximo << '\n';
            cout << " ................................\n\n";
        }

        if (achei != 1) {
            cout << "\nA matrícula " << mat << " não está cadastrada.\n\n";
        }
    }
}

void excluirMatricula(Alunos *&inicio, Alunos *&fim) {
    Alunos *d, *aux;
    int mat, achei = 0;
    d = inicio;
    aux = inicio;

    if (inicio == NULL && fim == NULL) {
        cout << "\n\t Não há alunos cadastrados.\n\n";
    }
    else {
        cout << "\n\t---------------\n";
        cout << "\t Apagar aluno\n";
        cout << "\t---------------\n";
        cout << "\n Matrícula: ";
        cin >> mat;
        if (mat == inicio->matricula && inicio == fim) {
            inicio = NULL;
            fim = NULL;
            delete d;
            achei = 1;
            total--;
        }
        else {
            while (d != fim) {
                if (mat == d-> matricula && d == inicio) {
                    inicio = d->proximo;
                    delete d;
                    achei = 1;
                    total--;
                    break;
                }
                else {
                    d = d->proximo;
                    if (mat == d->matricula && d != fim) {
                        aux->proximo = d->proximo;
                        delete d;
                        achei = 1;
                        total--;
                        break;
                    }
                    else {
                        if (d != fim) aux = d;
                    }
                    if (mat == d->matricula && d == fim) {
                        aux->proximo = NULL;
                        fim = aux;
                        delete d;
                        achei = 1;
                        total--;
                        break;
                    }
                }
            }
        }
    }
    if (achei != 1 && inicio != NULL && fim != NULL) {
        cout << "\nA matrícula " << mat << " não está cadastrada.\n\n";
    }
}

int main() {
    inicio = NULL;
    fim = NULL;
    menu();

    return 0;
}
