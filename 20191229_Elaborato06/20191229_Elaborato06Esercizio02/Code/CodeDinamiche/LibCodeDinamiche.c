//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 2 - FILE LIB C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>
#include "LibCodeDinamiche.h"

/*Inizializzazione coda di tipo struttura*/
CODADINAMICA Inizializzazione(int counter)
{
    /*Inizializzo una malloc di counter+1 elementi di tipo struttura con controllo*/
    CodaDinamica.numero = (MallocElementi *) malloc ((counter + 1) * sizeof(MallocElementi));
    if(CodaDinamica.numero == NULL)
    {
        printf("ERROR OCCURRED IN ALLOCATING MEMORY. ENDING PROGRAM...\n");
        exit(1);
    }
    /*Se il puntatore non punta a NULL allora salviamo la grandezza*/
    if(CodaDinamica.numero != NULL)
        CodaDinamica.grandezza = counter + 1;

    /*La funzione ritorna la LISTA creata*/
    return CodaDinamica;
}

/*Riallocazione della memoria per ogni elemento inserito*/
 void RiallocazioneMemoria(int counter)
 {
     /*Realloc memoria con controllo*/
    CodaDinamica.numero = realloc(CodaDinamica.numero, sizeof(MallocElementi)* (counter + 1));
    if(CodaDinamica.numero == NULL)
    {
        printf("ERROR OCCURRED IN ALLOCATING MEMORY. ENDING PROGRAM...\n");
        exit(1);
    }
    /*Update grandezza memoria*/
    CodaDinamica.grandezza = counter + 1;
 }

/*Inserisci elemento*/
int InserisciElemento(int num, int counter)
{
    /*Realloc memoria*/
    RiallocazioneMemoria(counter);

    /*Se l'elemento inserito è il primo...*/
    if(counter == 0)
    {
        /*...lo salviamo nella prima posizione*/
        CodaDinamica.numero[counter] = num;
        counter++;
        CodaDinamica.ultimo = CodaDinamica.numero[counter-1];
    }
    /*Se l'elemento inserito non è il primo...*/
    else
    {
        /*...lo salviamo in ultima posizione*/
        CodaDinamica.numero[counter] = num;
        counter++;
        CodaDinamica.ultimo = CodaDinamica.numero[counter-1];
    }

    /*Stampa lista*/
    StampaCoda(counter);
    StampaGrafica();
    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Cancella Coda*/
int CancellaCoda(int counter)
{
    /*Se il puntatore non punta a NULL...*/
    printf("\n");
    if(CodaDinamica.numero != NULL)
    {
        RiallocazioneMemoria(counter);
        CodaDinamica.grandezza = 0;
        CodaDinamica.ultimo = -1;
        counter = 0;
    }
    /*Se il puntatore non punta a nulla...*/
    else
        printf("La coda e' vuota!");

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Stampa Coda*/
void StampaCoda(int counter)
{
    printf("\n");
    for(int i = 0; i < counter; i++)
        printf("Elemento %d della CODA: %d\n", i, CodaDinamica.numero[i]);

    printf("\nGrandezza della Coda: %d\n", CodaDinamica.grandezza);
    /*Stampa dell'ultimo numero inserito solo se si è inserito un numero*/
    if(counter != 0)
        printf("Ultimo elemento della Coda: %d\n\n", CodaDinamica.ultimo);
}

/*Stampa divisori grafici a schermo*/
void StampaGrafica()
{
    for(int i = 0; i < 100; i++)
        printf("-");

    printf("\n");
}
