#include <iostream>
using namespace std;

class Node {
private: // 🚫 বাইরে থেকে direct access করা যাবে না
    int data;
    Node* next;

public: // ✅ বাইরে থেকে এই functions গুলো call করা যাবে
    
    // Constructor - node তৈরি করার function
    Node(int value) {
        data = value;
        next = nullptr;
    }
    
    // ✅安全的ভাবে data set করা
    void setData(int value) {
        if (value >= 0) { // validation
            data = value;
        }
    }
    
    // ✅安全的ভাবে data পড়া
    int getData() {
        return data;
    }
    
    // ✅安全的ভাবে next set করা
    void setNext(Node* nextNode) {
        next = nextNode;
    }
    
    // ✅安全的ভাবে next পড়া
    Node* getNext() {
        return next;
    }
};

int main() {
    // node তৈরি করছি
    Node* first = new Node(10); // constructor call
    Node* second = new Node(20);
    Node* third = new Node(30);
    
    // link করছি - safe way তে
    first->setNext(second);
    second->setNext(third);
    
    // লিস্ট traverse করছি - safe way তে
    Node* current = first;
    while (current != nullptr) {
        cout << current->getData() << " -> "; // ✅ safe data access
        current = current->getNext();         // ✅ safe next access
    }
    cout << "NULL" << endl;
    
    return 0;
}