//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 21-12-2019
//Esercizio 1 - HEADER
//Data di scadenza: 29-12-2019

#ifndef LIB_LISTADINAMICA
#define LIB_LISTADINAMICA

#define N 2

/*Esempio di struttura su cui si lavora*/
typedef int MallocElementi;
struct LISTA
{
    MallocElementi *numero;
    int grandezza;
    int ultimo;
};

/*La struttura su cui effettivamente si lavora*/
typedef struct LISTA LISTADINAMICA;
LISTADINAMICA ListaDinamica;

/*Inizializzazione lista*/
LISTADINAMICA Inizializzazione();

/*Riallocazione della Memoria*/
void RiallocazioneMemoria(int counter);

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
int CancellaLista(int counter);

/*Stampa lista*/
void StampaLista(int counter);

/*Stampa divisori grafici a schermo*/
void StampaGrafica();

#endif // LIB_LISTADINAMICA
