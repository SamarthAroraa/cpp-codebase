#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n)
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define RESET(a, b) memset(a, b, sizeof(a)) 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define TC(t) while (t--)
unordered_map<int, int > getfactors(int n){
	unordered_map<int, int> factor;
	int temp=n;
	for(int i=2;i*i<=temp;i++){
		// int c=0;
		// int temp=n;
		while(n%i==0){
			n/=i;
			// deb(i)
			// deb(n)
			factor[i]++;
		}
	}
	if(factor.empty() or n!=1){
		factor[n]++;
	}
	return factor;
}

int solve(int k, int n, int arr[]){
	unordered_map<int , int> k_fac= getfactors(k);
	unordered_map<int , int> cumulative;
	int ans=0;
	int i=0,j=0;
	unordered_map<int, int> factors=getfactors(arr[0]);
	FOREACH(fac, factors){
			cumulative[fac.fi]+=fac.se;
}

	while(i<n and j<n){
		bool flag=0;

		

		FOREACH(fac, k_fac){

			if(cumulative[fac.fi]<k_fac[fac.fi]){
				cerr<<cumulative[fac.fi]<<" "<<k_fac[fac.fi]<<" "<<fac.fi<<endl;
				
				flag=1;
				// break;
			}

		}
		if(flag==0){
			ans+=(n-j);
			deb(arr[j])
			deb(arr[i])
			deb(n-j)
			deb(j)
			deb(ans)
			unordered_map<int,int> reduction=getfactors(arr[i]);
			FOREACH(fac,reduction){
				
				cumulative[fac.fi]-=reduction[fac.fi];
				// deb(reduction[fac.fi])


			}
			i++;
		}
		else{
			j++;
			unordered_map<int, int> factors=getfactors(arr[j]);
			FOREACH(fac, factors){
			cumulative[fac.fi]+=fac.se;
		}
		}
	// 	else{
	// 	j++;
	// }

	}
return ans;
}

// ll ans(std::vector<ll> arr, std::vector<ll> prod, ll n, ll k){

// }
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];

	}
	// unordered_map<int , int>::iterator it=k_fac->begin();
	// FOREACH(fac, k_fac){
	// 	cout<<fac.fi<<" "<<fac.se<<endl;
	// }
	if(k!=1)
	cout<<solve(k,n,arr)<<endl;	 
	else{
		cout<<n*(n+1)/2;
	}
return 0;
}