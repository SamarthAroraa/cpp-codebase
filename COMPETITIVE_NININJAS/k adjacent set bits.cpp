
#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;


int dp[101][101][2]; 


ll   countStrings(ll   n, ll   k) 
{ 
	// dp[i][j][0] stores count of binary 
	// strings of length i with j consecutive 
	// 1's and ending at 0. 
	// dp[i][j][1] stores count of binary 
	// strings of length i with j consecutive 
	// 1's and ending at 1. 
	// ll   dp[n + 1][k + 1][2]; 
	memset(dp, 0, sizeof(dp)); 

	// If n = 1 and k = 0. 
	dp[1][0][0] = 1; 
	dp[1][0][1] = 1; 

	for (ll   i = 2; i <= n; i++) { 
		// number of adjacent 1's can not exceed i-1 
		for (ll   j = 0; j < i; j++) { 
			dp[i][j][0] = (dp[i - 1][j][0]%1000000007 + dp[i - 1][j][1]%1000000007)%1000000007; 
			dp[i][j][1] = dp[i - 1][j][0]; 

			if (j - 1 >= 0) 
				dp[i][j][1] = (dp[i][j][1]%1000000007 + dp[i - 1][j - 1][1]%1000000007)%1000000007; 
		} 
	} 

	return (dp[n][k][0]%1000000007 + dp[n][k][1]%1000000007)%1000000007; 
} 

// Driver code 

// int countStrings(int n, int k) 
// { 
//     // dp[i][j][0] stores count of binary 
//     // strings of length i with j consecutive 
//     // 1's and ending at 0. 
//     // dp[i][j][1] stores count of binary 
//     // strings of length i with j consecutive 
//     // 1's and ending at 1
//     // int***dp= new int**[n+1]
//     // for(int i =0;i<n+1;i++){
//     // 	for(int j=0;j<k+1;j++){
//     // 		dp[i]= new int*[k+1];
//     // 		for(int k=0;k<2;k++){
//     // 			dp[i][j]= new in
//     // 		}
//     // 	}
//     // } 
//     memset(dp, 0, sizeof(dp)); 
  
//     // If n = 1 and k = 0. 
//     dp[1][0][0] = 1; 
//     dp[1][0][1] = 1; 
  
//     for (int i = 2; i <= n; i++) { 
//         // number of adjacent 1's can not exceed i-1 
//         for (int j = 0; j < i; j++) { 
//             dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1]; 
//             dp[i][j][1] = dp[i - 1][j][0]; 
  
//             if (j - 1 >= 0) 
//                 dp[i][j][1] += dp[i - 1][j - 1][1]; 
//         } 
//     } 
  
//     return dp[n][k][0] + dp[n][k][1]; 
// } 
int  main() 
{ 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int p;
	cin>>p;
	// cout<<p<<endl;
	while(p--){
		ll garbage;
	ll n , k ;
		cin>>garbage;
	cin>>n>>k; 
	cout << garbage<<" "<<countStrings(n, k)<<endl;
	} 
	return 0; 
}
