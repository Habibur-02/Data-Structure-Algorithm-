/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online

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

bool loopDetect(node* cycle)
{
    node* slow= cycle;
    node* fast= cycle;
    
    while(fast!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            return true;
        }
        
    }
    return false;
}

struct node* findstartloop(node* cycle)
{
    node* slow= cycle;
    node* fast= cycle;
    bool ok=true;
    while(fast!=NULL)
    {
        if(ok)
        {
        fast=fast->next->next;
        slow=slow->next;
        }
        else
        {
            slow=slow->next;
            fast=fast->next;
        }
        if(fast==slow && ok)
        {
            slow=cycle;
            ok=false;
        }
        
        if(fast==slow && ok==false)
        {
            break;
        }
        
    }
    return fast;
}

struct node* foundintersection(node* head1, node* head2)
{
    node* p=head2;
    cout<<'\n';
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<'\n';
    
    p=head1;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<'\n';
    
    node* p1=head1;
    node* p2= head2;
    while(p1!=p2)
    {
        if(p1->next==NULL)
        {
            p1=head2;
        }
        if(p2->next==NULL)
        {
            p2=head1;
        }
        p1=p1->next;
        p2=p2->next;
    }
    
    return p1;
    
}

int main()
{

    node* head=new node();
    head->data= 10;
    head->next= NULL;
    // cout<<head->data;
    vector<int>v1={1,5,6,7,9,10};
    vector<int>v2={1,2,4,5};
    vector<int>v3={2,3,1,2,6,4,8,2,2,9};
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
    
    node* cycle= makelist(v3);
    
    node* lastnodecycle=cycle;
    
    while(lastnodecycle->next!=NULL)
    {
        lastnodecycle=lastnodecycle->next;
    }
    lastnodecycle->next=cycle->next->next->next->next->next;
    
    bool loop=loopDetect(cycle);
    cout<<loop;
    
    node* startloop= findstartloop(cycle);
    
    cout<<startloop->data;
    
    
    node* list3=makelist(v3);
    node* list4=list2;
    
    node* lastnodelist4=list4;
    
    while(lastnodelist4->next!=NULL)
    {
        lastnodelist4=lastnodelist4->next;
    }
    cout<<"Last node of list 4= "<<lastnodelist4->data<<" "<<'\n';
    lastnodelist4->next=list3->next->next->next->next->next;
    
    node* intersectionpoint=foundintersection(list3, list4);
    cout<<intersectionpoint->data<<" ";
    return 0;
}
