#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int max_loot(int arr[], int n){
	std::vector<int> dp(n);
	dp[0]= arr[0];
	dp[1]= arr[1];
	int glob_max=max(arr[0],arr[1]);
	for(int i=2;i<n;i++){
		int maxim=INT_MIN;
		for(int j=0;j<i-1;j++){
			maxim=max(maxim, dp[j]);
		}
		dp[i]= maxim+arr[i];
		glob_max= max(glob_max, dp[i]);
	}
return glob_max;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];

	}
cout<<max_loot(arr,n);
return 0;
}