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
		int i=0;
		int dtemp=d;
		int offset= dtemp%arr[0];

		int initd;
		while(1){
			dtemp=initd-(offset);
			initd=dtemp;
			deb(dtemp)

			bool flag=1;
			for(int j=1;j<n;j++){
				while(dtemp%arr[j]!=0){
					dtemp++;
					if(dtemp>d){
					flag=0;
					break;
				}
				// j--;
				// continue;
				}
				if(dtemp>d){
					flag=0;
					break;
				}
			}
			if(flag==1)
				break;
			i++;
		}
		
		cout<<"Case #"<<temp-t<<": "<<initd<<"\n";
	
	}
	



	 
return 0;
}