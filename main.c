/**
 * @Author Rodrigo Chaves
 * @Author Rodolfo DaOra
 * @Since 2018-10-19
 */

#include <stdio.h>
#include "bootstrap.c"
#include "estruturas/fila.c"
int main(int argc, char **argv){
   tipo_elementoFila *fila[3];
   fila[0]=criarFila(fila[0]);
   fila[1]=criarFila(fila[1]);
   fila[2]=criarFila(fila[2]);
   int qtdGuiches = 0;

   iniciaAplicacao(&qtdGuiches);
   printf("%i guichês informados\n", qtdGuiches);
   return 0;
}
