#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void printKMax(ll arr[], ll n, ll k) 
{ 
	ll global=0;
	for(ll i=0;i<n;i++){
		global= max(global,arr[i]+arr[i+1]+arr[i+2]);

	}
cout<<global<<endl;} 

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
		// ll k=3;
		ll arr[n+2];
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		arr[n]=arr[0];
		arr[n+1]=arr[1];
		printKMax(arr,n,3);
	}

return 0;
}

// C++ Program to find the maximum for 


// Method to find the maximum for each 
// and every contiguous subarray of size k. 

// Driver code 
