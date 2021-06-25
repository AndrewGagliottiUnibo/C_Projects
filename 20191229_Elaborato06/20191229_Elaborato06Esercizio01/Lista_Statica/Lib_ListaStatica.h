//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 21-12-2019
//Esercizio 1 - HEADER
//Data di scadenza: 29-12-2019

#ifndef LIB_LISTASTATICA_H_INCLUDED
#define LIB_LISTASTATICA_H_INCLUDED
#define N 10

/*Esempio di struttura su cui si lavora*/
typedef int ArrayElementi;
struct LISTA
{
    ArrayElementi numero[N];
    int ultimo;
};

/*La struttura su cui effettivamente si lavora*/
typedef struct LISTA LISTAELABORATO;
LISTAELABORATO ListaStatica;

/*Inizializzazione lista*/
LISTAELABORATO Inizializzazione();

/*Inserisci elemento in testa*/
int InserisciTesta (int num, int counter);

/*Inserisci elemento in coda*/
int InserisciCoda (int num, int counter);

/*Inserisci elemento in posizione desiderata*/
int InserisciElem (int num, int posizione, int counter);

/*Cancella elemento in testa*/
int CancellaTesta (int counter);

/*Cancella elemento in coda*/
int CancellaCoda (int counter);

/*Cancella occorrenze*/
int CancellaOccorrenza (int counter, int numero);

/*Cancella lista*/
void CancellaLista(int counter);

/*Stampa lista*/
void StampaLista(int counter);

/*Stampa divisori grafici a schermo*/
void StampaGrafica();


#endif // LIB_LISTASTATICA_H_INCLUDED
