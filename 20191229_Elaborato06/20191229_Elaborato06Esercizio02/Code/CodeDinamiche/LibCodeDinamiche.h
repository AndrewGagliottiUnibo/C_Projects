//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 2 - FILE HEADER
//Data di scadenza: 29-12-2019

#ifndef LIBCODEDINAMICHE_H
#define LIBCODEDINAMICHE_H

/*Esempio di struttura su cui si lavora*/
typedef int MallocElementi;
struct CODA
{
    MallocElementi *numero;
    int grandezza;
    int ultimo;
};

/*La struttura su cui effettivamente si lavora*/
typedef struct CODA CODADINAMICA;
CODADINAMICA CodaDinamica;

/*Inizializzazione coda*/
CODADINAMICA Inizializzazione();

/*Riallocazione della Memoria*/
void RiallocazioneMemoria(int counter);

/*Inserisci elemento*/
int InserisciElemento(int num, int counter);

/*Cancella coda*/
int CancellaCoda(int counter);

/*Stampa coda*/
void StampaCoda(int counter);

/*Stampa divisori grafici a schermo*/
void StampaGrafica();

#endif // LIBCODEDINAMICHE_H
