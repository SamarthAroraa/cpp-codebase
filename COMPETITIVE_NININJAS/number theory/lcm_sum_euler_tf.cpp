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
#define MAXN 1000001
ll etf[MAXN+2];
ll ans[MAXN+1];

void etfgen(){
	for(int i=1;i<=MAXN;i++){
		etf[i]=i;
	}
	// etf[1]=0;
	for(int i=2;i<=MAXN;i++){
		if(etf[i]==i){
			etf[i]=i-1;

			for(int j=i*2;j<=MAXN;j+=i){
				etf[j]=etf[j]*(i-1)/i;
			}
		}
	}
}

void lcmsumgen(int n){

	RESET(ans,0);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			ans[j]+=(i*etf[i]);
		}
	}
	
}
int lcmsum(int n){
	ll answer=ans[n];
	answer= (answer+1)*n;
	answer=answer/2;
	return answer;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	etfgen();
	// for(int i=0;i<100;i++){
	// 	deb(etf[i])
	// }
	int n ;
	cin>>n;
	lcmsumgen(MAXN);
	cout<<lcmsum(n)<<endl;
	



	 
return 0;
}