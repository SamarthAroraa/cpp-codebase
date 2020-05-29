#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll ans(ll arr[], ll n,ll maxi){
	// deb(maxi)
	vector<ll> small;
		ll acc=0;

	for(ll i=0;i<n;i++){
		if(arr[i]==maxi)
		{
			small.push_back(acc);

			small.push_back(-1);
			acc=0;
			continue;
		}
		acc++;
		
	}
	if(acc!=0)
	small.push_back(acc);

	ll sl= small.size();
	if(small[0]!=-1 and small[sl-1]!=-1){
		small[0]+=small[sl-1];
		small[sl-1]=0;
	}

ll sumk=0;
ll mid=n/2;
for(ll i=0;i<sl;i++){
	// cerr<<small[i]<<" ";
	if(small[i]<n/2){
		continue;
	}
	else{
		sumk+=(small[i]-mid+1);
	}
}
// cerr<<"\n";
return sumk;
}
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
	ll maxi=INT_MIN;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		maxi=max(maxi,arr[i]);
	}
	if(n!=1)
	cout<<ans(arr,n,maxi)<<endl;
	else{
		cout<<"0\n";
	}
}


return 0;
}