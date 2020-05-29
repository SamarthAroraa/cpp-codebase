#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int maxlen(string a, string b){
// if(a.length()==0 or b.length()==0)
// 	return 0;
// int aage;
// if(a[0]==b[0]){
// 	aage= 1+ maxlen(a.substr(1),b.substr(1));
// }
// else{
// 	aage= max(maxlen(a.substr(1),b),maxlen(a,b.substr(1)) );
// }

// return aage;

	int n1= a.length(), n2=b.length();
	if(n1==0 or n2==0)
		return 0;
	int dp[n1+1][n2+1];
	for(int i=0;i<=n1;i++){
	for(int j=0;j<=n2;j++){
	dp[i][j]=0;

		}
	// cout<<end bl;
}
	int maxi=INT_MIN;
	int i=1,j=1;
	for(i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
		if(a[n1-i]==b[n2-j]){
			dp[i][j]= dp[i-1][j-1]+1;
			// j++;i++; 
		}
		else{
			// if(dp[i][j-1]>dp[i-1][j]){
				dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
				// j++;
			// }
			// else{
			// 	dp[i][j]= dp[i-1][j];
			// 	i++;
			// }
		}
		maxi=max(maxi,dp[i][j]);
}
	}
for(i=0;i<=n1;i++){
	for(j=0;j<=n2;j++){
		cout<<dp[i][j]<< "\t"; 
	}
	cout<<endl;
}
	cout<<endl;

return maxi;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string a, b;
	 cin>>a>>b;
	 if(a.length()>b.length()){
	 	swap(a,b);
	 }
cout<<maxlen(a,b)<<endl;
return 0;
}	