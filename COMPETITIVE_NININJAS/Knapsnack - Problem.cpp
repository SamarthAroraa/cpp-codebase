#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int maxval(int* weights, int* values, int n, int maxWeight){
	int dp[n+1][maxWeight+1];
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int i=0;i<=maxWeight;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){

		for(int j=1;j<=maxWeight;j++){
			if(j-weights[i-1]>=0){
				dp[i][j]= max(dp[i-1][j-weights[i-1]]+values[i-1], dp[i-1][j]);
			}
			else
				dp[i][j]= dp[i-1][j];
		}
	}
	// int i,j;
// 		for(i=0;i<=n;i++){
// 	for(j=0;j<=maxWeight;j++){
// 		cout<<dp[i][j]<< "\t"; 
// 	}
// 	cout<<endl;
// }
// 	cout<<endl;
return dp[n][maxWeight];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int *weights= new int[n];
	int *values = new int[n];
	for(int i=0;i<n;i++){
		cin>>weights[i];
	}
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	int maxWeight;
	cin>>maxWeight;
	cout<<maxval(weights,values,n,maxWeight);

return 0;
}