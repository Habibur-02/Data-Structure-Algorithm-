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
int binexp1(int a, int b, int m){
	int result = 1;
	while(b>0){
		if(b & 1){
			result = (result  * 1LL * a) % m;
		}
		a = (a * 1LL * a) % m;
		b >>= 1;
	}
	return result;
}

long long multiply(long long a, long long b, long long m){
	long long result = 0;
	while(b>0){
		if(b & 1){
			result = result + a;
			result %= m;
		}
		a <<= 1;
		a %= m;
		b >>= 1;
	}
	return result;
}

long long binexp2(long long a, long long b, long long m){
	long long result = 1;
	while(b>0){
		if(b & 1){
			result = multiply(result, a, m);
		}
		a = multiply(a, a, m);
		b >>= 1;
	}
	return result;
}


int32_t main()
{ fast



 cout<<binexp2(837337287382373782,5,38934747834848734444444444444)<<'\n';
 cout<<binexp1(1000000324,1000007,100000000);







}





