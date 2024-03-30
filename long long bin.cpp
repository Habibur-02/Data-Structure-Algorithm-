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
int phii(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
void phi_1_to_n(int n) {
    vector<int> phii(n + 1);
    for (int i = 0; i <= n; i++)
        phii[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phii[i] == i) {
            for (int j = i; j <= n; j += i)
                phii[j] -= phii[j] / i;
        }
    }

    for(int i=1;i<=n;i++) cout<<phii[i]<<" ";

}
int32_t main()
{ fast


 cout<<phii(5)<<'\n'; //output euler er totient function of 5;
 phi_1_to_n(10);      //output 1 theke n porjonto euler er totient function
 cout<<nl;

    /******Binary Expotention*****/
    ///1.Normal expotention Base<=10^9,Power<=10^9 & Mod<=10^9

     cout<<binexp1(1000000000,1000000000,100000008)<<'\n';
    ///2.variation a^b^c er expotention ber kora a,b,c,mod<=10^9;

    //10000^10000^10000;
    //phi(mod)
    //
    int m=1000000007;
    int x=phii(m);
    cout<<binexp1(10000,binexp1(10000,10000,phii(m)),m); ///ekhane chaile majhkhane phii(m) na bosai x bosaleo hoto;

    ///3.variation a^b mod m,j khane base,mod<=10^18;

    cout<<binexp2(1003474682019274,457846743,19283747596095843)<<'\n';  ///ai varition a binexp2 te call hocche kintu;

    ///fartmet er little theorem moduler inverse ber kore
    ///(a^(phi(m)-1))%m=a^-1;

    cout<<binexp1(5,phii(6)-1,6);










}





