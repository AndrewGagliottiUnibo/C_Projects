//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 21-12-2019
//Esercizio 1 - FILE LIBRERIA C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>
#include "Lib_ListaStatica.h"

/*Inizializzazione lista di tipo struttura*/
LISTAELABORATO Inizializzazione()
{
    /*Inizializziamo tutti i numeri a 0*/
    for(int i = 0; i < N; i++)
        ListaStatica.numero[i] = 0;

    ListaStatica.ultimo = 0;

    /*La funzione ritorna la LISTA creata*/
    return ListaStatica;
}

/*Inserisci elemento in testa*/
int InserisciTesta (int num, int counter)
{
    int tmp, i = counter - 1;

    /*Se l'elemento inserito è il primo...*/
    if(counter == 0)
    {
        /*...lo salviamo nella prima posizione*/
        ListaStatica.numero[counter] = num;
        counter++;
        ListaStatica.ultimo = ListaStatica.numero[counter-1];
    }
    /*Se l'elemento inserito non è il primo:*/
    else
    {
        /*Facciamo scorrere in avanti di uno tutti i valori in memoria...*/
        while(i > -1)
        {
            tmp = ListaStatica.numero[i];
            ListaStatica.numero[i+1] = tmp;
            i--;
        }
        /*...e salviamo l'elemento inserito in testa*/
        counter++;
        ListaStatica.numero[0] = num;
        ListaStatica.ultimo = ListaStatica.numero[counter-1];
    }

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Inserisci elemento in coda*/
int InserisciCoda (int num, int counter)
{
    /*Se l'elemento inserito è il primo...*/
    if(counter == 0)
    {
        /*...lo salviamo nella prima posizione*/
        ListaStatica.numero[counter] = num;
        counter++;
        ListaStatica.ultimo = ListaStatica.numero[counter-1];
    }
    /*Se l'elemento inserito non è il primo...*/
    else
    {
        /*...lo salviamo in ultima posizione*/
        ListaStatica.numero[counter] = num;
        counter++;
        ListaStatica.ultimo = ListaStatica.numero[counter-1];
    }

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Inserisci elemento in posizione desiderata*/
int InserisciElem (int num, int posizione, int counter)
{
    int tmp;

    /*Se la posizione scelta è 0, il numero viene inserito in testa*/
    if(posizione == 0)
        counter = InserisciTesta(num, counter);
    /*Se la posizione scelta è maggiore del numero di elementi inseriti, il numero viene inserito in coda*/
    else if(posizione > counter)
        counter = InserisciCoda(num, posizione);
    /*Se la posizione scelta è all'interno della LISTA...*/
    else
    {
        /*...tutti i numeri da quella posizione in poi, vengono fatti scorrere in avanti...*/
        for(int i = counter - 1; i >= posizione - 1; i--)
        {
            tmp = ListaStatica.numero[i];
            ListaStatica.numero[i+1] = tmp;
        }
        /*...e si salva il numero nella posizione desiderata*/
        ListaStatica.numero[posizione - 1] = num;
        counter++;
        ListaStatica.ultimo = ListaStatica.numero[counter - 1];
    }

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Cancella elemento in testa*/
int CancellaTesta (int counter)
{
    /*Se non sono stati inseriti elementi...*/
    if(counter == 0)
        printf("\nNon puoi cancellare cio' che non esiste.\n");
    /*Se vi è almeno un elemento...*/
    else
        {
            /*...tutti i valori scorrono all'indietro nel vettore*/
            for(int i = 0; i < counter - 1; i++)
            {
                ListaStatica.numero[i] = ListaStatica.numero[i + 1];
            }
            /*L'ultimo elemento, nel vettore, da eliminare viene riazzerato*/
            ListaStatica.numero[counter - 1] = 0;
            counter--;
            ListaStatica.ultimo = ListaStatica.numero[counter - 1];
        }

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Cancella elemento in coda*/
int CancellaCoda (int counter)
{
    /*Se non sono stati inseriti elementi...*/
    if(counter == 0)
        printf("\nNon puoi cancellare cio' che non esiste.\n");
    /*Se vi è almeno un elemento...*/
    else
        {
            /*L'ultimo elemento, nel vettore, da eliminare viene riazzerato*/
            ListaStatica.numero[counter - 1] = 0;
            counter--;
            ListaStatica.ultimo = ListaStatica.numero[counter - 1];
        }

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Cancella occorrenze*/
int CancellaOccorrenza (int counter, int numero)
{
    int cambio = counter;

    /*Per ogni elemento salvato in memoria...*/
    for(int i = counter - 1; i >= 0; i--)
    {
        /*...se abbiamo trovato il numero cercato...*/
        if(ListaStatica.numero[i] == numero)
        {
            /*...questo viene azzerato immediatamente se è quello in coda...*/
            if(ListaStatica.numero[counter - 1] == numero)
                ListaStatica.numero[counter - 1] = 0;
            /*...altrimenti si fanno scorrere tutti gli elementi successivi all'indietro di una posizione*/
            else
            {
                for(int j = i; j <= counter - 1; j++)
                    ListaStatica.numero[j] = ListaStatica.numero[j+1];
            }
            /*L'ultimo elemento, nel vettore, da eliminare viene riazzerato*/
            ListaStatica.numero[counter - 1] = 0;
            counter--;
        }
    }
    ListaStatica.ultimo = ListaStatica.numero[counter - 1];

    /*Se non vengono eliminati numeri*/
    if(cambio == counter)
        printf("\nIl numero inserito non e' presente nella lista!");

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Cancella lista*/
void CancellaLista(int counter)
{
    Inizializzazione();
}

/*Stampa lista*/
void StampaLista(int counter)
{
    for(int i = 0; i < N; i++)
        printf("Elemento %d della LISTA: %d\n", i, ListaStatica.numero[i]);

    printf("\n");

    /*Stampa dell'ultimo numero inserito solo se si è inserito un numero*/
    if(counter != 0)
        printf("\nUltimo elemento della LISTA: %d\n\n", ListaStatica.ultimo);
}

/*Stampa divisori grafici a schermo*/
void StampaGrafica()
{
    for(int i = 0; i < 100; i++)
        printf("-");

    printf("\n");
}
