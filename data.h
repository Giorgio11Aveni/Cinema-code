#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUN 20
#define DIM 31
#define MAX 10
#define POS 10

//LISTA CONCATENATA PRENOTAZIONI
struct data{

    char nome_sala;
    char mese[MAX];
    int giorno;
    int orario;
    char posti[POS];
    char nome[LUN];
    char cognome[LUN];
    int recapito;

};
typedef struct data tdata;

struct nodo{

    tdata info;
    struct nodo *next;

};
typedef struct nodo tnodo;
typedef tnodo * prenotazione;

//STRUCT SALA

struct sala{

    char nome_sala;
    calendario *puntCal;


};
typedef struct sala tsala;
typedef tsala * sala;


// STRUCT CALENDARIO

struct calendario{

    spettacolo *puntSpet;

}

//LISTA CONCATENATA SPETTACOLO

struct informazioni {

    char nome_sala;
    char mese[MAX];
    int giorno;
    int orario;
    char titolo[LUN];
    int dim;

};

typedef struct informazioni tinformazioni;

struct node{

    tinformazioni date;
    struct node *next;

};

typedef struct node tnode;
typedef tnode * spettacolo;

//PROTOTIPI DI FUNZIONI

prenotazione carica_prenotazione(char *, prenotazione);
sala carica_sala (char *, sala);
spettacolo inizializza_c(int);
void carica_spettacolo(char *, spettacolo);
prenotazione inserisci_prenotazione(prenotazione, sala);
prenotazione inserisci_da_file(char *, prenotazione, sala);
void disponibili(sala);

