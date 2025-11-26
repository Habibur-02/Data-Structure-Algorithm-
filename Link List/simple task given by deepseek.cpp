#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
public:
    Node(int val) {
        data = val;
        next = nullptr;
    }
    
    int getData() { return data; }
    void setNext(Node* nextNode) { next = nextNode; }
    Node* getNext() { return next; }
    void printList(Node* head) {
 Node* temp=head;
  while(temp->next != NULL)
  {
      cout<<temp->data<<" ";
      temp=temp->next;
  }
  cout<<temp->data;
}
};

// TODO 1: এই ফাংশনটি কম্প্লিট করুন
void printList(Node* head) {
 Node* temp=head;
  while(temp!= NULL)
  {
      cout<<temp->getData()<<" ";
      temp=temp->getNext();
  }
  cout<<temp->getData();
}

// TODO 2: এই ফাংশনটি কম্প্লিট করুন  
void addToEnd(Node* head, int value) {
    // এখানে লিখুন: লিঙ্কড লিস্টের শেষে一个新 নোড যোগ করুন
    // যেমন: যদি list: 10->20->30 থাকে, আর value=40, তাহলে হবে: 10->20->30->40

    Node* asif= new Node(value);
    asif->setNext(nullptr);
    cout<<asif->getData();
    cout<<" "<<asif->getNext();
    
    while(head->getNext()!=nullptr)
    {
        head=head->getNext();
    }
    
    head->setNext(asif);
    
    cout<<'\n'<<head->getNext()->getData();
    
    
}

int main() {
    // 3টি নোড তৈরি হচ্ছে
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    
    // নোডগুলো কানেক্ট করা হচ্ছে
    head->setNext(second);
    second->setNext(third);
    
    // TODO 3: printList() ফাংশন কল করে লিস্ট প্রিন্ট করুন
    head->printList(head);
    cout<<'\n';
    // TODO 4: addToEnd() দিয়ে 40 যোগ করুন
    addToEnd(head, 60);
    cout<<'\n';
    // TODO 5: আবার printList() কল করে নতুন লিস্ট প্রিন্ট করুন
    head->printList(head);
    
    return 0;
}
