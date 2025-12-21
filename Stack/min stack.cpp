#include<bits/stdc++.h>
using namespace std;

void minstack2n(vector<int>v)
{
    for(auto kk: v) cout<<kk<<" ";
    // reverse(v.begin(),v.end());
    stack<pair<int,int>>st;
    int minvalue=INT_MAX;
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
    cout<<'\n';
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
vector<int>v={10,2,3,7,9};

minstack2n(v);
 return 0;
}
