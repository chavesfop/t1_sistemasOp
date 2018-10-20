/**
 * @Author Rodrigo Chaves
 * @Author Rodolfo DaOra
 * @Since 2018-10-19
 */

#include <stdio.h>
#include <pthread.h>
#include "bootstrap.c"
#include "estruturas/fila.c"
#include "simulador.c"


int main(int argc, char **argv){
   tipo_elementoFila *fila[3];
   fila[0]=criarFila(fila[0]);
       fila[1]=criarFila(fila[1]);
   fila[2]=criarFila(fila[2]);
   for (int i = 0; i < 50; i++){
	   int numFila = rand() % 3;
	  enfileirar(fila[numFila], numFila, rand() % 100);
   }
   fila[0] = proximo(fila[0]);
   fila[1] = proximo(fila[1]);
   fila[2] = proximo(fila[2]);

   fila[0]=criarFila(fila[0]);
   fila[1]=criarFila(fila[1]);
   fila[2]=criarFila(fila[2]);
   for (int i = 0; i < 50; i++){
	   int numFila = rand() % 3;
	  enfileirar(fila[numFila], numFila, rand() % 100);
   }
   fila[0] = proximo(fila[0]);
   fila[1] = proximo(fila[1]);
   fila[2] = proximo(fila[2]);
   exibir(fila[0]);
   exibir(fila[1]);
   exibir(fila[2]);
   int qtdGuiches = 0;

   //perguntar quantos guiches
   perguntarQtdGuiches(&qtdGuiches);
   simulacao(fila[0], fila[1], fila[2]);
   exibir(fila[0]);
   exibir(fila[1]);
   exibir(fila[2]); 
   printf("%i guichês informados\n", qtdGuiches);
   pthread_t threads[qtdGuiches];
   for (int j = 0; j < qtdGuiches; j++){
	pthread_create(&(threads[j], NULL, thread_guiche, &fila);
   }
   return 0;
}

int contadorGuiche = 0;
void *thread_guiche(void *arg){
	*n = (tipo_elementoFila *) *arg;
	int TMA = rand() % 20;
	while(true){
		
		sleep(TMA);
	}

}
