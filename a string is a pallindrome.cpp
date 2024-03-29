#include<bits/stdc++.h>
using namespace std;
#define nl '\n';
#define ll long long
int32_t main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);

 string s;
 getline(cin,s);
 int i=0,j=s.size()-1;

//int c=0;


int c=0;
 while(i<=j)
 {


   if(!isalnum(s[i]))
     {

         i++;
        // continue;

     }
 else if(!isalnum(s[j]))
     {

         j--;

       // continue;
     }


     else   if(tolower(s[i])==tolower(s[j]))
     {
         i++;
         j--;

     }
     else
     {
         cout<<"NOT Palindrome"<<nl;
         return 0;
     }




 }
cout<<"Palindrome"<<nl;

}
