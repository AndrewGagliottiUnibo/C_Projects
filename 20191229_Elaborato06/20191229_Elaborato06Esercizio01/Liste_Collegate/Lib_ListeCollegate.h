//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 21-12-2019
//Esercizio 1 - FILE HEADER
//Data di scadenza: 29-12-2019

#ifndef LIB_LISTECOLLEGATE_H_INCLUDED
#define LIB_LISTECOLLEGATE_H_INCLUDED

/*La LISTA sarà composta da una sequenze di strutture di questo tipo collegate fra loro dal puntatore all'interno di ciascuna di esse*/
/*Il puntatore punta sempre all'elemento successivo. Il puntatore finale punterà al NULL*/
struct LISTA
{
    struct LISTA *prec;
    int numero;
    struct LISTA *next;
};

/*Stampa divisori grafici a schermo*/
void StampaGrafica();

/*Inserisci elemento in testa*/
void InserisciTesta (int num, struct LISTA **ptr);

/*Inserisci elemento in coda*/
void InserisciCoda (int num, struct LISTA **ptr);

/*Inserisci elemento in una posizione desiderata*/
void InserisciElem (int num, int posizione, struct LISTA **ptr);

/*Cancella elemento in testa*/
int CancellaTesta (struct LISTA **ptr);

/*Cancella elemento in coda*/
int CancellaCoda (struct LISTA **ptr);

/*Cancella occorrenze*/
int CancellaOccorrenza (int num, struct LISTA **ptr, int counterino);

/*Cancella lista*/
int CancellaLista(struct LISTA **ptr);

/*Stampa lista*/
void StampaLista(struct LISTA **ptr, int counterino);

#endif // LIB_LISTECOLLEGATE_H_INCLUDED
