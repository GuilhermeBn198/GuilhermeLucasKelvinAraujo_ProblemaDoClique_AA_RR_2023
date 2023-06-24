#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

void criarGrafo() {

    FILE *f = fopen("ArquivoGrafo.txt", "w");

    if (f == NULL) {
        printf("\n\nNao foi possivel gerar o arqivo...");
        exit(1);
    }

    int vert;
    printf("\n\n\t\tDigite o total de vertices: ");
    scanf("%d", &vert);

    printf("\n\n\t\t...Gerando arquivo...\n\n");

    // Add comments and metadata
    fprintf(f, "c\n");
    fprintf(f, "c Complete Graph Generator\n");
    fprintf(f, "c\n");
    fprintf(f, "c Graph Size:%d\n", vert);
    fprintf(f, "c\n");

    // Calculate the total number of edges in a complete graph
    int total_edges = (vert * (vert - 1)) / 2;

    // Add "p edge" line
    fprintf(f, "p edge %d %d\n", vert, total_edges);

    int i, j;

    for (i = 0; i < vert; i++) {
        for (j = i + 1; j <= vert; j++) {
            if (i != j) {
                fprintf(f, "e %d %d\n", i, j); // Replace with "e" format
            }
        }
    }

    fclose(f);

    printf("\t\tArquivo Gerado...\n\n");

}

int main() {
    criarGrafo();
    return 0;
}
