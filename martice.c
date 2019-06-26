#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <data.h>


int main(){

  FILE *p;
  int x, y, prenotati;
  srand(time(NULL));
  int n, m;



  if((p = fopen("sale.txt", "r")) != NULL){
    while(!feof(p)){
      fscanf(p, "\n%d[^\n]", &x);
      if(!feof(p)){
      fscanf(p, "\n%d[^\n]", &y);
      }
      else{
        break;
      }
    }
  }

  printf("\nNumero righe: %d, Numero colonne: %d\n", x, y);

  sala a[x][y];

  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      a[i][j] = 0;
    }
  }

  /*for(n = 0; n < x; n++){
    printf("\n");
    for(m = 0; m < y; m++){
      printf("%d  ", a[n][m]);
    }
  }*/

  printf("\n");

  printf("Quanti posti vuoi occupare? \n");
  scanf("%d", &prenotati);

    while(prenotati != 0){
    n = (rand()%5);
    m = (rand()%10);
    if(a[n][m] != 1){
    a[n][m] = 1;
    prenotati = prenotati-1;
    }
    printf("Fila %d, Posto %d \n", n, m);
  }

printf("Matrice aggiornata");

  for(n = 0; n < x; n++){
    printf("\n");
    for(m = 0; m < y; m++){
      printf("%d  ", a[n][m]);
    }
  }

  return 0;
}
