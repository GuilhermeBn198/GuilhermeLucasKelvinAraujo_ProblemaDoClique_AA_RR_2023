#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar o grafo
typedef struct {
    int num_vertices;
    int** adjacency_matrix;
} Graph;

// função para criar um grafo com um numero especifico de vertices
Graph* create_graph(int num_vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_matrix = malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = calloc(num_vertices, sizeof(int));
    }
    return graph;
}

// Função para adionar as arestas ao grafo
void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
}

// função para checar se os vertices são adjacentes
int is_adjacent(Graph* graph, int vertex1, int vertex2) {
    return graph->adjacency_matrix[vertex1][vertex2];
}

// Funcção para calcular peso dos vestices
int degree(Graph* graph, int vertex) {
    int deg = 0;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (is_adjacent(graph, vertex, i)) {
            deg++;
        }
    }
    return deg;
}

// função implmentando o algoritmo guloso para o problema do clique máximo
int* greedy_clique(Graph* graph) {
    int* result = malloc(graph->num_vertices * sizeof(int));
    int result_count = 0;

    for (int vertex = 0; vertex < graph->num_vertices; vertex++) {
        int is_adjacent_to_all_in_result = 1;
        for (int i = 0; i < result_count; i++) {
            // checa se o vertice atual é adjacente a todos os outros vertices de result
            if (!is_adjacent(graph, vertex, result[i])) {
                is_adjacent_to_all_in_result = 0;
                break;
            }
        }
        // se o vertice atual é adjacente a todos os outros vertices, adiciona-o ao result
        if (is_adjacent_to_all_in_result) {
            result[result_count++] = vertex;
        }
    }

    return result;
}

int main() {
    int num_vertices = 5;
    Graph* graph = create_graph(num_vertices);

    // adiciona as arestas
__FILE__ 


    // aplica o algoritmo guloso
    int* result = greedy_clique(graph);

    // retorna os resultados
    printf("The vertices in the clique are: \n\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", result[i]);
    }
    printf("\n\n");
    // libera a memória
    free(result);
    free(graph);

    return 0;
}
