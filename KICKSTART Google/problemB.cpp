#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	ll temp=t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		ll arr[n];
		for(ll i=0;i<n;i++)
			cin>>arr[i];
		ll dtemp=d;
		ll j=n-1;
		while(j>=0 and dtemp>0){
			if(dtemp%arr[j]==0){
				j--;
				// deb(d/)
			}
			else{
				dtemp--;
			}
		}
	
				cout<<"Case #"<<temp-t<<": "<<dtemp<<"\n";
	
	}
	



	 
return 0;
}