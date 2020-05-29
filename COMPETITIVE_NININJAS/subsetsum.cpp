#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
bool subsum(std::vector<int> arr, ll sum, ll n)
{
	bool dp[n+1][sum+1];
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=sum;j++){
			dp[i][j]=0;
		}
	}
	for(ll j=0;j<=n;j++){
		dp[j][0]=1;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=sum;j++){
			dp[i][j]=dp[i-1][j];
			if(j-arr[i-1]>=0){
				dp[i][j]= dp[i-1][j] or dp[i-1][j-arr[i-1]];
			}
		}
	}
return dp[n][sum];
}
ll main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	std::vector<int> arr(n);
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	ll k;
	cin>>k;
	if(subsum(arr,k,n))
		cout<<"YES";
	else cout<<"NO";

return 0;
}