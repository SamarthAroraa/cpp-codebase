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
class entry{
public:
	int dist;
	pi city;
	int index;
};

bool compx(pair<int,int> p1, pair<int,int> p2){
	return p1.fi<p2.fi;
}
bool compy(pair<int,int> p1, pair<int,int> p2){
	return p1.se<p2.se;
}

bool operator > (const entry& lhs, const entry& rhs)
{
    return lhs.dist > rhs.dist;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	unordered_map<pii,i> indexy;
	unordered_map<pii,i> indexx;
	vii cities;
	bool done[n];
	vii citiesx;
	vii citiesy;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x,y;
		cities.pb({x,y});
		citiesy.pb({x,y});
		citiesx.pb({x,y});
	}
	sort(citiesy,citiesy+n, compy);
	sort(citiesx,citiesx+n, compx);
	for(int i=0;i<n;i++){
		indexx[citiesx]=i;
		indexy[citiesy]=i;
	}

	done[0]=1;
	priority_queue<entry> q;
	ll ans=0;
	q.push(cities[0]);
	while(!q.empty()){
		entry include=q.top();
		q.pop();
		if(done[])

	}


		
	



	 
return 0;
}