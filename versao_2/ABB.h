#ifndef ABB_H
#define ABB_H

typedef struct No {
    int data;
    struct No* esquerda;
    struct No* direita;
} No;

No* criar_no(int valor);
No* inserir(No* raiz, int data);
No* buscar(No* raiz, int elem);
void em_ordem(No* raiz);
void pre_ordem(No* raiz);
void pos_ordem(No* raiz);
int valor_minimo_ab(No* raiz);
int valor_maximo_ab(No* raiz);
No* encontrar_minimo(No* raiz);
No* remover(No* raiz, int valor);

#endif 
