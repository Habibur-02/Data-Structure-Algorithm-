#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int inv(int ar[],int n)
{
     o_set<int> s;

     s.insert(ar[0]);

     int inv=0;

     for(int i=1;i<n;i++)
     {

         s.insert(ar[i]);
         int k=s.order_of_key(ar[i]+1);

         inv+=s.size()-k;




     }


    return inv;

}
  int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  int ar[n];
  for(int i=0;i<n;i++) cin>>ar[i];

  cout<<inv(ar,n);








}

    
