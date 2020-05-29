#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
#define mod 1000000007
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t start, end; 
	time(&start);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr, arr+n, greater<ll>());
		ll sum=0;
		for(ll i=0;i<n;i++){
			if(arr[i]%mod-i%mod>0)
			sum= (sum%mod + (arr[i]%mod-i%mod)%mod)%mod;
		}
		cout<<sum<<"\n";

	}

//code here

	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}