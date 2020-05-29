#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

void maxfun(int *costs, int *fun, int n, int budget){
	int **dp= new int*[n+1];
	int sum=0;
	int spended[n+1][budget+1];
	spended[0][0]=0;
	for(int i=0;i<=n;i++){
		dp[i]= new int [budget+1];
	}

	for(int i=0;i<=n;i++){
		dp[i][0]=0;
		spended[i][0]=0;
	}
	for(int i=0;i<=budget;i++){
		dp[0][i]=0;
		spended[0][i]=0;

	}

	for(int siz=1;siz<=n;siz++){
		for(int bud=1;bud<=budget;bud++){
			dp[siz][bud]=dp[siz-1][bud];
			spended[siz][bud]= spended[siz-1][bud];
			if(bud>=costs[siz-1]){
				int temp=dp[siz][bud];
				dp[siz][bud]= max(dp[siz][bud], dp[siz-1][bud-costs[siz-1]]+ fun[siz-1]);
				if(temp!=dp[siz][bud])
				{
					spended[siz][bud]=spended[siz-1][bud- costs[siz-1]]+costs[siz-1];
				}

			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=budget;j++)
		{
			cout<<dp[i][j]<<" ";
		}
	cout<<endl;
}
	cout<<endl;

	for(int i=0;i<=n;i++){
		for(int j=0;j<=budget;j++)
		{
			cout<<spended[i][j]<<" ";
		}
	cout<<endl;
}
	cout<<endl;

int ans= dp[n][budget];
for(int i=0;i<=n;i++){
	delete [] dp[i];
}
delete []dp;
cout<<spended[n][budget]<<" "<<ans<<endl;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int budget=1;

	int n=1;
	while(1){
		cin>>budget;
		cin>>n;
		if(budget==0 and n==0)
			break;
		// cin>>n;
	int *costs= new int[n];
	int *fun= new int[n];
	for(int i=0;i<n;i++)
	{
	cin>>costs[i];
	cin>>fun[i];
	}
	maxfun(costs, fun,n,budget);
delete []costs;
delete[] fun;
}
return 0;
}