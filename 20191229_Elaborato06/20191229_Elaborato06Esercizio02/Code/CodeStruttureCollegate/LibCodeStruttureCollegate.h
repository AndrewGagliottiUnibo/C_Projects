//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 23-12-2019
//Esercizio 2 - FILE HEADER
//Data di scadenza: 29-12-2019

#ifndef LIBCODESTRUTTURECOLLEGATE_H
#define LIBCODESTRUTTURECOLLEGATE_H

/*La CODA sarà composta da una sequenze di strutture di questo tipo collegate fra loro dal puntatore all'interno di ciascuna di esse*/
/*Il puntatore punta sempre all'elemento successivo. Il puntatore finale punterà al NULL*/
struct CODA
{
    int numero;
    struct CODA *next;
};

/*Inserisci elemento*/
void InserisciElemento(int num, struct CODA **ptr, struct CODA **ptr2);

/*Cancella coda*/
int CancellaCoda(struct CODA **ptr, struct CODA **ptr2);

/*Stampa coda*/
void StampaCoda(struct CODA **ptr, struct CODA **ptr2, int counterino);

/*Stampa divisori grafici a schermo*/
void StampaGrafica();

#endif // LIBCODESTRUTTURECOLLEGATE_H
