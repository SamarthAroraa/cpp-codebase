#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
#define MAX 1000001
ll sieve[MAX];
void gensieve(){
	for(ll i=0;i<=MAX;i++){
		sieve[i]=0;
	}

	sieve[0]=0;sieve[1]=0;
	for(ll i=2;i<=MAX;i++){
		if(sieve[i]==0){
			// deb(i)
			for(ll j=i*2;j<=MAX;j+=i){
				sieve[j]+=1;
			}
			sieve[i]=1;
		}
	}
	
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	gensieve();
	ll t;
	cin>>t;
	while(t--){
	ll a, b,n;
	cin>>a>>b>>n;
	ll ans=0;
	for(ll i=a;i<=b;i++){
		if(sieve[i]==n){
			ans++;
		}
	}

	cout<<ans<<"\n";
	}



	 
return 0;
}