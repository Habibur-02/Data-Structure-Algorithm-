/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
struct node* makelist(vector<int>v)
{
    node* head= new node();
    node* temp=new node();
    temp=head;
    temp->data=v[0];
    temp->next=NULL;
    for(int i=1;i<v.size();i++)
    {
        node* x=new node();
        x->data= v[i];
        x->next= NULL;
        temp->next=x;
        temp=temp->next;
    }
    
    node* p=head;
    while(p!= NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
        
    }
    cout<<'\n';
    
    return head;
}

struct node* sort2list(node* list1, node* list2)
{
    node* head1= list1;
    node* head2=list2;
    node* ans= new node();
    if(list1->data<=list2->data)
    {
        ans->data= list1->data;
        ans->next=NULL;
        head1=head1->next;

    }
    else
    {
        ans->data= list2->data;
        ans->next=NULL;
        head2=head2->next;
    }
    node* ans1= ans;
    
    while(head1!=NULL | head2!=NULL)
    {
        node* x=new node();
        if(head1==NULL)
        {
            x->data=head2->data;
            x->next=NULL;
            ans1->next=x;
            ans1=ans1->next;
            head2=head2->next;
        }
        else if(head2==NULL)
        {
            x->data=head1->data;
            x->next=NULL;
            ans1->next=x;
            ans1=ans1->next;
            head1=head1->next;
        }
        else if(head1->data<=head2->data)
        {
            x->data=head1->data;
            x->next=NULL;
            ans1->next=x;
            ans1=ans1->next;
            head1=head1->next;
            
            
        }
        else
        {
            x->data=head2->data;
            x->next=NULL;
            ans1->next=x;
            ans1=ans1->next;
            head2=head2->next;
        }
    }
    
    node* p=ans;
    while(p!= NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
        
    }
    cout<<'\n';
    return ans;
}


int main()
{

    node* head=new node();
    head->data= 10;
    head->next= NULL;
    // cout<<head->data;
    vector<int>v1={1,5,6,7,9,10};
    vector<int>v2={1,2,4,5};
    node* list1=makelist(v1);
        node* p=list1;
    while(p!= NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
        
    }
    cout<<'\n';
    node* list2= makelist(v2);
    
    

    p=list2;
    while(p!= NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
        
    }
    cout<<'\n';
    
    
    node* mergelist= sort2list(list1, list2);
    
    return 0;
}
