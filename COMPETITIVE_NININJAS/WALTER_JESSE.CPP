#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll amax=INT_MIN, bmax=INT_MIN;
		ll n;
		cin>>n;
		for(ll i=0;i<n;i++){
			ll w;
			cin>>w;
			amax=max(amax,w);
		}
		for(ll i=0;i<n;i++){
			ll w;
			cin>>w;
			bmax=max(bmax,w);
		}

	if(amax!=bmax){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	}


return 0;
}