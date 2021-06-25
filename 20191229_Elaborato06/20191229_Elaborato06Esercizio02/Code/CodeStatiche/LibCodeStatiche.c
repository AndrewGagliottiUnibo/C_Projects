//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 2 - FILE LIB C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>
#include "LibCodeStatiche.h"

/*Inizializzazione coda di tipo struttura*/
CODAELABORATO Inizializzazione()
{
    /*Inizializziamo tutti i numeri a 0*/
    for(int i = 0; i < N; i++)
        CodaStatica.numero[i] = 0;

    CodaStatica.ultimo = 0;

    /*La funzione ritorna la CODA creata*/
    return CodaStatica;
}

/*Inserisci elemento*/
int InserisciElemento(int num, int counter)
{
    /*Se l'elemento inserito è il primo...*/
    if(counter == 0)
    {
        /*...lo salviamo nella prima posizione*/
        CodaStatica.numero[counter] = num;
        counter++;
        CodaStatica.ultimo = CodaStatica.numero[counter - 1];
    }
    /*Se l'elemento inserito non è il primo:*/
    else
    {
        counter++;
        CodaStatica.numero[counter - 1] = num;
        CodaStatica.ultimo = CodaStatica.numero[counter-1];
    }

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Cancella coda*/
void CancellaLista(int counter)
{
    Inizializzazione();
}

/*Stampa coda*/
void StampaLista(int counter)
{
    for(int i = 0; i < N; i++)
        printf("Elemento %d della LISTA: %d\n", i, CodaStatica.numero[i]);

    printf("\n");

    /*Stampa dell'ultimo numero inserito solo se si è inserito un numero*/
    if(counter != 0)
        printf("\nUltimo elemento della LISTA: %d\n\n", CodaStatica.ultimo);
}

/*Stampa divisori grafici a schermo*/
void StampaGrafica()
{
    for(int i = 0; i < 100; i++)
        printf("-");

    printf("\n");
}
