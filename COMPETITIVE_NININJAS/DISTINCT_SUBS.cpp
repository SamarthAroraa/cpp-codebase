#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define int long long
#define mod 1000000007
using namespace std;
int count(string s){
	int n= s.length();
	std::vector<int> dp(n+1,0);
	dp[0]=1;
	unordered_map <char,pair<int,int> > freq;
	for(int k=n-1;k>=0;k--){
		int repition=freq[s[k]].first;
		deb(s[k])
		deb(freq[s[k]].first)
		deb(freq[s[k]].second)
		
		if(repition)
			repition=dp[n-freq[s[k]].second-1]%mod;
		freq[s[k]].first++;
		freq[s[k]].second=k;

		dp[n-k]= (2*dp[n-k-1]%mod - repition)%mod;

	}
	// for(int i=0;i<=n;i++){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;
	return dp[n]%mod;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	cout<<count(s)<<endl;

}

return 0;
}