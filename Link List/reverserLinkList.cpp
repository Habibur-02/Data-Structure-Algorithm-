#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    
};

struct Node* reverse(Node* head)
{
    
    if(head==NULL | head->next==NULL)
    {
        return head;
    }
    struct Node* newhead=reverse(head->next);
    
    head->next->next=head;
    head->next=NULL;
    return newhead;
    
    
    
}

int main() {
	int arr[9]={1,2,3,4,6,3,2,4,8};
	struct Node* head=new Node();
	head->data=arr[0];
	head->next=nullptr;
	struct Node* last=new Node();
	last=head;
	
	
	for(int i=1;i<9;i++)
	{
    Node* temp=new Node();
    temp->data=arr[i];
    temp->next=nullptr;
    last->next=temp;
    last=temp;
}

    
    Node* p= head;
    while(p!= nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
	
	struct Node* revList=reverse(head);
	cout<<'\n';
	p= revList;
    while(p!= nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

}
