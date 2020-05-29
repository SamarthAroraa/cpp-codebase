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
#define bitcount __builtin_popcount
#define gcd __gcd
#define se second 
#define mp make_pair 
#define pb push_back 
#define TC(t) while (t--)


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	TC(t){
		int n;
		cin>>n;
		int arr[n];
		REP(i,n){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		int best=INT_MAX;	
		int worst=INT_MIN;
		REP(i,n){
			int l=i-1,r=i+1;
			int infl=0;
			while(l>=0){
				if(abs(arr[l]-arr[l+1])>2){
					break;
				}
				infl++;
				l--;
			}
			int infr=0;
			while(r<n){
				if(abs(arr[r]-arr[r-1])>2){
					break;
				}
				infr++;
				r++;
			}
			best=min(best, infr+infl+1);
			// deb(infl)
			// deb(infr)
			// deb(arr[i])

			worst=max(worst, infr+infl+1);

		}
		cout<<best<<" "<<worst<<"\n";


	}
	



	 
return 0;
}