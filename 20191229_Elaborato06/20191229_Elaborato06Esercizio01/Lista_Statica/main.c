//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 21-12-2019
//Esercizio 1 - MAIN C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>

#include "Lib_ListaStatica.h"

int main()
{
    int scelta = 0, verifica = 0, counter = 0;
    int num, pos;

    /*Inizializzo la lista*/
    Inizializzazione();

    do
        {
            printf("LISTE: Utente, scegli che operazioni svolgere:\n");
            printf("1)Inserisci elemento in testa\n2)Inserisci elemento in coda\n3)Inserisci elemento in posizione a tua scelta\n");
            printf("4)Cancella elemento in testa\n5)Cancella elemento in coda\n6)Cancella tutte le occorrenze\n7)Cancella Lista\n8)Esci\n");
            StampaGrafica();

            /*Controllo sull'input del menu: deve essere un intero e deve essere nel range di valori indicati*/
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

        /*Se la LISTA non è piena allora esegui il programma*/
        if(counter != N)
        {
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
                    /*Update del numero di elementi inseriti e inserimento*/
                    counter = InserisciTesta(num, counter);
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
                    /*Update del numero di elementi inseriti e inserimento*/
                    counter = InserisciCoda(num, counter);
                    break;
                }
                /*Inserisci elemento*/
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
                    printf("\n\nIn quale posizione? (DA 0 a X ELEMENTI INSERITI): ");
                    verifica = 0;
                    /*Controllo sull'input inserito: deve essere un intero e deve avere un certo range*/
                    while(verifica != 1)
                    {
                        verifica = scanf("%d", &pos);
                        fflush(stdin);
                        if (verifica != 1)
                            printf("Input errato.\n");
                        else if(pos > counter)
                        {
                            printf("Numero troppo grande.\n");
                            verifica = 0;
                        }
                        else
                            break;
                    }
                    /*Update del numero di elementi inseriti e inserimento*/
                    counter = InserisciElem(num, pos, counter);
                    break;
                }
                /*Cancellazione elemento in testa*/
                case 4:
                {
                    /*Update del numero di elementi inseriti e cancellazione*/
                    counter = CancellaTesta(counter);
                    break;
                }
                /*Cancellazione elemento in coda*/
                case 5:
                {
                    /*Update del numero di elementi inseriti e cancellazione*/
                    counter = CancellaCoda(counter);
                    break;
                }
                /*Cancella occorrenze*/
                case 6:
                {
                    /* Se non sono stati inseriti numeri, l'operazione ha esito negativo*/
                    if(counter == 0)
                    {
                        printf("\nLa LISTA e' attualmente vuota!\n");
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
                    /*Update del numero di elementi inseriti e cancellazione*/
                    counter = CancellaOccorrenza(counter, num);
                    break;
                }
                /*Cancellazione lista*/
                case 7:
                {
                    /* Se non sono stati inseriti numeri, l'operazione ha esito negativo*/
                     if(counter == 0)
                     {
                        printf("\nLa LISTA e' attualmente vuota!\n");
                        break;
                     }
                    /*Azzeramento del numero di elementi inseriti e cancellazione*/
                    CancellaLista(counter);
                    counter = 0;
                    break;
                }
                /*Uscita dal programma*/
                case 8:
                {
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
            StampaLista(counter);
            StampaGrafica();
            StampaGrafica();
            printf("\n\n");
        }
        /*Se la lista è piena...*/
        else
        {
            printf("\nMemoria piena, cancella almeno un elemento!\n");
            printf("\n");
            /*Stampa elementi della LISTA*/
            StampaLista(counter);
            StampaGrafica();
            StampaGrafica();
            printf("\n\n");

            verifica = 0;
        }

    }while(1);

    return 0;
}
