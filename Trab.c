#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode_t {
    int val;
    struct ListNode_t *next;
} ListNode_t;

void CriaLista( ListNode_t **cabeca, int val );
void ImprimeLista( ListNode_t *cabeca );
bool IsPalindrome( ListNode_t *cabeca );
void LimpaLista( ListNode_t **cabeca );

void CriaLista( ListNode_t **cabeca, int val ) {
    ListNode_t *newNode = ( ListNode_t* )malloc( sizeof ( ListNode_t ) );
    newNode->val = val;
    newNode->next = NULL;

    if ( *cabeca == NULL ) {
        *cabeca = newNode;
    } else {
        ListNode_t *lastNode = *cabeca;
        while ( lastNode->next != NULL ) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->next = NULL;
    }
}

void ImprimeLista( ListNode_t *cabeca ) {
    while ( cabeca != NULL ) {
        printf("%d ", cabeca->val);
        cabeca = cabeca->next;
    }
    printf("\n");
}

bool IsPalindrome( ListNode_t* cabeca ) {
    int count = 0;
    ListNode_t* atual = cabeca;
    while ( atual != NULL ) {
        count++;
        atual = atual->next;
    }


    int Metade = count / 2;
    atual = cabeca;
    ListNode_t* prev = NULL;
    for ( int i = 0; i < Metade; i++ ) {
        ListNode_t* next = atual->next;
        atual->next = prev;
        prev = atual;
        atual = next;
    }

    if ( count % 2 == 1 ) {
        atual = atual->next;
    }

    for ( int i = 0; i < Metade; i++ ) {
        if ( prev->val != atual->val ) {
            free( prev );
            return false;
        }
        prev = prev->next;
        atual = atual->next;
    }

    free( prev );
    free( atual );

    return true;
}


void LimpaLista( ListNode_t **cabeca ) {
    ListNode_t *atual = *cabeca;
    ListNode_t *prox;

    while ( atual != NULL ) {
        prox = atual->next;
        free(atual);
        atual = prox;
    }

    *cabeca = NULL;
    free(prox);
}


int main() {

    ListNode_t *cabeca = NULL;
    CriaLista( &cabeca, 1 );
    CriaLista( &cabeca, 2 );
    CriaLista( &cabeca, 2 );
    CriaLista( &cabeca, 2 );
    CriaLista( &cabeca, 1 );

    printf("Lista encadeada: ");
    ImprimeLista( cabeca );
    bool resultado = IsPalindrome( cabeca );
    if ( resultado ) {
        printf("A lista é um palíndromo.\n");
    } else {
        printf("A lista não é um palíndromo.\n");
    }

    LimpaLista( &cabeca );

//Teste 2:
    CriaLista( &cabeca, 1 );
    CriaLista( &cabeca, 2 );

    printf("\n");
    printf("Lista encadeada: ");
    ImprimeLista(cabeca);
    resultado = IsPalindrome( cabeca );
    if ( resultado ) {
        printf("A lista é um palíndromo.\n");
    } else {
        printf("A lista não é um palíndromo.\n");
    }


    return 0;
}
