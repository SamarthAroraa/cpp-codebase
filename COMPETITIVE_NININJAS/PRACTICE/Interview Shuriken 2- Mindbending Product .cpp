#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void product_arr(std::vector<ll > &arr){
	ll  accumul=1;
	ll  n= arr.size();
	for(ll  i=0;i<n;i++){
		ll  prod=1;
		for(ll  j=i+1;j<n;j++){
			prod*=arr[j];
		}
		ll  temp=accumul;

		accumul=arr[i]* accumul;
		arr[i]= temp * prod;
		// cerr<<accumul<<endl;

	}
}
int  main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll  t;
	cin>>t;
	while(t--){
		ll  n;
		cin>>n;
	std::vector<ll > arr(n);
	for(ll  i=0;i<n;i++){
		cin>>arr[i]; 
	}
	product_arr(arr);
	for(ll  i=0;i<n;i++){
		cout<<arr[i]<<" "; 
	}
	cout<<endl;
}

return 0;
}