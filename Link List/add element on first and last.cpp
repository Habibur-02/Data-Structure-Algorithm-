#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function 1: Print the entire linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function 2: Insert at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;  // আগের পুরো লিস্ট এখন newNode এর next
    head = newNode;        // head এখন নতুন নোডে পয়েন্ট করবে
}

// Function 3: Insert at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    // যদি লিস্ট খালি হয়
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = NULL;  // শুরুতে লিস্ট খালি

    insertAtBeginning(head, 10);  // 10
    insertAtBeginning(head, 5);   // 5 -> 10
    insertAtEnd(head, 20);        // 5 -> 10 -> 20
    insertAtEnd(head, 30);        // 5 -> 10 -> 20 -> 30

    printList(head);
}