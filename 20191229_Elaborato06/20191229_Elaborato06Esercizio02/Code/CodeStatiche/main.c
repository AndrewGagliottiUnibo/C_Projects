//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 2 - MAIN C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>

#include "LibCodeStatiche.h"

int main()
{
    int scelta = 0, verifica = 0, counter = 0;
    int num;

    /*Inizializzo la CODA*/
    Inizializzazione();

    do
        {
            printf("CODE: Utente, scegli che operazioni svolgere:\n\n");
            printf("NOTA: La stampa della coda ad ogni operazione viene fatta solo per visualizzarla e vedere il procedimento.");
            printf("\nL'opzione 2 stampa e cancella la coda come da consegna!");
            printf("\n\n1)Inserisci elemento\n2)Stampa Coda(Con cancellazione)\n3)Esci\n");
            StampaGrafica();

            /*Controllo sull'input del menu: deve essere un intero e deve essere nel range di valori indicati*/
            while(verifica != 1)
            {
                verifica = scanf("%d", &scelta);
                fflush(stdin);
                if (verifica != 1)
                    printf("Input errato.\n");
                else if (scelta < 1 || scelta > 3)
                {
                    printf("Input errato.\n");
                    verifica = 0;
                }
                else
                    break;
            }

        /*Se la CODA non è piena allora esegui il programma*/
        if(counter != N)
        {
            switch(scelta)
            {
                /*Inserisci elemento*/
                case 1:
                {
                    printf("\nInserimento di un elemento:\n");
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
                    counter = InserisciElemento(num, counter);
                    printf("\n");
                    /*Stampa elementi della CODA*/
                    StampaLista(counter);
                    break;
                }
                /*Stampa con cancellazione*/
                case 2:
                {
                    /* Se non sono stati inseriti numeri, l'operazione ha esito negativo*/
                     if(counter == 0)
                     {
                        printf("\nLa CODA e' attualmente vuota!\n");
                        break;
                     }
                     for(int i = 0; i < counter; i++)
                        printf("\nElemento %d, uscito correttamente!\n", CodaStatica.numero[i]);
                    /*Azzeramento del numero di elementi inseriti e cancellazione*/
                    CancellaLista(counter);
                    counter = 0;
                    break;
                }
                /*Uscita dal programma*/
                case 3:
                {
                    printf("\nENDING PROGRAM...\n\n");
                    exit(0);
                    break;
                }
            }
            verifica = 0;
            printf("\n");
            StampaGrafica();
            StampaGrafica();
            printf("\n\n");
        }
        /*Se la lista è piena...*/
        else
        {
            printf("\nMemoria piena, cancella la Coda!\n");
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
