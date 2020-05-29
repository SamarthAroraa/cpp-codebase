#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		cout<<arr[n-2]<<endl;
	}
return 0;
}