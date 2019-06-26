#include "data.h"

/*
*
* Funzione carica_prenotazione
*
*- char *nomeFile: nome del file che contiene le prenotazioni
* - prenotazione p: un puntatore alla lista prenotazioni
* - sale p2: un puntatore alla lista sale
*
* ritorna una varabile di tipo prenotazioni che conterrà tutte le prenotazioni
*
*/

prenotazione carica_prenotazione(char *nomefile, prenotazione p){

    prenotazione newElem;
    tdata elem;
    FILE *fp;

        if((fp=fopen(nomefile, "r"))!=NULL){

            while(fscanf(fp,"%s%s%d%d%d%s%s%d", elem.nome_sala, elem.mese, &elem.giorno, &elem.orario, &elem.posti, elem.nome, elem.cognome, &elem.recapito)!=EOF){

                newElem = (tnodo *) malloc (sizeof(prenotazione));
                newElem->next=p;
                newElem->info=elem;
                p=newElem;

            }
        }else{
            printf("Errore nell'apertura del file.\n");

        }
    fclose(fp);
    return p;
}


/*
*
* Funzione carica_sala
*
* - char *nomeFile: nome del file che contiene la disposizione delle sale
* - sala p: un puntatore che punta alla lista sale
*
*
* ritorna una variabile di tipo sale che conterrà tutte le sale
*
*/


sala carica_sala(char *nomefile, sala p){
    sala newElem;
    telem elem;
    FILE *fp;

        if(fp=fopen(nomefile, "r")!=NULL){

            while(fscanf(fp,"%s%d%d", elem.nome_sala, elem.n_file, elem.n_posti)!=EOF){

                newElem = (tnode *) malloc (sizeof(sala));
                newElem->next=p;
                newElem->campi=elem;
                p=newElem;
            }

        }else{
            printf("Errore nell'apertura del file.\n");

        }
    fclose(fp);
    return p;
}

/*
* Funzione inizializza_c
*
* - int size: la dimensione massima dell'array di struct che vado a creare
*
*
*
*
* ritornerà una variabile di tipo giorni che conterrà il calendario degli spettacoli
*
*/

spettacolo inizializza_c(int size){

    int i;
    spettacolo calendario;

        calendario = (giorni*) malloc (size*sizeof(spettacolo));

        for (i=0;i<DIM;i++){

            calendario[i].pieno=0;

        }

    return calendario;
}

/*
* Funzione carica_c
*
* - char *nomeFile: nome del file che contiene la rubrica
* - spettacolo p: un puntatore alla struttura spettacolo
*
*
*
*
*/

void carica_spettacolo(char *nomefile, spettacolo calendario){

    int i=0;
    FILE *fp;

        if (fp=fopen(nomefile, "r")!= NULL){

            while (!feof(fp)){
                fscanf(fp, "%s", calendario[i].nome_sala);
                    if (!feof(fp)){
                    fscanf(fp, "%s%d%d%[^\n]", calendario[i].mese, calendario[i].giorno, calendario[i].orario, calendario[i].titolo);
                    calendario[i].pieno = 1;
                    i++;
                    }else{

                        break;
                    }
            }

        }else{

            printf("Errore nell'apertura del file.\n");

        }

}






