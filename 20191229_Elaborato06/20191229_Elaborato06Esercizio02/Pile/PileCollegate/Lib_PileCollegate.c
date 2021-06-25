//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 22-12-2019
//Esercizio 1 - FILE LIBRERIA C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>

#include "Lib_PileCollegate.h"

/*Stampa divisori grafici a schermo*/
void StampaGrafica()
{
    for(int i = 0; i < 100; i++)
        printf("-");

    printf("\n");
}

/*Inserisci elemento*/
void Push (int num, struct PILA **ptr)
{
    struct PILA *nuovo;

    /*Inizializzo la MALLOC di grandezza struttura del nuovo elemento ed eseguo il controllo*/
    nuovo = (struct PILA*)malloc(sizeof(struct PILA));
    if (nuovo == NULL)
    {
        printf("\n\nINSUFFICENT MEMORY. ENDING PROGRAM...\n ");
        exit(1);
    }
    /*Salviamo il numero inserito nella struttura che abbiamo inizializzato (nuovo) e facciamo puntare il puntatore next alla testa (ptr all'inizio punta al vuoto poi ad un'altra struttura)*/
    /*Successivamente facciamo puntare la testa al nuovo elemento inserito*/
    nuovo->numero = num;
    nuovo->next = *ptr;
    *ptr = nuovo;
}

/*Eliminazione di un elemento*/
struct PILA* pop (struct PILA **ptr)
{
    struct PILA *tmp;
    /*Se non vi sono elementi da eliminare restituiamo lo stesso puntatore a NULL...*/
    if (ptr == NULL)
         return *ptr;

    /*...altrimenti con una variabile temporanea ci salviamo il valore da eliminare e facciamo scorrere in avanti di uno la PILA eliminando alla fine l'elemento desiderato*/
    tmp = *ptr;
    *ptr = (*ptr)->next;
    tmp->next = NULL;

    return tmp;
}

/*Eliminazione della PILA*/
void CancellaPila (struct PILA **ptr)
{
    struct PILA *tmp;

    /*Ripetizione ciclica della pop con la free() di ciascun elemento fino a quando il puntatore non punta a NULL*/
    while (*ptr != NULL)
    {
        tmp = pop(ptr);
        if (tmp != NULL)
            free(tmp);
    }
}

/*Stampa e cancella la PILA*/
void StampaPila(struct PILA **ptr, int counter)
{
    struct PILA *tmp;

    printf("\n");
    /*Se nella PILA non e' stato salvato alcun elemento...*/
    if (*ptr == NULL)
    {
        printf("La PILA e' vuota!\n\n");
        return;
    }
    /*Se nella PILA vi e' almeno un elemento...*/
    do
    {
        /*...si esegue ciclicamente la pop degli elementi indicandone il valore e stampandoli a schermo*/
        tmp = pop(ptr);
        if (tmp != NULL)
        {
            printf("Elemento %d inserito: %d\n", --counter, tmp->numero);
            /*Liberazione della variabile temporanea usata per la stampa*/
            free(tmp);
        }
    }while(*ptr != NULL);
    printf("\nLa PILA e' stata svuotata!\n");
}
