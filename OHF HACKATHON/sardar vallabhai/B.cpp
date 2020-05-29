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

bool isps(long double x) 
{   
  // Find floating poll value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// cout<<countOrderedPairs(4);
	ll q,n,k;
	cin>>q;
	REP(i,q){
		ll a,b;
		cin>>a>>b;
		ll prod=a*b;
		ll limsq=prod-1;
		ll lim=sqrt(prod-1);
		deb(lim)
		int sub=0;
		for(i=1;i<=lim;i++){
			if(limsq/i==i){
				sub++;
			}
		}
		ll ans=lim*2;
		if(a<=lim){
			ans--;
		}
		if(b<=lim)
			ans--;
		
		// if(isps((double)limsq))
		// 	ans--;
		cout<<ans<<"\n";

	}




	 
return 0;
}