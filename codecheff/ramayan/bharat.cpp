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
#define mXn 2001
int dp[mXn][mXn];


ll poss(int n, int k,int i, int h){

	if(i==1 or h==k)
		return 1;

	ll myans=0;
	for(int j=i;j>=1;j--){
		myans= (myans + poss(n, k , j, h+1)%mod)%mod;
	}
	return myans;
}
void solveQues(){
	int n,k;
	cin>>n>>k;
	ll ans=0;
	ll dp2[n+1][k+1];
	FOR(i,1,n+1){
		dp[i][1]=1;
		dp2[i][1]=1;
	}
	FOR(i,1,k+1){
		dp[1][i]=1;
		dp2[1][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++)
		{
			ll sum=0;
			for(int m =i ;m >=1; m--){
				sum = (sum + dp2[m][j-1]) % mod;
			}
			dp2[i][j]=sum;
			dp[i][j] = (dp[i][j-1]+dp[i-1][j])%mod;
		}
	}

	FOR(i,1,n+1){
		FOR(j,1,k+1){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	FOR(i,1,n+1){
		FOR(j,1,k+1){
			cout<<dp2[i][j]<<" ";
		}
		cout<<endl;
	}


	ans=0;
	FOR(i,1,n+1){
		ans= (ans + dp[i][k]) %mod;
	}
	cout<<ans<<endl;
	
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