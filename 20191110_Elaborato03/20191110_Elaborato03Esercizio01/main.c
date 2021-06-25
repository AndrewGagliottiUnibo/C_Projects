//Authors: Andrew Gagliotti, Andrea Zacconi, Cristian Crescentini
//Date: 31-10-2019
//Esercizio 01, Elaborato 03
//Data di scadenza: 10-11-2019

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j;                                                                           //Ci serviranno per lavorare sull'inizializzazione delle matrici e per le stampe
    int indicespostamento;                                                              //Rappresenta, in linea generale, il movimento che potrebbe intraprende il cammino
    int w,a,s,d;                                                                        //Variabili per il movimento. Inizializzate per verificare che le condizioni del movimento rispettassero la consegna dell'esercizio
    char lettera = 'A';                                                                 //Lettera che indica l'inizio della nostra camminata
    int R, C;
    int verifica = 0;

    /*++++++++++++++++++++++++++++++++++++++++++++++CICLO_CONTROLLO_E_VALUTAZIONE_DIMENSIONI_DELLA_MATRICE++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    while(verifica != 2)
    {
        printf("Inserisci i valori della nostra matrice(RIGHE E COLONNE):\n");          //Inserimento dimensioni matrice - scelta
        verifica = scanf("%d%d", &R, &C);
        fflush(stdin);

        if(verifica != 2)
            printf("Input sbagliato, reinserisci!\n");
    }
    char Matrice[R][C];                                                                 //La nostra matrice di gioco

    /*-------------------------------------------------CICLO_DI_INIZIALIZZAZIONE_DELLA_MATRICE_DI_PARTENZA--------------------------------------------------------------------------------*/
    //Inizializziamo il contenuto della matrice con il carattere char '.'
    for(i=0 ; i<R; i++)
        for(j=0 ; j<C ; j++)
            Matrice[i][j] = '.';

    //Partendo da questa matrice simuleremo una camminata aleatoria considerando la matrice come una mappa pseudosferica
    //Il programma simulerà una camminata e poi stamperà alla fine il risultato del nostro cammino.

    //Stampa della matrice di partenza.
    printf("Data una matrice di %d righe e %d colonne di partenza:\n",  R, C);
    for(i=0 ; i<R; i++)
    {
        printf("\n");
        for(j=0 ; j<C ; j++)
        {
             printf("|%c", Matrice[i][j]);
        }
           printf("|");
    }
    printf("\n\n");
    /*--------------------------------------------FINE_CICLO_DI_INIZIALIZZAZIONE_DELLA_MATRICE_DI_PARTENZA-------------------------------------------------------------------------------*/

    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++INIZIO_DEL_GIOCHINO+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    //Punto di partenza - Generazione randomica della posizione di partenza, contrassegnata con la lettera A.
    int PosizioneRandom1, PosizioneRandom2;
    PosizioneRandom1 = (rand() + time(NULL)) % R;                                           //Posizione di A in x riga
    PosizioneRandom2 = (rand() + time(NULL)) % C;                                           //Posizione di A in x colonna
    Matrice[PosizioneRandom1][PosizioneRandom2] = 'A';                                      //'A' assegnata in una posizione random all'interno della matrice

    //Non ci prendiamo la responsabilità della mancata consegna di biscotti in caso di vittoria
    printf("Voglio fare una scommessa con te. Se il percorso calcolato dal programma ti fara' arrivare alla fine, vincerai un biscotto!!\n");
    printf("Quando sei pronto, premi un tasto per cominciare!\n\n");
    system("pause");
    /*------------------------------------------------------------CICLO_DI_SPOSTAMENTO_CELLE---------------------------------------------------------------------------------------------*/
    int Righe = PosizioneRandom1;                                                           //Variabile che indica il numero di righe. Qui in particolare la posizione di partenza
    int Colonne = PosizioneRandom2;                                                         //Variabile che indica il numero di colonne. Qui in particolare la posizione di partenza


    do                                                                                      //Inizio ciclo dello spostamento nelle celle
        {
        indicespostamento = 0;                                                              //Inizializzo la variabile per lo spostamento a 0
        indicespostamento = ((rand() + time(NULL)) % 4 + 1);                                //Generazione numeri da 1 a 4 per lo spostamento fra le celle, un numero per ogni direzione secondo un'asse cartesiano immaginario

        if(indicespostamento == 1)                                                          //Se lo spostamento avviene verso nord, allora...
            {
                if(Matrice[(Righe = (Righe - 1 == -1) ? R - 1 : Righe -1)][Colonne]== '.')  //...operatore ternario: se lo spostamento avviene verso l'esterno della matrice, allora la lettera compare dal lato opposto...
                {                                                                           //...bisogna che nel vettore destinazione ci sia un '.' altrimenti verrà generato un nuovo indice di spostamento...
                Matrice[Righe][Colonne] = lettera + 1;                                      //...se lo spostamento avviene in questa direzione, incrementa di 1 la variabile lettera e inseriscila in questa posizione del vettore, seguendo il codicd ASCII...
                lettera = lettera + 1;                                                      //...la lettera incrementata al ritorno del ciclo sarà la nuova lettera da incrementare...
                }
                else                                                                        //...se non vi è un '.', viene rivalutata la condizione del ciclo senza operare alcuna assegnazione, lo spostamento viene resettato
                {
                    Righe++;
                    if(Righe == R)
                    {
                        Righe = 0;
                    }
                    continue;
                }
            }
        if(indicespostamento == 2)                                                          //Se lo spostamento avviene verso est, allora...
            {
               if(Matrice[Righe][Colonne = (Colonne + 1 == C) ? 0 : Colonne + 1] == '.')    //...operatore ternario: se lo spostamento avviene verso l'esterno della matrice, allora la lettera compare dal lato opposto...
                {                                                                           //...bisogna che nel vettore destinazione ci sia un '.' altrimenti verrà generato un nuovo indice di spostamento...
                Matrice[Righe][Colonne] = lettera + 1;                                      //...se lo spostamento avviene in questa direzione, incrementa di 1 la variabile lettera e inseriscila in questa posizione del vettore, seguendo il codicd ASCII...
                lettera = lettera + 1;                                                      //...la lettera incrementata al ritorno del ciclo sarà la nuova lettera da incrementare...
                }
                else                                                                        //...se non vi è un '.', viene rivalutata la condizione del ciclo senza operare alcuna assegnazione, lo spostamento viene resettato
                {
                    Colonne--;
                    if(Colonne == -1)
                    {
                        Colonne = C - 1;
                    }
                    continue;
                }
            }
        if(indicespostamento == 3)                                                          //Se lo spostamento avviene verso sud, allora...
            {
                if(Matrice[Righe = (Righe + 1 == R) ? 0 : Righe + 1][Colonne] == '.')       //...operatore ternario: se lo spostamento avviene verso l'esterno della matrice, allora la lettera compare dal lato opposto...
                {                                                                           //...bisogna che nel vettore destinazione ci sia un '.' altrimenti verrà generato un nuovo indice di spostamento...
                Matrice[Righe][Colonne] = lettera + 1;                                      //...se lo spostamento avviene in questa direzione, incrementa di 1 la variabile lettera e inseriscila in questa posizione del vettore, seguendo il codicd ASCII...
                lettera = lettera + 1;                                                      //...la lettera incrementata al ritorno del ciclo sarà la nuova lettera da incrementare...
                }
                else                                                                        //...se non vi è un '.', viene rivalutata la condizione del ciclo senza operare alcuna assegnazione, lo spostamento viene resettato
                {
                    Righe--;
                    if(Righe == -1)
                    {
                        Righe = R - 1;
                    }
                    continue;
                }
            }
        if(indicespostamento == 4)                                                          //Se lo spostamento avviene verso ovest, allora...
            {
               if(Matrice[Righe][Colonne = (Colonne-1 == -1) ? C - 1 : Colonne - 1]== '.')  //...operatore ternario: se lo spostamento avviene verso l'esterno della matrice, allora la lettera compare dal lato opposto...
                {                                                                           //...bisogna che nel vettore destinazione ci sia un '.' altrimenti verrà generato un nuovo indice di spostamento...
                Matrice[Righe][Colonne] = lettera + 1;                                      //...se lo spostamento avviene in questa direzione, incrementa di 1 la variabile lettera e inseriscila in questa posizione del vettore, seguendo il codicd ASCII...
                lettera = lettera + 1;                                                      //...la lettera incrementata al ritorno del ciclo sarà la nuova lettera da incrementare...
                }
                else                                                                        //...se non vi è un '.', viene rivalutata la condizione del ciclo senza operare alcuna assegnazione, lo spostamento viene resettato
                {
                    Colonne++;
                    if(Colonne == C)
                    {
                        Colonne = 0;
                    }
                    continue;
                }
            }

    //Le lettere w a s d, che rappresentano lo spostamento verso nord, sud, ovest, est, le dichiaro così in modo da rendere più leggibili le condizioni del ciclo do while
    w = (Righe+1 == R) ? 0 : Righe+1;                                                       //Operatore ternario: la condizione specifica che per un'uscita dalla matrice si avrà un assegnamento della variabile dal lato opposto, altrimenti un normale spostamento con assegnamento
    s = (Righe-1 == -1) ? R - 1 : Righe-1;                                                  //Operatore ternario: la condizione specifica che per un'uscita dalla matrice si avrà un assegnamento della variabile dal lato opposto, altrimenti un normale spostamento con assegnamento
    a = (Colonne-1 == -1) ? C - 1 : Colonne-1;                                              //Operatore ternario: la condizione specifica che per un'uscita dalla matrice si avrà un assegnamento della variabile dal lato opposto, altrimenti un normale spostamento con assegnamento
    d = (Colonne+1 == C) ? 0 : Colonne+1;                                                   //Operatore ternario: la condizione specifica che per un'uscita dalla matrice si avrà un assegnamento della variabile dal lato opposto, altrimenti un normale spostamento con assegnamento

    //Senza quest'ultima assegnazione di variabile la condizione del while sarebbe stata illeggibile
    }while(lettera < 90 && (Matrice[Righe][d] == '.' || Matrice[Righe][a] == '.' || Matrice[w][Colonne] == '.' || Matrice[s][Colonne] == '.'));
    /*-------------------------------------------------------FINE_ CICLO_DI_SPOSTAMENTO_CELLE---------------------------------------------------------------------------------------------*/

    //Stampa finale della matrice
    printf("\n\n");
    printf("Matrice a fine gioco:\n\n");

    for(i=0 ; i<R; i++)
        {
            printf("\n");
            for(j=0 ; j<C ; j++)
                {
                    printf("|%c", Matrice[i][j]);
                }
            printf("|");
        }

    //Hai vinto o perso?
    //Tenere a mente che impostando come condizione della matrice, la possibilità di una pseudosfera, è molto più difficile che l'utente possa perdere, quindi più biscotti per tutti!
        printf("\n\n");
    if(lettera == 90)
        printf("Hai vinto un biscotto!");
    else
        printf("Mi spiace, hai perso, sara' per un'altra volta!");

    printf("\n\n");
    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++FINE_DEL_GIOCHINO+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


    printf("Fine esercizio 1\n\n");
    return 0;
}
