#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

class Stack {
    Node* arr[30];
    int top;

public:
    Stack() { top = -1; }

    void push(Node* node) {
        arr[++top] = node;
    }

    Node* pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

class ExpressionTree {
public:
    Node* root;

    ExpressionTree() {
        root = nullptr;
    }

    void createFromPrefix(char expr[]) {
        Stack s;
        int len = strlen(expr);

        for (int i = len - 1; i >= 0; i--) {
            Node* newNode = new Node;
            newNode->data = expr[i];
            newNode->left = newNode->right = nullptr;

            if (isalpha(expr[i])) {
                s.push(newNode);
            } else if (strchr("+-*/", expr[i])) {
                newNode->left = s.pop();
                newNode->right = s.pop();
                s.push(newNode);
            }
        }

        root = s.pop();
    }

    void nonRecursivePostorder(Node* node) {
        if (!node) return;

        Stack s1, s2;
        s1.push(node);

        while (!s1.isEmpty()) {
            Node* temp = s1.pop();
            s2.push(temp);

            if (temp->left) s1.push(temp->left);
            if (temp->right) s1.push(temp->right);
        }

        cout << "\nPostorder traversal: ";
        while (!s2.isEmpty()) {
            cout << s2.pop()->data << " ";
        }
        cout << endl;
    }

    void deleteTree(Node* node) {
        if (!node) return;

        deleteTree(node->left);
        deleteTree(node->right);
        cout << "Deleting node: " << node->data << endl;
        delete node;
    }
};

int main() {
    ExpressionTree tree;
    char expr[30];

    cout << "Enter prefix expression: ";
    cin >> expr;

    tree.createFromPrefix(expr);
    tree.nonRecursivePostorder(tree.root);
    tree.deleteTree(tree.root);

    return 0;
}
