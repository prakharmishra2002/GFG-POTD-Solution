#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct graph {
    struct Node** adjList;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

bool dfsCycleDetection(int node, bool* visited, bool* recStack, struct graph* g) {
    visited[node] = true;
    recStack[node] = true;

    struct Node* temp = g->adjList[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfsCycleDetection(neighbor, visited, recStack, g)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            return true;  // Cycle detected
        }
        temp = temp->next;
    }

    recStack[node] = false; // Backtrack
    return false;
}

bool isCycle(struct graph* g, int n, int m) {
    // Initialize visited and recursion stack
    bool* visited = (bool*)calloc(n, sizeof(bool));
    bool* recStack = (bool*)calloc(n, sizeof(bool));

    // Check for cycles in each component
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycleDetection(i, visited, recStack, g)) {
                free(visited);
                free(recStack);
                return true;
            }
        }
    }

    free(visited);
    free(recStack);
    return false;
}
