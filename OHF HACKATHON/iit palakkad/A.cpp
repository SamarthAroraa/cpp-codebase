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
ll mincost(string ss, string ts, ll n, ll fi[], ll bi[], ll index, string a,ll cost)
{
	if(a.length()==ts.length()){
	if(a==ts){
		deb(a)
		deb(cost)
		return cost;
	}
	else{
		return INT_MAX;
	}
}

// ll prevmin=mincost(ss,ts,n,fi,bi,index-1,a);
return min(mincost(ss,ts,n,fi,bi,index+1,a+ss[index],cost+bi[index]),mincost(ss,ts,n,fi,bi,index+1,ss[index]+a,cost+fi[index]));
}


ll main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	TC(t){
		ll n;
		cin>>n;
		string s , ts;
		cin>>s>>ts;
		ll fi[n];
		ll bi[n];
		FOR(i,0,n){
			cin>>fi[i];
		}
		FOR(i,0,n){
			cin>>bi[i];
		}
		ll ans=mincost(s,ts,n,fi,bi,0,"",0);
		if(ans!=INT_MAX)
		cout<<ans<<endl;	
		else
			cout<<"cannot be formed\n";
}

	



	 
return 0;
}