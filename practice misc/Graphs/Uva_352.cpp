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


bool image[25][25];
bool visited[25][25];

void dfs(int i , int j,int n){
	// cerr<<i<<" "<<j<<endl;
	visited[i][j]=1;
	for(int m=0;m<8;m++){
		for(int k=0;k<8;k++){
			if(i+ddx[m]>=0 and i+ddx[m]<n and j+ddy[k]>=0 and j+ddy[k]<n){
			if(image[i+ddx[m]][j+ddy[k]]==1 and visited[i+ddx[m]][j+ddy[k]]==0){
				dfs(i+ddx[m],j+ddy[k],n);
			}
		}
	}


	}
	return;	
}
void solveQues(){
	
	int n;
	int number=0;
	while(true){
		number++;
		n=-1;
		cin>>n;
		if(n==-1)
		break;

	RESET(visited,0);
	RESET(image,0);
	FOR(i,0,n){
		FOR(j,0,n){
			char c;
			cin>>c;
			image[i][j]=c-'0';
		}
	}
	
	int count=0;
	FOR(i,0,n){
		FOR(j,0,n){
			if(visited[i][j]==0 and image[i][j]==1){
				dfs(i,j,n);
				cerr<<i<<" "<<j<<endl;
				count++;
				
			}
			
		}
	}
cout<<"Image number "<<number<<" contains "<<count<<" war eagles.\n";
	
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