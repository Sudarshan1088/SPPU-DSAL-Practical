#include <iostream>
#include <queue>
using namespace std;

int adj_mat[50][50]; // Adjacency matrix
bool visited[50]; // Visited array

// DFS function to traverse the graph
void dfs(int s, int n, string arr[]) {
    visited[s] = true;
    cout << arr[s] << " "; // Print the current city

    for (int i = 0; i < n; i++) {
        if (adj_mat[s][i] && !visited[i]) { // Check for adjacent cities
            dfs(i, n, arr); // Recursive call
        }
    }
}

// BFS function to traverse the graph
void bfs(int s, int n, string arr[]) {
    bool visited[n] = {false}; // Reset visited array for BFS
    visited[s] = true;

    queue<int> bfsq;
    bfsq.push(s);

    while (!bfsq.empty()) {
        int v = bfsq.front();
        bfsq.pop();
        cout << arr[v] << " "; // Print the current city

        for (int i = 0; i < n; i++) {
            if (adj_mat[v][i] && !visited[i]) { // Check for adjacent cities
                visited[i] = true;
                bfsq.push(i); // Add to queue for BFS
            }
        }
    }
}

int main() {
    int n, u;
    cout << "Enter number of cities: ";
    cin >> n;

    string cities[n]; // Array to store city names
    for (int i = 0; i < n; i++) {
        cout << "Enter city #" << (i + 1) << " (Airport Code): ";
        cin >> cities[i]; // Input city names
    }

    // Initialize the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << ": ";
            cin >> adj_mat[i][j]; // Input for adjacency matrix
        }
    }

    // Display the adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << cities[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << adj_mat[i][j] << "\t"; // Print the matrix
        }
        cout << endl;
    }

    // Get starting city for traversal
    cout << "\nEnter Starting Vertex (by number, 0 to " << n-1 << "): ";
    cin >> u;

    // Call DFS and BFS
    cout << "DFS: ";
    fill(begin(visited), end(visited), false); // Reset visited array before DFS
    dfs(u, n, cities); // Perform DFS
    cout << endl;

    cout << "BFS: ";
    bfs(u, n, cities); // Perform BFS
    cout << endl;

    return 0;
}
