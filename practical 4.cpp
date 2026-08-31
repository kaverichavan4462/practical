#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at start
void insertAtStart(Node*& head, Node*& last, int value) {
    Node* newNode = new Node;

    newNode->data = value;

    // Empty list
    if (head == nullptr) {
        head = newNode;
        last = newNode;
        newNode->next = head;
    }
    else {
        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(Node*& head, Node*& last, int value) {
    Node* newNode = new Node;

    newNode->data = value;

    // Empty list
    if (head == nullptr) {
        head = newNode;
        last = newNode;
        newNode->next = head;
    }
    else {
        newNode->next = head;
        last->next = newNode;
        last = newNode;
    }
}

// Delete from start
void deleteAtStart(Node*& head, Node*& last) {
    // Empty list
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    // Only one node
    if (head == last) {
        delete head;
        head = nullptr;
        last = nullptr;
    }
    else {
        Node* temp = head;
        head = head->next;
        last->next = head;
        delete temp;
    }
}

// Delete from end
void deleteAtEnd(Node*& head, Node*& last) {
    // Empty list
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    // Only one node
    if (head == last) {
        delete head;
        head = nullptr;
        last = nullptr;
    }
    else {
        Node* temp = head;

        // Find the second-last node
        while (temp->next != last) {
            temp = temp->next;
        }

        temp->next = head;
        delete last;
        last = temp;
    }
}

// Display
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* last = nullptr;

    int n, value, choice;

    // Create initial list
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;

        insertAtEnd(head, last, value);
    }

    do {
        cout << "\n===== Circular Linked List =====" << endl;
        cout << "1. Insert at Start" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete from Start" << endl;
        cout << "4. Delete from End" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtStart(head, last, value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, last, value);
                break;

            case 3:
                deleteAtStart(head, last);
                break;

            case 4:
                deleteAtEnd(head, last);
                break;

            case 5:
                cout << "Circular Linked List: ";
                display(head);
                break;

            case 6:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}
