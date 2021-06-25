//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 1 - MAIN C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>

#include "LibCodeDinamiche.h"

int main()
{
    int scelta = 0, verifica = 0, counter = 0;
    int num;

    /*Inizializzo la coda*/
    Inizializzazione(counter + 1);

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
                break;

            }
            /*Cancellazione coda*/
            case 2:
            {
                /* Se non sono stati inseriti numeri, l'operazione ha esito negativo*/
                if(counter == 0)
                {
                    printf("\nLa CODA e' attualmente vuota!\n");
                    break;
                }

                /*Update del numero di elementi inseriti e cancellazione*/
                for(int i = 0; i < counter; i++)
                    printf("\nElemento %d, uscito correttamente!\n", CodaDinamica.numero[i]);
                counter = CancellaCoda(counter);
                break;
            }
            /*Uscita dal programma con la free della struct*/
            case 3:
            {
                CancellaCoda(counter);
                free(CodaDinamica.numero);
                printf("\nENDING PROGRAM...\n\n");
                exit(0);
                break;
            }
        }
        verifica = 0;

    }while(1);

    return 0;
}
