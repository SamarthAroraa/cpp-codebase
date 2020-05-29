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

// A Dynamic Programming based solution for 0-1 Knapsack problem 


class item{
public:
ll price,value,number;
};




bool com(item a , item b){
	return (double)(a.value)/a.price>(double)(b.value)/b.price;
}


void solve(){
	ll n,m;
	cin>>n>>m;
	item items[n];
	FOR(i,0,n){
		cin>>items[i].price;
	}
	FOR(i,0,n){
	cin>>items[i].value;
	}
	FOR(i,0,n){
		cin>>items[i].number;
	}
	sort(items,items+n, com);
	ll ans=0;
	for(ll i=0;i<n;i++){
		if(m==0) break;
		if(m>=items[i].number*items[i].price){
			ans+=(items[i].value*items[i].number);
			m-=items[i].number*items[i].price;
		}
		else{
			ll taken= m/items[i].price;
			m-=(taken*items[i].price);
			ans+=(items[i].value* taken);
		}
	}

cout<<ans<<"\n";
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();	 
return 0;
}