#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll; 



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
		ll n,q;
		cin>>n>>q;
		// std::vector<ll> floors;
		ll ans=0;
		ll f,d;
		cin>>f>>d;
		ans+=f;
		ans+=abs(d-f);
		for(int i=1;i<q;i++){
			cin>>f;
			ans+=abs(d-f);
			cin>>d;
			ans+=abs(d-f);

		}
		cout<<ans<<"\n";

		
	}



	 
return 0;
}