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
#define se second 
#define mp make_pair 
#define pb push_back 
#define TC(t) while (t--)
#define mod 1000000007
ll powerLL(ll x, ll n) 
{ 
    ll result = 1; 
    while (n) { 
        if (n & 1) 
            result = result * x % mod; 
        n = n / 2; 
        x = x * x % mod; 
    } 
    return result; 
} 
  
// Returns modulo exponentiation for two numbers 
// represented as strings. It is used by 
// powerStrings() 
ll powerStrings(string sa, string sb) 
{ 
    // We convert strings to number  
  
    ll a = 0, b = 0; 
  
    // calculating  a % mod 
    for (int i = 0; i < sa.length(); i++) 
        a = (a * 10 + (sa[i] - '0')) % mod; 
  
    // calculating  b % (mod - 1) 
    for (int i = 0; i < sb.length(); i++) 
        b = (b * 10 + (sb[i] - '0')) % (mod - 1); 
  
    // Now a and b are long long int. We 
    // calculate a^b using modulo exponentiation 
    return powerLL(a, b); 
} 
  
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int  t;
	cin>>t;
	TC(t){
		ll p, a, n;
		cin>>n>>a;
		p=1;
		ll ans=0;
		for(int i=1;i<=n;i++){
			p=powerStrings(to_string(a), to_string(2*i-1));
			a=((a%mod)*(p%mod))%mod;
			ans= (ans%mod + p%mod)%mod;
		}
		cout<<(ans%mod)<<"\n";
	}
	



	 
return 0;
}