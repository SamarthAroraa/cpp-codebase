#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

bool check(ll arr[],int n,int k, int  mid){
	int t=0;
	int j=n-1;
	while(t<k and j>=0 ){
		t+=(arr[j--]/mid);
		if(t>=k)
			return 1;
	}
	

return 0;
}
ll binary_s(ll arr[], int n,int k){
	int low=0,high=arr[n-1];
	int mid= (low+high)/2;
	while(low<high){
		mid= ceil((low+high)/2.0);
	// cout<<mid<<" "<<low<<high<<endl;
	if(low== mid)
		return low;
		if(check(arr,n,k,mid)){
			low = mid;
		}
		else{
			high = mid-1;
		}

	}
	deb(low)
	deb(high)
	deb(mid)
	mid= (low+high)/2;
	deb(mid)
	cerr<<"\n\n";
	

return mid;
}


ll ans(ll arr[],ll n,ll k){
sort(arr,arr+n);
return binary_s(arr,n,k);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
ll t;
cin>>t;
while(t--){
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<ans(arr,n,k)<<endl;



}

return 0;
}