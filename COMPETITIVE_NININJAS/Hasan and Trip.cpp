#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<setprecision(7)<<x<<endl;
#define ll  long double
using namespace std;
inline long double distance(ll x1, ll y1, ll x2, ll y2)
{
	return (sqrt((long double)((ll)pow(x1-x2,2)+(ll)pow(y1-y2,2))));
}

long double happy(std::vector<pair<ll , ll > > coordinates, std::vector<ll > f, ll n)
{
	std::vector<long double> dp(n);
	dp[0]= f[0];
	// long double tank=f[0];
	for(ll i=1;i<n;i++){
		 dp[i] =INT_MIN;
		for(ll j=i-1;j>=0;j--){
			long double temp= dp[i];
			dp[i]= max(dp[i],(ll)((ll)dp[j]- (ll)distance(coordinates[i].first, coordinates[i].second, coordinates[j].first,coordinates[j].second)));
			// if(dp[i]!=temp){
			// deb(distance(coordinates[i].first, coordinates[i].second, coordinates[j].first,coordinates[j].second))

			// 	// coordinates[j].first= INT_MAX;
			// 	// coordinates[j].second= INT_MAX;
			// }
		}
		dp[i]+=f[i];
		
	}
return dp[n-1];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	std::vector<pair<ll ,ll >> coordinates(n);
	std::vector<ll > f(n);
	for(ll i=0;i<n;i++){
		cin>>coordinates[i].first;
		cin>>coordinates[i].second;
		cin>>f[i];

	}
	cout<<fixed;
	cout.precision(6);
	cout<<happy(coordinates,f,n)<<endl;
return 0;
}