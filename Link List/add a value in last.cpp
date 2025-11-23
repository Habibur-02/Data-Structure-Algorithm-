/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
    
};
struct node* makelink(int v[])
{
    struct node* head=new node();
    // cout<<v[0];
    struct node* temp= new node();
    head->data=v[0];
    head->next=NULL;
    temp=head;
    
    for(int i=1;i<5;i++)
    {
        
        struct node* p=new node();
        p->data=v[i];
        p->next=NULL;
        temp->next=p;
        temp=temp->next;
        // cout<<temp->data<<" ";
    }
    
    // head=temp;
    struct node* k=new node();
    k=head;
    
    // while(k->next!=NULL)
    // {
    //     cout<<k->data<<" ";
    //     k=k->next;
        
    // }
    // cout<<k->data;
    return head;
    
}

struct node* insertValBegin(struct node*head,int val)
{
    cout<<'\n';
    cout<<head->data;
    
    struct node* temp=new node();
    temp=head;
    struct node* x=new node;
    x->data=val;
    x->next= temp;
    head=x;
    cout<<'\n';
    while(x->next != NULL)
    {
        cout<<x->data<<" ";
        x=x->next;
        
    }
    cout<< x->data;
    
    
    return head;
}
struct node* insertValLast(struct node* head, int val)
{
    struct node* temp=new node();
    temp=head;
    struct node* k=new node;
    k->data= val;
    k->next= NULL;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=k;
    return head;
}
int main()
{
    // std::cout<<"Hello World";
    
    struct node *head=new node();
    head->data= 10;
    head->next=NULL;
    // cout<<head->data<<'\n';
    vector<int>v(5);
    int v1[5]={2,6,1,2,3};
    
    // struct node* head=new node();
    cout<<'\n';
    
    head=makelink(v1);
    cout<<head<<'\n';
    
    struct node* insert=insertValBegin(head,10);
    cout<<"----------------"<<'\n';
      while(insert->next != NULL)
    {
        cout<<insert->data<<" ";
        insert=insert->next;
        
    }
    cout<< insert->data;
    struct node* i_at_last=insertValLast(head, 80);
    

    cout<<'\n';
    cout<<"--------------------"<<'\n';
    
      while(i_at_last->next != NULL)
    {
        cout<<i_at_last->data<<" ";
        i_at_last=i_at_last->next;
        
    }
    cout<< i_at_last->data;
    
    
    
    

    return 0;
}
