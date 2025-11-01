#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    
};



int main() {
	// your code goes here
	cout<<"Aasif";
	int arr[4]={1,2,3,4};
	struct Node* head=new Node();
	head->data=arr[0];
	head->next=nullptr;
	struct Node* last=new Node();
	last=head;
	
	
	for(int i=1;i<4;i++)
	{
    Node* temp=new Node();
    temp->data=arr[i];
    temp->next=nullptr;
    last->next=temp;
    last=temp;
}

    cout<<"Aasif";
    
    Node* p= head;
    while(p!= nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
	
	

}
