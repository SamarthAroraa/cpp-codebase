#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
#define mod 1000000007
using namespace std;
bool judge(ll n, ll p, ll q, ll k[],ll a[], ll s[], string bin){
	ll kf=0,af=0;
	ll kd=0,ad=0;
	for(ll i=0;i<n;i++){
		ll sum= (k[i]%mod+a[i]%mod)%mod;
		if(sum==s[i]){
			if(bin[i]=='0'){
				kf=(k[i]+kf)%mod;
				af=(a[i]+af)%mod;
			}
			else{
				kd=(kd+k[i])%mod;
				ad=(ad+a[i])%mod;
			}
		}

	}
	deb(kf)
	deb(af)
	deb(kd)
	deb(ad)
	return ( (((p%mod)*(kf%mod))%mod + ((q%mod)*(af%mod))%mod)%mod  > ( ((p%mod) *(kd%mod))%mod + (q%mod)*(ad%mod)%mod)%mod )%mod	;
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
		ll p,q;
		cin>>p>>q;
		ll k[n],a[n],s[n];
		string bin;

	for(ll i=0;i<n;i++){
		cin>>k[i];
	}
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		cin>>s[i];
	}
	cin>>bin;
	if(judge(n,p,q,k,a,s,bin)){
		cout<<"Frost"<<endl;
	}
	else{
		cout<<"DustinKiller"<<endl;
	}
}
return 0;
}