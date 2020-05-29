#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
#define MAX 1000001
bool cubefree[MAX+1];
bool sieve[MAX+1];
ll cubes[MAX+1];


void gen_cf(std::vector<ll>* primes){
	ll n= primes->size();
	for(ll k=0;k<=MAX;k++){
		cubefree[k]=1;
	}

	for(ll i=0;i<n;i++){
		ll num= primes->at(i);
		ll cubed= pow(num,3);
		for(ll j=cubed;j<=MAX;j+=cubed){
			cubefree[j]=0;
		}
	}
	ll c=0;
	for(ll j=1;j<=MAX;j++){
		if(cubefree[j]==0){
			c++;
			cubes[j]=-1;
			continue;
		}
		cubes[j]=j-c;
	}

}
std::vector<ll>* gensieve(){
	for(ll i=0;i<=MAX;i++){
		sieve[i]=true;
	}

	sieve[0]=0;sieve[1]=0;
	for(ll i=2;i*i<=MAX;i++){
		if(sieve[i]==1){
			for(ll j=i*i;j<=MAX;j+=i){
				sieve[j]=0;
			}
		}
	}
	std::vector<ll>* v= new std::vector<ll>();
	v->push_back(2);
	for(ll i=3;i<=MAX;i+=2){
		if(sieve[i]){
			v->push_back(i);
		}
	}
	return v;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<ll> *primes=new vector<ll>();
	primes=gensieve();
	gen_cf(primes);
	int t;
	cin>>t;
	int temp=t;
	while(t--){
		int n;
		cin>>n;
		cout<<"Case "<<temp-t<<": ";
		if(cubes[n]==-1){
			cout<<"Not Cube Free\n";
		}
		else{
			cout<<cubes[n]<<"\n";
		}
	}




	 
return 0;
}