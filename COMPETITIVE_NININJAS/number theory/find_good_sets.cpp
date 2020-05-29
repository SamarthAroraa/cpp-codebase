#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
#define MAX  750000
#define mod 1000000007
int dp[MAX+1];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		int n;
		int maxel=0;
		cin>>n;
		int ans=0;
		for(int i=0;i<n;i++){
			int e;
			cin>>e;
			maxel=max(e,maxel);
			dp[e]=1;
			ans+=1;
		}
		for(int i=1;i<=maxel/2;i++){
			if(dp[i]!=0)
			{
				for(int j=2*i;j<=maxel;j+=i){
					if(dp[j]!=0 and j%i==0){
						dp[j]= (dp[i]%mod +  dp[j]%mod)%mod ;
						
						ans= (ans%mod + dp[i]%mod )%mod;
					}
				}
			}
		}
		cout<<ans<<"\n";
		

	}	 
return 0;
}