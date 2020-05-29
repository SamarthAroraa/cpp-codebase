#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int mincost(int **arr, int n, int m){
	int dp[n][m];
	for(int i=0;i<m;i++){
		dp[n-1][i]=arr[n-1][i];
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<m;j++){
			int left=INT_MAX,right=INT_MAX;
			if(j!=0)
			 left= dp[i+1][j-1];
			if(j!=m-1){
			 right= dp[i+1][j+1];
			}
			dp[i][j]= min(left,min(right,dp[i+1][j]))+arr[i][j];
		}
	}

	int mini=INT_MAX;
	for(int j=0;j<m;j++){
		mini=min(mini,dp[0][j]);
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<dp[i][j]<<  " ";
	// 	}
	// cout<<endl;}
	return mini;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	int **arr= new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]= new int[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
cout<<mincost(arr,n,m)<<endl;
for(int i=0;i<n;i++){
	delete [] arr[i];
}
delete [] arr;

return 0;
}