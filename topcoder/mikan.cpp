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


double dist(int x1,int x2, int y1, int y2){
	double d=pow( (double)pow(x1-x2,2)+(double)pow(y1-y2,2),0.5);
	return d;
}


class ATaleOfThreeCities{
    public:
     double connect(vector <int> ax, vector <int> ay, vector <int> bx, vector <int> by, vector <int> cx, vector <int> cy){
     	int as=ax.size();
     	int bs=bx.size();
     	int cs=cx.size();
     	double abmin=INT_MAX;
    	//a b min
    	FOR(i,0,as){
    		FOR(j,0,bs){
    			abmin=min(dist(ax[i],ay[i],bx[j],by[j]),abmin);
    		}


    	}
    	double acmin=INT_MAX;
    	FOR(i,0,as){
    		FOR(j,0,cs){
    			acmin=min(dist(ax[i],ay[i],cx[j],cy[j]),acmin);
    		}

    	}
    	double bcmin=INT_MAX;
    	FOR(i,0,bs){
    		FOR(j,0,cs){
    			bcmin=min(dist(bx[i],by[i],cx[j],cy[j]),bcmin);
    		}

    	}
    	double arr[3];
    	arr[0]=acmin;
    	arr[1]=bcmin;
    	arr[2]=abmin;
    	SORTA(arr);
    	return arr[0]+arr[1];
     }
};

void solveQues(){
		
	return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vi ax,
	
	solveQues();


	 
return 0;
}