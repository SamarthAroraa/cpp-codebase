#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n)
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define RESET(a, b) memset(a, b, sizeof(a)) 
#define fi first 
#define bitcount __builtin_popcount
#define gcd __gcd
#define se second 
#define mp make_pair 
#define pb push_back 
#define TC(t) while (t--)
#define mod 1000000007

ll compute(ll n, ll k){
	ll x=k/2;
	// ll sq= ((n+x)%mod)* ((n+x)%mod) %mod;
	ll sq= (ll)pow(n+x,2)%mod;

	sq= (sq+x)%mod;
	return sq%mod;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	TC(t)
	{
		ll n,k;
		cin>>n>>k;
		ll ans=0;
		if(n==0){
			cout<<1+(k-1)*2%mod<<endl;
			continue;
		}
		if(k%2==0){
			 ans= compute(n,k-1);
			ans = (ans%mod + (2*n)%mod)%mod;
		}
		else{
			ans= compute(n,k);
		}
		cout<<(ll)ans%mod<<"\n";

	}
	



	 
return 0;
}