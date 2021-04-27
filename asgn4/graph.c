#include "graph.h"
#include "vertices.h"

#include <stdlib.h>
#include <stdio.h>

struct Graph {
    uint32_t vertices; // Number of vertices.
    bool undirected; // Undirected graph?
    bool visited[VERTICES]; // Where have we gone?
    uint32_t matrix[VERTICES][VERTICES];
};

Graph *graph_create(uint32_t vertices, bool undirected) {
    Graph *G = (Graph *) malloc(sizeof(Graph)); // allocate memory for graph struct
    if (G) {
        G->vertices = vertices;
        G->undirected = undirected;
    }
    return G;

}

void graph_delete(Graph **G) {
    free(G);
    G = NULL;
}

uint32_t graph_vertices(Graph *G){
    return G ? G->vertices : -1;
}

bool graph_add_edge(Graph *G, uint32_t i, uint32_t j, uint32_t k) {
    if (G && i < VERTICES && j < VERTICES) {
        G->matrix[i][j] = k;
        if (G->undirected) {
            G->matrix[j][i] = k;
        }
        return 1;
    }
    return 0;
}

bool graph_has_edge(Graph *G, uint32_t i, uint32_t j) {
    return i; // NOT IMP
}

uint32_t graph_edge_weight(Graph *G, uint32_t i, uint32_t j) {
    return i; // NOT IMP
}

bool graph_visited(Graph *G, uint32_t v) {
    return G ? G->visited[v] : -1;
}

void graph_mark_visited(Graph *G, uint32_t v) {
    if (G) {
        G->visited[v] = 1;
    }
    return;
}

void graph_mark_unvisited(Graph *G, uint32_t v) {
    if (G) {
        G->visited[v] = 0;
    }
    return;
}

void graph_print(Graph *G) {
    for (uint32_t r = 0; r < VERTICES; r++) {
        printf("[");
        for (uint32_t c = 0; c < VERTICES; c++) {
            printf("%d", G->matrix[r][c]);
            if (c != VERTICES - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    return; // NOT IMP
}

int main() {

    Graph *G = graph_create(13, 1);
    graph_add_edge(G, 5, 10, 7);
    printf("%d vertices\n", graph_vertices(G));
    graph_print(G);
    return 1;
}
