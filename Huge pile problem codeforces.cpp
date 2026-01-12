#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        if(k>n)
        {
            cout<<-1<<'\n';
            continue;
        }
        long long l=n, r=n;
        int time= 0;
        while(l>k)
        {
            // cur= (cur+1)/2;
            // time++;
            l= l/2;
            r=(r+1)/2;
            time++;
            
            
        }
        
        if(l<= k && k<=r)
        {
            cout<<time<<'\n';
            
        }
        else
        {
            cout<<-1<<'\n';
        }
    }
    return 0;
}

