//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 02-12-2019
//Esercizio 2
//Data di scadenza: 08-12-2019

#include <stdio.h>

/*  Inizializzo queste variabili globali necessarie al corretto funzionamento del programma. La dichiarazione statica non avrebbe consentito il corretto
    funzionamento del programma; questo perchè se le avessi dichiarate all'interno della funzione ricorsiva esse si sarebbero riazzerate ogni volta e
    non mi avrebbero consentito di svolgere le operazioni di allineamento a cascata (operazione svolta da m) e di conteggio delle volte in cui viene richiamata
    la funzione stessa (operazione svolta da k) nella spiegazione logica della funzione stessa                                                                      */

int m = 0, k = 0;
int num_fatt;

/*Funzione per il calcolo del fattoriale*/
int calcolo_fattoriale(int n)
{
    /*Variabile che salva ricorsivamente il valore del fattoriale e si aggiorna man mano che la funzione richiama se stessa*/
    int risultato;

    if (n == 0)
    {
        /** \brief
         *
         * \param "\nSe il numero analizzato e' == 0 allora l'analisi logica della funzione si interrompe. Comincia quindi il calcolo vero e proprio comincia da 1:\n\n"
         *
         */
        printf("\nSe il numero analizzato e' == 0 allora l'analisi logica della funzione si interrompe. Comincia quindi il calcolo vero e proprio comincia da 1:\n\n");
        return 1;
    }
    /*Ciclo che stampa tot volte tab a mo di piramide aumentando ogni volta la quantità di spazi stampati*/
    for(int i = 0; i < m; i++)
        printf("\t");

    /*Inizio della funzione ricorsiva per il calcolo del fattoriale*/
    printf("Alla chiamata (%d), la funzione calcolo_fattoriale considera il fatto di dover moltiplicare %d per %d.\n", ++m, n, n-1);

    risultato = n * calcolo_fattoriale(n - 1);

    /*Ciclo che stampa tot volte tab a mo di piramide diminuendo ogni volta la quantità di spazi stampati*/
    for(int i = --m; i > 0; i--)
         printf("\t");

    /*Calcolo vero e prorpio del fattoriale*/
    printf("Alla chiamata di calcolo della funzione(%d) avremo %d ottenuto da %d moltiplicato per tutti i suoi precedenti.\n", ++k, risultato, n);

    return risultato;
}

int main()
{
    int verifica = 0;

    /*Cenni di teoria per aiutare l'utente a capire il fenomeno della ricorsione e il calcolo del fattoriale*/
    printf("Qualche cenno di teoria prima di cominciare:\n\n");

    printf("In matematica, si definisce fattoriale di un numero naturale n, (indicato con n!), ");
    printf("il prodotto dei numeri interi positivi minori o uguali a tale numero.\n");
    printf("Una funzione ricorsiva e' una funzione che e' letteralmente \"in grado di richiamare se stessa piu' volte\" ");
    printf("per svolgere piu' semplicemente cio' che una iterazione potrebbe fare ma occupando meno righe di codice.\n\n");

    printf("Ecco a te un programma in grado di aiutarti a capire come funziona il calcolo di un fattoriale tramite l'utilizzo delle funzioni ricorsive:\n");
    printf("Inserisci un numero di cui desideri esprimere il fattoriale tramite ricorsione (Massimo 16), verrai aiutato nel capire come funziona tutto il procedimento:\n\n");

    /*Ciclo di controllo sull'input dell'utente*/
    while(verifica != 1)
    {
        verifica = scanf("%d", &num_fatt);
        fflush(stdin);

        if(verifica != 1)
            printf("Hai inserito un input errato, reinserisci:\n");
        else if(num_fatt < 0)
        {
            printf("Hai inserito un input errato, reinserisci: Il fattoriale non e' definito per gli interi negativi!\n");
            verifica = 0;
        }
        else if(num_fatt > 16)
        {
            printf("Hai inserito un input errato, reinserisci: La grandezza del dato e' troppo grande per essere memorizzato!\n");
            verifica = 0;
        }
    }

    printf("\nPer facilitare la comprensione si immagini che la funzione ricorsiva calcolo_fattoriale analizza ogni intero che precede il numero scelto dall'utente:\n\n");

    /*Stampa del risultato finale*/
    printf("\n\nIl fattoriale del numero %d e': %d\n\n", num_fatt, calcolo_fattoriale(num_fatt));

    return 0;
}
