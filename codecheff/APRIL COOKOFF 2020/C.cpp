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
ll solve(string s, string r,ll n){

	bool diff[n];
	RESET(diff, 0);
	for(ll i=0;i<n;i++){
		if(s[i]!=r[i]){
			diff[i]=1;
		}
	}
	ll groups=0;
	ll si=-1;
	ll l=0;
	vi gaps;
	int last=-1;
	// if(diff[0]){
	// 	si=0;
	// }
	// int lo=-1;
	FOR(i,1,n-1){
		if(diff[i]==0 and diff[i-1]==1){
			last=i;
		}
		if(diff[i]==0 and diff[i+1]==1 and last!=-1){
			gaps.pb(i-last+1);
		}
	}
	for(ll i=0;i<n;i++){
		// if(diff[i])
			// lo=i;
		// if(diff[i])
		if(diff[i] and si==-1){
		 si=i;	
		}
		if(diff[i] and (diff[i+1]==0 or i==n-1)){
			int gs=(i-si+1);
			// if(gs>3 or i==n-1){
			groups++;
			si=-1;
			l+=gs;
		// }
		// else{
			// l+=(i-lo);
		// }
		}

	}
	ll ans= l*groups;
	sort(gaps.begin(), gaps.end());
	for(int i=0;i<gaps.size();i++){
		groups--;
		l+=gaps[i];
		ans= min(ans,l* groups);
	}
	// if(diff[n-1] and !diff[n-2]){
	// 	groups++;
	// 	l++;
	// }
	  
return ans;

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	TC(t){
		string s,r;
		cin>>s>>r;
		ll n= s.length();
		cout<<solve(s,r,n)<<"\n";
	}




	 
return 0;
}