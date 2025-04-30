#include <iostream>
using namespace std;

// Node structure for TBT
struct Node {
    int data;
    Node *left, *right;
    int lbit, rbit; // Left and right thread flags
};

class TBT {
    Node *head; // Dummy head node

public:
    TBT() {
        head = new Node();
        head->left = head;
        head->right = head;
        head->lbit = 0;
        head->rbit = 1;
    }

    // Create a new node
    Node* createNode() {
        Node *newNode = new Node();
        cout << "Enter data: ";
        cin >> newNode->data;
        newNode->left = newNode->right = nullptr;
        newNode->lbit = newNode->rbit = 0;
        return newNode;
    }

    // Insert a new node into TBT
    void insert() {
        Node *newNode = createNode();

        // If tree is empty
        if (head->left == head) {
            head->left = newNode;
            head->lbit = 1;
            newNode->left = head;
            newNode->right = head;
        } else {
            Node *current = head->left, *parent = nullptr;

            while (true) {
                parent = current;

                // Go left
                if (newNode->data < current->data) {
                    if (current->lbit == 1)
                        current = current->left;
                    else {
                        newNode->left = current->left;
                        newNode->right = current;
                        current->left = newNode;
                        current->lbit = 1;
                        break;
                    }
                }
                // Go right
                else {
                    if (current->rbit == 1)
                        current = current->right;
                    else {
                        newNode->right = current->right;
                        newNode->left = current;
                        current->right = newNode;
                        current->rbit = 1;
                        break;
                    }
                }
            }
        }
    }

    // In-order display
    void inorderDisplay(Node *root) {
        if (root == head || root == nullptr)
            return;

        if (root->lbit == 1)
            inorderDisplay(root->left);

        cout << root->data << " ";

        if (root->rbit == 1)
            inorderDisplay(root->right);
    }

    // Threaded traversal (inorder)
    void threadedTraversal() {
        cout << "\nThreaded Inorder Traversal: ";
        printThreaded(head->left);
    }

    void printThreaded(Node *root) {
        if (root == nullptr || root == head)
            return;

        if (root->lbit == 1)
            printThreaded(root->left);

        cout << root->data << " ";

        if (root->rbit == 1)
            printThreaded(root->right);
    }

    Node* getRoot() {
        return head->left;
    }
};

int main() {
    TBT tree;
    int choice;

    while (true) {
        cout << "\n\n--- Threaded Binary Tree Menu ---\n";
        cout << "1. Insert Data\n";
        cout << "2. Inorder Display\n";
        cout << "3. Threaded Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: tree.insert(); break;
            case 2: 
                cout << "Inorder Display: ";
                tree.inorderDisplay(tree.getRoot());
                break;
            case 3: tree.threadedTraversal(); break;
            case 4: return 0;
            default: cout << "Invalid choice. Try again!\n";
        }
    }
}
