#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TRUE  1
#define FALSE 0
#define PRETO 10
#define TAM 30001


//
//
//
// quando for compilar, botar o nome do arquivo resultante como main, então executar o arquivo python
//
//
//
//




struct grafo{
	int tamVertices;
	int vetVisitado[TAM];
	int Matriz[TAM][TAM];
}Grafo;

struct cliqueMax{
	int Principal;
	int tamClique;
	int vetClique[TAM];
}CliqueMax;

void pulaLinha(){
	printf("\n");
}

void imprimeMatriz(){
    printf("\n\n\t...Imprimindo Matriz de Adjacencia...\n\n");
    int i , j;
    printf("\tTotal de Vertices = %d\n\n",Grafo.tamVertices);
    printf("\t");
    for(i=0 ; i<=Grafo.tamVertices ; i++){
        printf("%d\t",i);
    }
    pulaLinha();pulaLinha();
    for(i=0 ; i<=Grafo.tamVertices ; i++){
        printf("%d\t",i);
        for(j=0 ; j<=Grafo.tamVertices ; j++){
            printf("%d\t",Grafo.Matriz[i][j]);
        }
        pulaLinha();
    }
    pulaLinha();

}

void limparGrafo(){
    int i,j;
    for(i=0;i<TAM;i++){
        Grafo.vetVisitado[i]=0;
        Grafo.tamVertices=0;
        for(j=0;j<TAM;j++){
            Grafo.Matriz[i][j]=0;
        }
    }
}

void limpaClique(){
    int i;
    CliqueMax.Principal=-1;
    CliqueMax.tamClique=0;
    for(i=0;i<TAM;i++){
        CliqueMax.vetClique[i]=-1;
    }
}

void lerArquivo(const char* input_file_path) {
    limparGrafo();
    FILE *f = fopen(input_file_path, "r");
    if (f == NULL) {
        system("clear");
        printf("\n\n\tNao foi possivel acessar o arquivo...\n\n");
        exit(1);
    }
    //printf("\n\n\t...Lendo Arquivo com Grafo...\n\n");
    char line[256];
    int totalVertices, totalEdges;
    char keyword[10];
    while (fgets(line, sizeof(line), f)) {
        if (line[0] == 'p') {
            sscanf(line, "p %s %d %d", keyword, &totalVertices, &totalEdges);
            Grafo.tamVertices = totalVertices;
        } else if (line[0] == 'e') {
            int v, a;
            sscanf(line, "e %d %d", &v, &a);
            Grafo.Matriz[v][a] = 1;
            Grafo.Matriz[a][v] = 1;
        }
    }
    fclose(f);
}

void zeraVisitado(){
    int i;
    for(i=0 ; i< Grafo.tamVertices+10 ; i++){
        Grafo.vetVisitado[i] = 0;
    }
}

void verificarCliqueMaximo(){
    limpaClique();
    int  vertice , i , j , tam_adj;
    tam_adj = 0;
    int vet_adj[TAM]={0};
    // printf("\t\t...Procurando Clique no Grafo...\n\n");

	for(vertice=0 ; vertice <= Grafo.tamVertices ; vertice++){
        if(Grafo.vetVisitado[vertice] == PRETO) continue;
        printf("Verificando vertice %d.\n",vertice);
        tam_adj=0;

		//pega os adjacentes ao vertice selecionado
		for(i=0 ; i <= Grafo.tamVertices ; i++){
			if(Grafo.Matriz[ vertice ][ i ] == 1){
				vet_adj[ tam_adj] = i; tam_adj++;
			}
		}

        //verifica os cliques
		for(i=0 ; i<tam_adj-1 ; i++){
			if(vet_adj[i] == -1) continue;
			for(j = i+1 ; j < tam_adj ; j++){
				if(vet_adj[j] != -1 && Grafo.Matriz[ vet_adj[i] ][ vet_adj[j] ] != 1){
					//se no fizer ligação com algum fica fora do clique
					vet_adj[j] = -1;
				}
			}
		}

        //verifica o tamanho do clique
		int tot = 1;
		for(i = 0 ; i < tam_adj ; i++){
			if( vet_adj[i] != -1){
				tot++;
			}
		}

        //verifica se é maior que o maior ja encontrado
		if( tot > CliqueMax.tamClique){
			CliqueMax.tamClique = tot;
			CliqueMax.Principal = vertice;
            Grafo.vetVisitado[vertice] = PRETO;
			int k=0;
			for(i=0 ; i<tam_adj ; i++){
				if(vet_adj[i] != -1){
					CliqueMax.vetClique[k++] = vet_adj[i];
					Grafo.vetVisitado[ vet_adj[i] ] = PRETO;
				}
			}
		}else{ //marca o clique como ja encontrado, mesmo nao sendo maximo
            Grafo.vetVisitado[vertice] = PRETO;
            int y;
            for(y=0 ; y<tam_adj ; y++){
                if(vet_adj[y] != -1)
                    Grafo.vetVisitado[ vet_adj[y] ] = PRETO;
            }
		}
	}
}

void imprimeCliqueMax(){
	int i , j;
	// printf("\n\n\t\t...Impressao das Arestas...\n\n");
	
    if(CliqueMax.tamClique > 1) printf("\tClique maximo no Grafo = %d.\n\n",CliqueMax.tamClique);
    else printf("\tClique maximo no Grafo = %d.\n\n",CliqueMax.tamClique - 1);
	
    // for(i=0 ; i<CliqueMax.tamClique -1 ; i++){
	// 	printf("\t\t%d <----> %d\n",CliqueMax.Principal,CliqueMax.vetClique[i]);
	// }

	// for(i=0 ; i < CliqueMax.tamClique -2 ; i++){
	// 	for(j = i + 1; j < CliqueMax.tamClique-1 ; j++){
	// 		printf("\t\t%d <----> %d\n",CliqueMax.vetClique[i], CliqueMax.vetClique[j]);
	// 	}
	// }

}

int main(int argc, char *argv[]){
	if (argc < 2) {
        printf("Usage: %s <input_file_path>\n", argv[0]);
        return 1;
    }
    const char *input_file_path = argv[1];
    lerArquivo(input_file_path);
	if(Grafo.tamVertices < 21)
            imprimeMatriz();
    else
        printf("\nNao vai imprimir tabela.. total de vertices > 20\n\n");

	clock_t ci , cf;
    ci = clock();//clock inicial
	verificarCliqueMaximo();
    cf = clock();//clock final

    double tempoTotal = (double) (cf - ci) / (double) CLOCKS_PER_SEC;

	imprimeCliqueMax();

    printf("\nTempo total Clique: %lf seg\n\n",tempoTotal);

	return 0;
}
