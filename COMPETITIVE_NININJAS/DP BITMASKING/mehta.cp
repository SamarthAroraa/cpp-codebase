#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


ll unsetBit(ll n,ll x){
	n = n ^ (1<<x);
	return n;
}

ll dp[2001][2001][11];

ll func(ll n,ll prime_rem,ll w,vector<pll> &Items,vector<ll> &Primes){
	if(n==0 || w<=0){
		return 0;
	}
	if(dp[n][w][prime_rem]!=-1){
		return dp[n][w][prime_rem];
	}

	ll op1 = func(n-1,prime_rem,w,Items,Primes);
	ll op2 = 0;
	if(w>=Items[n-1].second){
		ll prime_num = 1;
		if(prime_rem>0){
			prime_num = Primes[prime_rem-1];
			op2 = Items[n-1].first*prime_num +  func(n-1,prime_rem-1,w-Items[n-1].second,Items,Primes);
		}else{
			op2 = Items[n-1].first + func(n-1,prime_rem,w-Items[n-1].second,Items,Primes);
		}
	}
	dp[n][w][prime_rem] = max(op1,op2);
	return dp[n][w][prime_rem];
}

int main(){
	
	
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		#endif
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		
	
	
	
		 
	
		memset(dp,-1,sizeof(dp));
		ll n,w; cin>>n>>w;
		vector<pll> Items(n);
		vector<ll> Primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

		for(ll i=0;i<n;i++){
			cin>>Items[i].first>>Items[i].second;
		}

		auto mycmp = [&] (pll a,pll b){
			if(a.first == b.first){
				return a.second>b.second;
			}
			return a.first<b.first;
		};
		sort(Items.begin(),Items.end(),mycmp);
		ll ans = func(n,10,w,Items,Primes);
		cout<<ans<<endl;
	return 0;
}


