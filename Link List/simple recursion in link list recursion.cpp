#include <iostream>
#include <cstdlib> // Needed for malloc or new, though 'new' is preferred in C++

using namespace std;

struct node {
    int data;
    node* next;
};

int len(node* head)
{
    if(head->next==NULL)
    return 1;
    return 1+len(head->next);
}
int search(node* head, int val)
{
    if(head->data==30)
    return true;
    if(head->next==NULL)
    {
        return false;
    }
    return search(head->next, val);
}
int main() {

    node* head = nullptr;

    // Allocate memory for the nodes using 'new'
    head = new node;
    node* h1 = new node;
    node* h2 = new node;
    node* h3 = new node;
    node* h4 = new node;

    // Set the data for each node
    head->data = 1;
    h1->data = 10;
    h2->data = 20;
    h3->data = 30;
    h4->data = 40;

    // Link the nodes together
    head->next = h1;
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = nullptr; // The last node must point to NULL/nullptr

    // Print the data of the h3 node
    // cout << h3->data << endl; // Should output 30

  
    // delete head;
    // delete h1;
    // delete h2;
    // delete h3;
    // delete h4;
    
    // cout<<head->next->next->data;
    
    cout<<"Lenght would be "<<len(head);
    
    cout<<"Search element 30 is "<<search(head, 30);
    
    

    return 0;
}
