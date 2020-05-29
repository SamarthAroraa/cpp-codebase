#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define mod 1000000007
#define SORTV(a) sort(a.begin(),a.end())
#define eb emplace_back
#define SORTA(a,n) sort(a,a+n)
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
#define INF (int)1e9
#define EPS 1e-9
#define bitcount  __builtin_popcount
#define fill(a,v) memset(a, v, sizeof a)
#define checkbit(n,b) ( (n >> b) & 1)
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int ddx[] = {1,0,-1,0,1,-1,-1,1};
int ddy[] = {0,1,0,-1,1,-1,1,-1};
#define MAXV(v) *max_element(v.begin(),v.end())
#define MINV(v) *min_element(v.begin(),v.end())
#define MAXA(a,n) *max_element(a,a+n)
#define MINA(a,n) *min_element(a,a+n)
#define REV(v) reverse(v.begin(),v.end())
#define SUM(v) accumulate(v.begin(),v.end(),0)
#define gcd __gcd
#define TC(t) while (t--)

vi segment_tree;
void init_segment_tree(int N) { // if original array size is N,
// the required segment_tree array length is 2*2^(floor(log2(N)) + 1); int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1))); segment_tree.resize(length, 0); // resize this vector and fill with 0
}

ll pow(ll a, ll b, ll c){
	if(b==0)
		return  1;

		ll val=pow(a,b/2,c);
		ll ans= (val*val)%c;
		if(b%2!=0){
			ans =( ans* (a%c))%c;
		}
		return ((ans+c)%c);

}
void solveQues(){
	int t;
	cin>>t;
	TC(t){
		int n;
		cin>>n;	
		int arr[n];
		unordered_map<int, int>f;
		FOR(i,0,n){cin>>arr[i];
			f[arr[i]]++;
		};
		bool flag=0;
		unordered_map<int,bool> m;
		FOR(i,0,n-1){
			if(m[arr[i]]==0){
				if(arr[i]!=arr[i+1]){
					m[arr[i]]=1;
				}
				else{
					continue;
				}
			}
			else{
				flag=1;
				// cerr<<arr[i]<<" "<<i;
				break;
			}
		}
		if(arr[n-1]!=arr[n-2] and m[arr[n-1]]==1){
			// deb(m[])
			flag=1;
		}
		unordered_map<int, int> finv;
		FOREACH(k,f){
			if(finv[k.se]==0){
			finv[k.se]=k.fi;
		}
		else{
			// deb(k.fi)
			// deb(k.se)
			flag=1;
			break;
		}
		}
		if(flag==0){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	
	return;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solveQues();


	 
return 0;
}