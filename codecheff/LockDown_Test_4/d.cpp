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
ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};
ll ddx[] = {1,0,-1,0,1,-1,-1,1};
ll ddy[] = {0,1,0,-1,1,-1,1,-1};
#define MAXV(v) *max_element(v.begin(),v.end())
#define MINV(v) *min_element(v.begin(),v.end())
#define MAXA(a,n) *max_element(a,a+n)
#define MINA(a,n) *min_element(a,a+n)
#define REV(v) reverse(v.begin(),v.end())
#define SUM(v) accumulate(v.begin(),v.end(),0)
#define gcd __gcd
#define TC(t) while (t--)

vi segment_tree;
void init_segment_tree(ll N) { // if original array size is N,
// the required segment_tree array length is 2*2^(floor(log2(N)) + 1); ll length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1))); segment_tree.resize(length, 0); // resize this vector and fill with 0
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
ll compute(ll n, ll k){
	ll x=k/2;
	// ll sq= ((n+x)%mod)* ((n+x)%mod) %mod;
	ll sq= (ll)pow(n+x,2,mod);
	
	sq= (sq%mod+x%mod)%mod;
	return sq;
}


void solveQues(){
	ll t;
	cin>>t;
	TC(t)
	{
		ll n,k;
		cin>>n>>k;
		ll ans=0;
		if(n!=0){
		if(k%2==0){
			 ans= compute(n,k-1);
			ans = (ans%mod + (2*(n%mod))%mod)%mod;
		}
		else{
			ans= compute(n,k);
		}
		cout<<ans<<"\n";

	}
	else{
		ll n1=k;
		ll n2=k-1;
		ll ans;
		if(k<=1){
			ans=0;
		}
		else if(k==2){
			ans=2;
		}
			else{
				ans= (n1*n2)%mod;
			}
			cout<<ans<<endl;
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