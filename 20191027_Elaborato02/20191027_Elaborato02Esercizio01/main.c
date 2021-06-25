//Authors: Andrew Gagliotti, Andrea Zacconi, Cristian Crescentini
//Date: 24-10-2019
//Esercizio 1
//Data di scadenza: 27-10-2019

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>                  //Libreria usata per le funzioni di valutazione e operazioni su caratteri alfanumerici
#define N 30

int main()
{
//Dichiaro tutte le variabili in gioco. Tutte le variabili int mi servono per stampare quanti caratteri ho per ogni classe analizzata. Le char mi serviranno per il testo in input e per le conversioni delle lettere.
    char lettera, trasformato1, trasformato2, stringa1[N];
    int i, sommaalfanum, sommaletteragenerale, sommanumero, sommacaratteriminuscoli, sommacaratterimaiuscoli;
    int sommaspazi, sommagrafica, sommastampabile, sommapunteggiatura, sommaspaziatura, sommacontrollo;

//Assegno come valore 0, a tutte le variabili che uso; questo mi garantisce di "contare" correttamente le lettere per ogni classe di appartenenza.
    sommaalfanum = 0;
    sommaletteragenerale = 0;
    sommanumero = 0;
    sommacaratteriminuscoli = 0;
    sommacaratterimaiuscoli = 0;
    sommaspazi = 0;
    sommagrafica = 0;
    sommastampabile = 0;
    sommapunteggiatura = 0;
    sommaspaziatura = 0;
    sommacontrollo = 0;

    printf("Inserisci liberamente quanti caratteri vuoi a schermo per vederne le caratteristiche generali:\n");
    printf("per ogni testo inserito potrai vedere i caratteri alfanumerici invertiti (da maiuscolo a minuscolo e viceversa) immediatamente e poi subito dopo le caratteristiche compositive.\n\n");
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    i = 0;
    do{
        lettera = getchar();                                //Leggo il testo in input lettera per lettera e lo analizzo allo stesso modo
                                                            //feedback di ciò che abbiamo inserito, se si vuole
    if(lettera != '#')
    {
        if(isalnum(lettera))                                //se si ha un carattere si fa + 1 al suo contatore
            sommaalfanum++;
        if(isalpha(lettera))                                //se si ha un carattere letterale si fa + 1 al suo contatore
            sommaletteragenerale++;
        if(isdigit(lettera)){                               //se si ha un carattere numerico si fa + 1 al suo contatore
            sommanumero++;
            trasformato1 = lettera;
            *(stringa1 +i) = trasformato1;
            i++;}
        if(ispunct(lettera)){                               //se si ha un carattere di punteggiatura si fa + 1 al suo contatore
            sommapunteggiatura++;
            trasformato1 = lettera;
            *(stringa1 +i) = trasformato1;
            i++;}
        if(isspace(lettera)){                               //se si ha un carattere di spaziatura si fa + 1 al suo contatore
            sommaspaziatura++;
            trasformato1 = lettera;
            *(stringa1 +i) = trasformato1;
            i++;}
        if(iscntrl(lettera))                                //se si ha un carattere di controllo si fa + 1 al suo contatore
            sommacontrollo++;
        if(isblank(lettera))                                //se si ha un carattere "bianco" (non visibile) si fa + 1 al suo contatore
            sommaspazi++;
        if(isgraph(lettera))                                //se si ha un carattere grafico (es. glifo) si fa + 1 al suo contatore
            sommagrafica++;
        if(isprint(lettera))                                //se si ha un carattere stampabile a schermo si fa + 1 al suo contatore
            sommastampabile++;
        if(islower(lettera)){                               //se si ha un carattere letterale minuscolo si fa + 1 al suo contatore
            sommacaratteriminuscoli++;
            trasformato1 = toupper(lettera);                //e lo trasformiamo nel suo equivalente maiuscolo
            *(stringa1 + i)= trasformato1;
            i++;}
        if(isupper(lettera)){                               //se si ha un carattere letterale maiuscolo si fa + 1 al suo contatore
            sommacaratterimaiuscoli++;
            trasformato2 = tolower(lettera);                //e lo trasformiamo nel suo equivalente minuscolo
            *(stringa1 + i) = trasformato2;
            i++;}

    }
    else
    break;

     }while (1);                                            //1 lo fa ripetere all'infinito e noi usiamo l'else per uscire quando abbiamo analizzato tutte le lettere
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("\n\n");

    printf("Caratteri invertiti:\n");
//Stampa caratteri invertiti del testo inserito.
    for (int a = 0 ; a < stringa1[a] ; a++)
    {
        printf("%c", *(stringa1 + a));
    }
    printf("\n\n");

//Stampa delle statistiche del testo inserito per ogni caso precedentemente riportato
    printf("Totale caratteri inseriti = %d\n\n", sommaalfanum + sommapunteggiatura + sommaspazi);
    printf("Totale caratteri alfanumerici = %d\n\n", sommaalfanum);
    printf("Totale lettere = %d\n\n", sommaletteragenerale);
    printf("Totale numeri = %d\n\n", sommanumero);
    printf("Totale lettere minuscole = %d\n\n", sommacaratteriminuscoli);
    printf("Totale lettere maiuscole = %d\n\n", sommacaratterimaiuscoli);
    printf("Totale spazi, tabulazioni(caratteri bianchi) = %d\n\n", sommaspazi);
    printf("Totale segni grafici = %d\n\n", sommagrafica);
    printf("Totale caratteri stampabili = %d\n\n", sommastampabile);
    printf("Totale punteggiatura = %d\n\n", sommapunteggiatura);
    printf("Totale spaziature = %d\n\n", sommaspaziatura);
    printf("Totale caratteri di controllo = %d\n\n\n", sommacontrollo);

    system("pause");
    printf("\n\n\nFine esercizio.\n\n\n");
    return 0;
}
