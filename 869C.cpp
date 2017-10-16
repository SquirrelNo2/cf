#include<cstdio>
#include<algorithm>

#define mod 998244353

using namespace std;
typedef long long ll;

ll num[5001][5001];

ll dp(ll m, ll n){
	if(!m || !n){
		return 1;
	}
	if(!num[m][n]){
		num[m][n] = (n * dp(m-1, n-1) + dp(m-1, n)) % mod;
	}
	return num[m][n];
}

int main(){
	ll a[3];
	scanf("%lld %lld %lld", &a[0], &a[1], &a[2]);
	sort(a, a+3);
	printf("%lld\n", dp(a[0], a[1]) * dp(a[1], a[2]) % mod * dp(a[0], a[2]) % mod);
}