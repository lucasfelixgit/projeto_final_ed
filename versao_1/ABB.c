#include <stdio.h>
#include <stdlib.h>

//Estrutura do no
typedef struct No {
    int data;
    struct No* esquerda;
    struct No* direita;
} No;

//Funcao para criar no
No* criar_no(int valor) {
    No* novo_no = malloc(sizeof(No));
    novo_no->data = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;

    return novo_no;
}

//Funcao para inserir novo valor na ABB
No* inserir(No* raiz, int data) {
    if (raiz == NULL) {
        return criar_no(data);
    }

    if (data < raiz->data) {
        raiz->esquerda = inserir(raiz->esquerda, data);
    } else if (data > raiz->data) {
        raiz->direita = inserir(raiz->direita, data);
    }

    return raiz;
}

//Funcao para buscar um elemento na AB
No* buscar(No* raiz, int elem) {
    if (raiz == NULL) {
        return NULL;
    }

    if (elem == raiz->data) {
        return raiz;
    }

    if (elem < raiz->data) {
        return buscar(raiz->esquerda, elem);
    } else {
        return buscar(raiz->direita, elem);
    }
}

//Percurso Em-ordem (E-R-D) ou Percurso Simétrico
void em_ordem(No* raiz) {  
    if (raiz == NULL) {
        return;
    }

    em_ordem(raiz->esquerda);
    printf("%d ", raiz->data);
    em_ordem(raiz->direita);
}

//Percurso Pre-ordem (R-E-D) 
void pre_ordem(No* raiz) { 
    if (raiz == NULL) {
        return;
    }

    printf("%d ", raiz->data);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

//Percurso Pos-ordem (E, D, R)
void pos_ordem(No* raiz) { 
    if (raiz == NULL) {
        return;
    }

    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("%d ", raiz->data);
}

//Função para encontrar valor minimo da AB
int valor_minimo_ab(No* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz->data;
}

//Função para encontrar valor máximo da AB
int valor_maximo_ab(No* raiz) {
    while (raiz->direita != NULL) {
        raiz = raiz->direita;
    }
    return raiz->data;
}

No* encontrar_minimo(No* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

No* remover(No* raiz, int valor) {

    //Caso Base: Raiz nula ou No nao encontrado
    if (raiz == NULL) {
        return raiz;
    }

    //Escolha do Subcaso (Recursao)
    if (valor < raiz->data) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } 
    else if (valor > raiz->data) {
        raiz->direita = remover(raiz->direita, valor);
    } 
    //Valor encontrado
    else { 

        //1o Caso: No com 0 ou 1 filho
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        //Caso 2: No com 2 filhos
        No* temp = encontrar_minimo(raiz->direita);
        raiz->data = temp->data;
        raiz->direita = remover(raiz->direita, temp->data);
    }
    return raiz;
}

int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 15);
    inserir(raiz, 8);
    inserir(raiz, 24);
    inserir(raiz, 5);
    inserir(raiz, 13);
    inserir(raiz, 19);
    inserir(raiz, 28);

    printf("\n");

    int x = 5;
    if (buscar(raiz, x)) {
        printf("O elemento %d esta na arvore!\n", x);
    } else {
        printf("O elemento %d nao esta na arvore!\n", x);
    }

    printf("\nValor Minimo da ABB: %d\n", valor_minimo_ab(raiz));
    printf("Valor Maximo da ABB: %d\n", valor_maximo_ab(raiz));

    printf("\nPre ordem: ");
    pre_ordem(raiz);

    printf("\nEm ordem: ");
    em_ordem(raiz);

    printf("\nPos ordem: ");
    pos_ordem(raiz);

    printf("\n");

    int y = 28;
    raiz = remover(raiz, y);

    printf("\nABB apos remocao do %d: ", y);
    em_ordem(raiz);
    printf("\n\n");

    return 0;
}