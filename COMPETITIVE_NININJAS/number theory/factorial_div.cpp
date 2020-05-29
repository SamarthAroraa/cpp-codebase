#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
#define mod 1000000007
bool sieve[50001];
std::vector<ll>* gensieve(){
	for(int i=0;i<50001;i++){
		sieve[i]=true;
	}

	sieve[0]=0;sieve[1]=0;
	for(ll i=2;i*i<=50000;i++){
		if(sieve[i]==1){
			for(ll j=i*i;j<=50000;j+=i){
				sieve[j]=0;
			}
		}
	}
	std::vector<ll>* v= new std::vector<ll>();
	v->push_back(2);
	for(int i=3;i<=50000;i+=2){
		if(sieve[i]){
			v->push_back(i);
		}
	}
	return v;
}
ll ans(ll n,std::vector<ll>*& primes){
	ll ans=1;
	int j=0;
	while(primes->at(j)<=n and j<primes->size()){
		int i=primes->at(j);
			ll p=1;
			ll count=0;
			ll temp=pow(i,p);

			while(temp<=n){
				temp=pow(i,p);
				count+= (n/temp);
				p++;
			}
			deb(i)
			deb(count)
			ans=(ans%mod* (count+1)%mod)%mod;
		
	j++;
}
return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	vector<ll> *primes=new vector<ll>();
	primes=gensieve();
	ll n;
	cin>>n;
	cout<<ans(n,primes)<<"\n";
}
	



	 
return 0;
}