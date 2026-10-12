#include <iostream>
using namespace std;

// Structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Search for an element
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Inorder traversal: Left, Root, Right
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Preorder traversal: Root, Left, Right
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, value, key;

    // Create the BST
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    int choice;

    do {
        cout << "\n\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert a node\n";
        cout << "2. Search for an element\n";
        cout << "3. Inorder traversal\n";
        cout << "4. Preorder traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Node inserted successfully.\n";
                break;

            case 2:
                cout << "Enter element to search: ";
                cin >> key;

                if (search(root, key)) {
                    cout << "Element found in the tree.\n";
                } else {
                    cout << "Element not found in the tree.\n";
                }
                break;

            case 3:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}