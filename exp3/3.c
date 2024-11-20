#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int vertex, weight;
} Node;

typedef struct {
    int v, e;
    Edge *edges;
} Graph;

Graph* createGraph(int v, int e) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->v = v;
    graph->e = e;
    graph->edges = (Edge*)malloc(e * sizeof(Edge));
    return graph;
}

void bellmanFord(Graph* graph, int src) {
    int v = graph->v, e = graph->e;
    int dist[v];
    for (int i = 0; i < v; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int j = 0; j < e; j++) {
        int u = graph->edges[j].src;
        int v = graph->edges[j].dest;
        int weight = graph->edges[j].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Bellman-Ford distances:\n");
    for (int i = 0; i < v; i++) printf("%d -> %d: %d\n", src, i, dist[i]);
}

void dijkstra(int v, int graph[v][v], int src) {
    int dist[v], visited[v];
    for (int i = 0; i < v; i++) dist[i] = INF, visited[i] = 0;
    dist[src] = 0;

    for (int count = 0; count < v - 1; count++) {
        int min = INF, u;
        for (int i = 0; i < v; i++)
            if (!visited[i] && dist[i] <= min) min = dist[i], u = i;

        visited[u] = 1;

        for (int i = 0; i < v; i++)
            if (!visited[i] && graph[u][i] && dist[u] != INF && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
    }

    printf("Dijkstra distances:\n");
    for (int i = 0; i < v; i++) printf("%d -> %d: %d\n", src, i, dist[i]);
}

int main() {
    int v = 5, e = 8;
    Graph* graph = createGraph(v, e);
    graph->edges[0] = (Edge){0, 1, -1};
    graph->edges[1] = (Edge){0, 2, 4};
    graph->edges[2] = (Edge){1, 2, 3};
    graph->edges[3] = (Edge){1, 3, 2};
    graph->edges[4] = (Edge){1, 4, 2};
    graph->edges[5] = (Edge){3, 2, 5};
    graph->edges[6] = (Edge){3, 1, 1};
    graph->edges[7] = (Edge){4, 3, -3};

    int adjMatrix[5][5] = {
        {0, -1, 4, 0, 0},
        {0, 0, 3, 2, 2},
        {0, 0, 0, 0, 0},
        {0, 1, 5, 0, 0},
        {0, 0, 0, -3, 0}
    };

    bellmanFord(graph, 0);
    dijkstra(v, adjMatrix, 0);

    return 0;
}
