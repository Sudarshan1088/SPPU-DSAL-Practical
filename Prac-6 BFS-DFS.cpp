#include <iostream>
#include <stdlib.h>
using namespace std;

int matrix[10][10], n, m, v; // Adjacency matrix, number of vertices, and edges
int qu[10], front = 0, rear = 0; // Queue for BFS
int visited[10] = {0}; // To mark visited nodes for BFS
int stk[10], top = -1; // Stack for DFS
int visited1[10] = {0}; // To mark visited nodes for DFS

// Main function
int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    // Initializing adjacency matrix to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    // Input edges to create the graph
    cout << "\nEnter edges (format: u v):\n";
    for (int k = 0; k < m; k++) {
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1; // Since it's an undirected graph
    }

    // Display adjacency matrix
    cout << "\nThe adjacency matrix of the graph is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // BFS Implementation
    cout << "\nEnter initial vertex for BFS: ";
    cin >> v;
    cout << "The BFS traversal of the graph is: ";
    
    visited[v] = 1; // Mark the starting vertex as visited
    qu[rear++] = v; // Enqueue the starting vertex

    while (front < rear) {
        v = qu[front++]; // Dequeue the front vertex
        cout << v << " "; // Print the vertex
        for (int j = 0; j < n; j++) {
            if (matrix[v][j] != 0 && visited[j] == 0) { // If there's an edge and the node is unvisited
                visited[j] = 1; // Mark the node as visited
                qu[rear++] = j; // Enqueue the node
            }
        }
    }
    cout << endl;

    // DFS Implementation
    cout << "\nEnter initial vertex for DFS: ";
    cin >> v;
    cout << "The DFS traversal of the graph is: ";

    visited1[v] = 1; // Mark the starting vertex as visited
    stk[++top] = v; // Push the starting vertex onto the stack

    while (top != -1) { // While stack is not empty
        v = stk[top--]; // Pop the top vertex from the stack
        cout << v << " "; // Print the vertex
        for (int j = n - 1; j >= 0; j--) { // Iterate through the neighbors (reverse order for DFS)
            if (matrix[v][j] != 0 && visited1[j] == 0) { // If there's an edge and the node is unvisited
                visited1[j] = 1; // Mark the node as visited
                stk[++top] = j; // Push the node onto the stack
            }
        }
    }
    cout << endl;

    return 0;
}
