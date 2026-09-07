#include <iostream>
using namespace std;

// Define the structure for a Linked List Node
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a node at the end (tail) of the linked list
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    
    // If the list is empty, make the new node the head
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    // Otherwise, traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    
    // Attach the new node at the end
    temp->next = newNode;
}

// Function to display the elements of the linked list
void displayList(Node* head) {
    Node* temp = head;
    cout << "\nLinked List Elements: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr; // Initialize an empty linked list
    int n, val;

    cout << "Enter the number of elements you want to insert: ";
    cin >> n;

    // Taking user input for each node
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        insertAtTail(head, val);
    }

    // Displaying the final linked list
    displayList(head);

    // Freeing the allocated memory to avoid memory leaks
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}