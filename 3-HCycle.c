#include<stdio.h>
#include<stdbool.h>

int graph[10][10];
int path[100];
int NODE;

void displayCycle();
bool isValid(int v, int k);
bool cycleFound(int k);
bool hamiltonianCycle();

int main() {
    int i, j;
    printf("HAMILTONIAN CYCLE - BACKTRACKING\n\n");
    printf("Enter the number of nodes in the graph:\n");
    scanf("%d", &NODE);
    
    printf("Enter the Adjacency Matrix:\n");
    for (i = 0; i < NODE; i++) {
        for (j = 0; j < NODE; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("\n");
    hamiltonianCycle();
    return 0;
}

void displayCycle() {
    printf("The Hamiltonian Cycle:\n");
    for (int i = 0; i < NODE; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

bool isValid(int v, int k) {
    if (graph[path[k-1]][v] == 0)
        return false;
    for (int i = 0; i < k; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool cycleFound(int k) {
    if (k == NODE) {
        if (graph[path[k-1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    
    for (int v = 1; v < NODE; v++) {
        if (isValid(v, k)) {
            path[k] = v;
            if (cycleFound(k + 1) == true)
                return true;
            path[k] = -1;
        }
    }
    return false;
}

bool hamiltonianCycle() {
    for (int i = 0; i < NODE; i++)
        path[i] = -1;
    path[0] = 0;
    
    if (cycleFound(1) == false) {
        printf("Solution does not exist\n");
        return false;
    }
    
    displayCycle();
    return true;
}
