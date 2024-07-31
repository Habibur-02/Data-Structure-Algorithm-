#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //cin>>n;
    string s;
    cin>>s;
    n=s.size();


    int dp[n][n];
    string ans="";
    int mx=-1;

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {

            if(i==j)  dp[i][j]=1;
            else if(j=i+1)
            {
                if(s[i]==s[j])
                dp[i][j]=2;
                else dp[i][j]=0;


            }
            else
            {

                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=dp[i+1][j-1]+2;

                }
                else dp[i][j]=0;




            }
            if(dp[i][j])
        {
            mx=max(mx,dp[i][j]);
            ans=s.substr(i,j-i+1);

        }


        }




    }
    cout<<ans;


}
