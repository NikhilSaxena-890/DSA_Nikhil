#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for (int i = 0; i < n; i++) {
        if (i != node && graph[i][node] == 1 && color[i] == col) {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int n, int m, bool graph[101][101]) {
    if (node == n) {
        return true;
    }
    
    for (int i = 1; i <= m; i++) { // Colors are numbered from 1 to m
        if (isSafe(node, color, graph, n, i)) {
            color[node] = i;
            if (solve(node + 1, color, n, m, graph)) {
                return true;
            }
            color[node] = 0; // Backtrack
        }
    }
    
    return false;
}

bool N_Coloring(bool graph[101][101], int m, int n) {
    int color[101] = {0}; // Initialize all colors to 0
    return solve(0, color, n, m, graph);
}

int main() {
    int n = 4; // Number of vertices
    int m = 3; // Number of colors
    bool graph[101][101] = { {0} };

    // Sample adjacency matrix representation of a graph
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][3] = graph[3][2] = 1;

    if (N_Coloring(graph, m, n)) {
        cout << "Graph can be colored with " << m << " colors.\n";
    } else {
        cout << "Graph cannot be colored with " << m << " colors.\n";
    }

    return 0;
}
