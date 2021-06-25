//Authors: Andrew Gagliotti, Andrea Zacconi, !Cristian Crescentini
//Date: 08-12-2019
//Esercizio 1 - memoria statica
//Data di scadenza: 08-12-2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRINGA 40
#define STUDENTI_MASSIMI 5
#define MAXINSEGNAMENTI 5
#define MAXCORSI 3
#define NUM_ESAMI 3
#define VOTO_MINIMO 0
#define VOTO_MASSIMO 30

/*----LISTA DELLE STRUCT UTILIZZATE----*/

/*STRUTTURA INSEGNAMENTO*/
typedef struct
{
    int ins_CodIns;
    char ins_NomeIns[STRINGA + 1];
    int ins_VototIns;
    int ins_Credito;
}INSEGNAMENTO;
INSEGNAMENTO MATERIA[MAXINSEGNAMENTI] = {{10, "Scienze", 31, 12}, {11, "Analisi", 31, 12}, {12, "Geometria", 31, 10}, {13, "Programmazione", 31, 15}, {14, "Sistemi e Reti", 31, 13}};

/*STRUTTURA STUDENTE CON PIANO STUDI*/
struct
{
    int std_NumMatricola;
    char std_Nome[STRINGA + 1];
    char std_Cognome[STRINGA + 1];
    char std_CorsoIscritto[STRINGA + 1];
    INSEGNAMENTO std_PianoStudi[NUM_ESAMI];
}STUDENTE[STUDENTI_MASSIMI];

/*STRUTTURA CORSO*/
struct
{
    char crs_NomeCorso[STRINGA + 1];
    int crs_CodInsegnamenti[MAXINSEGNAMENTI];
    int crs_MtrCorso[STUDENTI_MASSIMI];
}CORSO[MAXCORSI] = {{"Ingegneria", {11, 13}}, {"Scienze Informatiche", {11, 13, 14}}, {"Geometria Applicata", {10, 12} } };



/*----LISTA DELLE FUNZIONI UTILIZZATE----*/

/*FUNZIONE DI UTILIZZO GRAFICO*/
void FunzStampa()
{
    for(int i = 0; i < 100; i++)
        printf("-");
    printf("\n\n");
}

/*FUNZIONE STAMPA MESSAGGIO DI ERRORE*/
void FunzVerifica(int var)
{
    printf("\n");
    FunzStampa();
    printf("Hai inserito un input errato, reinserisci!\n\n");
    FunzStampa();
    var = 0;
}

/*FUNZIONE PER TROVARE LA VERIFICA INSERITA E CONTROLLARE SE ESISTE*/
int FunzMatricola(int Count)
{
    int VarMatricola;
    int Matricola;
    int Verifica;
    int Trovata = 0;

    while(1)
    {
        Verifica = scanf("%d", &Matricola);
        fflush(stdin);

        /*Ciclo controllo esistenza matricola in memoria*/
        for(int i = 0; i < Count; i++)
        {
            if(STUDENTE[i].std_NumMatricola == Matricola)
            {
                VarMatricola = i;
                Trovata++;
                break;
            }
        }

        /*Controllo input utente*/
        if(Verifica != 1 || Trovata == 0)
            FunzVerifica(Verifica);
        else
        {
            Trovata = 0;
            break;
        }
    }
    /*Se la matricola viene trovata allora ne restituisce il valore*/
    return VarMatricola;
}





int main()
{
    int CountStudentiAgg = 0, AsMatricola = 10, verifica = 0, trovata = 0, NInsegnamenti = 0, VarCiclo = 0;
    int Scelta, VarMatricola;
    char answer;
    float Num = 0.0, Den = 0.0, Media = 0.0;

    /*----------------------------------------------Ciclo scelte possibili nel programma-------------------------------------------------------------------------------------------------------------*/
    while(VarCiclo != 1)
    {
        printf("Quale operazione desideri attuare?\n(1). Aggiungi nuovi studenti\n(2). Stampa dati di un singolo studente\n");
        printf("(3). Inserisci valutazioni studente\n(4). Calcolo media dei voti di uno studente.\n");
        FunzStampa();

        while(1)
        {
            verifica = scanf("%d", &Scelta);
            fflush(stdin);

            if(verifica != 1 || Scelta > 4 || Scelta < 1)
                FunzVerifica(verifica);
            else if(CountStudentiAgg == 0 && Scelta != 1)
            {
                printf("\n");
                FunzStampa();
                printf("Devi prima inserire almeno uno studente!\n\n");
                FunzStampa();
            }
            else
                break;
        }

        /*Inizio azioni possibili nel programma*/
        switch(Scelta)
        {
        /*INSERISCI LO STUDENTE*/
        case 1:
            {
                if(CountStudentiAgg == STUDENTI_MASSIMI)
                {
                    printf("Non puoi aggiungere piu' studenti!\n\n");
                    break;
                }

                printf("\n");
                FunzStampa();
                printf("Inserisci il nome dello studente: ");
                scanf("%s", STUDENTE[CountStudentiAgg].std_Nome);
                fflush(stdin);

                printf("\n");
                printf("Inserisci il cognome dello studente: ");
                scanf("%s", STUDENTE[CountStudentiAgg].std_Cognome);
                fflush(stdin);

                printf("\n");
                STUDENTE[CountStudentiAgg].std_NumMatricola = AsMatricola + CountStudentiAgg;
                printf("NUMERO MATRICOLA DELLO STUDENTE: %d\n\n", AsMatricola + CountStudentiAgg);

                printf("\n");
                printf("Segli il corso di iscrizione dello studente tra quelli elencati: \n");

                for(int i = 0; i < MAXCORSI; i++)
                    printf("-[%d]%s\n", i + 1, CORSO[i].crs_NomeCorso);

                FunzStampa();

                /*Ciclo analisi scelta del corso*/
                while(1)
                {
                    verifica = scanf("%d", &Scelta);
                    fflush(stdin);

                    if(verifica != 1 || Scelta < 1 || Scelta > MAXCORSI)
                        FunzVerifica(verifica);
                    else
                    {
                        /*Ciclo che conta le materie presenti nel corso selezionato*/
                        for(int i = 0; i < MAXINSEGNAMENTI; i++)
                        {
                            if(CORSO[Scelta - 1].crs_CodInsegnamenti[i] > AsMatricola - 1 && CORSO[Scelta - 1].crs_CodInsegnamenti[i] < AsMatricola + MAXINSEGNAMENTI)
                                NInsegnamenti++;
                            else
                                break;
                        }

                        /*Prendiamo il nome del corso e lo inseriamo nella struct studente*/
                        strcpy(STUDENTE[CountStudentiAgg].std_CorsoIscritto, CORSO[Scelta - 1].crs_NomeCorso);
                        /*Ciclo che assegna ogni materia allo studente che è iscritto ad un determinato corso*/
                        for(int i = 0; i < NInsegnamenti; i++)
                        {
                            STUDENTE[CountStudentiAgg].std_PianoStudi[i].ins_CodIns = CORSO[Scelta - 1].crs_CodInsegnamenti[i];
                            /*Ciclo che controlla se il codice insegnamento ha le materie giuste all'interno*/
                            for(int a = 0; a < MAXINSEGNAMENTI; a++)
                            {
                                if(MATERIA[a].ins_CodIns == CORSO[Scelta - 1].crs_CodInsegnamenti[i])
                                {
                                    strcpy(STUDENTE[CountStudentiAgg].std_PianoStudi[i].ins_NomeIns, MATERIA[a].ins_NomeIns);
                                    STUDENTE[CountStudentiAgg].std_PianoStudi[i].ins_VototIns = MATERIA[a].ins_VototIns;
                                    STUDENTE[CountStudentiAgg].std_PianoStudi[i].ins_Credito = MATERIA[a].ins_Credito;
                                }
                            }
                        }
                        NInsegnamenti = 0;
                        break;
                    }
                }

                /*Aumento il counter di numeri studenti che ho inserito*/
                CountStudentiAgg++;
                printf("\n");
                FunzStampa();

                printf("\nLo studente e' stato memorizzato con successo!\n\n\n\n\n\n\n\n\n");
                break;
            }
        /*STAMPA LO STUDENTE*/
        case 2:
            {
                printf("\n");
                FunzStampa();
                printf("Inserisci la matricola dello studente desiderato\n\n");

                /*Controllo la matricola in memoria*/
                VarMatricola = FunzMatricola(CountStudentiAgg);

                printf("\nSTUDENTE MATRICOLA: %d\n", STUDENTE[VarMatricola].std_NumMatricola);
                printf("NOME: %s\n", STUDENTE[VarMatricola].std_Nome);
                printf("COGNOME: %s\n", STUDENTE[VarMatricola].std_Cognome);
                printf("CORSO: %s\n", STUDENTE[VarMatricola].std_CorsoIscritto);
                printf("MATERIE ASSEGNATE:\n");

                /*Ciclo di conto delle materie in un insegnamento*/
                for(int a = 0; a < NUM_ESAMI; a++)
                {
                    if(STUDENTE[VarMatricola].std_PianoStudi[a].ins_CodIns > AsMatricola - 1 && STUDENTE[VarMatricola].std_PianoStudi[a].ins_CodIns < AsMatricola + MAXINSEGNAMENTI)
                        NInsegnamenti++;
                    else
                        break;
                }

                /*Ciclo di stampa dei voti delle materie dello studente in un determinato corso di studi*/
                for(int i = 0; i < NInsegnamenti; i++)
                {
                    if(STUDENTE[VarMatricola].std_PianoStudi[i].ins_VototIns == 31)
                        printf("-MATERIA: %s    VOTO: ANCORA DA ASSEGNARE\n", STUDENTE[VarMatricola].std_PianoStudi[i].ins_NomeIns);
                    else if(STUDENTE[VarMatricola].std_PianoStudi[i].ins_VototIns == 0)
                        printf("-MATERIA: %s    VOTO: NON SOSTENUTO\n", STUDENTE[VarMatricola].std_PianoStudi[i].ins_NomeIns);
                    else
                        printf("-MATERIA: %s    VOTO: %d\n", STUDENTE[VarMatricola].std_PianoStudi[i].ins_NomeIns, STUDENTE[VarMatricola].std_PianoStudi[i].ins_VototIns);
                }

                NInsegnamenti = 0;
                printf("\n");
                FunzStampa();
                printf("\n");
                break;
            }
        /*ASSEGNAMENTO VOTI MATERIE*/
        case 3:
            {
                printf("\n");
                FunzStampa();
                printf("Inserisci la matricola dello studente desiderato: ");

                /*Controllo la matricola in memoria*/
                VarMatricola = FunzMatricola(CountStudentiAgg);

                printf("\nSeleziona la materia da valutare tra le seguenti:\n");

                /*Ciclo di conto delle materie in un insegnamento*/
                for(int a = 0; a < NUM_ESAMI; a++)
                {
                    if(STUDENTE[VarMatricola].std_PianoStudi[a].ins_CodIns > AsMatricola - 1 && STUDENTE[VarMatricola].std_PianoStudi[a].ins_CodIns < AsMatricola + MAXINSEGNAMENTI)
                        NInsegnamenti++;
                    else
                        break;
                }

                /*Ciclo di stampa dei voti delle materie dello studente in un determinato corso di studi*/
                for(int i = 0; i < NInsegnamenti; i++)
                {
                    if(STUDENTE[VarMatricola].std_PianoStudi[i].ins_VototIns == 31)
                        printf("[%d]%s\t\tVOTO ANCORA DA ASSEGNARE\n", i + 1, STUDENTE[VarMatricola].std_PianoStudi[i].ins_NomeIns);
                    else
                        printf("[%d]%s\n", i + 1, STUDENTE[VarMatricola].std_PianoStudi[i].ins_NomeIns);
                }
                printf("\n");
                FunzStampa();

                /*Ciclo inserimento materia specifica con controllo su input*/
                while(1)
                {
                    verifica = scanf("%d", &Scelta);
                    fflush(stdin);

                    if(verifica != 1 || Scelta < 1 || Scelta > NInsegnamenti)
                        FunzVerifica(verifica);
                    else
                    {
                        int voto;
                        printf("Inserisci il voto in 30esimi: ");

                        /*Ciclo inserimento di un voto in una materia specifica con controllo input*/
                        while(1)
                        {
                            verifica = scanf("%d", &voto);
                            fflush(stdin);

                            if(verifica != 1 || voto < VOTO_MINIMO || voto > VOTO_MASSIMO)
                                FunzVerifica(verifica);
                            else
                            {
                                STUDENTE[VarMatricola].std_PianoStudi[Scelta - 1].ins_VototIns = voto;
                                break;
                            }
                        }
                        break;
                    }
                }

                NInsegnamenti = 0;
                printf("\n");
            break;
            }
        /*MEDIA PONDERATA*/
        case 4:
            {

                printf("\n");
                FunzStampa();
                printf("Inserisci la matricola dello studente desiderato\n\n");

                /*Controllo la matricola in memoria*/
                VarMatricola = FunzMatricola(CountStudentiAgg);

                /*Ciclo che controlla se tutte le materie sono state inserite*/
                for(int i = 0; i < NUM_ESAMI; i++)
                {
                    if(STUDENTE[VarMatricola].std_PianoStudi[i].ins_VototIns == 31)
                    {
                        printf("\nUna o piu' materie non hanno un voto assegnato, riprova quando avrai inserito tutti i voti\n\n\n\n\n\n");
                        trovata++;
                        break;
                    }
                }
                if(trovata != 0)
                {
                    trovata = 0;
                    break;
                }

                /*Ciclo calcolo numeratore e denominatore*/
                for(int i = 0; i < NUM_ESAMI; i++)
                {
                    Num = Num + (STUDENTE[VarMatricola].std_PianoStudi[i].ins_VototIns * STUDENTE[VarMatricola].std_PianoStudi[i].ins_Credito);
                    Den = Den + STUDENTE[VarMatricola].std_PianoStudi[i].ins_Credito;
                }

                /*Calcolo media*/
                Media = Num / Den;

                printf("\nLa media dello studente selezionato e': %f\n", Media);
                break;
            }
        }

        printf("Vuoi eseguire altre operazioni? Si (s) o No (n): ");

        /*Ciclo controllo risposta se ripetere programma o meno*/
        while(1)
        {
            verifica = scanf("%c", &answer);
            fflush(stdin);

            if(verifica != 1 || (answer != 'N' && answer != 'n' && answer != 'S' && answer != 's'))
                FunzVerifica(verifica);
            else if(answer == 'N' || answer == 'n')
            {
                VarCiclo = 1;
                break;
            }
            else if(answer == 'S' || answer == 's')
                break;
        }
        printf("\n");

    }

    return 0;
}
