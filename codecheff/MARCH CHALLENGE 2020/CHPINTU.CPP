#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll mincost(ll p[], ll f[] , ll n){
	ll mini=INT_MAX;
	unordered_map<ll ,ll> sumcost;
	for(ll i=0;i<n;i++){
		sumcost[f[i]]+=p[i];
		// deb(sumcost[f[i]])

	}
	for(auto n: sumcost){
		mini= min(mini, n.second);
	}
return mini;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll m;
		cin>>m;
		ll p[n];
		ll f[n];
		for(ll i=0;i<n;i++){
			cin>>f[i];
		}
	for(ll i=0;i<n;i++){
			cin>>p[i];
		}
	cout<<mincost(p,f,n)<<endl;
	}

return 0;
}