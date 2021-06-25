//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 2 - FILE HEADER
//Data di scadenza: 29-12-2019

#ifndef LIB_PILESTATICHE_H_INCLUDED
#define LIB_PILESTATICHE_H_INCLUDED
#define N 10

/*Esempio di struttura su cui si lavora*/
typedef int ArrayElementi;
struct PILA
{
    ArrayElementi numero[N];
    int ultimo;
};

/*La struttura su cui effettivamente si lavora*/
typedef struct PILA PILAELABORATO;
PILAELABORATO PilaStatica;

/*Stampa divisori grafici a schermo*/
void StampaGrafica();

/*Inizializzazione PILA*/
PILAELABORATO Inizializzazione();

/*Inserisci elemento*/
int Push(int num, int counter);

/*Elimina un elemento*/
int Pop(int counter);

/*Stampa ed eliminazione della PILA*/
void StampaPila(int counter);

/*Elimina la PILA*/
void CancellaPila();

#endif // LIB_PILESTATICHE_H_INCLUDED
