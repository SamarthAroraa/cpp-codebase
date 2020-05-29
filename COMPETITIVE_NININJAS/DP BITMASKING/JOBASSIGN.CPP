#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
// ll jobassign(ll index, ll n,ll cost[][4],ll mask,ll *dp){
// 	if(index>=n)
// 		return 0;
// 	if(dp[mask]!=INT_MAX){
// 		cerr<<1<<endl;
// 		return dp[mask];
// 	}
// 	ll mincost=INT_MAX;
// 	for(ll i=0;i<n;i++){
// 		if((mask&1<<i)==0){
// 			ll ans=jobassign(index+1,n,cost,mask or 1<<i,dp)+cost[index][i];
// 			mincost=min(ans,mincost);
// 		}
// 	}
// dp[mask]=mincost;
// return mincost;
// }

ll dpsolution(ll cost[][4], ll n){
	ll dp[1<<n];
	for(ll i=0;i<1<<n;i++)
		dp[i]=INT_MAX;

	dp[0]=0;
	ll mask=0;
	for(mask=0;mask<(1<<n)-1;mask++){
		ll k=0;
		ll temp= mask;
		while(temp>0){
			if(temp%2==1){
				k++;
			}
			temp/=2;
		}
		// deb(k)
		for(ll j=0;j<n;j++){
		if( ((mask & (1<<j))==0 )){
			dp[mask | (1<<j)] = min( dp[mask | (1<<j)] , dp[mask] + cost[k][j] );
			deb(dp[mask | 1<<j])
			int x=(mask | (1<<j));
			deb(x)
			deb(cost[k][j])
			deb(dp[mask])
			deb(mask)
		}
	}

	}
	// deb((1<<n)-1)
	for(ll i=0;i<1<<n;i++){
		cerr<<dp[i]<<" ";
	}
	cerr<<endl;
	return dp[(1<<n)-1];
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t start, end; 
	time(&start);
	ll cost[4][4]={{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
	// ll *dp=new int[1<<4];

// 	for(ll i=0;i<(1<<4);i++){
// 	dp[i]=INT_MAX;

// }
	cout<<dpsolution(cost,4);

//code here

	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}