#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll maxperi(ll arr[], ll n){
	sort(arr,arr+n,greater<	ll>());
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			for(ll k=j+1;k<n;k++){
				if(arr[j]+arr[k]>arr[i] and arr[j]+arr[i]>arr[k] and arr[k]+arr[i]>arr[j]){
					cout<<arr[k]<<" "<<arr[j]<<" "<<arr[i]<<"\n";
					return arr[j]+arr[i]+arr[k];
				}
			}

		}
	}
	cout<<-1<<"\n";
return -1;
	
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
ll res=maxperi(arr,n);
return 0;
}