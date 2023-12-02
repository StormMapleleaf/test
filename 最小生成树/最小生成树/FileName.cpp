#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_VERTICES 100

// 边的结构体，包含终点和权重
typedef struct {
    int vertex;
    int weight;
} Edge;

// 图的结构体，包含顶点数、边的数组和每个顶点的边的数量
typedef struct {
    Edge* edges[MAX_VERTICES];
    int numEdges[MAX_VERTICES];
    int numVertices;
} Graph;

// 创建图并初始化
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    if (graph == NULL) {
        fprintf(stderr, "Memory allocation failed for graph.\n");
        exit(EXIT_FAILURE);
    }

    graph->numVertices = numVertices;

    // 初始化每个顶点的边的数量为0，并为每个顶点的边数组分配内存
    for (int i = 0; i < numVertices; i++) {
        graph->numEdges[i] = 0;
        graph->edges[i] = (Edge*)malloc(MAX_VERTICES * sizeof(Edge));

        if (graph->edges[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for edges array.\n");
            exit(EXIT_FAILURE);
        }
    }

    return graph;
}

// 向图中添加一条边
void addEdge(Graph* graph, int startVertex, int endVertex, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));

    if (newEdge == NULL) {
        fprintf(stderr, "Memory allocation failed for new edge.\n");
        exit(EXIT_FAILURE);
    }

    // 初始化新边的终点和权重
    newEdge->vertex = endVertex;
    newEdge->weight = weight;

    // 将新边添加到起点的边数组中，并增加起点的边的数量
    graph->edges[startVertex][graph->numEdges[startVertex]] = *newEdge;
    graph->numEdges[startVertex]++;
}

// Prim算法实现，找到最小生成树
void primMST(Graph* graph) {
    int parent[MAX_VERTICES]{};
    int key[MAX_VERTICES]{};
    int inMST[MAX_VERTICES]{};

    for (int i = 0; i < graph->numVertices; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;// 选择起始顶点

    // 循环构建最小生成树
    for (int count = 0; count < graph->numVertices - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;

        // 从尚未包含在最小生成树中的顶点中选择具有最小键值的顶点
        for (int v = 0; v < graph->numVertices; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = 1;// 将选定的顶点标记为已访问

        // 更新相邻顶点的键值和父节点
        for (int i = 0; i < graph->numEdges[u]; i++) {
            int v = graph->edges[u][i].vertex;
            int weight = graph->edges[u][i].weight;

            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    // 输出最小生成树的边及其权重
    printf("Edge \tWeight\n");
    for (int i = 1; i < graph->numVertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, key[i]);
    }

    // 计算并输出最小生成树的总花费
    int totalCost = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        totalCost += key[i];
    }

    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf_s("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf_s("%d", &numEdges);

    // 输入每条边的信息并添加到图中
    for (int i = 0; i < numEdges; i++) {
        int startVertex, endVertex, weight;
        printf("Enter edge %d (start end weight): ", i + 1);
        scanf_s("%d %d %d", &startVertex, &endVertex, &weight);
        addEdge(graph, startVertex, endVertex, weight);
        addEdge(graph, endVertex, startVertex, weight); 
    }

    // 执行Prim算法并输出最小生成树
    printf("Minimum Spanning Tree:\n");
    primMST(graph);

    return 0;
}
