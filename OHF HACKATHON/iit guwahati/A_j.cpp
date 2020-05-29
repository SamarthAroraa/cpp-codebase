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
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll x, y, z;
	cin>>x>>y>>z;
	ll a[x+z];
	ll b[y+z];
	ll c[z];
	for(ll i=0;i<x;i++){
	cin>>a[i];
	}
	for(ll i=0;i<y;i++){
	cin>>b[i];
	}
	for(ll i=0;i<z;i++){
	cin>>c[i];
	}
	sort(a,a+x,greater<int>());
	sort(b,b+y,greater<int>());
	sort(c,c+z,greater<int>());
	ll i=0,j=0,k=0;
	ll ans=0;
	ll total=0;
	while(i<x and k<z and total<n){
		if(a[i]>=c[k]){
			ans+=a[i];
			deb(a[i])
			i++;
			total++;
		}
		else{
			ans+=c[k];
			deb(c[k])

			k++;
			total++;
		}
	}
	while(total<n and i<x){
		ans+=a[i];
		deb(a[i])
		i++;
		total++;
	}
	total=0;
	while(j<y and k<z and total<m){
		if(b[j]>=c[k]){
			ans+=b[j];
			deb(b[j])
			j++;
			total++;
		}
		else{
			ans+=c[k];
			deb(c[k])

			k++;
			total++;
		}
	}
	while(total<m and j<y){
		ans+=b[j];
			deb(b[j])

		j++;
		total++;
	}
	cout<<ans;




	



	 
return 0;
}