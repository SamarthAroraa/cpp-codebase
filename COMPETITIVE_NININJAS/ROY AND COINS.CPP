#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void solve(){
	ll  n;
	cin>>n;
	ll  m;
	cin>>m;
	std::vector<ll > diff(n+1,0);
	std::vector<ll > final_dp(1000003);

	for(ll  i=0;i<m;i++){
		ll  l,r;
		cin>>l>>r;
		diff[l]+=1;
		diff[r+1]-=1;
	}
	ll  start=0;
	std::vector<ll > dp_diff(1000003,0);
	for(ll  i=1;i<=n;i++){
		start+=diff[i];

		dp_diff[i]=start;
		final_dp[start]++;

	}
	ll  k= n;
	for(ll  j=1;j<=1000000;j++){
		
		final_dp[j]+=final_dp[j-1];
		// if(k==0)
		// 	break;
	}
ll  q;
cin>>q;
for(ll  i=0;i<q;i++){
	ll  qi;
	cin>>qi;
	if(qi!=0)
	cout<<n-final_dp[qi]<<endl;
else cout<<n<<endl;
}
return;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	solve();

return 0;
}