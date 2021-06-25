//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 21-12-2019
//Esercizio 1 - FILE LIBRERIA C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>
#include "Lib_ListeCollegate.h"

/*Stampa divisori grafici a schermo*/
void StampaGrafica()
{
    for(int i = 0; i < 100; i++)
        printf("-");

    printf("\n");
}

/*Inserisci elemento in testa*/
void InserisciTesta (int num, struct LISTA **ptr)
{
    struct LISTA *nuovo;

    /*Inizializzazione MALLOC grande quanto una struttura struct LISTA*/
    nuovo = (struct LISTA *)malloc(sizeof(struct LISTA));
    if(nuovo == NULL)
    {
        printf("\nNOT ENOUGH MEMORY.. ENIDNG PROCESS...\n");
        exit(1);
    }
    /*Salviamo il numero inserito nella struttura che abbiamo inizializzato (nuovo) e facciamo puntare il puntatore next alla testa (ptr all'inizio punta al vuoto poi ad un'altra struttura)*/
    /*Successivamente facciamo puntare la testa al nuovo elemento inserito*/
    nuovo->numero = num;
    nuovo->next = *ptr;
    *ptr = nuovo;
}

/*Inserisci elemento in coda*/
void InserisciCoda (int num, struct LISTA **ptr)
{
    /*tmp è una variabile temporanea*/
    struct LISTA *nuovo, *tmp;
    tmp = *ptr;

    /*Inizializzazione MALLOC grande quanto una struttura struct LISTA*/
    nuovo = (struct LISTA *)malloc(sizeof(struct LISTA));
    if(nuovo == NULL)
    {
        printf("\nNOT ENOUGH MEMORY.. ENIDNG PROCESS...\n");
        exit(1);
    }
    /*Salviamo il numero inserito*/
    nuovo->numero = num;

    /*Se l'elemento inserito in coda è il primo della LISTA allora questo diventa il primo*/
    if(tmp == NULL)
    {
        tmp = nuovo;
        nuovo->next = NULL;
        *ptr = tmp;
    }
    else
    {
        /*Altrimenti faccio scorrere la LISTA finchè non arrivo in fondo (tmp punta a NULL) e poi salvo lì l'elemento che si vuole aggiungere*/
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        nuovo->next = NULL;
        tmp->next = nuovo;
    }
}

/*Inserisci elemento in una determinata posizione*/
void InserisciElem (int num, int posizione, struct LISTA **ptr)
{
    int i = 0;
    struct LISTA *nuovo, *tmp, *succ;
    tmp = *ptr;

    /*Inizializzazione MALLOC grande quanto una struttura struct LISTA*/
    nuovo = (struct LISTA *)malloc(sizeof(struct LISTA));
    if(nuovo == NULL)
    {
        printf("\nNOT ENOUGH MEMORY. ENIDNG PROCESS...\n");
        exit(1);
    }
    /*Salvo il valore inserito*/
    nuovo->numero = num;

    /*Se la posizione scelta è la prima, allora lo si salva in testa...*/
    if(posizione == 0)
    {
        InserisciTesta(num, ptr);
    }
    else
    {
        /*...altrimenti si fa scorrere la variabile temporanea fino alla posizione cercata*/
        while(i < posizione - 1)
        {
            tmp = tmp->next;
            i++;
        }
        /*Se la posizione in cui si vuole inserire il dato non è l'ultima...*/
        if(tmp->next != NULL)
        {
            /*...salviamo l'elemento successivo e nella posizione desiderata inseriamo il nostro elemento e facciamo poi puntare il puntatore next all'elemento succesivo...*/
            /*...inserendo correttamente il valore nella LISTA e senza perdere nessun dato...*/
           succ = tmp->next;
           tmp->next = nuovo;
           nuovo->next = succ;
        }
        else
            /*Se la posizione inserita è l'ultima inseriamo in coda l'elemento*/
            InserisciCoda(num, ptr);
    }
}

/*Cancella elemento in testa*/
/*La funzione restituisce l'esito positivo o negativo dell'operazione*/
int CancellaTesta (struct LISTA **ptr)
{
    struct LISTA *tmp;
    /*Se la LISTA è vuota allora l'operazione ha esito negativo*/
    if(*ptr == NULL)
    {
        printf("\nLa lista e' vuota.\n");
        return 1;
    }
    /*Altrimenti...*/
    else
    {
        /*...salviamo l'elemento in una variabile temporanea e affidiamo alla testa l'elemento successivo della LISTA*/
        /*Liberiamo poi con la free() la parte di memoria riservata all'elemento che si vuole eliminare*/
        tmp = *ptr;
        *ptr = tmp->next;
        free(tmp);
        return 0;
    }
}

/*Cancella elemento in coda*/
/*La funzione restituisce l'esito positivo o negativo dell'operazione*/
int CancellaCoda (struct LISTA **ptr)
{
    struct LISTA *tmp, *prec;
    tmp = *ptr;
    prec = *ptr;

    /*Se la LISTA è vuota allora l'operazione ha esito negativo*/
    if(*ptr == NULL)
    {
        printf("\nLa lista e' vuota.\n");
        return 1;
    }
    /*Altrimenti...*/
    else
    {
        /*...facciamo scorrere la LISTA fino all'ultimo elemento...*/
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        /*...e facciamo puntare l'elemento precedente a NULL liberando poi la memoria dell'elemento desiderato con la free()*/
        while(prec->next != tmp)
        {
            prec = prec->next;
        }
            prec->next = NULL;
            free(tmp);
        return 0;
    }

}

/*Cancella occorrenze*/
 int CancellaOccorrenza (int num, struct LISTA **ptr, int counterino)
{
    int conteggio_elementi_totali = counterino;
    struct LISTA *tmp, *prec, *elimina;
    prec = NULL;
    tmp = *ptr;

    /*Finchè non abbiamo controllato tutti gli elementi inseriti...*/
    while (tmp != NULL)
    {
        /*...se il numero cercato è presente in un elemento, allora:*/
        if (tmp->numero == num)
        {
            /*Se è il primo si fa scorrere in avanti la LISTA di una posizione...*/
            if (prec == NULL)
            {
                *ptr = tmp->next;
                counterino--;
            }
            /*...altrimenti salviamo l'elemento precedente e poi lo colleghiamo all'elemento successivo di quello che si vuole eliminare*/
            else
            {
                prec->next = tmp->next;
                counterino--;
            }
                elimina = tmp;
                tmp = tmp->next;
                /*Eliminazione dell'elemento e liberazione della memoria*/
                free(elimina);
        }
        /*Se il numero non è presente in nell'elemento già analizzato, si scorre in avanti di una posizione per analizzare il prossimo*/
        else
        {
            prec = tmp;
            tmp = tmp->next;
        }
    }

    /*Se il numero non è presente in memoria*/
    if(counterino == conteggio_elementi_totali)
    {
        printf("\nIl numero inserito non e' presente, termine operazione\n\n");
    }
    /*La funzione restituisce il nuovo numero di elementi totali attualmente presenti in memoria*/
    return counterino;
}

/*Cancella LISTA*/
/*La funzione restituisce l'esito positivo o negativo dell'operazione*/
int CancellaLista(struct LISTA **ptr)
{
    struct LISTA *tmp;

    /*Se la LISTA è vuota l'operazione non ha successo, altrimenti...*/
    if(*ptr == NULL)
    {/*Se la cancellazione ha esito positivo...*/
        return 1;
    }
    else/*Se la cancellazione ha esito positivo...*/
    {
        /*...si elimina ogni elemento della LISTA partendo dalla cima*/
        while(*ptr != NULL)
        {
            tmp = *ptr;
            *ptr = tmp->next;
            free(tmp);
        }
        return 0;
    }
}

/*Stampa LISTA*/
void StampaLista(struct LISTA **ptr, int counterino)
{
    struct LISTA *tmp;
    int counter = 0;
    tmp = *ptr;

    /*Si stampa ciascun elemento della LISTA partendo dalla testa*/
    for(int i = 0; i < counterino; i++)
    {
        printf("Elemento %d della LISTA: %d\n", counter++, tmp->numero);
        tmp = tmp->next;
    }
    printf("\n");

    /*Se la LISTA è vuota...*/
    if(*ptr == NULL)
    {
        printf("La LISTA e' attualmente vuota\n\n");
    }
}
