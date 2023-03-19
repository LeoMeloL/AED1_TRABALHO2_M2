#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

void CriaLista(ListNode **cabeca, int val);
void ImprimeLista(ListNode *cabeca);
bool isPalindrome(ListNode *cabeca);
void LimpaLista(ListNode **cabeca);

void CriaLista(ListNode **cabeca, int val) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (*cabeca == NULL) {
        *cabeca = newNode;
    } else {
        ListNode *lastNode = *cabeca;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void ImprimeLista(ListNode *cabeca) {
    while (cabeca != NULL) {
        printf("%d ", cabeca->val);
        cabeca = cabeca->next;
    }
    printf("\n");
}

bool isPalindrome(ListNode* cabeca) {
    int count = 0;
    ListNode* atual = cabeca;
    while (atual != NULL) {
        count++;
        atual = atual->next;
    }

    int Metade = count / 2;
    atual = cabeca;
    ListNode* prev = NULL;
    for (int i = 0; i < Metade; i++) {
        ListNode* next = atual->next;
        atual->next = prev;
        prev = atual;
        atual = next;
    }

    if (count % 2 == 1) {
        atual = atual->next;
        atual = atual->next;
    }

    for (int i = 0; i < Metade; i++) {
        if (prev->val != atual->val) {
            return false;
        }
        prev = prev->next;
        atual = atual->next;
    }

    return true;
}


void LimpaLista(ListNode **cabeca) {
    ListNode *atual = *cabeca;
    ListNode *prox;

    while (atual != NULL) {
        prox = atual->next;
        free(atual);
        atual = prox;
    }

    *cabeca = NULL;
}


int main() {

    ListNode *cabeca = NULL;
    CriaLista(&cabeca, 1);
    CriaLista(&cabeca, 2);
    CriaLista(&cabeca, 2);
    CriaLista(&cabeca, 2);
    CriaLista(&cabeca, 2);
    CriaLista(&cabeca, 1);

    printf("Lista encadeada: ");
    ImprimeLista(cabeca);
    bool resultado = isPalindrome(cabeca);
    if (resultado) {
        printf("A lista é um palíndromo.\n");
    } else {
        printf("A lista não é um palíndromo.\n");
    }

    LimpaLista(&cabeca);

//Teste 2:
    CriaLista(&cabeca, 1);
    CriaLista(&cabeca, 2);

    printf("\n");
    printf("Lista encadeada: ");
    ImprimeLista(cabeca);
    resultado = isPalindrome(cabeca);
    if (resultado) {
        printf("A lista é um palíndromo.\n");
    } else {
        printf("A lista não é um palíndromo.\n");
    }

    free(cabeca);
    return 0;
}