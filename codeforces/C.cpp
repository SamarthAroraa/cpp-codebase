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
#define PI 3.141592653589793238462

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

double apothemLength(int n, float a){
   
   	double r1=(2.0*tan((180.0/n)*PI/180.0));
   	deb(r1)
     return (double)(a/r1);
}
float polyapothem(float n, float a) 
{ 
  
    // Side and side length cannot be negative 
    if (a < 0 && n < 0) 
        return -1; 
  
    // Degree converted to radians 
    return a / (2 * tan((180 / n) * 3.14159 / 180)); 
} 

float polydiagonal(float n, float a) 
{ 
  
    // Side and side length cannot be negative 
    if (a < 0 && n < 0) 
        return -1; 
  
    // diagonal 
    // degree converted to radians 
    return 2 * a * sin((((n - 2) * 180) / (2 * n)) * 3.14159 / 180); 
} 
void solveQues(){
	int t;
	cin>>t;
	TC(t){
		int n;
		cin>>n;
		// double n2=n*n;

		// double apo= polyapothem(2.0*n,1);
		// // deb(2*apo)
		// double smdeg=(double)90.0/(n);
		// deb(apo)
		// double smallval=cos(smdeg*PI/180.0);
		// double ans= apo*2*cos(PI/(2*n));
		// ans=ans*2.0;
		// cout<<setprecision(10)<<ans<<endl;
		double()
		// cout<<polydiagonal(6,1);
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