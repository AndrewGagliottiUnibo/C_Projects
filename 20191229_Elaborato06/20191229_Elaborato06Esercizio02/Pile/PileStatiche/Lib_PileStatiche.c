//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 1 - FILE LIBRERIA C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>

#include "Lib_PileStatiche.h"

/*Stampa divisori grafici a schermo*/
void StampaGrafica()
{
    for(int i = 0; i < 100; i++)
        printf("-");

    printf("\n");
}

/*Inizializzazione PILA*/
PILAELABORATO Inizializzazione()
{
    /*Inizializziamo tutti i numeri a 0*/
    for(int i = 0; i < N; i++)
        PilaStatica.numero[i] = 0;

    PilaStatica.ultimo = 0;

    /*La funzione ritorna la PILA creata*/
    return PilaStatica;
}

/*Inserisci elemento*/
int Push(int num, int counter)
{
    int tmp, i = counter - 1;

    /*Se l'elemento inserito è il primo...*/
    if(counter == 0)
    {
        /*...lo salviamo nella prima posizione*/
        PilaStatica.numero[counter] = num;
        counter++;
        PilaStatica.ultimo = PilaStatica.numero[counter-1];
    }
    /*Se l'elemento inserito non è il primo:*/
    else
    {
        /*Facciamo scorrere in avanti di uno tutti i valori in memoria...*/
        while(i > -1)
        {
            tmp = PilaStatica.numero[i];
            PilaStatica.numero[i+1] = tmp;
            i--;
        }
        /*...e salviamo l'elemento inserito in testa*/
        counter++;
        PilaStatica.numero[0] = num;
        PilaStatica.ultimo = PilaStatica.numero[0];
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
            printf("\nEliminazione elemento %d in posizione %d\n", PilaStatica.numero[0], counter - 1);
            /*...tutti i valori scorrono all'indietro nel vettore*/
            for(int i = 0; i < counter - 1; i++)
            {
                PilaStatica.numero[i] = PilaStatica.numero[i + 1];
            }
            /*L'ultimo elemento, nel vettore, da eliminare viene riazzerato*/
            PilaStatica.numero[counter - 1] = 0;
            counter--;
            PilaStatica.ultimo = PilaStatica.numero[0];
        }
    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Stampa ed eliminazione della PILA*/
void StampaPila(int counter)
{
    int counterino = counter - 1;

    for(int i = 0; i < counter; i++)
        printf("Elemento %d della PILA: %d\n", counterino--, PilaStatica.numero[i]);

    printf("\n");

    /*Stampa dell'ultimo numero inserito solo se si è inserito un numero*/
    if(counter != 0)
        printf("\nUltimo elemento della PILA: %d\n\n", PilaStatica.ultimo);

    Inizializzazione();
}

/*Elimina la PILA*/
void CancellaPila()
{
    Inizializzazione();
}
