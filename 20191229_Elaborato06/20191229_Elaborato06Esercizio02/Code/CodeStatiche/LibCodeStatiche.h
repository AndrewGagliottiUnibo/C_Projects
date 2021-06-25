//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 2 - FILE HEADER
//Data di scadenza: 29-12-2019

#ifndef LIBCODESTATICHE_H
#define LIBCODESTATICHE_H

#define N 10

/*Esempio di struttura su cui si lavora*/
typedef int ArrayElementi;
struct CODA
{
    ArrayElementi numero[N];
    int ultimo;
};

/*La struttura su cui effettivamente si lavora*/
typedef struct CODA CODAELABORATO;
CODAELABORATO CodaStatica;

/*Inizializzazione coda*/
CODAELABORATO Inizializzazione();

/*Inserisci elemento*/
int InserisciElemento(int num, int counter);

/*Cancella coda*/
void CancellaLista(int counter);

/*Stampa coda*/
void StampaLista(int counter);

/*Stampa divisori grafici a schermo*/
void StampaGrafica();

#endif // LIBCODESTATICHE_H
