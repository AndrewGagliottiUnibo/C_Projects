//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 21-12-2019
//Esercizio 1 - LIBRERIA FUNZIONI C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>
#include "Lib_ListaDInamica.h"

/*Inizializzazione lista di tipo struttura*/
LISTADINAMICA Inizializzazione(int counter)
{
    /*Inizializzo una malloc di counter+1 elementi di tipo struttura con controllo*/
    ListaDinamica.numero = (MallocElementi *) malloc ((counter + 1) * sizeof(MallocElementi));
    if(ListaDinamica.numero == NULL)
    {
        printf("ERROR OCCURRED IN ALLOCATING MEMORY. ENDING PROGRAM...\n");
        exit(1);
    }
    /*Se il puntatore non punta a NULL allora salviamo la grandezza*/
    if(ListaDinamica.numero != NULL)
        ListaDinamica.grandezza = counter + 1;

    /*La funzione ritorna la LISTA creata*/
    return ListaDinamica;
}

/*Riallocazione della memoria per ogni elemento inserito*/
 void RiallocazioneMemoria(int counter)
 {
    /*Realloc memoria con controllo*/
    ListaDinamica.numero = realloc(ListaDinamica.numero, sizeof(MallocElementi)* (counter + 1));
    if(ListaDinamica.numero == NULL)
    {
        printf("ERROR OCCURRED IN ALLOCATING MEMORY. ENDING PROGRAM...\n");
        exit(1);
    }
    /*Update grandezza memoria*/
    ListaDinamica.grandezza = counter + 1;
 }

/*Inserisci elemento in testa*/
int InserisciTesta (int num, int counter)
{
    int tmp, i = counter - 1;

    /*Realloc memoria*/
    RiallocazioneMemoria(counter);

    /*Se l'elemento inserito è il primo...*/
    if(counter == 0)
    {
        /*...lo salviamo nella prima posizione*/
        ListaDinamica.numero[counter] = num;
        counter++;
        ListaDinamica.ultimo = ListaDinamica.numero[counter-1];
    }
    /*Se l'elemento inserito non è il primo:*/
    else
    {
        /*Facciamo scorrere in avanti di uno tutti i valori in memoria...*/
        while(i > -1)
        {
            tmp = ListaDinamica.numero[i];
            ListaDinamica.numero[i+1] = tmp;
            i--;
        }
         /*...e salviamo l'elemento inserito in testa*/
        counter++;
        ListaDinamica.numero[0] = num;
        ListaDinamica.ultimo = ListaDinamica.numero[counter-1];
    }

    /*Stampa lista*/
    StampaLista(counter);
    StampaGrafica();
    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Inserisci elemento in coda*/
int InserisciCoda (int num, int counter)
{
    /*Realloc memoria*/
    RiallocazioneMemoria(counter);

    /*Se l'elemento inserito è il primo...*/
    if(counter == 0)
    {
        /*...lo salviamo nella prima posizione*/
        ListaDinamica.numero[counter] = num;
        counter++;
        ListaDinamica.ultimo = ListaDinamica.numero[counter-1];
    }
    /*Se l'elemento inserito non è il primo...*/
    else
    {
        /*...lo salviamo in ultima posizione*/
        ListaDinamica.numero[counter] = num;
        counter++;
        ListaDinamica.ultimo = ListaDinamica.numero[counter-1];
    }

    /*Stampa lista*/
    StampaLista(counter);
    StampaGrafica();
    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Inserisci elemento in posizione desiderata*/
int InserisciElem (int num, int posizione, int counter)
{
    int tmp;

    /*Realloc memoria*/
    RiallocazioneMemoria(counter);

    /*Se la posizione scelta è 0, il numero viene inserito in testa*/
    if(posizione == 0)
        counter = InserisciTesta(num, counter);
    /*Se la posizione scelta è maggiore del numero di elementi inseriti, il numero viene inserito in coda*/
    else if(posizione > counter)
        counter = InserisciCoda(num, counter);
    /*Se la posizione scelta è all'interno della LISTA...*/
    else
    {
        /*...tutti i numeri da quella posizione in poi, vengono fatti scorrere in avanti...*/
        for(int i = counter - 1; i >= posizione - 1; i--)
        {
            tmp = ListaDinamica.numero[i];
            ListaDinamica.numero[i+1] = tmp;
        }
        /*...e si salva il numero nella posizione desiderata*/
        ListaDinamica.numero[posizione - 1] = num;
        counter++;
        ListaDinamica.ultimo = ListaDinamica.numero[counter - 1];
    }

    /*Stampa lista*/
    StampaLista(counter);
    StampaGrafica();
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
                ListaDinamica.numero[i] = ListaDinamica.numero[i + 1];
            }
            counter--;
            ListaDinamica.ultimo = ListaDinamica.numero[counter - 1];
        }

    /*Realloc memoria*/
    RiallocazioneMemoria(counter);
    ListaDinamica.grandezza = counter;

    /*Stampa lista*/
    printf("\n");
    StampaLista(counter);
    StampaGrafica();
    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Cancella elemento in coda*/
int CancellaCoda (int counter)
{
    /*Se non sono stati inseriti elementi...*/
    if(counter == 0)
        printf("\nNon puoi cancellare cio' che non esiste.\n\n");
    /*Se vi è almeno un elemento...*/
    else
        {
            counter--;
            ListaDinamica.ultimo = ListaDinamica.numero[counter - 1];
        }

    /*Realloc memoria*/
    RiallocazioneMemoria(counter);
    ListaDinamica.grandezza = counter;

    /*Stampa lista*/
    printf("\n");
    StampaLista(counter);
    StampaGrafica();
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
        if(ListaDinamica.numero[i] == numero)
        {
            /*...questo viene azzerato immediatamente se è quello in coda...*/
            if(ListaDinamica.numero[counter - 1] == numero)
            {
                ListaDinamica.numero[counter - 1] = 0;
                counter--;
            }
            /*...altrimenti si fanno scorrere tutti gli elementi successivi all'indietro di una posizione*/
            else
            {
                for(int j = i; j <= counter - 1; j++)
                    ListaDinamica.numero[j] = ListaDinamica.numero[j+1];

                counter--;
            }
            /*Realloc memoria*/
            RiallocazioneMemoria(counter);
            ListaDinamica.grandezza = counter;
        }
    }
    ListaDinamica.ultimo = ListaDinamica.numero[counter - 1];

    /*Se non vengono eliminati numeri*/
    if(cambio == counter)
        printf("\nIl numero inserito non e' presente nella lista!");

    /*Stampa lista*/
    printf("\n");
    StampaLista(counter);
    StampaGrafica();
    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Cancella lista*/
int CancellaLista(int counter)
{
    /*Se il puntatore non punta a NULL...*/
    printf("\n");
    if(ListaDinamica.numero != NULL)
    {
        RiallocazioneMemoria(counter);
        ListaDinamica.grandezza = 0;
        ListaDinamica.ultimo = -1;
        counter = 0;
    }
    /*Se il puntatore non punta a nulla...*/
    else
        printf("La lista e' vuota!");

    /*La funzione restituisce il numero di elementi inseriti aggiornato*/
    return counter;
}

/*Stampa lista*/
void StampaLista(int counter)
{
    printf("\n");
    for(int i = 0; i < counter; i++)
        printf("Elemento %d della LISTA: %d\n", i, ListaDinamica.numero[i]);

    printf("\nGrandezza della LISTA: %d\n", ListaDinamica.grandezza);
    /*Stampa dell'ultimo numero inserito solo se si è inserito un numero*/
    if(counter != 0)
        printf("Ultimo elemento della LISTA: %d\n\n", ListaDinamica.ultimo);
}

/*Stampa divisori grafici a schermo*/
void StampaGrafica()
{
    for(int i = 0; i < 100; i++)
        printf("-");

    printf("\n");
}
