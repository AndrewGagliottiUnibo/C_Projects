//Authors: Andrew Gagliotti, Andrea Zacconi, Cristian Crescentini
//Date: 11-10-2019
//Esercizio 2
//Data di scadenza: 13-10-2019

//Per semplificare il lavoro di correzione ai professori divideremo il lavoro in 3 sezioni
//elencando poi quale parte di esercizio sarà svolta. Il termine di una parte verrà indicato dalla funzione system("pause");
//L'esercizio presenta 17 warnings perchè nella rappresentazione dell'overflow il compilatore ci avvisa del fatto che ci potrebbero essere degli errori di visualizzazione

#include <stdio.h>                                                  //Includiamo questa libreria per poter utilizzare la funzione printf();
#include <stdlib.h>                                                 //Includiamo questa libreria per poter utilizzare la funzione system("pause");
#include <math.h>                                                   //Includiamo questa libreria per poter utilizzare le funzioni matematiche al suo interno.
#include <time.h>                                                   //Includiamo questa libreria per poter utilizzare la funzione random.
#include <limits.h>                                                 //Includiamo questa libreria per poter riportare i valori di massimo e minimo delle varie variabili int e char
#include <float.h>                                                  //Includiamo questa libreria per poter riportare i valori di massimo e minimo delle varie variabili float e double
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Inizio esercizio 2


int main()
{

    //Parte 1: utilizzo di tutti gli operatori studiati
    int numerointero1, numerointero2, numerointero3, numeroRandom, y, a, b, c, f, g, h, i, l, m, n;         //Variabili usate nel corso dell'esercizio
    y = 0;                                                                                                  //y = 0 come valore iniziale, visto che va specificato per non fargli stampare un valore casuale
                                                                                                            //a e b serviranno poi per gli operatori
    numeroRandom = 1 + (rand()+time(NULL)) % 3;                                                             //formula matematica per la generazione di un numero random

    float x;
    //Scelta di 3 numeri interi da parte dell'utente
    printf("Parte 1: utilizzo degli operatori studiati:\n");
    printf("Utente, inserisci 3 numeri interi separati da uno spazio.\n\n");                                //scanf() serve per ricevere ed elaborare input da tastiera
    scanf("%d%d%d", &numerointero1, &numerointero2, &numerointero3);
    fflush(stdin);
    printf("\n\n");

    a = numerointero1;
    b = numerointero2;
    printf("Hai scelto %d %d %d\n\n\n\n\n", numerointero1, numerointero2, numerointero3);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Esempio dell'operatore assegnamento, assegnare un numero ad una variabile
    printf("Operatore assegnamento (=):\n");
    printf("Creata una variabile y, di valore %d\n", y);
    printf("Le assegnamo un valore di uno dei numeri che mi hai fornito prima: %d\n", numeroRandom);

    if(numeroRandom == 1)
        y = numerointero1;
    else if(numeroRandom == 2)
        y = numerointero2;
    else if(numeroRandom == 3)
        y = numerointero3;

    printf("Assegnamento random effettuato: y = %d\n\n\n\n", y);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Esempio di operatori matematici/aritmetici binari, operazioni tra due o più numeri
    printf("Operatori matematici/aritmetici binari:\n");
    printf("Questa e\' l'addizione tra i 3 numeri inseriti: %d\n", y = numerointero1 + numerointero2 + numerointero3);
    printf("Questa e\' la sottrazione tra i 3 numeri inseriti: %d\n", y = numerointero1 - numerointero2 - numerointero3);
    printf("Questa e\' la moltiplicazione tra i 3 numeri inseriti: %d\n", y = numerointero1 * numerointero2 * numerointero3);
    printf("Questa e\' la divisione tra i primi 2 numeri inseriti: %f\n", x = numerointero1 / numerointero2);
    printf("Questa e\' il resto tra i primi 2 numeri inseriti: %d\n\n\n\n", y = numerointero1 % numerointero2);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Esempio di operatori matematici/aritmetici unari, aumento o diminuisco di 1 un valore di una variabile
    printf("Operatori matematici/aritmetici unari:\n");
    printf("Prendiamo i primi due numeri inseriti e applicchiamo l'incremento rispettivamente prefisso e postfisso:\n");
    printf("Incremento prefisso di a = %d, incremento postfisso di b = %d\n", ++a, b++);                                        //a prima viene incrementato e poi visualizzato, b prima viene visualizzato e poi incrementato
    printf("Valori finali di a e b = %d, %d\n", a, b);

    a = numerointero1;                                                                                                          //resettiamo i valori di a e b
    b = numerointero2;
    printf("Prendiamo i primi due numeri inseriti e applicchiamo il decremento rispettivamente prefisso e postfisso:\n");
    printf("Decremento prefisso di a = %d, incremento postfisso di b = %d\n", --a, b--);                                        //a prima viene decremento e poi visualizzato, b prima viene visualizzato e poi decrementato
    printf("Valori finali di a e b = %d, %d\n\n\n\n", a, b);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Esempio di operatori compatti
    y = numerointero2;                                                                                                           //resettiamo il valore di y
    printf("Operatori matematici/aritmetici compatti:\n");
    printf("L'addizione compatta della variabile y con il primo numero inserito: y += a da come risultato %d\n", y += numerointero1);
    y = numerointero2;
    printf("La sottrazione compatta della variabile y con il primo numero inserito: y -= a da come risultato %d\n", y -= numerointero1);
    y = numerointero2;
    printf("La moltiplicazione compatta della variabile y con il primo numero inserito: y *= a da come risultato %d\n", y *= numerointero1);
    y = numerointero2;
    printf("La divisione compatta della variabile y con il primo numero inserito: y /= a da come risultato %d\n", y /= numerointero1);
    y = numerointero2;
    printf("Il resto compatto della variabile y con il primo numero inserito: y 0/0= a da come risultato %d\n\n\n\n", y %= numerointero1);      //Sono costretto a scrivere 0/0 perchè mi darebbe un warning in quanto % è un carattere speciale
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Esempio di operatore virgola
    printf("Operatore virgola:\n");
    printf("L'operatore virgola serve per separare delle sottoespressioni all'interno di una espressione:\n");
    a = numerointero1;                                                                                                        //resetto i valori di a e b e specifico una variabile c
    b = numerointero2;
    c = numerointero3;
    y = (a++, b--, c++);

    printf("Data l'espressione y = (a++, b--, c++), y assumera\' il valore: %d\n", y);
    printf("a, b, c alla fine varranno rispettivamente: %d, %d, %d. \n", a, b, c);
    printf("L'espressione verra\' risolta da sinistra a destra ma ad y verra\' assegnato il valore di c, ovvero l'operatore piu' a destra.\n\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Esempio di operatori relazionali, relazioni logiche tra due o più variabili
    printf("Operatori relazionali:\n");
    printf("Inserisci 4 numeri, due uguali fra loro e due diversi da questi, separati fra loro da uno spazio:\n\n");          //scanf di nuovo per ricevere ed elaborare input da tastiera
    scanf("%d %d %d %d", &f, &g, &h, &i);
    fflush(stdin);
    printf("\n\n");
    printf("Dati i 4 numeri: %d, %d, %d, %d; indico le varie relazione che li legano:\n\n", f, g, h, i);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Maggioranza tra almeno due (>):\n");                                                                              //Da questo momento in poi concateneremo una serie di if, else if ed else per ottenere la corretta visualizzazione logica
    if (f > g)                                                                                                                //if per la maggioranza
        printf("%d e\' maggiore (>) di %d\n\n\n", f, g);
    else if (f > h)
        printf("%d e\' maggiore (>) di %d\n\n\n", f, h);
    else if (f > i)
        printf("%d e\' maggiore (>) di %d\n\n\n", f, i);
    else if (g > f)
        printf("%d e\' maggiore (>) di %d\n\n\n", g, f);
    else if (g > h)
        printf("%d e\' maggiore (>) di %d\n\n\n", g, h);
    else if (g > i)
        printf("%d e\' maggiore (>) di %d\n\n\n", g, i);
    else if (h > g)
        printf("%d e\' maggiore (>) di %d\n\n\n", h, f);
    else if (h > g)
        printf("%d e\' maggiore (>) di %d\n\n\n", h, g);
    else if (h > i)
        printf("%d e\' maggiore (>) di %d\n\n\n", h, i);
    else if (i > f)
        printf("%d e\' maggiore (>) di %d\n\n\n", i, f);
    else if (i > g)
        printf("%d e\' maggiore (>) di %d\n\n\n", i, g);
    else if (i > h)
        printf("%d e\' maggiore (>) di %d\n\n\n", i, h);
    else
        printf("Tutti i numeri sono uguali fra loro.\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Minoranza tra almeno due (<):\n");
    if (f < g)                                                                                                                                       //if per la minoranza
        printf("%d e\' minore (<) di %d\n\n\n", f, g);
    else if (f < h)
        printf("%d e\' minore (<) di %d\n\n\n", f, h);
    else if (f < i)
        printf("%d e\' minore (<) di %d\n\n\n", f, i);
    else if (g < f)
        printf("%d e\' minore (<) di %d\n\n\n", g, f);
    else if (g < h)
        printf("%d e\' minore (<) di %d\n\n\n", g, h);
    else if (g < i)
        printf("%d e\' minore (<) di %d\n\n\n", g, i);
    else if (h < g)
        printf("%d e\' minore (<) di %d\n\n\n", h, f);
    else if (h < g)
        printf("%d e\' minore (<) di %d\n\n\n", h, g);
    else if (h < i)
        printf("%d e\' minore (<) di %d\n\n\n", h, i);
    else if (i < f)
        printf("%d e\' minore (<) di %d\n\n\n", i, f);
    else if (i < g)
        printf("%d e\' minore (<) di %d\n\n\n", i, g);
    else if (i < h)
        printf("%d e\' minore (<) di %d\n\n\n", i, h);
    else
        printf("Tutti i numeri sono uguali fra loro.\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Maggioranza o uguaglianza tra almeno due (>=):\n");
    if (f >= g)                                                                                                                                         //if per la maggioranza o uguaglianza
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", f, g);
    else if (f >= h)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", f, h);
    else if (f >= i)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", f, i);
    else if (g >= f)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", g, f);
    else if (g >= h)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", g, h);
    else if (g >= i)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", g, i);
    else if (h >= f)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", h, f);
    else if (h >= g)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", h, g);
    else if (h >= i)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", h, i);
    else if (i >= f)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", i, f);
    else if (i >= g)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", i, g);
    else if (i >= h)
        printf("%d e\' maggiore o uguale (>=) a %d\n\n\n", i, h);
    else
        printf("Nessuno dei numeri inseriti e\' maggiore o uguale ad un altro (>=)\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Minoranza o uguaglianza tra almeno due (<=):\n");
   if (f <= g)                                                                                                                                          //if per la minoranza o uguaglianza
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", f, g);
    else if (f <= h)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", f, h);
    else if (f <= i)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", f, i);
    else if (g <= h)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", g, h);
    else if (g <= i)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", g, i);
    else if (g <= f)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", g, f);
    else if (h <= f)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", h, f);
    else if (h <= g)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", h, g);
    else if (h <= i)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", h, i);
    else if (i <= f)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", i, f);
    else if (i <= g)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", i, g);
    else if (i <= h)
        printf("%d e\' minore o uguale (<=) a %d\n\n\n", i, h);
    else
        printf("Nessuno dei numeri inseriti è minore o uguale ad un altro (>=)\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Uguaglianza (==):\n");
    if (f == g && g == h && h == i)                                                                                                                     //if per l'uguaglianza e piccola anticipazione degli operatori logici
       printf("Tutti i numeri sono uguali fra loro.\n\n\n\n\n");
    else if (f == g)
        printf("Almeno 2 numeri: %d e %d sono uguali fra loro (==)\n\n\n\n\n", f, g);
    else if (f == h)
        printf("Almeno 2 numeri: %d e %d sono uguali fra loro (==)\n\n\n\n\n", f, h);
    else if (f == i)
        printf("Almeno 2 numeri: %d e %d sono uguali fra loro (==)\n\n\n\n\n", f, i);
    else if (g == h)
        printf("Almeno 2 numeri: %d e %d sono uguali fra loro (==)\n\n\n\n\n", g, h);
    else if (g == i)
        printf("Almeno 2 numeri: %d e %d sono uguali fra loro (==)\n\n\n\n\n", g, i);
    else if (h == i)
        printf("Almeno 2 numeri: %d e %d sono uguali fra loro (==)\n\n\n\n\n", h, i);
    else
        printf("Nessun numero e\' uguale ad un altro.\n\n\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Esempi di operatori logici
    printf("Operatori Logici:\n");                                                                                                                      //scanf di nuovo per ricevere ed elaborare input da tastiera
    printf("Inserisci 3 numeri interi a caso, ognuno separato da uno spazio da un altro, per visualizzare 3 esempi con gli operatori logici:\n\n");
    scanf("%d %d %d", &l, &m, &n);
    fflush(stdin);
    printf("\n\n");

    printf("Hai inserito %d %d %d\n\n\n", l, m, n);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("AND logico (&&):\n");                                                                                                                       //if per visualizzazione dei vari AND logici possibili
    if (l > 0 && m > 0 && n > 0)
        printf("Hai inserito degli interi positivi perche\': l > 0 && m > 0 && n > 0\n\n\n");
    else if (l < 0 && m > 0 && n > 0)
        printf("%d e' l'unico intero negativo perche\': l < 0 && m > 0 && n > 0\n\n\n", l);
    else if (l > 0 && m < 0 && n > 0)
        printf("%d e' l'unico intero negativo perche\': l > 0 && m < 0 && n > 0\n\n\n", m);
    else if (l > 0 && m > 0 && n < 0)
        printf("%d e' l'unico intero negativo perche\': l > 0 && m > 0 && n < 0\n\n\n", n);
    else if (l < 0 && m > 0 && n < 0)
        printf("%d e' l'unico intero positivo perche\': l < 0 && m > 0 && n < 0\n\n\n", m);
    else if (l < 0 && m < 0 && n > 0)
        printf("%d e' l'unico intero positivo perche\': l < 0 && m < 0 && n > 0 \n\n\n", n);
    else if (l > 0 && m < 0 && n < 0)
        printf("%d e' l'unico intero positivo perche\': l > 0 && m < 0 && n < 0\n\n\n", l);
    else if (l < 0 && m < 0 && n < 0)
        printf("Hai inserito degli interi negativi perche\': l < 0 && m < 0 && n < 0\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("OR logico (||)\n");                                                                                                                         //if per visualizzare dei vari OR logici possibili
    if ((l > 0 && m < 0 && n > 0) || (l < 0 && m > 0 && n > 0) || (l > 0 && m > 0 && n < 0))
        printf("Almeno due numeri inseriti sono interi positivi perche\': (l > 0 && m < 0 && n > 0) || (l < 0 && m > 0 && n > 0) || (l > 0 && m > 0 && n < 0)\n\n\n");
    else if ((l < 0 && m > 0 && n < 0) || (l < 0 && m < 0 && n > 0) || (l > 0 && m < 0 && n < 0))
        printf("Almeno uno dei numeri inseriti e\' positivo perche\': (l < 0 && m > 0 && n < 0) || (l < 0 && m < 0 && n > 0) || (l > 0 && m < 0 && n < 0)\n\n\n");
    else if ((l > 0 && m > 0 && n > 0) || (l < 0 && m < 0 && n < 0))
        printf("Tutti i numeri inseriti hanno lo stesso segno perche\': (l > 0 && m > 0 && n > 0) || (l < 0 && m < 0 && n < 0)\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
                                                                                                                                            //if per la visualizzazione dei vari NOT logici
    printf("NOT logico (!)\n");                                                                                                             //Solo questi due esempi perchè incastarare più operatori logici porterebbe alla valutazione in corto circuito
    if ((l < 0 && m > 0 && n < 0) || (l < 0 && m < 0 && n > 0) || (l > 0 && m < 0 && n < 0) || (l > 0 && m < 0 && n > 0) || (l < 0 && m > 0 && n > 0) || (l > 0 && m > 0 && n < 0))                                                                                                 //e quindi quella più interna prevarrebbe sul NOT logico
        printf("Almeno un numero e\' discordante di segno da un altro.\n\n\n\n\n");
    else if (!((l < 0 && m < 0 && n < 0)))
        printf("I numeri inseriti sono tutti concordi e positivi fra di loro perche\': !(l < 0 && m < 0 && n < 0)\n\n\n\n\n");
    else if (!(l > 0 && m > 0 && n > 0))
        printf("I numeri inseriti sono tutti concordi e negativi fra di loro perche\': !(l > 0 && m > 0 && n > 0)\n\n\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Esempi di operatori sizeof() e casting()
    int numero1 = 10, numero2 = 3, numeroint;                                                                                       //Riporto alcune variabili che ci serviranno qui in questo contesto
    float numerofloat;                                                                                                              //L’assegnamento di un tipo di dato ad un tipo più piccolo può causare troncamento o overflow, qui faremo un esempio semplice, dettagli nella seconda parte
    numerofloat = (float)numero1 / (float)numero2;
    numeroint = numero1 / numero2;

    printf("Operatori sizeof() e casting():\n\n");
    printf("Il primo ci permette di determinare quanta memoria viene richiesta per memorizzare un valore di un particolare tipo di variabile:\n");
    printf("Esempio: Byte richiesti per una variabile di tipo int: %d\n\n",sizeof(int));                                             //usiamo sizeof() per visualizzare i byte richiesti

    printf("Il secondo ci permette di forzare un espressione di una variabile come se fosse di un altro tipo:\n");                   //(tipo) espressione
    printf("Esempio:\n");
    printf("Il risultato delle espressione %d/%d espressa in int e\' %d, in float e\' uguale a: %f\n\n\n\n\n", numero1, numero2, numeroint, numerofloat);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Esempi di operatori bitwise
    printf("Operatori bitwise.\n");                                                                                                   //Servono per spostare o controllare i bit delle word o dei byte corrispondenti ai tipi char e int
    printf("AND logico bit a bit tra due o piu\' operandi (&):\n");
    printf("x = 0 0 1 1 1 1 1 1 0 1 0 1 0 0 1 0    &\ny = 1 0 0 1 1 0 1 1 0 1 1 0 0 1 1 1\nDa\'come risultato 1 per ciascuna posizione se entrambi i valori presentano 1:\n\nx&y = 0 0 0 1 1 0 1 1 0 1 0 0 0 0 1 0\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("OR logico bit a bit tra due o piu\' operandi (|):\n");
    printf("x = 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1 1    |\ny = 1 1 1 0 1 1 1 1 0 0 0 0 1 0 0 1\nDa\'come risultato 1 per ciascuna posizione se almeno uno presenta un 1:\n\nx|y = 1 1 1 0 1 1 1 1 1 1 0 1 1 0 1 1\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("XOR logico bit a bit tra due o piu\' operandi (^):\n");
    printf("x = 1 1 1 0 1 0 0 0 1 1 0 1 0 0 0 1    ^\ny = 0 1 0 1 1 0 0 1 0 0 0 1 0 0 1 1\nDa\'come risultato 1 per ciascuna posizione solo se x presenta un 1:\n\nx^y = 1 0 1 1 0 0 0 1 1 1 0 0 0 0 1 0\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Complemento a 1 di un operando (~):\n");
    printf("x = 1 0 1 1 0 0 1 0 1 0 0 1 1 1 0 0 \nE\' l'inverso dell'operando in bit.\n\n~x = 0 1 0 0 1 1 0 1 0 1 1 0 0 0 1 1\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Shift a destra di un operando per un numero di bit pari al valore a destra dell'operatore (>>):\n");
    printf("x = 1 0 1 1 1 0 0 0\nAd esempio con x >> 6, si perdono i primi 6 bit a destra e si aggiungono 6 zeri a sinistra:\n\nx >> 3 = 0 0 0 0 0 0 0\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Shift a sinistra di un operando per un numero di bit pari al valore a destra dell'operatore (<<):\n");
    printf("x = 0 0 1 0 1 1 1 0 1 0 1 1 0 1 1 1\nAd esempio con x << 5, si perdono i primi 5 bit a sinistra e si aggiungono 5 zeri a destra\':\n\nx << 4 = 1 1 0 1 0 1 1 0 1 1 1 0 0 0 0 0\n\n\n\n\n");



    system("pause");
    printf("\n\n\n\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Parte 2: tipi non adatti alle dimensioni delle variabili, side effects tra operatori all'interno di un'espressione, regole di conversione implicita, overflow di range per i tipi di dato
    //Nella sezione dei tipi non appropriati delle variabili, non utiliziamo il long int perche' in 3 macchine diverse in cui abbiamo lavorato i tipi int e long int hanno la stessa estensione in memoria, dunque non da errore di conversione
    int NumeroInt01 = 32000, NumeroInt02 = 50000, NumeroInt03 = 200000567, NumeroInt04 = 2000000004, NumeroInt05 = 2147483000;
    short int NumeroShortInt1 = 31000, NumeroShortInt2 = 23000;
    unsigned int NumeroUInt1 = 429496700, NumeroUInt2 = 9990;
    unsigned short int NumeroUSInt1 = 65000, NumeroUSInt2 = 998;

    printf("Parte 2: tipi non adatti alle dimensioni delle variabili, side effects, conversioni implicite, overflow di range.\n");
    printf("Seguono alcuni esempi di somme che vengono visualizzate errate perche' espresse con un tipo di variabile dal valore limitato.\n");
    short int somma1 = NumeroInt01 + NumeroInt02;                                                                           //somma errata di 2 interi convertita in short, superamento limite variabile(short: int + int)
    printf("Somma errata di 2 interi convertita in short: %d + %d = %d\n\n", NumeroInt01, NumeroInt02, somma1);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    short int somma2 = NumeroShortInt1 + NumeroShortInt2;                                                                   //somma errata di 2 short, superamento limite variabile(short: short + short)
    printf("Somma errata di 2 short: %d + %d = %d\n\n", NumeroShortInt1, NumeroShortInt2, somma2);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    short int somma3 = NumeroShortInt1 + NumeroInt03;                                                                       //somma errata di 1 short ed 1 int, superamento limite variabile(short: short + int)
    printf("Somma errata di 1 short ed 1 int: %d + %d = %d\n\n", NumeroShortInt1, NumeroInt03, somma3);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    int somma4 = NumeroInt03 + NumeroInt04;                                                                                 //somma errata di 2 interi, superamento limite variabile(int: int + int)
    printf("Somma errata di 2 interi: %d + %d = %d\n\n", NumeroInt03, NumeroInt04, somma4);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    int somma5 = NumeroInt05 + NumeroShortInt2;                                                                             //somma errata di 1 short ed 1 int, superamento limite variabile(int: short + int)
    printf("Somma errata di 1 short ed 1 int: %d + %d = %d\n\n", NumeroInt05, NumeroShortInt2, somma5);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    unsigned int somma6 =  NumeroUInt1 + NumeroInt03;                                                                       //somma errata di 1 unsigned int ed 1 int, superamento limite variabile(unsigned int: unsigned int + int)
    printf("Somma errata di 1 unsigned int ed 1 int: %d + %d = %d\n\n", NumeroUInt1, NumeroInt03, somma6);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    unsigned int somma7 = NumeroShortInt1 + NumeroUInt1;                                                                    //somma errata di 1 unsigned int ed 1 short int, superamento limite variabile(unsigned int: unsigned int + short int)
    printf("Somma errata di 1 unsigned int ed 1 short int: %d + %d = %d\n\n", NumeroShortInt1, NumeroUInt1, somma7);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    unsigned int somma8 =  NumeroUInt1 + NumeroUInt2;                                                                       //somma errata di 2 unsigned int, superamento limite variabile(unsigned int: unsigned int + unsigned int)
    printf("Somma errata di 2 unsigned int: %d + %d = %d\n\n", NumeroUInt1, NumeroUInt2, somma8);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    unsigned short int somma9 = NumeroUSInt1 + NumeroInt01;                                                                 //somma errata di 1 unsigned short int e di 1 int, superamento limite variabile(unsigned short int: unsigned short int + int)
    printf("Somma errata di 1 unsigned short int e di 1 int: %d + %d = %d\n\n", NumeroUSInt1, NumeroInt01, somma9);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    unsigned short int somma10 = NumeroShortInt1 + NumeroUSInt1;                                                            //somma errata di 1 short int e di un unsigned short int, superamento limite variabile(unsigned short int: short int + unsigned short int)
    printf("Somma errata di 1 short int e di un unsigned short int: %d + %d = %d\n\n", NumeroShortInt1, NumeroUSInt1, somma10);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    unsigned short int somma11 = NumeroUSInt2 + NumeroUSInt1;                                                               //somma errata di 2 unsigned short int, superamento limite variabile(unsigned short int: unsigned short int + unsigned short int)
    printf("Somma errata di 2 unsigned short int: %d + %d = %d\n\n\n\n", NumeroUSInt2, NumeroUSInt1, somma11);

    system("pause");
    printf("\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Side effects all'interno di espressioni con diversi operatori
    printf("Side effects nell'assegnamento:\n\n\n\n");

    int r = 3, s = 4, z = 0, t = 5;                                                                                                                             //variabili usate nella parte di esercizio
    printf("In un assegnamento in cui bisogna far precedere un incremento o decremento, puo' non essere chiaro il risultato se si scrive: r = r++\n");
    printf("Ci potranno essere due possibili risultati:\n");
    printf("Se r prima viene incrementato e poi visualizzato, cioe' se si vuole intendere r = (r++)..., si avra': r = %d\n\n", ++r);
    r = 3;                                                                                                                                                      //ogni volta che dichiariamo a lo facciamo per resettarne il valore ed evitare problemi
    printf("Se r prima viene valutato e poi incrementato, scrivendolo in forma r = r++..., si avra': r = %d\n", r++);
    printf("r prima viene visualizzato e poi incrementato, infatti ora r sara': %d\n\n\n\n\n\n", r);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;                                                                                                                                                      //operatori unari in relazione con i binari
    printf("Side effects tra incrementi o decrementi unari addizionati ad operatori binari.\n");
    //Gli esempi seguenti riportano solo i decrementi ed incrementi postfissi...con i prefissi non si presentano fenomeni di side effects nei calcoli che sono indicati a seguito
    printf("Tutti i seguenti casi riportano una situazione di incremento e decremento postfisso. La scelta e' giutificata dal fatto che l'operazione unaria prefissa non genera side effects in queste situazioni. Esempio:\n");
    printf("Nella espressione: ++r *s il risultato verra' calcolato normalmente e sara' z = %d\n\n\n", z = ++r * s);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Con gli incrementi:\n");                                                                                                                            //incrementi unari
    printf("Il compilatore segue delle regole di precedenza nella valuazione degli operatori. Nei seguenti casi, verranno prima valutati gli incrementi unari e poi altre operazioni:\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso delle addizioni:\n");                                                                                                                      //addizione
    printf("L'espressione z = r++ + s puo' avere diverse soluzioni a seconda di come la si vuole far intendere:\n");
    printf("In questa forma viene visualizzata l'addizione con r prima dell'incremento e poi l'incremento stesso. Nella espressione z = %d, r = %d (r prima usato e poi incrementato)\n", z = r + s, r);
    r = 3;
    z = 0;                                                                                                                                                      //ogni volta che dichiariamo x lo facciamo per resettarne il valore ed evitare problemi
    ++r;
    printf("Se si vuole intendere  z = (r++) + s  viene svolto prima l'incremento e poi la moltiplicazione: z = %d e r = %d\n\n", z = r + s, r);
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso delle sottrazioni:\n");                                                                                                                    //sottrazione
    printf("L'espressione z = r++ - s puo' avere diverse soluzioni a seconda di come la si vuole far intendere:\n");
    printf("In questa forma viene visualizzata l'addizione con r prima dell'incremento e poi l'incremento stesso. Nella espressione z = %d, r = %d (r prima usato e poi incrementato)\n", z = r - s, r);
    r = 3;
    z = 0;
    ++r;
    printf("Se si vuole intendere  z = (r++) - s  viene svolto prima l'incremento e poi la moltiplicazione: z = %d e r = %d\n\n", z = r - s, r);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso della moltiplicazione:\n");                                                                                                                //moltiplicazione
    printf("L'espressione z = r++ * s puo' avere diverse soluzioni a seconda di come la si vuole far intendere:\n");
    printf("In questa forma viene visualizzata la moltiplicazione con r prima dell'incremento e poi l'incremento stesso. Nella espressione z = %d, r = %d (r prima usato e poi incrementato)\n", z = r * s, r);
    r = 3;
    z = 0;
    ++r;
    printf("Se si vuole intendere  z = (r++) * s  viene svolto prima l'incremento e poi la moltiplicazione: z = %d e r = %d\n\n", z = r * s, r);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso della divisione:\n");                                                                                                                      //divisione
    printf("L'espressione z = r++ / s puo' avere diverse soluzioni a seconda di come la si vuole far intendere:\n");
    printf("In questa forma viene visualizzata la divisione con r prima dell'incremento e poi l'incremento stesso. Nella espressione z = %d, r = %d (r prima usato e poi incrementato)\n", z = r / s, r);
    r = 3;
    z = 0;
    ++r;
    printf("Se si vuole intendere  z = (r++) / s  viene svolto prima l'incremento e poi la divisione: z = %d e r = %d\n\n\n\n", z = r / s, r);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso del resto:\n");                                                                                                                            //resto
    printf("L'espressione z = r++ 0/0 s puo' avere diverse soluzioni a seconda di come la si vuole far intendere:\n");
    printf("In questa forma viene visualizzato il resto con r prima dell'incremento e poi l'incremento stesso. Nella espressione z = %d, r = %d (r prima usato e poi incrementato)\n", z = r % s, r);
    r = 3;
    z = 0;
    ++r;
    printf("Se si vuole intendere  z = (r++) 0/0 s  viene svolto prima l'incremento e poi la divisione: z = %d e r = %d\n\n\n\n", z = r % s, r);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Con i decrementi:\n");                                                                                                                              //decrementi unari
    printf("Il compilatore segue delle regole di precedenza nella valuazione degli operatori. Nei seguenti casi, verranno prima valutati i decrementi unari e poi altre operazioni:\n\n");
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso delle addizioni:\n");                                                                                                                       //addizione
    printf("L'espressione z = r-- + s puo' avere diverse soluzioni a seconda di come la si vuole far intendere:\n");
    printf("In questa forma viene visualizzata l'addizione con r prima dell'incremento e poi l'incremento stesso. Nella espressione z = %d, r = %d (r prima usato e poi incrementato)\n", z = r + s, r);
    r = 3;
    z = 0;
    --r;
    printf("Se si vuole intendere  z = (r--) + s  viene svolto prima l'incremento e poi la moltiplicazione: z = %d e r = %d\n\n", z = r + s, r);
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso delle sottrazioni:\n");                                                                                                                    //sottrazioni
    printf("L'espressione z = r-- - s puo' avere diverse soluzioni a seconda di come la si vuole far intendere:\n");
    printf("In questa forma viene visualizzata l'addizione con r prima dell'incremento e poi l'incremento stesso. Nella espressione z = %d, r = %d (r prima usato e poi incrementato)\n", z = r - s, r);
    r = 3;
    z = 0;
    --r;
    printf("Se si vuole intendere  z = (r--) - s viene svolto prima l'incremento e poi la moltiplicazione: z = %d e a = %d\n\n", z = r - s, r);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso della moltiplicazione:\n");                                                                                                                //moltiplicazione
    printf("L'espressione z = r-- * s puo' avere diverse soluzioni a seconda di come la si vuole far intendere:\n");
    printf("In questa forma viene visualizzata la moltiplicazione con r prima del decremento e poi il decremento stesso. Nella espressione z = %d, r = %d (r prima usato e poi decrementato)\n", z = r * s, r);
    r = 3;
    z = 0;
    --r;
    printf("Se si vuole intendere  z = (r--) * s  viene svolto prima il decremento e poi la moltiplicazione: z = %d e r = %d\n\n", z = r * s, r);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso della divisione:\n");                                                                                                                      //divisione
    printf("L'espressione z = r-- / s puo' avere diverse soluzioni a seconda di come la si vuole far intendere:\n");
    printf("In questa forma viene visualizzata la divisione con r prima del decremento e poi il decremento stesso. Nella espressione z = %d, r = %d (r prima usato e poi decrementato)\n", z = r / s, r);
    r = 3;
    z = 0;
    --r;
    printf("Se si vuole intendere  z = (r--) / s  viene svolto prima il decremento e poi la divisione: z = %d e r = %d\n\n\n\n", z = r / s, r);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso del resto:\n");                                                                                                                            //resto
    printf("L'espressione z = r-- 0/0 s puo' avere diverse soluzioni a seconda di come la si vuole far intendere:\n");
    printf("In questa forma viene visualizzato il resto con r prima del decremento e poi il decremento stesso. Nella espressione z = %d, r = %d (r prima usato e poi decrementato)\n", z = r % s, r);
    r = 3;
    z = 0;
    --r;
    printf("Se si vuole intendere  z = (r--) 0/0 s  viene svolto prima il decremento e poi la divisione: z = %d e r = %d\n\n\n\n", z = r % s, r);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Side effects nelle espressioni complesse (addizione):\n");                                                                                          //addizione combinata con operandi a priorità maggiore
    printf("Il compilatore segue delle regole di precedenza nella valuazione degli operatori. Nei seguenti casi, verranno prima valutati moltiplicazioni, divisioni, resto e poi le somme algebriche:\n\n\n\n\n");
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    r = 3;
    z = 0;
    printf("Nel caso della moltiplicazione:\n");                                                                                                                //moltiplicazione
    printf("L'espressione z = r + s * t ha un'unica soluzione, pero' magari noi la volevamo intendere in modo diverso da come l'abbiamo scritta:\n");
    printf("In questa forma viene risolta la moltiplicazione tra s e t prima che avvenga la somma. l'espressione dunque risultera': z = r + (s * t) = %d\n\n", z = r + (s * t));
    z = 0;
    printf("Se si vuole intendere  z = (r + s) * t  viene svolta prima la somma e poi la moltiplicazione, dunque: r = %d\n\n\n", z = (r + s) * t);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    z = 0;
    printf("Nel caso della divisione:\n");                                                                                                                      //divisione
    printf("L'espressione z = r + s / t ha un'unica soluzione, pero' magari noi la volevamo intendere in modo diverso da come l'abbiamo scritta:\n");
    printf("In questa forma viene risolta la divisione tra s e t prima che avvenga la somma. l'espressione dunque risultera': z = r + (s / t) = %d\n\n", z = r + (s / t));
    z = 0;
    printf("Se si vuole intendere  z = (s + r) / t  viene svolta prima la somma e poi la divisione, dunque: z = %d\n\n\n", z = (r + s) / t);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    z = 0;
    printf("Nel caso del resto:\n");                                                                                                                            //resto
    printf("L'espressione z = r + s 0/0 t ha un'unica soluzione, pero' magari noi la volevamo intendere in modo diverso da come l'abbiamo scritta:\n");
    printf("In questa forma viene risolto il resto tra s e t prima che avvenga la somma. l'espressione dunque risultera': z = r + (s 0/0 t) = %d\n\n", z = r + (b % t));
    z = 0;
    printf("Se si vuole intendere  z = (r + s) 0/0 t  viene svolta prima la somma e poi il resto, dunque: z = %d\n\n\n", z = (r + s) % t);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Side effects nelle espressioni complesse (sottrazione):\n");                                                                                        //sottrazione combinata con operandi a priorità maggiore
    printf("Il compilatore segue delle regole di precedenza nella valuazione degli operatori. Nei seguenti casi, verranno prima valutati moltiplicazioni, divisioni, resto e poi le somme algebriche:\n\n\n\n\n");
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    z = 0;
    printf("Nel caso della moltiplicazione:\n");                                                                                                                //moltiplicazione
    printf("L'espressione z = r - s * t ha un'unica soluzione, pero' magari noi la volevamo intendere in modo diverso da come l'abbiamo scritta:\n");
    printf("In questa forma viene risolta la moltiplicazione tra s e t prima che avvenga la somma. l'espressione dunque risultera': z = r - (s * t) = %d\n\n", z = r - (s * t));
    z = 0;
    printf("Se si vuole intendere  z = (r - s) * t  viene svolta prima la somma e poi la moltiplicazione, dunque: z = %d\n\n\n", z = (r - s) * t);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    z = 0;
    printf("Nel caso della divisione:\n");                                                                                                                      //divisione
    printf("L'espressione r = r - s / t ha un'unica soluzione, pero' magari noi la volevamo intendere in modo diverso da come l'abbiamo scritta:\n");
    printf("In questa forma viene risolta la divisione tra s e t prima che avvenga la somma. l'espressione dunque risultera': z = r - (s / t) = %d\n\n", z = r - (s / t));
    z = 0;
    printf("Se si vuole intendere  z = (r - s) / t  viene svolta prima la somma e poi la divisione, dunque: z = %d\n\n\n", z = (r - s) / t);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    z = 0;
    printf("Nel caso del resto:\n");                                                                                                                            //resto
    printf("L'espressione z = r - s 0/0 t ha un'unica soluzione, pero' magari noi la volevamo intendere in modo diverso da come l'abbiamo scritta:\n");
    printf("In questa forma viene risolto il resto tra s e t prima che avvenga la somma. l'espressione dunque risultera': z = r - (s 0/0 t) = %d\n\n", z = r - (s % t));
    z = 0;
    printf("Se si vuole intendere  z = (r - s) 0/0 t  viene svolta prima la somma e poi il resto, dunque: z = %d\n\n\n", z = (r - s) % t);
    system("pause");
    printf("\n\n\n");
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Regole di conversione implicita
    int VariabileInt = 5.0, VariabileSommaInt;
    float VariabileFloat = 6, VariabileSommaFloat;
    char VariabileChar = 'a', VariabileSommaChar;

    //Conversione Float/Int con Variabili(Questa conversione avviene anche con gli altri tipi di variabili come: double, long int, shrt int ecc.)
    printf("In questo esercizio verra' visualizzata la conversione implicita da parte del compilatore!\n");
    printf("Alcuni esempi di conversione implicita sono:\n\n");
    printf("1)Conversione delle variabili:\n");
    printf("-Data la variabile a(Float), se gli viene assegnato un valore intero, nellla funzione printf verra' stampato il suo attuale valore ma convertito in float(Lo stesso vale per la sua controparte Int)!\n");
    printf("Esempio: a(Float) = 6(Senza virgola), il printf stampera': %.2f\n", VariabileFloat);
    printf("Esempio: a(Int) = 5.00, il printf stampera': %d\n\n", VariabileInt);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Conversione Float/Int con Operazioni(Questa conversione avviene anche con tutti gli alti tipi di operazioni e funzioni matematiche come: -, *, /, % ecc.)
    printf("2)Conversione Float/Int nelle operazioni matematiche:\n");
    printf("-Data una variabile a(Int), ed una variabile b(Float), se sommiamo entrambe le variabili s = a + b, oppure eseguiamo a = a + b, il compilatore attuera' una conversione implicita:\n");
    VariabileInt = 6, VariabileFloat = 5.0;
    VariabileSommaInt = VariabileFloat + VariabileInt;
    VariabileSommaFloat = VariabileFloat + VariabileInt;
    printf("Esempio: a(Int) = %d, b(Float) = %.2f, se eseguiamo la somma s(Int) = a + b, il printf stampera': %d\n", VariabileInt, VariabileFloat, VariabileSommaInt);
    printf("Esempio: a(Int) = %d, b(Float) = %.2f, se eseguiamo la somma s(Float) = a + b, il printf stampera': %.2f\n", VariabileInt, VariabileFloat, VariabileSommaFloat);
    VariabileSommaInt = VariabileInt;
    VariabileSommaInt = VariabileSommaInt + VariabileFloat;
    printf("Esempio: a(Int) = %d, b(Float) = %.2f, se eseguiamo la somma a(Int) = a + b, il printf stampera': %d\n", VariabileInt, VariabileFloat, VariabileSommaInt);
    VariabileSommaFloat = VariabileFloat;
    VariabileSommaFloat = VariabileSommaFloat + VariabileInt;
    printf("Esempio: a(Int) = %d, b(Float) = %.2f, se eseguiamo la somma b(float) = b + a, il printf stampera': %.2f\n\n", VariabileInt, VariabileFloat, VariabileSommaFloat);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Conversione Char/Int(Se il valore INT supera il valore della tabella ASCII, il printf stampa un carattere speciale)
    printf("3)Conversione Char/Int:\n");
    printf("-Data una variabile c(Char), se eseguiamo un qualsiasi operazione tra un CHAR(NON LE STRINGHE) ed un INT, l'evento della conversione implicita avverra':\n");
    VariabileSommaChar = VariabileChar + VariabileInt;
    printf("Esempio: c(Char) = %c, a(Int) = %d, se eseguiamo la samma c = c + a, il printf stampera': %c(basandosi sul valore del codice ASCII), mentre: %d(se vogliamo fare semplicemente la somma)\n\n\n", VariabileChar, VariabileInt, VariabileSommaChar, VariabileSommaChar);
    system("pause");
    printf("\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Overflow dei limiti di range
    //Prima specifichiamo le variabili che andremo ad utilizzare
    printf("Overflow per i tipi di dato:\n\n");
    int OverInt1 = 3208490237328783, OverInt2 = INT_MIN -30843827489327432894;
    short int OverShortInt1 = 32047230947, OverShortInt2 = -76432738487234;
    long int OverLongInt1 = 234243423423432423423, OverLongInt2 = 23432423423423443;
    unsigned int OverUnsignedInt = 234234234324424323442;
    unsigned short int OverUnsignedShortInt = 324234324234234234324423;
    unsigned long int OverUnsignedLongInt = 324324324234324234234;
    float OverFloat1 = FLT_MAX + 1, OverFloat2 = FLT_MIN - 1;
    double OverDouble1 = DBL_MAX + 1, OverDouble2 = DBL_MIN - 1;
    char OverChar1 = CHAR_MAX + 1, OverChar2 = CHAR_MIN - 1;
    unsigned char OverUnsignedChar = UCHAR_MAX +1;
    //Tipo int
    printf("Il dato OverInt1, che e' un intero positivo molto grande, va in overflow e restituisce un numero errato: %d\n", OverInt1);
    printf("Il dato OverInt2, che e' un intero negativo molto piccolo, va in overflow e restituisce un numero errato: %d\n\n", OverInt2);
    //Tipo short int
    printf("Il dato OverShortInt1,che e' un intero positivo molto grande, va in overflow e restituisce un numero errato: %d\n", OverShortInt1);
    printf("Il dato OverShortInt2,che e' un intero negativo molto piccolo, va in overflow e restituisce un numero errato: %d\n\n", OverShortInt2);
    //Tipo long int
    printf("Il dato OverLongInt1, che e' un intero positivo molto grande, va in overflow e restituisce un numero errato: %ld\n", OverLongInt1);
    printf("Il dato OverLongInt2, che e' un intero negativo molto piccolo, va in overflow e restituisce un numero errato:  %ld\n\n", OverLongInt2);
    //Tipi unsigned int
    printf("Il dato OverUnsignedInt, che e' un intero solo positivo molto grande, va in overflow e restituisce un numero errato: &d\n", OverUnsignedInt);
    printf("Il dato OverUnsignedShortInt, che e' un intero solo positivo molto grande, va in overflow e restituisce un numero errato: %d\n", OverUnsignedShortInt);
    printf("Il dato OverUnsignedLongInt, che e' un intero solo positivo molto grande, va in overflow e restituisce un numero errato: %ld\n\n", OverUnsignedLongInt);
 /*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Tipo float e double
    printf("Il dato OverFloat1, che e' un floating point molto grande, va in overflow e restituisce un numero errato: %f \n", OverFloat1);
    printf("Il dato OverFloat2, che e' un floating point molto piccolo, va in overflow e restituisce un numero errato: %f \n\n", OverFloat2);
    printf("Il dato OverDouble1, che e' un double molto grande, va in overflow e restituisce un numero errato: %lf\n", OverDouble1);
    printf("Il dato OverDouble2, che e' un double molto piccolo, va in overflow e restituisce un numero errato: %lf\n\n", OverDouble2);
  /*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Tipo char
    printf("Il dato OverChar1, che e' un char piu' grande del suo limite di range, va in overflow e restituisce un numero errato: %c\n", OverChar1);
    printf("Il dato OverChar2, che e' un char piu' piccolo del suo limite di range, va in overflow e restituisce un numero errato: %c\n", OverChar2);
    printf("Il dato OverUnsignedChar, che e' un unsigned char piu' grande del suo limite di range, va in overflow e restituisce un numero errato: %c\n\n\n\n\n", OverUnsignedChar);


    system("pause");
    printf("\n\n\n\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Parte 3: esempi di funzioni con la libreria math.h
    //specifichiamo le variabili che andremo ad utilizzare e poi le facciamo inserire dall'utente tramite una scanf, 18 funzioni usate
    float NumeroFloat1 = 0.0, NumeroFloat2 = 0.0, RisultatoFloat1 = 0.0, RisultatoFloat2 = 0.0, RisultatoFloat3 = 0.0, RisultatoFloat4 = 0.0, RisultatoFloat5 = 0.0, RisultatoFloat6 = 0.0;

    printf("Parte 3: utilizzo delle funzioni matematiche della math.h.\n");
    //Prendiamo due numeri in input
    printf("Inserisci due numeri separati da uno spazio (anche con la virgola):\n");
    scanf("%f %f", &NumeroFloat1, &NumeroFloat2);
    fflush(stdin);
    printf("\n\nHai inserito: %f e %f", NumeroFloat1, NumeroFloat2);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Radice quadrata(funzione sqrt();)
    RisultatoFloat1 = sqrt (NumeroFloat1);
    RisultatoFloat2 = sqrt (NumeroFloat2);
    printf("\n\n\nQuesta e' la radice quadrata dei tuoi numeri: (%.3f) (%.3f)\n\n", RisultatoFloat1, RisultatoFloat2);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Potenza (funzione pow();)
    RisultatoFloat1 = pow (NumeroFloat1, 2);
    RisultatoFloat2 = pow (NumeroFloat2, 2);
    printf("Questa e' la potenza alla seconda dei tuoi numeri: %f %f\n\n", RisultatoFloat1, RisultatoFloat2);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Logaitmo in base 2 e logaritmo in base 10 (funzion1 log(); log10();)
    RisultatoFloat1 = log(NumeroFloat1);
    RisultatoFloat2 = log(NumeroFloat2);
    RisultatoFloat3 = log10(NumeroFloat1);
    RisultatoFloat4 = log10(NumeroFloat2);
    printf("Questo e' il logaritmo in base 2 e 10 dei tuoi numeri: (%.3f) (%.3f) e (%.3f) (%.3f)\n\n", RisultatoFloat1, RisultatoFloat2, RisultatoFloat3, RisultatoFloat4);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Seno, seno iperbolico e arcoseno (funzioni sin(); sinh(); asin();)
    RisultatoFloat1 = sin(NumeroFloat1);
    RisultatoFloat2 = sin(NumeroFloat2);
    RisultatoFloat3 = sinh(NumeroFloat1);
    RisultatoFloat4 = sinh(NumeroFloat2);
    RisultatoFloat5 = asin(NumeroFloat1);
    RisultatoFloat6 = asin(NumeroFloat2);
    printf("Questi sono il seno, il seno-iperbolico e l'arcoseno dei tuoi numeri: (%.3f) (%.3f), (%.3f) (%.3f) e (%.3f) (%.3f)\n\n", RisultatoFloat1, RisultatoFloat2, RisultatoFloat3, RisultatoFloat4, RisultatoFloat5, RisultatoFloat6);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Coseno, coseno iperbolico e arcocoseno (funzione cos(); cosh(); acos();)
    RisultatoFloat1 = cos(NumeroFloat1);
    RisultatoFloat2 = cos(NumeroFloat2);
    RisultatoFloat3 = cosh(NumeroFloat1);
    RisultatoFloat4 = cosh(NumeroFloat2);
    RisultatoFloat5 = acos(NumeroFloat1);
    RisultatoFloat6 = acos(NumeroFloat2);
    printf("Questi sono il coseno, il coseno-iperbolico e l'arcocoseno dei tuoi numeri: (%.3f) (%.3f), (%.3f) (%.3f) e (%.3f) (%.3f)\n\n", RisultatoFloat1, RisultatoFloat2, RisultatoFloat3, RisultatoFloat4, RisultatoFloat5, RisultatoFloat6);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Tangente, tangente iperbolica e arcotangente (funzione tan(); tanh(); atan();)
    RisultatoFloat1 = tan(NumeroFloat1);
    RisultatoFloat2 = tan(NumeroFloat2);
    RisultatoFloat3 = tanh(NumeroFloat1);
    RisultatoFloat4 = tanh(NumeroFloat2);
    RisultatoFloat5 = atan(NumeroFloat1);
    RisultatoFloat6 = atan(NumeroFloat2);
    printf("Questi sono la tangente, la tangente-iperbolica e l'arcotangente dei tuoi numeri: (%.3f) (%.3f), (%.3f) (%.3f) e (%.3f) (%.3f)\n\n", RisultatoFloat1, RisultatoFloat2, RisultatoFloat3, RisultatoFloat4, RisultatoFloat5, RisultatoFloat6);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //e eleavato alla x (funzione exp();)
    RisultatoFloat1 = exp(NumeroFloat1);
    RisultatoFloat2 = exp(NumeroFloat2);
    printf("Questo e' l'esponente elevato ai tuoi numeri(e^x): (%.3f) (%.3f)\n\n", RisultatoFloat1, RisultatoFloat2);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Valore assoluto (funzione fabs();)
    RisultatoFloat1 = fabs(NumeroFloat1);
    RisultatoFloat2 = fabs(NumeroFloat2);
    printf("Questo e' il valore assoluto dei tuoi numeri: (%.3f) (%.3f)\n\n", RisultatoFloat1, RisultatoFloat2);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Floor(Il piu' grande intero non maggiore del parametro) (funzione floor();)
    //ESEMPIO: se NumeroFloat fosse 12.98467, il floor restituisce semplicemente 12
    RisultatoFloat1 = floor(NumeroFloat1);
    RisultatoFloat2 = floor(NumeroFloat2);
    printf("Questo e' il valore piu' grande(intero) non maggiore dei tuoi numeri: (%.3f) (%.3f)\n\n", RisultatoFloat1, RisultatoFloat2);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Ceil (Il più piccolo intero non minore del parametro) (funzione ceil();)
    //Esempio se NumeroFloat fosse 12.98467, il ceil restituisce semplicemente 13
    RisultatoFloat1 = ceil(NumeroFloat1);
    RisultatoFloat1 = ceil(NumeroFloat2);
    printf("Questo e' il valore piu' piccolo(intero) non minore dei tuoi numeri: (%.3f) (%.3f)\n\n\n\n", RisultatoFloat1, RisultatoFloat2);


    system("pause");
    printf("\n\n\n\n");
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("Fine esercizio.\n\n\n\n");

    return 0;
}
