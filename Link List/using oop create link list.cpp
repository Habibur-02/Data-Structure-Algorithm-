#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

public: // 
    
    // Constructor - 
    Node(int value) {
        data = value;
        next = nullptr;
    }
    
    // 
    void setData(int value) {
        if (value >= 0) { // validation
            data = value;
        }
    }
    
    
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