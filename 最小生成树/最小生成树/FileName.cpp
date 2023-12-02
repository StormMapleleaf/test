#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_VERTICES 100

// �ߵĽṹ�壬�����յ��Ȩ��
typedef struct {
    int vertex;
    int weight;
} Edge;

// ͼ�Ľṹ�壬�������������ߵ������ÿ������ıߵ�����
typedef struct {
    Edge* edges[MAX_VERTICES];
    int numEdges[MAX_VERTICES];
    int numVertices;
} Graph;

// ����ͼ����ʼ��
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    if (graph == NULL) {
        fprintf(stderr, "Memory allocation failed for graph.\n");
        exit(EXIT_FAILURE);
    }

    graph->numVertices = numVertices;

    // ��ʼ��ÿ������ıߵ�����Ϊ0����Ϊÿ������ı���������ڴ�
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

// ��ͼ�����һ����
void addEdge(Graph* graph, int startVertex, int endVertex, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));

    if (newEdge == NULL) {
        fprintf(stderr, "Memory allocation failed for new edge.\n");
        exit(EXIT_FAILURE);
    }

    // ��ʼ���±ߵ��յ��Ȩ��
    newEdge->vertex = endVertex;
    newEdge->weight = weight;

    // ���±���ӵ����ı������У����������ıߵ�����
    graph->edges[startVertex][graph->numEdges[startVertex]] = *newEdge;
    graph->numEdges[startVertex]++;
}

// Prim�㷨ʵ�֣��ҵ���С������
void primMST(Graph* graph) {
    int parent[MAX_VERTICES]{};
    int key[MAX_VERTICES]{};
    int inMST[MAX_VERTICES]{};

    for (int i = 0; i < graph->numVertices; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;// ѡ����ʼ����

    // ѭ��������С������
    for (int count = 0; count < graph->numVertices - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;

        // ����δ��������С�������еĶ�����ѡ�������С��ֵ�Ķ���
        for (int v = 0; v < graph->numVertices; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = 1;// ��ѡ���Ķ�����Ϊ�ѷ���

        // �������ڶ���ļ�ֵ�͸��ڵ�
        for (int i = 0; i < graph->numEdges[u]; i++) {
            int v = graph->edges[u][i].vertex;
            int weight = graph->edges[u][i].weight;

            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    // �����С�������ı߼���Ȩ��
    printf("Edge \tWeight\n");
    for (int i = 1; i < graph->numVertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, key[i]);
    }

    // ���㲢�����С���������ܻ���
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

    // ����ÿ���ߵ���Ϣ����ӵ�ͼ��
    for (int i = 0; i < numEdges; i++) {
        int startVertex, endVertex, weight;
        printf("Enter edge %d (start end weight): ", i + 1);
        scanf_s("%d %d %d", &startVertex, &endVertex, &weight);
        addEdge(graph, startVertex, endVertex, weight);
        addEdge(graph, endVertex, startVertex, weight); 
    }

    // ִ��Prim�㷨�������С������
    printf("Minimum Spanning Tree:\n");
    primMST(graph);

    return 0;
}
