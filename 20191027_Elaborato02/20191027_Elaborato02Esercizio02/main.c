//Authors: Andrew Gagliotti, Andrea Zacconi, Cristian Crescentini
//Date: 20-10-2019
//Esercizio 2
//Data di scadenza: 27-10-2019

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    int CampoMinimo, CampoMassimo, VariabileTemporanea, NumeroRandom, Verifica, VariabileFlag = 0;
    char Risposta = 'n', Risposta2;
/*----------------------------------------------------------------CICLO_VERIFICA_INSERIMENTO_CORRETTO-------------------------------------------------------------------------------------------------------------------------------------*/
    //while per i vari controlli dei campi minimi e massimi(controllo se: non negativi, diversi tra loro, se presenti delle lettere)
    while(1)
    {
        printf("Dammi due campi, minimo e massimo, per incominciare a giocare!\n");
        Verifica = scanf("%d%d", &CampoMinimo, &CampoMassimo);
        fflush(stdin);

        //Controllo se sono 2 int
        if(Verifica != 2)
        {
            printf("Inserisci dei numeri, non delle lettere!\n\n");
        }
        //Controllo se diversi
        else if(CampoMinimo == CampoMassimo)
        {
            printf("Non puoi inserire due campi uguali!\n\n");
        }
        //Controllo se positivi
        else if(CampoMinimo < 0 || CampoMassimo < 0)
        {
            printf("Inserisci dei valori positivi!\n\n");
        }
        //Se soddisfatte tutte le richieste precedenti
        else
        {
            //Controllo se Minimo e minore di Massimo e viceversa
            if(CampoMinimo > CampoMassimo)
            {
                VariabileTemporanea = CampoMinimo;
                CampoMinimo = CampoMassimo;
                CampoMassimo = VariabileTemporanea;
            }
            break;
        }
    }
    //Pausa per far scegliere il numero all'utente
    printf("Una volta che hai pensato al tuo numero, premi un tasto per avviare il gioco!\n\n\n");
    system("pause");
    printf("\n\nOttimo, ora pensa ad un numero, compreso tra i due campi che mi hai fornito, ed io cercero' di indovinarlo!\n\n");
    //Inizializzazione srand()
    srand(time(NULL));
    NumeroRandom = CampoMinimo + rand() % (CampoMassimo + 1 - CampoMinimo);
/*----------------------------------------------------------------PRIMO_CICLO--------------------------------------------------------------------------------------------------------------------------------------------------*/
    while(VariabileFlag != 1)
    {
        //Controllo se i Campi Massimo e Minimo coincidono
        if(CampoMassimo == CampoMinimo)
        {
            printf("Il numero da indovinare e' %d", CampoMinimo);
            break;
        }
        else
        {
            //Risposta da parte dell'utente, se la risposta e' sbagliata o corretta
            printf("Il numero che hai pensato e' %d?(Rispondi con 's/S' o 'n/N')\n\n", NumeroRandom);
            scanf("%c", &Risposta);
            fflush(stdin);
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\SECONDO_CICLO\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
            //Ciclo per il controllo dei caratteri corretti(SI o NO)
            while(1)
            {
                //Condizione se la risposta e' vera
                if(Risposta == 's' || Risposta == 'S')
                {
                    printf("Evviva ho indovinato!!");
                    ++VariabileFlag;
                    break;
                }
                //Condizione se la risposta e' falsa
                else if(Risposta == 'n' || Risposta == 'N')
                {
                    //Controllo del range del Random
                    if(CampoMassimo - CampoMinimo >= 2)
                    {
                        if(NumeroRandom == CampoMinimo)
                        {
                            CampoMinimo = ++NumeroRandom;
                            NumeroRandom = CampoMinimo + rand() % (CampoMassimo + 1 - CampoMinimo);
                        }
                        else if(NumeroRandom == CampoMassimo)
                        {
                            CampoMassimo = --NumeroRandom;
                            NumeroRandom = CampoMinimo + rand() % (CampoMassimo + 1 - CampoMinimo);
                        }
                        else
                        {
/*---------------------------------------------------------------TERZO_CICLO------------------------------------------------------------------------------------------------------------------------------------*/
                            //Ciclo per il controllo dei caratteri corretti(MAGGIORE, MINORE)
                            while(1)
                            {
                                //Indizio fornito dall'utente, se MAGGIORE o MINORE tramite: M, > o m, <
                                printf("Il numero da indovinare e' Minore(m, <) o Maggiore(M, >) di quello che ho detto?\n\n");
                                scanf("%c", &Risposta2);
                                fflush(stdin);
                                //Controllo se MINORE
                                if(Risposta2 == '<' || Risposta2 == 'm')
                                {
                                    CampoMassimo = --NumeroRandom;
                                    NumeroRandom = CampoMinimo + rand() % (CampoMassimo + 1 - CampoMinimo);
                                    break;
                                }
                                //Controllo se MAGGIORE
                                else if (Risposta2 == '>' || Risposta2 == 'M')
                                {
                                    CampoMinimo = ++NumeroRandom;
                                    NumeroRandom = CampoMinimo + rand() % (CampoMassimo + 1 - CampoMinimo);
                                    break;
                                }
                                else
                                {
                                    printf("\nHai inserito un caratere sbagliato, riprova con < o m(MINORE), > o M(MAGGIORE)!\n\n\n");
                                }
                            }
/*------------------------------------------------------------------FINE_TERZO_CICLO---------------------------------------------------------------------------------------------------------------------------------*/
                        }
                    }
                    //Controllo del range del Random(per evitare possibili crash da parte del programma)
                    else
                    {
                        //Controllo del campo massimo
                        if(CampoMassimo != NumeroRandom)
                        {
                            //Assegno al numero da indovinare il campo minimo + 1
                            printf("Il numero da indovinare e' %d", ++CampoMinimo);
                            ++VariabileFlag;
                        }
                        else if(CampoMinimo != NumeroRandom)
                        {
                            //Assegno al numero da indovinare il campo massimo - 1
                            printf("Il numero da indovinare e' %d", --CampoMassimo);
                            ++VariabileFlag;
                        }
                    }
                    break;
                }
                else
                {
                    printf("\nHai inserito un carattere non accettato, riprova con s o S(SI!), n o N(NO!)!\n\n\n");
                    break;
                }
            }
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\FINE_SECONDO_CICLO\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
        }
    }
/*---------------------------------------------------------------------FINE_PRIMO_CICLO------------------------------------------------------------------------------------------------------------------------------------*/

    printf("\n\n");
    system("pause");
    printf("\n\nFine esercizio.\n\n\n");
    return 0;
}
