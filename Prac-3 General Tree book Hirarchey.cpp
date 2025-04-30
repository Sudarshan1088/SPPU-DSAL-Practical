#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string label;
    vector<Node*> children;
};

class GeneralTree {
    Node* root;

public:
    GeneralTree() {
        root = nullptr;
    }

    void createTree() {
        root = new Node;
        cout << "Enter book title: ";
        cin >> root->label;

        int chapterCount;
        cout << "Enter number of chapters: ";
        cin >> chapterCount;

        for (int i = 0; i < chapterCount; i++) {
            Node* chapter = new Node;
            cout << "Enter name of Chapter " << i + 1 << ": ";
            cin >> chapter->label;

            int sectionCount;
            cout << "Enter number of sections in Chapter " << chapter->label << ": ";
            cin >> sectionCount;

            for (int j = 0; j < sectionCount; j++) {
                Node* section = new Node;
                cout << "Enter name of Section " << j + 1 << ": ";
                cin >> section->label;
                chapter->children.push_back(section);
            }

            root->children.push_back(chapter);
        }
    }

    void displayTree() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }

        cout << "\n--- Book Hierarchy ---";
        cout << "\nBook Title: " << root->label;

        for (int i = 0; i < root->children.size(); i++) {
            Node* chapter = root->children[i];
            cout << "\n Chapter " << i + 1 << ": " << chapter->label;
            cout << "\n  Sections:";
            for (int j = 0; j < chapter->children.size(); j++) {
                cout << "\n   - " << chapter->children[j]->label;
            }
        }
        cout << endl;
    }
};

int main() {
    GeneralTree tree;
    int choice;

    while (true) {
        cout << "\n\n---- Menu ----";
        cout << "\n1. Create Book Tree";
        cout << "\n2. Display Book Tree";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.createTree();
                break;
            case 2:
                tree.displayTree();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
