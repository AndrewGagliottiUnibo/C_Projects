//Authors: Andrew Gagliotti, Andrea Zacconi, Cristian Crescentini
//Date: 11-10-2019
//Esercizio 1
//Data di scadenza: 13-10-2019

//Per semplificare il lavoro di correzione ai professori divideremo il lavoro in 3 sezioni
//elencando poi quale parte di esercizio sarà svolta. Il termine di una parte dalla funzione system("pause");

#include <stdio.h>                                                  //Includiamo questa libreria per poter utilizzare la funzione printf();
#include <stdlib.h>                                                 //Includiamo questa libreria per poter utilizzare la funzione system("pause");
#include <limits.h>                                                 //Includiamo questa libreria per il lavoro svolto nella parte 3: contiene costanti per i valori di massimo e minimo di tipo int
#include <float.h>                                                  //Includiamo questa libreria per il lavoro svolto nella parte 3: contiene costanti per i valori di massimo e minimo dei tipi float e double
#define DATA 2301                                                   //Definiamo una costante tramite la direttiva define, servirà in seguito



 //Inizio esercizio 1



int main()
{
    int lunghezza;                                                  //Definiamo la variabile lunghezza affinchè possa utilizzarla in seguito nelle printf per calcolarne i caratteri totali che vengono stampati
    lunghezza = 0;

    int variabileint = 2301;
    short int variabileSint = 231;                                  //Indichiamo le varie variabili che useremo ogni volta prima di utilizzarle
    long int variabileLint = 2045614;
    unsigned int variabileUint = 23001;
    unsigned short int variabileUSint = 30000;
    unsigned long int variabileULint = 900000;                      //Di base una variabile di tipo short vale come una variabile di tipo int, infatti occupano lo stesso numero di byte in memoria
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Inizio parte 1: printf() di tutti i tipi di variabili incontrate, con un esempio e la quantità di memoria occupata da ciascuna di esse, in generale
    lunghezza = printf("\n\t\tParte 1: elenco di tutte le variabili studiate (tutte le variabili per default sono di tipo signed):\n");
    printf("\t\tCaratteri stampati: %d\n\n\n\n", lunghezza);
    lunghezza = printf("\tVariabili di tipo int:\n");
    printf("\tCaratteri stampati: %d\n\n", lunghezza);
    //Tutti i tipi di variabili, un esempio di valore e la loro occupazione in memoria
    //Una variabile di tipo int è un numero intero

    lunghezza = printf("La variabile di tipo int e\' un numero intero, ad esempio: +/- %d\n", variabileint);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("La variabile di tipo int occupa in memoria: %d byte\n", sizeof(int));
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("La variabile di tipo short int e\' un numero intero minore o uguale rispetto ad int, ad esempio: +/- %hd\n", variabileSint);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("La variabile di tipo short int occupa in memoria: %d byte\n", sizeof(short int));
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("La variabile di tipo long int e\' un numero intero uguale o maggiore rispetto ad int, ad esempio: +/- %ld\n", variabileLint);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("La variabile di tipo long int occupa in memoria: %d byte\n", sizeof(long int));
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("La variabile di tipo unsigned int e\' un int ma solo di segno positivo o nullo: ad esempio: %d\n", variabileUint);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("La variabile di tipo unsigned int occupa in memoria: %d byte\n", sizeof(unsigned int));
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("La variabile di tipo unsigned short int e\' uno short int ma solo di segno positivo o nullo: %hd\n", variabileUSint);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("La variabile di tipo unsigned short int occupa in memoria: %d byte\n", sizeof(unsigned short int));
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("La variabile di tipo unsigned long int e\' un long int ma solo di segno positivo o nullo: %ld\n", variabileULint);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("La variabile di tipo unsigned long int occupa in memoria: %d byte\n", sizeof(unsigned long int));
    printf("Caratteri stampati: %d\n\n\n\n", lunghezza);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    float variabilefloat = 34.657894;
    //Una variabile float è un numero con la virgola con precisione singola fino a 6 cifre decimali
    lunghezza = printf("\tVariabile di tipo float:\n");
    printf("\tCaratteri stampati: %d\n\n", lunghezza);

    lunghezza = printf("La variabile di tipo float e\' un numero a virgola mobile con precisione singola, ad esempio: %f\n", variabilefloat);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("La variabile di tipo float occupa in memoria: %d byte\n", sizeof(float));
    printf("Caratteri stampati: %d\n\n\n\n", lunghezza);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    double variabiledouble = 134.47885478;
    //Una variabile di tipo double è un numero a virgola mobile con precisione doppia
    //Bisogna specificare il numero di cifre decimali tra gli specificatori di conversione per evitare errori di visualizzazione

    lunghezza = printf("\tVariabile di tipo double:\n");
    printf("\tCaratteri stampati: %d\n\n", lunghezza);

    lunghezza = printf("La variabile di tipo double e\' un numero a virgola mobile con precisione doppia (max 15 cifre dopo la virgola), ad esempio: %.8f\n", variabiledouble);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("La variabile di tipo double occupa in memoria: %d byte\n", sizeof(double));
    printf("Caratteri stampati: %d\n\n\n\n", lunghezza);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    char variabilelettera = 'E';
    unsigned char variabileUchar[3] = "12";
    char variabilestringa[50] = "stringa";
    //char si usa per i caratteri e per le stringhe, due tipi di char

    lunghezza = printf("\tVariabili di tipo char:\n");
    printf("\tCaratteri stampati: %d\n\n", lunghezza);

    lunghezza = printf("La variabile di tipo char rappresenta un carattere dell\'ambiente in cui risiede il compilatore o una stringa letterale, ad esempio: %c o %s\n", variabilelettera, variabilestringa);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("La variabile di tipo char occupa in memoria: %d byte\n", sizeof(char));
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("La variabile di tipo unsigned char rappresenta un carattere senza segno: %2s\n", variabileUchar);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("La variabile di tipo unsigned char occupa in memoria: %d byte\n", sizeof(unsigned char));
    printf("Caratteri stampati: %d\n\n\n\n\n\n", lunghezza);


    system("pause");
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Inizio parte 2: output della printf() e tutto ciò che può contenere
    lunghezza = printf("\n\n\n\n\t\tParte 2: tutti gli argomenti della funzione printf() studiati e le diverse varianti:\n");
    printf("\t\tCaratteri stampati: %d\n\n\n", lunghezza);

    lunghezza = printf("La funzione printf() puo\' contenere diversi argomenti: stringhe di formato letterale, espressioni, indicatori di conversione per variabili e le variabili.\n");
    printf("Caratteri stampati: %d\n\n\n", lunghezza);

    lunghezza = printf("01 - Stringa di formato letterale: inserire del testo che appaia a schermo.\n");
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Esempi:\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("Tramite printf() ho fatto in modo che questa stringa letterale venisse visualizzata a schermo.\n");
    printf("Caratteri stampati: %d\n\n\n", lunghezza);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    int a = 3, b = 9, soluzione = a * b;
    //Definiamo le variabili usate nell'espressione complessa. Facciamo un unico esempio perchè specificare ora tutte le espressioni con tutti gli operatori possibili significherebbe sfociare nell'esercizio 2.
    lunghezza = printf("02 - Espressioni: possono essere semplici (variabili e costanti) o complesse (operazioni).\n");
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Esempi:\n");
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Espressione semplice - Attribuire un valore ad una variabile o ad una costante: nome usato precedentemente %s o costante %d.\n", variabilestringa, DATA);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Espressione complessa - L'espressione %d * %d restituisce come risultato %d.\n", a, b, soluzione);
    printf("Caratteri stampati: %d\n\n\n", lunghezza);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    lunghezza = printf("03 - Indicatori di conversione per le variabili, in generale: 0/0(1)m.p(2)X\n");
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Modificatore (1) che o allinea il numero a sinistra(-), o che ne specifica il segno(+), o che pone degli zeri antecedenti se vi sono degli spazi (0).\n");
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("\"m\" indica il campo minimo, ovvero il numero di spazi massimi disponibili per rappresentare il numero.\n");
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("\".p\" puo\' indica la precisione, ovvero il minimo numero di cifre per gli interi, il numero di cifre dopo la virgola, il numero di cifre significative.\n");
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Vi e\' il modificatore della lunghezza (2) anteposto alla specifica di conversione, ne chiarisce il sottotipo. Avremo \"h\" per gli short e gli unsigned short, \"l\" per i long e gli unsigned long, \"L\" per i long double.\n");
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("\"X\" indica lo specificatore di conversione, che serve per visualizzare le variabili durante la chiamata della printf(). E\' l'unico obbligatorio.\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);

    //Riprendiamo le variabili int e float usate precedentemente e le adattiamo a questo esercizio
    //Abbiamo dovuto giocare molto di spazi, tab e con le cifre per incolonnare tutto per renderlo bello da vedere
    lunghezza = printf("\tRappresentazione numeri secondo le regole precedentemente elencate: normale, numero massimo di cifre accettate, allineamento a sinistra, precisione, zeri alla sinistra del numero.\n");
    printf("\tCaratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("Variabili int\t        |%d|     %10d|%-10d     |        %7.6d|%015d|\n", variabileint, variabileint, variabileint, variabileint, variabileint);
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("Variabili float\t   |%f|%15f|%-15f|%15.3f|%015f|\n", variabilefloat, variabilefloat, variabilefloat, variabilefloat, variabilefloat);
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("Variabili double|%.8f|%15f|%-15f|%15.5f|%015f|\n",variabiledouble, variabiledouble, variabiledouble, variabiledouble, variabiledouble);
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("Variabili char\t          |%s|     %10s|%-10s     |        %7.1s|%015s|\n", variabileUchar, variabileUchar, variabileUchar, variabileUchar, variabileUchar);
    printf("Caratteri stampati: %d\n\n\n\n\n", lunghezza);
    //Con il modificatore 0 nel dichiarare la variabile char sotto forma numerica ci da' un warning ma la visualizzazione avviene come desiderato.

    //Le sequenze di escape
    lunghezza = printf("04 - Sequenze di escape: Sono caratteri speciali che svolgono funzioni di controllo del formato di visualizzazione, inserendo anche caratteri che non e' sempre possibile rappresentare:\n");
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Ad esempio:\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("\\n...avanzamento di una riga, a capo\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("\\a...produce un segnale acustico nel caso si voglia ricevere un feedback durante l'esecuzione del programma\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("\\t...tabulazione, equivale al tasto tab della tastiera\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("\\b...blankspace, che cancella il carattere immediatamente precedente\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("\\'...visualizzazione di un apice singolo\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("\\\"...visualizzazione di un apice doppio\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("\\\\...barra inversa inserita come carattere stampato\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("\\?...inserire il punto di domanda proprio come carattere stampato\n");
    printf("Caratteri stampati: %d\n\n\n\n\n\n", lunghezza);


    system("pause");
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Inizio parte 3: valori massimi e minimi posssibili delle variabili utilizzate precedentemente
    lunghezza = printf("\n\n\n\n\t\tParte 3: valori di massimo e minimo per ogni tipo di variabile utilizzato.\n");
    printf("\t\tCaratteri stampati: %d\n\n\n", lunghezza);

    lunghezza = printf("Elenco di seguito i valori di minimo e massimo per ciascun tipo di variabile usato precedentemente:\n");
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("Minimo valore per il tipo int: %d\n", INT_MIN);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Massimo valore per il tipo int: %d\n", INT_MAX);
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("Minimo valore per il tipo short int: %d\n", SHRT_MIN);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Massimo valore per il tipo short int: %d\n", SHRT_MAX);
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("Minimo valore per il tipo long int: %ld\n", (long) LONG_MIN);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Massimo valore per il tipo long int: %ld\n", (long) LONG_MAX);
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("Massimo valore per il tipo unsigned int: %u\n", (unsigned int) UINT_MAX);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Massimo valore per il tipo unsigned short: %u\n", (unsigned short) USHRT_MAX);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Massimo valore per il tipo unsigned long: %lu\n", (unsigned long) ULONG_MAX);
    printf("Caratteri stampati: %d\n\n\n", lunghezza);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    lunghezza = printf("Minimo valore per il tipo float: %e.\n", FLT_MIN);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Massimo valore per il tipo float: %e.\n", FLT_MAX);
    printf("Caratteri stampati: %d\n\n\n", lunghezza);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    lunghezza = printf("Minimo valore per il tipo double: %e.\n", DBL_MIN);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Massimo valore per il tipo double: %e.\n", DBL_MAX);
    printf("Caratteri stampati: %d\n\n\n", lunghezza);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    lunghezza = printf("Minimo valore per il tipo char: %d.\n", CHAR_MIN);
    printf("Caratteri stampati: %d\n", lunghezza);
    lunghezza = printf("Massimo valore per il tipo char: %d.\n", CHAR_MAX) ;
    printf("Caratteri stampati: %d\n\n", lunghezza);
    lunghezza = printf("Massimo valore per il tipo unsigned char: %d.\n", UCHAR_MAX);
    printf("Caratteri stampati: %d\n\n\n\n", lunghezza);



    system("pause");
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    lunghezza = printf("\n\n\n\nFine esercizio 1.\n");
    printf("Caratteri stampati: %d\n\n\n\n", lunghezza);


    return 0;
}
