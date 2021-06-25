//Authors: Andrew Gagliotti, Andrea Zacconi, Cristian Crescentini
//Date: 08-10-2019
//Esercizio 02, Elaborato 03
//Data di scadenza: 10-11-2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>                                                                                                         //Libreria per le operazioni sulle stringhe

#define GRANDEZZA_VETTORE 31                                                                                                //Costante lunghezza prima stringa
#define GRANDEZZA_VETTORE2 31                                                                                               //Costante lunghezza seconda stringa, viene indicata di nuovo solo per lasciare la possibilità all'utente di cambiare le dimensioni della stringa
#define NUMERO 90                                                                                                           //Costante usata in "funzione" per la stampa dei divisori a schermo nella console

/*
    La prima parte del programma sfrutta dei counter per l'analisi delle due stringhe, la loro comparazione e succesivamente la sostituzione delle occorrrenze.
    La seconda parte sfrutta i puntatori e le funzioni della string.h per andare a sostituire in una determinata posizione il valore della occorrenza con un '*'
*/


/*------------------------------------INIZIALIZZAZIONE_FUNZIONI_CHE_USEREMO---------------------------------------------------------------------------------------------------*/
//Funzione per stampare a schermo una serie di - come estetica divisioria
void funzione()
{
    for(int i = 0; i <= NUMERO; i++)
        printf("-");
}
//Funzione per la stampa delle stringhe indicate -> la stringa viene stampata fino al carattere terminatore. Non fa la sostituzione ma stampa solamente la stringa.
void funzionestampastringa(char a[], int b)
{
    for(int i = 0; i < b; i++)
    {
        if(a[i] != '\0')
            printf("%c", a[i]);
        else
            break;
    }
}

/*.....................................INIZIO_DEL_PROGRAMMA...................................................................................................................*/
/*............................................................................................................................................................................*/
int main()
{
    //Dichiarazioni delle variabili prese in considerazione
    char parola1[GRANDEZZA_VETTORE], parola2[GRANDEZZA_VETTORE2], parola1f[GRANDEZZA_VETTORE], parola2f[GRANDEZZA_VETTORE2], *ElementoF, *carattere;
    int NelementiP1 = 0, NelementiP2 = 0, NelementiC = 0;


/*-------------------------------------CICLO_DI_CONTROLLO_SULLE_STRINGHE_INSERITE---------------------------------------------------------------------------------------------*/
    printf("\n**************************ESERCIZIO SOSTITUZIONI SENZA FUNZIONI DI STRING.H!**************************\n\n");

    while(1)
    {
        //Inizializzazione prima frase del programma
        printf("Inserisci una frase a tuo piacimento:\n");
        gets(parola1);                                                                                                  //Usiamo la gets per includere lo spazio come carattere di input evitando i problemi della scanf
        printf("\n");
        fflush(stdin);

    /*'''''''''''''''''''''''''''''''''CONTEGGIO_CARATTERI_PRIMA_STRINGA''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/
        for(int i = 0; i < GRANDEZZA_VETTORE; i++)                                                                      //Ciclo per contare il numero di caratteri della prima stringa
        {
            if(parola1[i] != '\0')                                                                                      //Il ciclo conta i caratteri finchè non arriva al terminatore...
                NelementiP1++;                                                                                          //...e usa un counter che aumenta di uno ogni volta
            else
                break;
        }
    /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/


        //Inizializzazione seconda frase del programma
        printf("Ottimo, ora inserisci una concatenazione di lettere (Minore o uguale della prima parola):\n");
        gets(parola2);                                                                                                  //Uso gets per lo stesso motivo di prima
        printf("\n");
        fflush(stdin);
        funzione();                                                                                                      //Ogni volta che compare questa funzione si richiama ciò che è stato dichiarato prima del main


    /*++++++++++++++++++++++++++++++++++++CONTEGGIO_CARATTERI_SECONDA_STRINGA+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
       for(int i = 0; i < GRANDEZZA_VETTORE2; i++)                                                                      //Ciclo per contare il numero di caratteri della seconda stringa
        {
            if(parola2[i] != '\0')                                                                                      //Il ciclo conta i caratteri finchè non arriva al terminatore...
                NelementiP2++;                                                                                          //..e usa un counter che aumenta di uno ogni volta
            else
                break;
        }
    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


    /*...................................CONFRONTO_CARATTERTI_DELLE_DUE_STRINGHE..................................................................................................*/
        if(NelementiP1 >= NelementiP2)                                                                                  //Se il numero di elementi della prima è maggiore della seconda...
            break;                                                                                                      //...allora interrompi il ciclo...
        else
        {
            NelementiP1 = 0;                                                                                            //...altrimenti riazzera i due counter e ricomincia da capo notificando l'utente che ha sbagliato
            NelementiP2 = 0;
            printf("\n\nLa seconda stringa e' troppo lunga rispetto alla prima, reinserisci le due parole!\n\n");
            funzione();
            printf("\n");
        }
    }

/*----------------------------------------FINE_CICLO_CONTROLLO_DELLE_STRINGHE_IN_INPUT----------------------------------------------------------------------------------------*/

    //Stampa delle due stringhe inserite
    printf("\n\nLa prima parola che hai inserito e': ");
    funzionestampastringa(parola1, NelementiP1);
    printf("\nLa seconda parola che hai inserito e': ");
    funzionestampastringa(parola2, NelementiP2);
    printf("\n\n");



    /*  Copio le stringhe inserite precedentemente in altri due array dimostrando il funzionamento della strcpy, uso solo qui le funzioni per la copia per agevolare la seconda parte
        tutto ciò è fatto per ottimizzazione poichè servirebbe richiedere un secondo input con un secondo controllo dei caratteri inseriti, poco efficiente e linee di codice ripetitive
    */
    strcpy(parola1f, parola1);                                                                                          //Si copia il contenuto della seconda stringa in un'altra stringa di destinazione, ovvero la prima
    strcpy(parola2f, parola2);




    printf("Premi un tasto per far partire la sostituzione delle occorenze: ");
    system("pause");
    printf("\n");
    funzione();


/*-----------------------------------------STRUTTURE_DI_CONTROLLO_PER_LA_SOSTITUZIONE_DEI_CARATTERI---------------------------------------------------------------------------*/
    if(NelementiP2 == 1)                                                                                                //Se il numero di elementi della seconda stringa sono uguali a 1...
    {
      for(int i = 0; i <= GRANDEZZA_VETTORE; i++)                                                                       //...analizza ogni cella e...
      {
        if(parola1[i] == parola2[0])                                                                                    //...allora per ogni occorrenza sostituisci il carattere corrispodente con '*'
        {
            parola1[i] = '*';
        }
      }
    }
    else if(NelementiP2 >= 2)                                                                                           //Se il numero di elementi della seconda stringa sono maggiori o uguali a 2 elementi della prima...
    {
        for(int h = 0; h <= NelementiP1; h++)                                                                           //...analizza ogni cella e...
        {
            NelementiC = 0;                                                                                             //...inizializzo una variabile counter per il numero di caratteri da sostituire
            for(int i = 0; i <= NelementiP2; i++)
            {
                if(parola2[i] == parola1[h + NelementiC] && parola2[i] != '\0')
                    NelementiC++;                                                                                       //Sfrutto il counter NelementiC per contare i caratteri da sostituire...
                else
                    break;                                                                                              //...se tra le due stringhe non si riesce a trovare una occorrenzza, allora termina l'analisi...
            }
            if(NelementiP2 == NelementiC)                                                                               //...altrimenti se i caratteri della seconda stringa sono uguali al counter...
            {
                parola1[h] = '*';
                for(int c = h + 1; c <= NelementiP1; c++)                                                               //...allora opera la sostituzione con la stessa modalità di prima...
                {
                    parola1[c] = parola1[c + (NelementiP2 - 1)];                                                        //...ma ricorda di "traslare" le celle che rimangono vuote in modo da poter permettere una stampa corretta
                }
            }
        }
    }

    printf("\n\n");



    //Stampa della stringa con eventuali sostituzioni
    printf("La parola inserita, con eventuali sostituzioni tramite \"*\" per ogni occorrenza e': ");
    funzionestampastringa(parola1, NelementiP1);
    printf("\n\n");
    printf("Fine prima parte: ");
    system("pause");


/*------------------------------------------INIZIO_ESERCIZIO_CON_FUNZIONI_DI_STRING.H-----------------------------------------------------------------------------------------*/
    printf("\n**************************STESSO ESERCIZIO, MA CON FUNZIONI DI STRING.H!*****************************");

    printf("\n\nLa prima parola che hai inserito e': ");                                                                //Vengono mostrate di nuovo le due stringhe inserite
    funzionestampastringa(parola1f, NelementiP1);
    printf("\nLa seconda parola che hai inserito e': ");
    funzionestampastringa(parola2f, NelementiP2);
    printf("\n\n");

    printf("Premi un tasto per far partire la sostituzione delle occorenze: ");
    system("pause");
    printf("\n");
    funzione();

    /*-----------------------------------------STRUTTURE_DI_CONTROLLO_PER_LA_SOSTITUZIONE_DEI_CARATTERI---------------------------------------------------------------------------*/
    if(NelementiP2 == 1)                                                                                                //Se bisogna sostituire solo un carattere...
    {
            while(strchr(parola1f, parola2f[0])!= NULL)                                                                 //...inizializzo un ciclo di controllo delle ricorrenze
            {                                                                                                           //...assegno al puntatore il valore del carattere ricorrente e...
                carattere = strchr(parola1f, parola2f[0]);
                *carattere = '*';                                                                                       //...sostituisco ogni singola ricorrenza con un '*' tramite il puntatore, il puntatore assegna in n posizione '*' al posto del carattere
            }
    }
    else if(NelementiP2 >= 2)                                                                                           //Se vi è più di un carattere da sostiuire...
    {
        while(strstr(parola1f, parola2f)!= NULL)                                                                        //...sfrutto il concetto di puntatore per fargli puntare l'occorrenza di una stringa specifica all'interno della prima stringa basandosi sulla seconda stringa...
            {
                ElementoF = strstr(parola1f, parola2f);                                                                 //...se vi è una occorrenza...
                strncpy(ElementoF, "*", NelementiP2);                                                                   //...allora copia '*' nel puntatore alla stringa e sottrae n-1 volte '*' in modo da avere un solo asterisco per ogni sostituzione anzichè molteplici asterischi...
                strcat(parola1f, ElementoF + NelementiP2);                                                              //...e incolla la stringa originale con la sostituzione avvenuta
            }
    }

    printf("\n\n");

    //Seconda atampa della stringa con eventuale sostituzione tramite le funzioni di string.h
    printf("La parola inserita, con eventuali sostituzioni tramite \"*\" per ogni occorrenza SFRUTTANDO le funzioni di string.h e': ");
    funzionestampastringa(parola1f, NelementiP1);
    printf("\n\n");



    printf("\n\n\n\n*******************FINE ESERCIZIO!*******************\n\n");

/*--------------------------------------------FINE_ESERCIZIO_CON_FUNZIONI_DI_STRING.H-----------------------------------------------------------------------------------------*/

    return 0;
}
