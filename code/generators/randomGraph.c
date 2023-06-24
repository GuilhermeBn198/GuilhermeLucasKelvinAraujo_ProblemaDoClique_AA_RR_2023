#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void criar_Grafo() {

    FILE *f = fopen("ArquivoGrafo.txt", "w");

    if (f == NULL) {
        printf("Nao foi possivel gravar no arquivo....\n\n");
        exit(1);
    }

    int vertices;

    printf("Informe o Total de Vertices: ");
    scanf("%d", &vertices);

    printf("\n\n\tgerando....\n\n");

    // Add comments and metadata
    fprintf(f, "c\n");
    fprintf(f, "c Random Graph Generator\n");
    fprintf(f, "c\n");
    fprintf(f, "c Graph Size:%d\n", vertices);
    fprintf(f, "c\n");

    int total_edges = 0;
    int i, j;

    // Count the total number of edges
    for (i = 0; i < vertices + 1; i++) {
        int k = rand() % (vertices + 1);
        for (j = 0; j < k; j++) {
            total_edges++;
        }
    }

    // Add "p edge" line
    fprintf(f, "p edge %d %d\n", vertices, total_edges);

    // Generate edges with "e" format
    for (i = 0; i < vertices + 1; i++) {
        int k = rand() % (vertices + 1);
        for (j = 0; j < k; j++) {
            int h;
            do {
                h = rand() % (vertices + 1);
            } while (i == h);
            fprintf(f, "e %d %d\n", i, h);
        }
    }

    fclose(f);

}

int main() {
    criar_Grafo();
    return 0;
}
