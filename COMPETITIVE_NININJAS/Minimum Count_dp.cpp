#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int minCount(int  n){
	int dp[n+1];
	dp[1]=1;
	dp[2]=2;
	for(int j=3;j<=n;j++){
		int current=INT_MAX;
		float check= sqrt(j);
		check= check - floor(check);
		deb(check)
		if(check==(float)0)
			dp[j]=1;
		else{
		for(int i=j-1;i>=1;i--){
			// deb(dp[i]+dp[j-i])
			// deb(j)
			// deb(i)
			current= min(dp[i]+dp[j-i], current);
		}
		dp[j]= current;
	}
	}
return dp[n];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	for(int i=1;i<=13;i++){
		cout<<minCount(i)<<endl;
	}

return 0;
}