#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'
typedef pair<int,int>pll;
typedef vector<pll>vll;
vector<pair<int,int>>v[1000];
int dis[1000];
#define inf 9000000
int dijstra(int s,int n)
{
    for(int i=1;i<=n;i++) dis[i]=INT_MAX;

    dis[s]=0;

    priority_queue<pll,vll,greater<pll>>pq;
    pq.push({s,0});


    while(!pq.empty())
    {
        int node=pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(dis[node]<cur) continue;

        for(auto child:v[node])
        {
            if(child.second+cur<dis[child.first])
            {
                dis[child.first]=child.second+cur;
                pq.push({child.first,dis[child.first]});
            }



        }




    }







}
int main()
{
    int n,e;
    cin>>n>>e;


    while(e--)
    {
        int x,y,w;
        cin>>x>>y>>w;

        v[x].push_back({y,w});
        v[y].push_back({x,w});





    }


    dijstra(3,n);


    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";


}
