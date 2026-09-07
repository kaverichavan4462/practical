#include <iostream>
using namespace std;

// Define the structure for a Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;
    
    // Constructor to initialize a node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// 1. Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    cout << "Successfully inserted " << val << " at the beginning.\n";
}

// 2. Function to delete a node from the beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "\nList is empty! Nothing to delete.\n";
        return;
    }
    
    Node* temp = head;
    head = head->next;
    
    // If the list still has nodes, update the new head's prev pointer
    if (head != nullptr) {
        head->prev = nullptr;
    }
    
    cout << "\nDeleted " << temp->data << " from the beginning.\n";
    delete temp;
}

// 3. Function for forward traversal
void traverseForward(Node* head) {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }
    
    Node* temp = head;
    cout << "\nForward Traversal: NULL <-> ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 3. Function for backward traversal
void traverseBackward(Node* head) {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }
    
    Node* temp = head;
    // Traverse to the very last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    
    cout << "\nBackward Traversal: NULL <-> ";
    // Traverse backwards using the 'prev' pointers
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, val;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Delete at Beginning\n";
        cout << "3. Traverse Forward\n";
        cout << "4. Traverse Backward\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                insertAtBeginning(head, val);
                break;
            case 2:
                deleteAtBeginning(head);
                break;
            case 3:
                traverseForward(head);
                break;
            case 4:
                traverseBackward(head);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    // Memory cleanup before exiting
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}