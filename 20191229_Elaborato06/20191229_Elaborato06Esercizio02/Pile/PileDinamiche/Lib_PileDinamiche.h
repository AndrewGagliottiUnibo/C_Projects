//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 24-12-2019
//Esercizio 2 - FILE HEADER
//Data di scadenza: 29-12-2019

#ifndef LIB_PILEDINAMICHE_H_INCLUDED
#define LIB_PILEDINAMICHE_H_INCLUDED

/*Esempio di struttura su cui si lavora*/
typedef int MallocElementi;
struct PILA
{
    MallocElementi *numero;
    int grandezza;
    int ultimo;
};

/*La struttura su cui effettivamente si lavora*/
typedef struct PILA PILADINAMICA;
PILADINAMICA PilaDinamica;

/*Stampa divisori grafici a schermo*/
void StampaGrafica();

/*Inizializzazione PILA*/
PILADINAMICA Inizializzazione(int counter);

/*Riallocazione della Memoria*/
void RiallocazioneMemoria(int counter);

/*Inserisci elemento*/
int Push(int num, int counter);

/*Elimina un elemento*/
int Pop(int counter);

/*Stampa ed eliminazione della PILA*/
void StampaPila(int counter);

/*Elimina la PILA*/
int CancellaPila(int counter);

#endif // LIB_PILEDINAMICHE_H_INCLUDED
