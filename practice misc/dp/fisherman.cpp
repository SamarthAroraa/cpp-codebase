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
#define Mxn 51
		int arr[Mxn][Mxn];
		int tolls[Mxn][Mxn];

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
bool visited[Mxn][Mxn];

pii mincost(int i,int n, int time_left){
	if(time_left<0){
		return  mp(INF,INF);
	}
	if(i==n){
		return mp(0,0);
	}
	// visited[i][j]=1;
	pii minc=mp(INF,INF);
	for(int j=1;j<n+1;j++){
		if(j==i)
			continue;
		// if(visited[i][j]==0){
			pii res= mincost(j,n,time_left-arr[i][j]);
			minc=min(minc,res.fi+tolls[i][j]);
		// }
	}
	return  minc;

}

void solveQues(){
	
		int n , tim;
		cin>>n>>tim;
		if(n==0 and t==0)
			return;
		RESET(visited, 0);
		RESET(arr, 0);
		FOR(i,1,n+1){
			FOR(j,1,n+1){
				cin>>arr[i][j];
			}
		} 
		FOR(i,1,n+1){
			FOR(j,1,n+1){
				cin>>tolls[i][j];
			}
		} 
		cout<<mintime(1, n)<<endl;
	
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