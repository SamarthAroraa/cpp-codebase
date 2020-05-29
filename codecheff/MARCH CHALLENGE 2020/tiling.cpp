#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
#define mod 1000000007
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	unordered_map <ll,ll> dp;
	dp[0]=1;
	dp[1]=2;
	dp[2]=6;
	
	ll t;
	cin>>t;
	while(t--){
	ll n;
	cin>>n;
	if(dp[n]){
		cout<<dp[n]%mod<<endl;
		continue;
	}
	for(ll i=3;i<=n;i++){
		if(!dp[i])
		dp[i]= (4*(dp[i-1]%mod))%mod;
	}
	cout<<dp[n]%mod<<endl;
}


return 0;
}