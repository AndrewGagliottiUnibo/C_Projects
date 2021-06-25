//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 2 - MAIN C
//Data di scadenza: 29-12-2019

#include <stdio.h>
#include <stdlib.h>
#include "LibCodeStruttureCollegate.h"

int main()
{
    int Scelta = 0, Elemento, verifica = 0, counter = 0, flag;
    struct CODA *Testa = NULL;
    struct CODA *Coda = NULL;

    do
    {
        printf("CODE: Utente, scegli che operazioni svolgere:\n");
        printf("\nNOTA: La stampa della coda ad ogni operazione viene fatta solo per visualizzarla e vedere il procedimento.");
        printf("\nL'opzione 2 stampa e cancella la coda come da consegna!\n\n");
        printf("1)Inserisci elemento\n2)Cancella Lista\n3)Esci\n");
        StampaGrafica();

        /*Controllo valore inserito per il menu delle scelte: deve essere un intero e deve essere all'interno di un determinato range di valori*/
        while(verifica != 1)
        {
            verifica = scanf("%d", &Scelta);
            fflush(stdin);
            if (verifica != 1)
                printf("Input errato.\n");
            else if (Scelta < 1 || Scelta > 3)
            {
                printf("Input errato.\n");
                verifica = 0;
            }
            else
                break;
        }

        switch(Scelta)
        {
            /*Inserisci elemento nella coda*/
            case 1:
            {
                printf("\nInserimento di un elemento:\n");
                printf("Inserisci elemento: ");
                verifica = 0;
                /*Controllo sull'input inserito: deve essere un intero*/
                while(verifica != 1)
                {
                    verifica = scanf("%d", &Elemento);
                    fflush(stdin);
                    if (verifica != 1)
                        printf("Input errato.\n");
                    else
                        break;
                }
                /*Se è un intero allora inseriscilo*/
                InserisciElemento(Elemento, &Testa, &Coda);
                counter++;
                break;
            }
            /*Cancellazione coda*/
            case 2:
            {
                flag = CancellaCoda(&Testa, &Coda);
                /*Se la cancellazione ha esito negativo...*/
                if(flag == 0)
                {
                    printf("\nLa coda ora e' vuota!\n");
                    counter = 0;
                    break;
                }
                /*Se la cancellazione ha esito positivo...*/
                else
                {
                    printf("\nLa coda e' gia' vuota quindi non c'e' bisogno di cancellare cio' che non esiste!\n");
                    break;
                }
            }
            /*Uscita dal programma con la free della struct*/
            case 3:
            {
                flag = CancellaCoda(&Testa, &Coda);
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
        StampaCoda(&Testa, &Coda, counter);
        StampaGrafica();
        StampaGrafica();
        printf("\n\n");

    }while(1);

    return 0;
}
