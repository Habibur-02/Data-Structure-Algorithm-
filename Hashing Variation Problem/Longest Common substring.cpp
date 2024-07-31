    #include<bits/stdc++.h>
using namespace std;
#define ll long long
int dx[]={0,-1,0,1,1,-1,-1,1};
int dy[]={1,0,-1,0,1,1,-1,-1};
char dir[]={'R','U','L','D'};
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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//using namespace std;

gp_hash_table<int, int> mp;


const int N = 1e6 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;


int power(long long n, long long k, int mod) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
  }
  ip1 = power(p1, mod1 - 2, mod1);
  ip2 = power(p2, mod2 - 2, mod2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
  }
}

pair<int, int> string_hash(string s) {
  int n = s.size();
  pair<int, int> hs({0, 0});
  for (int i = 0; i < n; i++) {
    hs.first += 1LL * s[i] * pw[i].first % mod1;
    hs.first %= mod1;
    hs.second += 1LL * s[i] * pw[i].second % mod2;
    hs.second %= mod2;
  }
  return hs;
}
struct hashh{
pair<int, int> pref[N];
void build(string s) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    pref[i].first = 1LL * s[i] * pw[i].first % mod1;
    if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
    pref[i].second = 1LL * s[i] * pw[i].second % mod2;
    if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
  }
}
pair<int, int> get_hash(int i, int j) {
  assert(i <= j);
  pair<int, int> hs({0, 0});
  hs.first = pref[j].first;
  if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
  hs.first = 1LL * hs.first * ipw[i].first % mod1;
  hs.second = pref[j].second;
  if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
  hs.second = 1LL * hs.second * ipw[i].second % mod2;
  return hs;
}

}A,B;
int n;
int first,second;
int ok(int len)
{

    set<pair<int,int>>se;

    for(int i=0;i+len-1<n;i++)
    {

        se.insert(A.get_hash(i,i+len-1));

    }

    for(int i=0;i+len-1<n;i++)
    {

        auto kk=B.get_hash(i,i+len-1);

        if(se.find(kk)!=se.end())
        {
            first=kk.first;
            second=kk.second;
            return true;

        }


    }


    return false;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  cin>>n;
  string a, b; cin >> a >> b;
  A.build(a);
  B.build(b);
  int ans = 0;
//  n = a.size();
  auto hash_b = string_hash(b);

  int l=1;
  int r=n;
  while(l<=r)
  {
      int mid=(l+r)/2;

      if(ok(mid))
      {

          ans=mid;
          l=mid+1;
      }
      else r=mid-1;
  }

    cout<<ans;

    ok(ans);

    pair<int,int>pp;
    pp.first=first;
    pp.second=second;


    for(int i=0;i+ans-1<n;i++)
    {
        if(A.get_hash(i,i+ans-1)==pp)
        {
            cout<<a.substr(i,i+ans);
        }


    }



}






    
