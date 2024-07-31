    #include<bits/stdc++.h>
using namespace std;

  int n;
  const int inf=1<<30;
   int ar[30][30];
   int dp[30][30];
int solve(int i,int j)
{
    if(i==n && j== n) return ar[i][j];
    if(i>n || j>n) return inf;

    if(dp[i][j]!=-1) return dp[i][j];
    int p=solve(i,j+1);
    int q=solve(i+1,j);

    //return ar[i][j] + min(solve(i,j+1),solve(i+1,j));
    return dp[i][j]=ar[i][j]+min(p,q);








}
void path(int i,int j)
{

    cout<<i<<" -> "<<j<<'\n';

     if(i==n && j==n) return;

    int l=solve(i+1,j);
    int r=solve(i,j+1);
    //int l=solve(i+1,j);


    if(r>=l) path(i+1,j);
    else path(i,j+1);



}




int main()
{

    cin>>n;
    memset(dp,-1,sizeof dp);

    for(int i=1;i<=n;i++)
    {


        for(int j=1;j<=n;j++) cin>>ar[i][j];
    }

    cout<<solve(1,1)<<'\n';


    path(1,1);






}

    
