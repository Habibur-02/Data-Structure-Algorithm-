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

struct node* element(node* z, vector<int>arr)
{
    z->data=arr[0];
    z->next=NULL;
    struct node* x=z;
    // cout<<arr[0];
    
    for(int i=1;i<arr.size();i++)
    {
        node* q=new node();
        q->data= arr[i];
        q->next= NULL;
        x->next=q;
        x=x->next;
    }
    cout<<'\n';
  struct node* p=z;
  while(p!=NULL)
  {
      cout<<p->data<<" ";
      p=p->next;
      
  }
    return z;
}


struct node* delete100(node* head, int value)
{
    node* temp= head;
    node* pre=new node();
    node* post=new node();
    bool ok=true;
    cout<<'\n';
    while(temp!=NULL)
    {
        if(temp->next->data== value)
        {
            temp->next=temp->next->next;
            break;
        }
        temp=temp->next;
    }
    node* x= head;
     while(x!= NULL)
     {
         cout<<x->data<< " ";
         x=x->next;
     }
    return head;
}
int len1(node* head)
{
    if(head->next==NULL)
    {
        return 1;
    }
    
    return 1+ len1(head->next);
}
int middlepointer(struct node* head)
{
    int len=0;
    node* slow=head;
    node* fast= head;
    
    while(fast!=NULL && fast->next!= NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        len++;
        
    }
    
    
    return slow->data;
}
int main()
{

    struct node* head=new node();
    vector<int> arr={1,5,400,2,300,48,5,6, 7};
    node* list= element(head, arr);
    int value=2;
    node* deleteval= delete100(list, value);
    int length= len1(deleteval);
    cout<<'\n';
    cout<<"Length OF Link LIST "<<length;
    int len=middlepointer(deleteval);
    cout<<" middlepoint "<<len<<" ";
    



    return 0;
}
