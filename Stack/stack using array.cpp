

#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define len 3 
int st[len];
int top=-1;

void push(int x)
{
    if(top<len-1)
    {
        top=top+1;
        st[top]=x;
        cout<<"Successfully added"<<'\n';
        
    }
    else
    {
        cout<<"Execption! No spaces"<<'\n';
    }
}
void pop()
{
    // return -1;
    if(top>=0)
    {
        cout<<"Current value "<<st[top]<<'\n';
        top--;
        cout<<"Remove Suceesfully"<<'\n';
        
    }
    else
    {
        cout<<"There are no value in array"<<'\n';
    }
}
int peek()
{
    // return -1;
    if(top>=0)
    {
        return st[top];
        
    }
    else
    {
        return -1;
    }
}
int main()
{
   push(10);
   push(20);
   push(30);
   push(40);
   cout<<peek();
   pop();
      cout<<peek()<<'\n';

   
   pop();
      cout<<peek()<<'\n';

   pop();
      cout<<peek()<<'\n';

   pop();
      cout<<peek()<<'\n';

   
    return 0;
}
