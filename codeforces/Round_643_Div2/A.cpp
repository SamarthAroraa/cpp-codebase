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
bool check(ll n)
{
    while(n!=0)
    {
        if(n%10==0)
        {
            return 1;
        }
        n/=10;
    }
    return 0;
}

void solveQues(){
	
	ll t;
	cin>>t;
	TC(t){
		ll n,k;
		ll ans=0;
        // flag=true;

		cin>>n>>k;
		std::vector<ll> v;
		 ans=n;
		while(true){
			v.pb(ans);
			if(check(ans)){
break;
			}
		ll count=ans;
        ll mx=INT_MIN;
        ll mn=INT_MAX;
 
            while(count!=0)
            {
             mn=min(mn,count%10);
             mx=max(mx,count%10);
           count=count/10;
            }
            ans+=(mn*mx);
        }
        if(k>=v.size())
        {
            cout<<v[v.size()-1]<<endl;
        }
        else
        cout<<v[k-1]<<endl;
    }

				// string s;
	
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



