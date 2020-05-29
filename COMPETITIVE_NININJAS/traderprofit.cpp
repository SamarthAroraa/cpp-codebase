#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
// int trader_profit(std::vector<int> prices, int n, int k){
// 	int dp[n+1][k+1][2];
// 	deb(k)
// 	//initializing 0 profit for 0 element array
// 	// for(int i=0;i<=k;i++){
// 	// 	dp[0][i][0]=0;
// 	// 	dp[0][i][1]=0;
// 	// }
// 	// //initializing 0 profit for 0 number of transactions
// 	// for(int i=0;i<=n;i++){
// 	// 	dp[i][0][0]=0;
// 	// 	dp[i][0][1]=0;
// 	// }
// 	for(int i=0;i<=n;i++){
// 		for(int j=0;j<=k;j++){
// 			for(int m=0;m<=1;m++){
// 				dp[i][j][m]=0;
// 			}
// 		}
// 	}
// 	int ongoing=0;
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=k;j++){
// 			if(ongoing){
// 				if(dp[i-1][j-1][0]+prices[i-1]>dp[i-1][j-1][1]){
// 					ongoing = 0;
// 					dp[i][j][0]=dp[i-1][j-1][1]+prices[i-1];
// 				}

// 			}
// 			else if(j>0){
// 				// if(dp[i-1][j][1]-prices[i-1]>dp[i][j][ongoing]){
// 					ongoing=1;
// 					dp[i][j][1]=dp[i-1][j][0]+prices[i-1];
// 					deb(prices[i-1])
// 					deb(dp[i][j][0])
// 					dp[i][j][0]=dp[i-1][j][0];

// 				// }
// 			}
// 	}
// }
// // for(int i=0;i<n;i++){
// // 	cerr<<prices[i]<<"\t    ";
// // }
// // cerr<<endl;
// for(int i=0;i<=n;i++){
// 	if(i!=0)
// 		cerr<<prices[i-1]<<"\t";
// 	else
// 		cerr<<" \t";
// 		for(int j=0;j<=k;j++){
// 			// for(int m=0;m<=1;m++){
// 				cerr<<"("<<dp[i][j][0]<<","<<dp[i][j][1]<<")\t";
// 			// }
// 		}
// 	cerr<<endl;}
// return max(dp[n][k][0],dp[n][k][1]);
// }

int trader_profit(int array[],int n,int k, bool ongoing){
	if(n==0)
		return 0;
	int buy= INT_MIN,sell=INT_MIN;
	int ignore= trader_profit(array+1, n-1,k,ongoing);
	if(ongoing){
		 sell= trader_profit(array+1,n-1,k-1,0)+array[0];
	}
	else if(k>0){
		buy=trader_profit(array+1,n-1,k,1)-array[0];
	}
	return max(buy,max(sell,ignore));
}
int trader_profit_dp(int array[], int n, int k){
int ignore;
bool ongoing = 0;
int dp[n+1][k+1];
for(int i=0;i<n+1;i++){
	for(int j=0;j<k+1;j++){
		
			dp[i][j]=0;
		
	}
}
for(int j=1;j<k+1;j++){
	ongoing=0;
	int prev=INT_MIN;

	for(int i=1;i<n+1;i++){
	prev=max(prev, dp[i-1][j-1]-array[i-1]);
	dp[i][j]=max(dp[i][j-1],array[i-1]+ prev);
	}
	

}
for(int i=0;i<=n;i++){
	if(i!=0)
		cerr<<array[i-1]<<"\t";
	else
		cerr<<" \t";
		for(int j=0;j<=k;j++){
			// for(int m=0;m<=1;m++){
				cerr<<"("<<dp[i][j]<<")\t";
			// }
		}
	cerr<<endl;}
return (dp[n][k]);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int q;
	cin>>q;
	while(q--){
	int k;
	cin>>k;
	int n;
	cin>>n;
	int prices[n];
	for(int i=0;i<n;i++){
		cin>>prices[i];
	}
	cout<<trader_profit_dp(prices,n,k)<<endl;
}
return 0;
}