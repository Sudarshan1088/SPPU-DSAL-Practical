#include <iostream>
#include <string>
using namespace std;

class Tree {
    struct Node {
        string key, meaning;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root = nullptr;

public:
    Tree() = default;
    ~Tree() { destroyTree(root); }

    void create();
    void insert(Node*& root, Node* newNode);
    void inorder() const;
    void inorder_rec(Node* root) const;
    void postorder() const;
    void postorder_rec(Node* root) const;
    void destroyTree(Node* root);
};

void Tree::inorder_rec(Node* root) const {
    if (root) {
        inorder_rec(root->left);
        cout << "\n\t" << root->key << "\t" << root->meaning;
        inorder_rec(root->right);
    }
}

void Tree::postorder_rec(Node* root) const {
    if (root) {
        postorder_rec(root->left);
        postorder_rec(root->right);
        cout << "\n\t" << root->key << "\t" << root->meaning;
    }
}

void Tree::create() {
    Node* newNode = new Node;

    cout << "\nEnter the keyword: ";
    cin >> newNode->key;
    cout << "Enter the meaning of " << newNode->key << ": ";
    cin >> newNode->meaning;

    if (!root) {
        root = newNode;
    } else {
        insert(root, newNode);
    }
}

void Tree::insert(Node*& root, Node* newNode) {
    if (!root) {
        root = newNode;
    } else if (newNode->key < root->key) {
        insert(root->left, newNode);
    } else if (newNode->key > root->key) {
        insert(root->right, newNode);
    } else {
        cout << "Keyword already exists in the dictionary.\n";
    }
}

void Tree::destroyTree(Node* root) {
    if (root) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

void Tree::inorder() const { inorder_rec(root); }

void Tree::postorder() const { postorder_rec(root); }

int main() {
    Tree dictionary;
    int choice;
    char ans;

    do {
        cout << "\n**** BST Operations ****";
        cout << "\n1. Insert keyword";
        cout << "\n2. Display dictionary";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                do {
                    dictionary.create();
                    cout << "Do you want to add another keyword? (y/n): ";
                    cin >> ans;
                } while (ans == 'y' || ans == 'Y');
                break;

            case 2:
                cout << "\n1. Ascending order\n2. Descending order\nEnter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "\nDictionary (Ascending Order - Inorder):";
                        dictionary.inorder();
                        break;
                    case 2:
                        cout << "\nDictionary (Descending Order - Postorder):";
                        dictionary.postorder();
                        break;
                    default:
                        cout << "Invalid choice!";
                }
                break;

            case 3:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice!";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
