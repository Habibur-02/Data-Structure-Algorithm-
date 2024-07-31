    #include<bits/stdc++.h>
using namespace std;
void merges(int ar[],int l,int mid,int r)
{
    int br[r+3];
     //int inv=0;
    int i=l,j=mid+1,k=l;

    while(i<=mid && j<=r)
    {
        if(ar[i]<=ar[j])
        {
            br[k]=ar[i];
            i++;
        }
        else
        {
            br[k]=ar[j];
            j++;
           // int inv=mid-i;

        }
        k++;

    }
    while(i<=mid)
    {
        br[k]=ar[i];
        k++;
        i++;

    }
      while(j<=r)
    {
        br[k]=ar[j];
        k++;
        j++;

    }

    for(int i=l;i<=r;i++)
    {
        ar[i]=br[i];
    }


//  return inv;


}
void solve(int ar[],int l,int r)
{
    //int inv=0;
    if(l<r)
    {


    int mid=(r+l)/2;
    solve(ar,l,mid);
    solve(ar,mid+1,r);

    merges(ar,l,mid,r);

    }
//return inv;
}
int main()
{
    int n;
    cin>>n;
    int ar[n+3];
    for(int i=0;i<n;i++) cin>>ar[i];

 solve(ar,0,n-1);

  for(int i=0;i<n;i++) cout<<ar[i]<<" ";


}

    
