#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int edit_dist(string a, string b){
	int n1= a.length();
	int n2= b.length();

	int dp[n1+1][n2+1];
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			if(i!=0 and j!=0)
			dp[i][j]=0;
			else if(i==0 and j!=0){
				dp[i][j]= j;
			}
			else{
				dp[i][j]= i;
			}
		}
	}
	dp[0][0]=0;

	int i=1,j=1;
	for(i=1;i<=n1;i++){
		for(j=1;j<=n2;j++){
			if(a[n1-i]==b[n2-j]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1), dp[i-1][j-1]+1);
			}
		}
	}
// 	for(i=0;i<=n1;i++){
// 	for(j=0;j<=n2;j++){
// 		cout<<dp[i][j]<< "\t"; 
// 	}
// 	cout<<endl;
// }
// 	cout<<endl;
return dp[n1][n2];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string a,b;
	cin>>a>>b;
	cout<<edit_dist(a,b)<<endl;

return 0;
}