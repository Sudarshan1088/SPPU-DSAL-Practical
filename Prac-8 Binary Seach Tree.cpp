#include <iostream>
#include <iomanip>
using namespace std;

void constructOBST();
void printOBST(int, int);

float a[20], b[20];                 // a: successful probs, b: unsuccessful
float wt[20][20], c[20][20];        // wt: weight matrix, c: cost matrix
int r[20][20];                      // root matrix
int n;

int main() {
    cout << "\n** PROGRAM FOR OPTIMAL BINARY SEARCH TREE (OBST) **\n";
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "\nEnter probabilities for successful search (P):\n";
    for (int i = 1; i <= n; i++) {
        cout << "P[" << i << "]: ";
        cin >> a[i];
    }

    cout << "\nEnter probabilities for unsuccessful search (Q):\n";
    for (int i = 0; i <= n; i++) {
        cout << "Q[" << i << "]: ";
        cin >> b[i];
    }

    constructOBST();
    cout << "\nStructure of OBST (Rooted Tree):\n";
    printOBST(0, n);
    cout << endl;

    return 0;
}

void constructOBST() {
    int i, j, k, l;
    float minval;

    for (i = 0; i <= n; i++) {
        wt[i][i] = b[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }

    for (l = 1; l <= n; l++) { // l is the chain length
        for (i = 0; i <= n - l; i++) {
            j = i + l;
            wt[i][j] = wt[i][j - 1] + a[j] + b[j];
            c[i][j] = 9999;
            for (k = i + 1; k <= j; k++) {
                float cost = c[i][k - 1] + c[k][j] + wt[i][j];
                if (cost < c[i][j]) {
                    c[i][j] = cost;
                    r[i][j] = k;
                }
            }
        }
    }

    cout << "\nOptimal Cost Matrix:\n";
    cout << "C[0][" << n << "] = " << fixed << setprecision(2) << c[0][n] << endl;
    cout << "Root of OBST: Key[" << r[0][n] << "]\n";
}

void printOBST(int i, int j) {
    if (i >= j) return;

    int root = r[i][j];
    cout << "Root of subtree [" << i+1 << "..." << j << "] is Key[" << root << "]\n";

    if (r[i][root - 1] != 0)
        cout << " Left child of Key[" << root << "] is Key[" << r[i][root - 1] << "]\n";
    else
        cout << " Left child of Key[" << root << "] is a dummy node\n";

    if (r[root][j] != 0)
        cout << " Right child of Key[" << root << "] is Key[" << r[root][j] << "]\n";
    else
        cout << " Right child of Key[" << root << "] is a dummy node\n";

    printOBST(i, root - 1);
    printOBST(root, j);
}

