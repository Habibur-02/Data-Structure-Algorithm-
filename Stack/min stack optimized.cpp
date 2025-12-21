// min stack using o(n) space complexity
#include<bits/stdc++.h>
using namespace std;
stack<int>st;
int min_val=INT_MAX;
int val_in_stack=-1;


void push(int val)
{
    if(st.empty())
    {
        st.push(val);
        min_val=val;
    }
    else
    {
        if(val<min_val)
        {
            val_in_stack=2*val - min_val;
            min_val=val;
            st.push(val_in_stack);
        }
        else
        {
            st.push(val);
        }
    }
}

void pop()
{
    if(st.empty()) return;
    
    if(st.top()<min_val)
    {
        min_val=2*min_val - st.top();
        
    }
    st.pop();
}

int top_or_peek()
{
    if(st.top()<min_val) return min_val;
    else return st.top();
}

void seevalue()
{
    stack<int>stt=st;
 cout<<"-----------------------"<<'\n';
 while(!stt.empty())
 {
     cout<<stt.top()<<" ";
     stt.pop();
 }
 cout<<"minimium value "<<min_val<<'\n';
}
int main()
{
 push(10);
 cout<<" Now top value "<<top_or_peek()<<" "<<'\n';
 push(20);
 push(30);
  cout<<" Now top value "<<top_or_peek()<<" "<<'\n';

 push(9);
   cout<<" Now top value "<<top_or_peek()<<" "<<'\n';

 seevalue();
 
pop();
  cout<<" Now top value "<<top_or_peek()<<" "<<'\n';


 seevalue();

 
 

  
  return 0;
}
