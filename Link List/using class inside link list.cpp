#include <iostream>

using namespace std;


class node{
    private:
    int data;
    node* next;
    public:
    node(int val)
    {
        data=val;
        next=nullptr;
    }
    void setnext(node * nextnode)
    {
        next=nextnode;
    }
    int showdata(node* x)
    {
        return x->data;
    }
    
};

int main() {
    // 1. Create the Head Node
    // 'head' is a pointer to the start of the list.
    // Node* head = new Node(10); 

    // // 2. Create the Subsequent Nodes
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    node* head=new node(10);
    node* second= new node(20);
    node* third = new node(30);
    node* fourth= new node(40);
    

    head->setnext(second);     // 10 points to 20
    second->setnext(third);    // 20 points to 30
    third->setnext(fourth);    // 30 points to 40
    fourth->setnext(nullptr);  // 40 points to NULL (End of list)

    cout << "--- Linked List Created Successfully ---" << endl;
    
    // cout << "List Contents: ";
    // node* current = head;
    // while (current != nullptr) {
    //     cout << current->data << " -> ";
    //     current = current->next;
    // }
    // cout << "NULL" << endl;
    
    cout<<second->showdata(second);
    
    return 0;
}
