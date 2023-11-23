#include "ABB.h"
#include <stdio.h>

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

    int x = 10;
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

    int y = 13;
    raiz = remover(raiz, y);

    printf("\nABB apos remocao do %d: ", y);
    em_ordem(raiz);
    printf("\n\n");

    return 0;
}
