#include <iostream>
using namespace std;

struct No {
    int valor;
    No *direito, *esquerdo, *proximo;
} *raiz, *a, *aux, *inicio, *fim;

// Prototipos das funcoes
void Compara(No *&aux);
void Inserir(int num);
void Exibir(No *&aux);

int numero;

void Compara(No *&aux) {
    if (a->valor < aux->valor) {
        if (aux->esquerdo == NULL) {
            aux->esquerdo = a;
            cout << "Número " << a->valor << " incluído com sucesso à esquerda de " << aux->valor << "\n";
        }
        else {
            aux = aux->esquerdo;
            Compara(aux);
        }
    }

    if (a->valor > aux->valor) {
        if (aux->direito == NULL) {
            aux->direito = a;
            cout << "Número " << a->valor << " incluído com sucesso à direita de " << aux->valor << "\n";
        }
        else {
            aux = aux->direito;
            Compara(aux);
        }
    }
}

void Inserir(int num) {
    if (raiz == NULL) {
        raiz = new No;
        raiz->valor = num;
        raiz->esquerdo = NULL;
        raiz->direito = NULL;
        raiz->proximo = NULL;
        inicio = raiz;
        fim = inicio;
        cout << "Raiz incluída com sucesso!\n";
    }
    else {
        a = new No;
        fim->proximo = a;
        a->valor = num;
        a->esquerdo = NULL;
        a->direito = NULL;
        a->proximo = NULL;
        fim = a;

        if (raiz != NULL) {
            aux = raiz;
            Compara(aux);
        }
    }
}

void Exibir(No *&inicio) {
    No *b;
    int nEsq, nDir;
    b = inicio;

    if (inicio == NULL && fim == NULL) {
        cout << "\n\t Não há números cadastrados.\n\n";
    }
    else {
        cout << "\n\tE X I B I N D O . . .\n\n";

        while (b != fim) {
            if (b->esquerdo != NULL) nEsq = b->esquerdo->valor;
            if (b->direito != NULL) nDir = b->direito->valor;

            cout << "Valor: " << b->valor << "\n";
            if (b->esquerdo != NULL) {
                cout << "Nó esquerdo: " << b->esquerdo->valor << "\n";
            }
            else {
                cout << "Nó esquerdo: " << b->esquerdo << "\n";
            }

            if (b->direito != NULL) {
                cout << "Nó direito: " << b->direito->valor << "\n\n";
            }
            else {
                cout << "Nó direito: " << b->direito << "\n\n";
            }
            b = b->proximo;
        }

        cout << "Valor: " << b->valor << "\n";
        if (b->esquerdo != NULL) {
            cout << "Nó esquerdo: " << b->esquerdo->valor << "\n";
        }
        else {
            cout << "Nó esquerdo: " << b->esquerdo << "\n";
        }

        if (b->direito != NULL) {
            cout << "Nó direito: " << b->direito->valor << "\n\n";
        }
        else {
            cout << "Nó direito: " << b->direito << "\n\n";
        }

    }
}

int main() {
    do {
        cout << "\nInforme um número: ";
        cin >> numero;
        if (numero != 0) {
            Inserir(numero);
        } else {
            cout << "Fim da inclusão de elementos.\n\n";
        }
    } while (numero != 0);

    Exibir(inicio);
    return 0;
}
