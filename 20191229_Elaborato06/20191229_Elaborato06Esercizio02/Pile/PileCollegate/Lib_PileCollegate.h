//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 22-12-2019
//Esercizio 2 - FILE HEADER
//Data di scadenza: 29-12-2019

#ifndef LIB_PILECOLLEGATE_H_INCLUDED
#define LIB_PILECOLLEGATE_H_INCLUDED

/*La PILA sarà composta da una sequenze di strutture di questo tipo collegate fra loro dal puntatore all'interno di ciascuna di esse*/
/*Il puntatore punta sempre all'elemento successivo. Il puntatore finale punterà al NULL*/
struct PILA
{
    int numero;
    struct PILA *next;
};

/*Stampa divisori grafici a schermo*/
void StampaGrafica();

/*Inserisci elemento*/
void Push(int num, struct PILA **ptr);

/*Eliminazione di un elemento*/
struct PILA *pop(struct PILA **ptr);

/*Eliminazione della PILA*/
void CancellaPila (struct PILA **ptr);

/*Stampa e cancella la PILA*/
void StampaPila(struct PILA **ptr, int counter);

#endif // LIB_PILECOLLEGATE_H_INCLUDED
