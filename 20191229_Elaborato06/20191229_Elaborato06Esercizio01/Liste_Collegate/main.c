//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 21-12-2019
//Esercizio 1 - MAIN C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>
#include "Lib_ListeCollegate.h"

int main()
{
    int scelta = 0, num, pos, verifica = 0, counter = 0, flag;
    struct LISTA *testa = NULL;

    do
    {
        printf("LISTE: Utente, scegli che operazioni svolgere:\n");
        printf("1)Inserisci elemento in testa\n2)Inserisci elemento in coda\n3)Inserisci elemento in posizione a tua scelta\n");
        printf("4)Cancella elemento in testa\n5)Cancella elemento in coda\n6)Cancella tutte le occorrenze\n7)Cancella Lista\n8)Esci\n");
        StampaGrafica();

        /*Controllo valore inserito per il menu delle scelte: deve essere un intero e deve essere all'interno di un determinato range di valori*/
        while(verifica != 1)
        {
            verifica = scanf("%d", &scelta);
            fflush(stdin);
            if (verifica != 1)
                printf("Input errato.\n");
            else if (scelta < 1 || scelta > 8)
            {
                printf("Input errato.\n");
                verifica = 0;
            }
            else
                break;
        }

        switch(scelta)
        {
            /*Inserisci elemento in testa*/
            case 1:
            {
                printf("\nInserimento in testa:\n");
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
                InserisciTesta(num, &testa);
                counter++;
                break;

            }
            /*Inserisci elemento in coda*/
            case 2:
            {
                printf("\nInserimento in coda:\n");
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
                InserisciCoda(num, &testa);
                counter++;
                break;
            }
            /*Inserisci elemento in una posizione desiderata*/
            case 3:
            {
                printf("\nInserimento in posizione desiderata:\n");
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
                printf("\n\nIn quale posizione? (DA 0 A X ELEMENTI CHE HAI INSERITO): ");
                verifica = 0;
                /*Controllo sull'input inserito: la posizione deve essere minore o uguale al numero di elementi inseriti nella LISTA*/
                while(verifica != 1)
                {
                    verifica = scanf("%d", &pos);
                    fflush(stdin);
                    if (verifica != 1)
                        printf("Input errato.\n");
                    else if(pos > counter)
                    {
                        printf("La posizione inserita non e' interna alla lista.\n");
                        verifica = 0;
                    }
                    else
                        break;
                }
                /*Se il numero è un intero e la posizione è corretta allora inseriscilo*/
                InserisciElem(num, pos, &testa);
                counter++;
                break;
            }
            /*Cancellazione elemento in testa*/
            case 4:
            {
                /*Se la cancellazione ha esito positivo...*/
                flag = CancellaTesta(&testa);
                /*Segnala all'utente il corretto funzionamento*/
                if(flag == 0)
                {
                    printf("Cancellazione elemento in testa\n");
                    counter--;
                    break;
                }
                /*Altrimenti termina*/
                else
                    break;
            }
            /*Cancellazione elemento in coda*/
            case 5:
            {
                /*Se la cancellazione ha esito positivo...*/
                flag = CancellaCoda(&testa);
                /*Segnala all'utente il corretto funzionamento*/
                if(flag == 0)
                {
                    printf("\nCancellazione elemento in coda:\n");
                    counter--;
                    break;
                }
                /*Altrimenti termina*/
                else
                    break;
            }
            /*Cancella occorrenze*/
            case 6:
            {
                /*Se non ci sono elementi nella lista l'operazione termina*/
                if(testa == NULL)
                {
                    printf("\nLa lista e' vuota e non c'e' nulla da cancellare\n");
                    break;
                }

                printf("\nCancella occorrenze:\n");
                printf("Inserisci elemento che vuoi cancellare: ");
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
                /*Se l'input è corretto si cancellano i numeri cercati in memoria e si fa l'update del counter di numeri inseriti*/
                counter = CancellaOccorrenza(num, &testa, counter);
                break;
            }
            /*Cancellazione lista*/
            case 7:
            {
                flag = CancellaLista(&testa);
                /*Se la cancellazione ha esito negativo...*/
                if(flag == 0)
                {
                    printf("\nLa lista ora e' vuota!\n");
                    counter = 0;
                    break;
                }
                /*Se la cancellazione ha esito positivo...*/
                else
                {
                    printf("\nLa lista e' gia' vuota quindi non c'e' bisogno di cancellare cio' che non esiste!\n");
                    break;
                }
            }
            /*Uscita dal programma con la free della struct*/
            case 8:
            {
                flag = CancellaLista(&testa);
                /*Se la cancellazione ha esito positivo...*/
                if(flag == 0)
                {
                    printf("\nENDING PROGRAM and DEALLOCATING MEMORY...\n\n");
                }
                /*Se la cancellazione ha esito negativo...*/
                else
                    printf("\nENDING PROGRAM...\n\n");
                exit(0);
                break;
            }
        }
        verifica = 0;

        printf("\n");
        StampaGrafica();
        printf("\n");
        /*Stampa elementi della LISTA*/
        StampaLista(&testa, counter);
        StampaGrafica();
        StampaGrafica();
        printf("\n\n");

    }while(1);

    return 0;
}
