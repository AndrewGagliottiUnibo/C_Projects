//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 22-11-2019
//Esercizio 1
//Data di scadenza: 24-11-2019

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    /*Variabili usate nel programma*/
    char **p_stringa, *p_scambio, lettera;
    int verifica1 = 0, verifica2 = 0, j, count_malloc = 0;
    int str_num, lunghezza_stringa;

/*----------------------------------------CICLO_DI_VERIFICA_DI_INPUT_1--------------------------------------------------------------------------------------*/
    printf("Quante stringhe vuoi inserire?\n");

    while(verifica1 != 1)
    {
        /*Richiesta del dato di input da parte dell'utente per il numero di strighe da inserire*/
        verifica1 = scanf("%d", &str_num);
        fflush(stdin);

        /*Verifica per l'inserimento di un dato di input corretto(che sia int)*/
        if(verifica1 != 1)
            printf("Hai inserito un input errato, reinserisci!\n");
        /*Verifica per l'inserimento di un dato di input maggiore di 0*/
        else if( str_num <= 0 )
        {
            printf("Hai inserito un input errato, reinserisci!\n");
            verifica1 = 0;
        }
    }

/*----------------------------------------CICLO_DI_VERIFICA_DI_INPUT_2--------------------------------------------------------------------------------------*/
    printf("\nQuanto vuoi che sia grande al massimo ciascuna stringa?\n");
    verifica2 = 0;

    while(verifica2 != 1)
    {
        /*Richiesta del dato di input da parte dell'utente per la lunghezza della stringa*/
        verifica2 = scanf("%d", &lunghezza_stringa);
        fflush(stdin);

        /*Verifica per l'inserimento di un dato di input corretto(che sia int)*/
        if(verifica2 != 1)
            printf("Hai inserito un input errato, reinserisci!\n");
        /*Verifica per l'inserimento di un dato di input maggiore di 0*/
        else if( lunghezza_stringa <= 0 )
        {
            printf("Hai inserito un input errato, reinserisci!\n");
            verifica2 = 0;
        }
    }

    /*Inizializzo l'array di puntatori a puntatori di stringhe e verifico la disponibilità in memoria*/
    p_stringa = (char **)malloc((lunghezza_stringa + 1) * sizeof(char *));
    if(p_stringa == NULL)
    {
        printf("\n***No memory available for p_stringa array! Ending process!***\n\n\n");
        exit(1);
    }

    /*Array di conservazione momentanea delle stringhe*/
    char stringa[lunghezza_stringa + 1];

/*------------------------------------------------------CICLO_DI_LETTURA_E_INSERIMENTO_IN_MEMORIA_DELLE_STRINGHE--------------------------------------------*/
    printf("\nInserisci le stringhe:\n");
    for(int i = 0; i < str_num; i++)
    {
        j = 0;
        lettera = ' ';
        while(lettera != '\n')
        {
            lettera = getchar();
            lettera = toupper(lettera);
            stringa[j] = lettera;
            j++;
        }
        /*Carattere terminatore inserito alla fine della stringa*/
        stringa[j] = '\0';

        /*Counter per la malloc generale basata sul numero di caratteri*/
        count_malloc += j;

        /*Inizializzo ogni singolo puntatore contenente le stringhe con una dimensione data e precisa dell'utente e controllo la disponibilità in memoria*/
        p_scambio = (char *)malloc(lunghezza_stringa * sizeof(char *));
        if(p_scambio == NULL)
        {
            printf("\n***No memory available for p_scambio array! Ending process!***\n\n\n");
            exit(1);
        }

        /*Se la dimensione indicata viene violata allora viene riallocata la memoria e si controlla sempre la disponibilità*/
        if(j < lunghezza_stringa + 1 || j > lunghezza_stringa + 1)
        {
            printf("Hai inserito una stringa troppo lunga o troppo corta!(La stringa verra' presa lo stesso!)\n");
            p_stringa = realloc(p_stringa, j * sizeof(char));
            if(p_stringa == NULL)
            {
                printf("\n***No memory available for p_stringa array! Ending process!***\n\n\n");
                exit(1);
            }
        }
        /*Copio la stringa dall'array statico al puntatore dinamico*/
        strcpy(p_scambio, stringa);
        /*Assegno all'array di puntatori un puntatore che punta al puntatore della stringa*/
        p_stringa[i] = p_scambio;
    }

/*-----------------------------------CICLO_DI_STAMPA_DELLE_STRINGHE_IN_MALLOC-------------------------------------------------------------------------------*/
    printf("\n\nStampa stringhe tutte in maiuscolo!\n\n");
    for(int i = 0; i < str_num; i++)
    {
        printf("%s", p_stringa[i]);
        printf("In indirizzo: %p\n", &p_stringa[i]);
    }

/*------------------------------------CICLO_DI_LIBERAZIONE_DELLA_MEMORIA------------------------------------------------------------------------------------*/
    for(int i = 0; i < str_num; i++)
        free(p_stringa[i]);

    /*Libero anche il puntatore usato per puntare ad ogni singola stringa*/
    free(p_stringa);
    return 0;

}
