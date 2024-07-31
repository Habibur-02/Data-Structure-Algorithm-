#include<bits/stdc++.h>
using namespace std;
vector<int>manachar_algo(string s)
{

    int n=s.size();

    vector<int>vc(n);

    int c=0;
    int r=0;

    for(int i=1;i<n;i++)

    {

        int mir=2*c-i;

        if(i<r) vc[i]=min(r-i,vc[mir]);
        while(s[i+vc[i]+1]==s[i-vc[i]-1]) vc[i]++;
        if(i+vc[i]>r)
        {
            c=i;
            r=i+vc[i];
        }

    }

    return vc;

}
int main()
{
  string s;
  cin>>s;

  string ss="@";

  for(auto j:s)
  {

      ss+="#";
      ss+=j;

  }
  ss+="#";
  ss+="$";
  vector<int>vc=manachar_algo(ss);
  int mx=0;
  for(auto k:vc)
  {
      mx=max(mx,k);

  }


  cout<<mx<<" ";

}
