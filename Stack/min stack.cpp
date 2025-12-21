#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int>>st;
int minvalue=INT_MAX;
void minstack2n(vector<int>v)
{
    for(auto kk: v) cout<<kk<<" ";
    // reverse(v.begin(),v.end());
    
    
    cout<<'\n';
    for(auto k: v)
    {
        if(st.empty())
        {
            st.push({k,min(k,minvalue)});
            minvalue=min(k,minvalue);
            cout<<" Min value"<<minvalue<<'\n';
        }
        else
        {
            st.push({k, min(minvalue, k)});
            minvalue=min(minvalue, k);
            cout<<" Min value"<<minvalue<<'\n';
        }
       
    }
}


int push(int val)
{
    if(st.empty())
    {
        minvalue=min(val,minvalue);
        st.push({val, minvalue});
        
    }
    else
    {
        // int top=st.top();
        minvalue=min(val,st.top().second);
        st.push({val, minvalue});
        
    }
    return 0;
}
    
void pop()
{
    int min_val=st.top().second;
    st.pop();
    
    
    
}

    int top()
    {
        return st.top().second;
    }
    
void printstack()
{
    stack<pair<int,int>>stt=st;
    while(!stt.empty())
    {
        cout<<stt.top().first<<" "<<stt.top().second<<'\n';
        stt.pop();
    }
}

int main()
{
 cout<<"Trying min stack"<<'\n';
vector<int>v={100,20,30,70,90};

minstack2n(v);

push(10);
push(90);
push(9);
printstack();

cout<<"-------------------"<<'\n';

pop();
printstack();
cout<<"-------------------"<<'\n';

pop();
printstack();
cout<<"-------------------"<<'\n';
pop();

printstack();

pop();
 return 0;
}
