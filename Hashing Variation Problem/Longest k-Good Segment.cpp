#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dx[]={0,-1,0,1,1,-1,-1,1};
int dy[]={1,0,-1,0,1,1,-1,-1};

#define nl '\n'
#define s_i stoi(string s)
#define i_s to_string(num)
const ll INF=numeric_limits<ll>::max()-1;
#define ll_inf (1LL << 62)
#define inf (1 << 30)
#define SetBit(x, k) (x = (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
int32_t main()
{ fast

int n,k;
cin>>n>>k;
int ar[n+3];
for(int i=1;i<=n;i++)
{
    cin>>ar[i];
}

int ans=-1;
int last=1;
vector<pair<int,int>>v;

for(int i=1;i<=n;i++)
{
    if(ar[i]>k)
    {
     if(last==i)  v.push_back({last,last});
     else   v.push_back({last,i-1});
       last=i+1;

    }

}
if(ar[n]<k) v.push_back({last,n});
if(v.empty())
{
    cout<<1<<" "<<n<<'\n';

}
else
{


int p,q;
int dif=-1;
 for(auto [i,j]:v)
 {

     if(j-i+1>dif)
     {
         p=i;
         q=j;
         dif=j-i+1;
     }

 }
  cout<<p<<" "<<q<<'\n';


}




}





