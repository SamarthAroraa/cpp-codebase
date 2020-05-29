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


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int grundy[n+1];
	RESET(grundy,0);
	grundy[1]=1;
	for(int i=2;i<=n;i++){
		int v1,v2,v3;
		v1=grundy[i-2];
		v2=grundy[i-3];
		v3=grundy[i-6];
		int endv=max(v1,max(v2,v3));
		for(int j=0;j<=endv+1;j++){
			if(j!=v1 and j!=v2 and j!=v3){
				grundy[i]=j;
				break;
				}
		}
	}
	// REP(i,n){
	// 	cout<<grundy[i]<<" ";
	// }
	// cout<<endl;
	cout<<grundy[n];
	
	



	 
return 0;
}