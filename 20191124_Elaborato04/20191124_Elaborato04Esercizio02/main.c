//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 13-11-2019
//Esercizio 2
//Data di scadenza: 24-11-2019

#include <stdio.h>
#include <stdlib.h>

/*
    L'esercizio prevede fin da subito una allocazione della memoria in modo dinamico, si elimina quindi il problema
    dell'aumento dei limiti di range nel caso in cui l'utente voglia cambiare il range dei numeri da visualizzare:
    E' l'utente fin da subito a decidere i limiti di range di visualizzazione dei numeri primi
*/

/*Funzione utilizzata per la stampa di caratteri '-', solo per scopo grafico*/
void funzione()
{
    for(int i = 0; i < 100; i++)
        printf("-");
}

int main()
{
    /*Dichiarazione di variabili usate nel ciclo + verifica*/
    int counter_numeri = 0, count_ciclo = 1, numerostampa = 0, primo, verifica = 0, m = 0;
    /*Dichiarazione di puntatori*/
    int *p_numeroprimo;

/*------------------------------------INIZIO_ESERCIZIO-------------------------------------------------------------------*/
    printf("**********************ECCO A TE UN MODO SEMPLICE E VELOCE PER VEDERE E RICORDARE DEI NUMERI PRIMI!**********************\n\n");
    printf("Fino a che numero vuoi visualizzare dei numeri primi?\n");
    funzione();
    printf("\n\n");

/*------------------------------------CICLO_VERIFICA---------------------------------------------------------------------*/
    /*Ciclo di verifica del dato di input*/
    while(verifica != 1)
    {
        /*Richiesta del dato di input da parte dell'utente*/
        verifica = scanf("%d", &counter_numeri);
        fflush(stdin);

        /*Verifica per l'inserimento di un dato di input corretto(che sia int)*/
        if(verifica != 1)
            printf("Hai inserito un input errato, reinserisci!\n");
        /*Verifica per l'inserimento di un dato di input maggiore di 1*/
        else if( counter_numeri < 2 )
        {
            printf("Hai inserito un input errato, reinserisci!\n");
            verifica = 0;
        }
    }
/*---------------------------------INIZIALIZZAZIONE_NUMERI_PRIMI---------------------------------------------------------*/
    /*Dichiarazione della malloc con grandezza pari al numero inserito dall'utente*/
    p_numeroprimo = (int *)malloc(counter_numeri * sizeof(int));

    /*If per il controllo della memoria*/
    if(p_numeroprimo == NULL)
    {
        printf("Memoria insufficiente\n");
        exit(1);
    }

    printf("\n");
    funzione();
    printf("\n\n");

    /*Ciclo per il trattamento del puntatore, utilizzato come array*/
    while(m <= counter_numeri)
    {
            /*Variabile per la conta dei numeri*/
            count_ciclo++;
            /*If per il controllo del numero attuale se minore del numero fornito in input*/
            if(count_ciclo <= counter_numeri)
            {
                /*Variabile per indicare che il numero attuale e' "potenzialmente" un numero primo*/
                primo = 1;
                /*Ciclo per la divisione del numero attuale*/
                for (int i = 1 ; i <= count_ciclo; i++)
                    {
                        /*If per il controllo del resto del numero attuale, che non sia egli stesso il numero e non sia 1*/
                        if ((count_ciclo % i) == 0 && i != count_ciclo && i != 1)
                            {
                                /*Se la condizione dell'if e' soddisfatta, allora il numero non e' primo...*/
                                primo = 0;
                                break;
                            }
                    }
                /*Se il numero attuale e' al 100% un numero primo allora lo memorizziamo nel puntatore*/
                if (primo == 1)
                    {
                        p_numeroprimo[m] = count_ciclo;
                        numerostampa++;
                        m++;
                    }
            }
            else
                break;
        }

/*------------------------------------STAMPA_NUMERI----------------------------------------------------------------------*/
    /*Dichiarazione di un secondo vettore dinamico, di ampiezza esatta per contenere i numeri primi usciti*/
    p_numeroprimo = (int *) realloc(p_numeroprimo, numerostampa * sizeof(int));

    /*If per il controllo della memoria*/
    if(p_numeroprimo == NULL)
    {
        printf("Memoria insufficiente\n");
        exit(1);
    }

    /*Ciclo per la stampa degli elementi del secondo vettore*/
    for(int j = 0; j < numerostampa; j++)
    {
        printf("%d\n", p_numeroprimo[j]);
        printf("Allocato in indirizzo %p\n\n", &p_numeroprimo[j]);
    }

    /*Liberazione della memoria occupata dalla malloc*/
    funzione();
    free(p_numeroprimo);

    return 0;
}
