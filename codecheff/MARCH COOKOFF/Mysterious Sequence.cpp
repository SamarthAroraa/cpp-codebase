#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
#define mod (long long)1000000007
using namespace std;
ll ans(  ll b[],ll n){
	ll ans=1;
	for(ll i=1;i<n;i++)
	{
		ll f= b[i]&b[i-1];
		ll k = __builtin_popcountll(f);
		
		ll pow=((ll)1<<k)%mod;
		ans=((ans%mod) * (pow%mod)) % mod;
	}
	// cerr<<"&&&&&&&&&\n";
return ans%mod;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		 ll b[n];
		for(ll i=0;i<n;i++){
			cin>>b[i];
		}
		cout<<ans(b,n)<<endl;
	}
return 0;
}