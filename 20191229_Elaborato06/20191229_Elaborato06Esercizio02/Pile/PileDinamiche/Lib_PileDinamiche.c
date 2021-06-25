//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 24-12-2019
//Esercizio 1 - FILE LIBRERIA C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>

#include "Lib_PileDinamiche.h"

/*La struttura su cui effettivamente si lavora*/
typedef struct PILA PILADINAMICA;
PILADINAMICA PilaDinamica;

/*Stampa divisori grafici a schermo*/
void StampaGrafica()
{
    for(int i = 0; i < 100; i++)
        printf("-");

    printf("\n");
}

/*Inizializzazione PILA*/
PILADINAMICA Inizializzazione(int counter)
{
    /*Inizializzo una malloc di counter+1 elementi di tipo struttura con controllo*/
    PilaDinamica.numero = (MallocElementi *) malloc ((counter + 1) * sizeof(MallocElementi));
    if(PilaDinamica.numero == NULL)
    {
        printf("ERROR OCCURRED IN ALLOCATING MEMORY. ENDING PROGRAM...\n");
        exit(1);
    }
    /*Se il puntatore non punta a NULL allora salviamo la grandezza*/
    if(PilaDinamica.numero != NULL)
        PilaDinamica.grandezza = counter + 1;

    /*La funzione ritorna la LISTA creata*/
    return PilaDinamica;
}

/*Riallocazione della Memoria*/
void RiallocazioneMemoria(int counter)
 {
    /*Realloc memoria con controllo*/
    PilaDinamica.numero = realloc(PilaDinamica.numero, sizeof(MallocElementi)* (counter + 1));
    if(PilaDinamica.numero == NULL)
    {
        printf("ERROR OCCURRED IN ALLOCATING MEMORY. ENDING PROGRAM...\n");
        exit(1);
    }
    /*Update grandezza memoria*/
    PilaDinamica.grandezza = counter + 1;
 }

/*Inserisci elemento*/
int Push(int num, int counter)
{
    int tmp, i = counter - 1;

    /*Realloc memoria*/
    RiallocazioneMemoria(counter);

    /*Se l'elemento inserito è il primo...*/
    if(counter == 0)
    {
        /*...lo salviamo nella prima posizione*/
        PilaDinamica.numero[counter] = num;
        counter++;
        PilaDinamica.ultimo = PilaDinamica.numero[counter - 1];
    }
    /*Se l'elemento inserito non è il primo:*/
    else
    {
        /*Facciamo scorrere in avanti di uno tutti i valori in memoria...*/
        while(i > -1)
        {
            tmp = PilaDinamica.numero[i];
            PilaDinamica.numero[i + 1] = tmp;
            i--;
        }
         /*...e salviamo l'elemento inserito in testa*/
        counter++;
        PilaDinamica.numero[0] = num;
        PilaDinamica.ultimo = PilaDinamica.numero[0];
    }

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Elimina un elemento*/
int Pop(int counter)
{
    /*Se non sono stati inseriti elementi...*/
    if(counter == 0)
        printf("\nNon puoi cancellare cio' che non esiste.\n");
    /*Se vi è almeno un elemento...*/
    else
        {
            printf("\nEliminazione elemento %d in posizione %d\n", PilaDinamica.ultimo, counter - 1);
            /*...tutti i valori scorrono all'indietro nel vettore*/
            for(int i = 0; i < counter - 1; i++)
            {
                PilaDinamica.numero[i] = PilaDinamica.numero[i + 1];
            }
            counter--;
            PilaDinamica.ultimo = PilaDinamica.numero[0];
            PilaDinamica.grandezza = PilaDinamica.grandezza - 1;
            printf("Grandezza attuale della PILA: %d\n", PilaDinamica.grandezza);
        }

    /*Realloc memoria*/
    RiallocazioneMemoria(counter);
    PilaDinamica.grandezza = counter;

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Stampa ed eliminazione della PILA*/
void StampaPila(int counter)
{
    int counterino = counter - 1;

    printf("\n");
    for(int i = 0; i < counter; i++)
        printf("Elemento %d della LISTA: %d\n", counterino--, PilaDinamica.numero[i]);

    CancellaPila(counter);
}

/*Elimina la PILA*/
int CancellaPila(int counter)
{
    /*Se il puntatore non punta a NULL...*/
    printf("\n");
    if(PilaDinamica.numero != NULL)
    {
        RiallocazioneMemoria(counter);
        PilaDinamica.grandezza = 0;
        PilaDinamica.ultimo = -1;
        counter = 0;
    }
    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}
