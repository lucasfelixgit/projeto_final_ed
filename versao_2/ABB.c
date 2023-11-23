#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>

No* criar_no(int valor) {
    No* novo_no = malloc(sizeof(No));
    novo_no->data = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

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

void em_ordem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    em_ordem(raiz->esquerda);
    printf("%d ", raiz->data);
    em_ordem(raiz->direita);
}

void pre_ordem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    printf("%d ", raiz->data);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

void pos_ordem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("%d ", raiz->data);
}

int valor_minimo_ab(No* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz->data;
}

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
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->data) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->data) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No* temp = encontrar_minimo(raiz->direita);
        raiz->data = temp->data;
        raiz->direita = remover(raiz->direita, temp->data);
    }

    return raiz;
}
