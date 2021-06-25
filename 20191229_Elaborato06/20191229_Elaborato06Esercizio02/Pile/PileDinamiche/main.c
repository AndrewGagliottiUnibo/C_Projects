//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 24-12-2019
//Esercizio 1 - MAIN C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>

#include "Lib_PileDinamiche.h"

int main()
{
    int scelta = 0, verifica = 0, counter = 0;
    int num;

    Inizializzazione(counter);

    do
    {
        printf("PILE: Utente, scegli che operazioni svolgere:\n");
        printf("1)Inserisci elemento\n2)Cancella elemento\n3)Cancella PILA\n4)Stampa PILA\n5)Esci\n");
        StampaGrafica();
        printf("\n");

        /*Controllo sull'input inserito: deve essere un intero e deve essere nel range di valori indicato*/
        while(verifica != 1)
            {
                verifica = scanf("%d", &scelta);
                fflush(stdin);
                if (verifica != 1)
                    printf("Input errato.\n");
                else if (scelta < 1 || scelta > 5)
                {
                    printf("Input errato.\n");
                    verifica = 0;
                }
                else
                    break;
            }

        switch(scelta)
            {
                /*Inserisci elemento*/
                case 1:
                {
                    printf("\nInserimento:\n");
                    printf("Inserisci elemento: ");
                    verifica = 0;
                    /*Controllo sull'input inserito: deve essere un intero*/
                    while(verifica != 1)
                    {
                        verifica = scanf("%d", &num);
                        fflush(stdin);
                        if (verifica != 1)
                            printf("Input errato.\n");
                        else
                            break;
                    }
                    /*Se è un intero allora inseriscilo*/
                    printf("\nElemento %d inserito in posizione %d\n", num, counter);
                    counter = Push(num, counter);
                    printf("Grandezza attuale della PILA: %d\n", PilaDinamica.grandezza);
                    break;
                }
                /*Eliminazione di un elemento della PILA*/
                case 2:
                {
                    /*Chiamo la funzione Pop() passandogli il numero di elementi inseriti fino ad ora e cancello l'elemento in cima*/
                    counter = Pop(counter);
                    break;
                }
                /*Cancellazione PILA*/
                case 3:
                {
                    /*Se la PILA e' vuota...*/
                    if (counter == 0)
                        printf("\nLa PILA e' gia' vuota!\n");
                    /*Se la PILA non e' vuota...*/
                    else
                    {
                        CancellaPila(counter);
                        printf("\nLa PILA e' stata svuotata!\n");
                    }
                    counter = 0;
                    break;
                }
                /*Stampa della PILA*/
                case 4:
                {
                    if(counter == 0)
                        printf("\nLa PILA e' vuota!\n");
                    else
                    {
                        /*Stampa e reset del counter*/
                        StampaPila(counter);
                        printf("La PILA ora e' vuota!\n");
                        counter = 0;
                    }
                    break;
                }

                /*Uscita dal programma e reset pila*/
                case 5:
                {
                    /*Se la PILA ha almeno un elemento al suo interno*/
                    if(counter > 0)
                    {
                        printf("\nENDING PROGRAM and DEALLOCATING MEMORY...\n\n");
                        CancellaPila(counter);
                    }
                    /*Se la cancellazione ha esito negativo...*/
                    else
                        printf("\nENDING PROGRAM...\n\n");
                    exit(0);
                    break;
                }
            }
            verifica = 0;
            StampaGrafica();
            StampaGrafica();
            printf("\n");

    }while(1);

    return 0;
}
