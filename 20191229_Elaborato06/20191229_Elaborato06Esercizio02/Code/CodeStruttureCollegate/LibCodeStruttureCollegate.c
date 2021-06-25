//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 2 - FILE LIB C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>

#include "LibCodeStruttureCollegate.h"

/*Inserisci elemento*/
void InserisciElemento(int num, struct CODA **ptr, struct CODA **ptr2)
{
    struct CODA *nuovo, *tmp;

    tmp = *ptr;

    /*Inizializzazione MALLOC grande quanto una struttura struct CODA*/
    nuovo = (struct CODA *)malloc(sizeof(struct CODA));
    if(nuovo == NULL)
    {
        printf("\nNOT ENOUGH MEMORY.. ENDING PROCESS...\n");
        exit(1);
    }
    /*Salviamo il numero inserito nella struttura che abbiamo inizializzato (nuovo) e facciamo puntare il puntatore next alla testa (ptr all'inizio punta al vuoto poi ad un'altra struttura)*/
    /*Successivamente facciamo puntare la testa al nuovo elemento inserito*/
    nuovo->numero = num;

    /*Se l'elemento inserito è il primo della CODA allora questo diventa il primo*/
    if(tmp == NULL)
    {
        tmp = nuovo;
        nuovo->next = NULL;
        *ptr = tmp;
    }
    else
    {
        /*Altrimenti faccio scorrere la CODA finchè non arrivo in fondo (tmp punta a NULL) e poi salvo lì l'elemento che si vuole aggiungere*/
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        nuovo->next = NULL;
        tmp->next = nuovo;

        /*Assegno il puntatore coda al nuovo elemento*/
        *ptr2 = nuovo;
    }
}

/*Cancella CODA*/
/*La funzione restituisce l'esito positivo o negativo dell'operazione*/
int CancellaCoda(struct CODA **ptr, struct CODA **ptr2)
{
    struct CODA *tmp, *tmp2;

    tmp = *ptr;

    /*Se la CODA è vuota l'operazione non ha successo, altrimenti...*/
    if(tmp == NULL)
        return 1;
    /*Se la cancellazione ha esito positivo...*/
    else
    {
        /*...si elimina ogni elemento della CODA partendo dalla cima*/
        while(tmp->next != NULL)
        {
            printf("\nElemento %d, uscito correttamente!\n", tmp->numero);
            tmp2 = tmp->next;
            free(tmp);
            tmp = tmp2;
        }

        printf("\nElemento %d, uscito correttamente!\n", tmp->numero);
        free(tmp);

        *ptr2 = NULL;
        *ptr = NULL;
        return 0;
    }
}

/*Stampa divisori grafici a schermo*/
void StampaGrafica()
{
    for(int i = 0; i < 100; i++)
        printf("-");

    printf("\n");
}

/*Stampa CODA*/
void StampaCoda(struct CODA **ptr, struct CODA **ptr2, int counterino)
{
    struct CODA *tmp;
    int counter = 0;
    tmp = *ptr;

    /*Si stampa ciascun elemento della CODA partendo dalla testa*/
    for(int i = 0; i < counterino; i++)
    {
        printf("Elemento %d della CODA: %d\n", counter++, tmp->numero);
        tmp = tmp->next;
    }

    /*Stampa dell'ultimo elemento della coda*/
    tmp = *ptr2;
    if(tmp == NULL)
        printf("\nUltimo elemento della coda: VUOTO\n");
    else
        printf("\nUltimo elemento della coda: %d\n", tmp->numero);
    printf("\n");

    /*Se la CODA è vuota...*/
    if(*ptr == NULL)
    {
        printf("La CODA e' attualmente vuota!\n\n");
    }
}
