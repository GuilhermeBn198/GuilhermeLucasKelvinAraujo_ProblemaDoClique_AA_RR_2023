#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int find_degree(int **graph, int vertex, int *clique, int n) {
    int degree = 0;
    for (int i = 0; i < n; i++) {
        if (clique[i] && graph[vertex][i]) {
            degree++;
        }
    }
    return degree;
}

int *find_maximal_clique(int **graph, int n) {
    int *current_clique = (int *)calloc(n, sizeof(int));
    int *remaining_vertices = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        remaining_vertices[i] = 1;
    }

    while (true) {
        int best_vertex = -1;
        int best_vertex_degree = -1;

        for (int v = 0; v < n; v++) {
            if (remaining_vertices[v]) {
                int degree = find_degree(graph, v, current_clique, n);
                if (degree > best_vertex_degree) {
                    best_vertex = v;
                    best_vertex_degree = degree;
                }
            }
        }

        if (best_vertex_degree == -1) {
            break;
        }

        int clique_size = 0;
        for (int i = 0; i < n; i++) {
            if (current_clique[i]) {
                clique_size++;
            }
        }

        if (best_vertex_degree == clique_size) {
            current_clique[best_vertex] = 1;
            remaining_vertices[best_vertex] = 0;
        } else {
            break;
        }
    }

    return current_clique;
}

int **read_dimacs_graph(const char *file_path, int *n) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[256];
    int num_vertices, num_edges;

    

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == 'p') {
            sscanf(line, "p col %d %d", &num_vertices, &num_edges);
            *n = num_vertices; // Update the value of n
            break;
        }
    }

    int **graph = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        graph[i] = (int *)calloc(num_vertices, sizeof(int));
    }

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == 'e') {
            int v1, v2;
            sscanf(line, "e %d %d", &v1, &v2);
            if (v1 >= 1 && v1 <= *n && v2 >= 1 && v2 <= *n) {
                graph[v1 - 1][v2 - 1] = 1;
                graph[v2 - 1][v1 - 1] = 1;
            } else {
                printf("Invalid edge: e %d %d\n", v1, v2);
            }
        }
    }

    fclose(file);

    *n = num_vertices;
    return graph;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path_to_graph_file>\n", argv[0]);
        return 1;
    }

    int n;
    int **graph = read_dimacs_graph(argv[1], &n);

    int *maximal_clique = find_maximal_clique(graph, n);

    printf("Maximal Clique: ");
    for (int i = 0; i < n; i++) {
        if (maximal_clique[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(maximal_clique);

    return 0;
}
