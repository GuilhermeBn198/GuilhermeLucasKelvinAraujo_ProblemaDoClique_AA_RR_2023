#include <stdio.h>
#include <stdbool.h>

#define TAM 100
#define PRETO 1

typedef struct {
    int tamVertices;
    int Matriz[TAM][TAM];
    int vetVisitado[TAM];
} Grafo;

int degree(Grafo *graph, int vertex) {
    int degree = 0;
    for (int i = 0; i < graph->tamVertices; i++) {
        if (graph->Matriz[vertex][i] == 1) {
            degree++;
        }
    }
    return degree;
}

void greedyClique(Grafo *graph) {
    int clique[TAM] = {0};
    int cliqueSize = 0;
    bool isVisited[TAM] = {false};
    int unvisited = graph->tamVertices;

    while (unvisited > 0) {
        int maxDegree = -1;
        int maxVertex = -1;

        // Find the vertex with the highest degree
        for (int i = 0; i < graph->tamVertices; i++) {
            if (!isVisited[i] && degree(graph, i) > maxDegree) {
                maxDegree = degree(graph, i);
                maxVertex = i;
            }
        }

        bool isConnectedToAll = true;
        for (int i = 0; i < cliqueSize; i++) {
            if (graph->Matriz[maxVertex][clique[i]] != 1) {
                isConnectedToAll = false;
                break;
            }
        }

        if (isConnectedToAll) {
            clique[cliqueSize++] = maxVertex;
        }

        isVisited[maxVertex] = true;
        unvisited--;
    }

    printf("Greedy clique: ");
    for (int i = 0; i < cliqueSize; i++) {
        printf("%d ", clique[i]);
    }
    printf("\n");
}
