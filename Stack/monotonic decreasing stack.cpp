/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int>nextgreater(vector<int>v)
{
    // return v;
    int n=v.size();
    vector<int> st;
    
    vector<int>ans(n, -1);
    
    for(int i=0;i<n;i++)
    {
        
        while(!st.empty() && v[i]<v[st.back()])
        {
            ans[st.back()]=v[i];
            st.pop_back();
        }
        st.push_back(i);
    }
    
    return ans;
    
}


int main()
{

    vector<int>v={2,1,2,4,3};
    vector<int> ans=nextgreater(v);
    
    for(auto k:ans)
    {
        cout<<k<<" ";
    }
    

    return 0;
}
