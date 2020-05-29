#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
long ways(int n){
	std::vector<long> dp(n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		int l=i-2,m=i-3;
		long w= dp[i-1];
		if(l>=0)
			w+=dp[i-2];
		if(m>=0)
			w+=dp[i-3];
		dp[i]=w;
	}
return dp[n];}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cout<<ways(1)<<endl;
	cout<<ways(2)<<endl;
	cout<<ways(3)<<endl;
	cout<<ways(4)<<endl;

return 0;
}