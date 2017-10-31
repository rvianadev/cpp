/* Este programa implementa uma lista encadeada simples
   com funcoes para incluir elemento, localizar elemento,
   excluir elemento e listar todos os elementos cadastrados

   Falta implementar o código que testa se a lista está vazia
   29/10/2017
   Rodrigo Viana
   roviol at gmail com
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

/* A variavael 'total' sera incrementada a cada registro incluido
 * e sera atribuida a variavel 'contador', que sera decrementada
 * na funcao imprimirLista() e localizarMatricula(), auxiliando na
 * exibicao dos registros
*/
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

        // Sem o if abaixo ocorre erro no contador da funcao excluirMatricula
        // apos esta ter sido chamada pela primeira vez
        if (opcao == 4) achei = 0;

        switch (opcao) {
            case 1:
                while (mat != 0) {
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
    int contador = total;
    // Testa se a lista esta vazia
    if (inicio == fim && inicio == NULL) {
        inicio = new Alunos;
        inicio->matricula = mat;
        inicio->nota1 = n1;
        inicio->nota2 = n2;
        inicio->media = (n1 + n2) / 2;
        inicio->proximo = NULL;
        fim = inicio;
        contador++;
        total = contador;
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
        contador++;
        total = contador;
    }
    cout << "\n\t" << total << " registro(s).\n";
}

void imprimirLista (Alunos *&inicio) {
    Alunos *b;
    b = inicio;
    int contador = total;
    cout << "\n\t--------------------\n";
    cout << "\t Alunos cadastrados\n";
    cout << "\t--------------------\n";
    while (contador > 0) {
        cout << "\n\t  Matrícula:\t " << b->matricula << '\n';
        cout << "\n\t  Nota 1:\t " << b->nota1 << '\n';
        cout << "\n\t  Nota 2:\t " << b->nota2 << '\n';
        cout << "\n\t  Média:\t " << b->media << "\n";
        cout << "\n\t .....................\n\n";
        b = b->proximo;
        contador--;
    }
}

void localizarMatricula(Alunos *&inicio) {
    Alunos *c;
    int mat;
    c = inicio;
    int contador = total;
    cout << "\n\t---------------\n";
    cout << "\t Localizar aluno\n";
    cout << "\t---------------\n";
    cout << "\n Matrícula: ";
    cin >> mat;
    while (contador > 0) {
        if (c->matricula == mat) {
            cout << "\n .....................\n";
            cout << "  Matrícula:\t " << c->matricula << '\n';
            cout << "  Nota 1:\t " << c->nota1 << '\n';
            cout << "  Nota 2:\t " << c->nota2 << '\n';
            cout << "  Média:\t " << c->media << "\n";
            cout << " .....................\n\n";
        }
        c = c->proximo;
        contador--;
    }
}

void excluirMatricula(Alunos *&inicio, Alunos *&fim) {
    Alunos *d, *aux;
    int mat;
    d = inicio;
    aux = inicio;
    int contador = total;
    cout << "\n\t---------------\n";
    cout << "\t Apagar aluno\n";
    cout << "\t---------------\n";
    cout << "\n Matrícula: ";
    cin >> mat;

    while (contador > 0) {
        if (mat == d->matricula && inicio == fim) {
            delete d;
            inicio = NULL;
            fim = NULL;
            achei = 1;
            cout << "\n1\n";
            break;
        }

        if (mat == d->matricula && d == inicio) {
            inicio = d->proximo;
            delete d;
            achei = 1;
            cout << "\n2\n";
            break;
        }

        if (mat == d->matricula && d != inicio && d != fim) {
            if (aux == inicio) {
                aux->proximo = d->proximo;
                inicio = aux;
                delete d;
                achei = 1;
                cout << "\n3\n";
                break;
            }
            else {
                aux->proximo = d->proximo;
                delete d;
                achei = 1;
                cout << "\n3\n";
                break;
            }
        }
        else {
            aux = d;
            d = d->proximo;
        }

        if (mat == d->matricula && d == fim) {
            aux->proximo = NULL;
            fim = aux;
            delete d;
            achei = 1;
            cout << "\n4\n";
            break;
        }
        else {
            aux = d;
            d = d->proximo;
        }
    }

    if (achei == 1) {
        total--;
    }
    else {
        cout << "\n Matrícula não encontrada.\n\n";
    }
    cout << "\t Total: " << total << "\n\n";
}

int main() {
    inicio = NULL;
    fim = NULL;
    menu();

    return 0;
}
