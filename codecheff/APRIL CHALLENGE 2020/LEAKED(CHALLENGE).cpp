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
	time_t start, end; 
	time(&start);
	ll t;
	cin>>t;
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;

		unordered_map<ll, ll>* vertical= new unordered_map<ll,ll>[k];
		unordered_map<ll, ll>* horizontal=new unordered_map<ll,ll>[n];
		ll arr[n][k];

		for(ll i=0;i<n;i++){
			for(ll j=0;j<k;j++){
				cin>>arr[i][j];
				vertical[j][arr[i][j]]++;
				horizontal[i][arr[i][j]]++;
			}
		}
		ll ans[n];
		for(ll i=0;i<n;i++){
		ll besto=0;
		ll max_freq=INT_MIN;
		for(ll j=0;j<k;j++){
			for(ll x=1;x<=m;x++){
				ll curr=0;
				if(horizontal[i].find(x)!=horizontal[i].end())
				curr+= horizontal[i][x];
				if(vertical[j].find(x)!=vertical[j].end())
					curr+=vertical[j][x];
				if(curr>max_freq){
					max_freq=curr;
					besto=x;
				}
			}
		}
		if(besto!=0)
			ans[i]=besto;
		else
			ans[i]=4;
		cout<<ans[i]<<" ";

		}	
		cout<<"\n";
		delete [] vertical;
		delete[] horizontal;
	}

//code here

	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}