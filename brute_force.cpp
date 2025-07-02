#include <iostream>
using namespace std;

const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int minDistance = 1e9;

void recursive(int current, int end, int depth, int numNodes) {
    if (current == end) {
        if (depth < minDistance)
            minDistance = depth;
        return;
    }

    visited[current] = true;
    for (int i = 0; i < numNodes; i++) {
        if (graph[current][i] && !visited[i]) {
            recursive(i, end, depth + 1, numNodes);
        }
    }
    visited[current] = false;
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    for (int i = 0; i < MAX_NODES; i++)
        for (int j = 0; j < MAX_NODES; j++)
            graph[i][j] = 0;

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start, end;
    cin >> start >> end;

    for (int i = 0; i < numNodes; i++)
        visited[i] = false;

    recursive(start, end, 0, numNodes);

    if (minDistance != 1e9)
        cout << minDistance << endl;
    else
        cout << "No path" << endl;

    return 0;
}
