//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 22-12-2019
//Esercizio 1 - MAIN C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>

#include "Lib_PileCollegate.h"

int main()
{
    int scelta = 0, verifica = 0, counter = 0;
    int num;
    struct PILA *cima = NULL;
    struct PILA *eliminazione = NULL;

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
                    printf("Elemento %d inserito in posizione %d\n", num, counter);
                    Push(num, &cima);
                    counter++;
                    break;
                }
                /*Eliminazione di un elemento della PILA*/
                case 2:
                {
                    /*Se la PILA e' vuota...*/
                    if(cima == NULL)
                    {
                        printf("Nessun elemento inserito nella PILA!\n");
                        break;
                    }
                    /*Se vi e' almeno un elemento...*/
                    else
                    {
                        printf("Ultimo elemento inserito %d, eliminato. Elementi attuali: %d\n", cima->numero, --counter);
                        eliminazione = pop(&cima);
                        free(eliminazione);
                        break;
                    }
                }
                /*Cancellazione PILA*/
                case 3:
                {
                    /*Se la PILA e' vuota...*/
                    if (cima == NULL)
                        printf("\n\nLa PILA e' gia' vuota!\n");
                    /*Se la PILA non e' vuota...*/
                    else
                    {
                        CancellaPila(&cima);
                        printf("\n\nLa PILA e' stata svuotata!\n");
                    }
                    counter = 0;
                    break;
                }
                /*Stampa della PILA*/
                case 4:
                {
                    /*Stampa e reset del counter*/
                    StampaPila(&cima, counter);
                    counter = 0;
                    break;
                }

                /*Uscita dal programma con la free della struct*/
                case 5:
                {
                    /*Se la PILA ha almeno un elemento al suo interno*/
                    if(cima != NULL)
                    {
                        printf("\nENDING PROGRAM and DEALLOCATING MEMORY...\n\n");
                        CancellaPila(&cima);
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
