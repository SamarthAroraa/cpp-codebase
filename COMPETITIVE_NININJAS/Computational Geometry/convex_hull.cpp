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
#define se second 
#define mp make_pair 
#define pb push_back 
#define TC(t) while (t--)
bool toChange(vii points, int p, int q, int r){
	int x1=points[q].fi-points[p].fi;
	int y1=points[q].se-points[p].se;
	int x2=points[r].fi-points[q].fi;
	int y2=points[r].se-points[q].se;
	int cross= x1*y2-x2*y1;
	return cross<0;
}

void hull(vii points, int n){
	vii hull;
	int l=0;
	FOR(i,1,n){
		if(points[l].fi>points[i].fi){
			l=i;
		}
	}
	int p=l;
	deb(l)
	do{
		hull.pb(points[p]);
		int q=(p+1)%n;
		for(int i=0;i<n;i++){
			if(toChange(points, p,q,i)){
				q=i;
			}
		}

	p=q;
	}while(p!=l);

REP(i, hull.size()){
	cout<<hull[i].fi<<" "<<hull[i].se<<"\n";
}

}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin>>n;
	vl x,y;
	REP(i,n){
		int e;
		cin>>e;
		x.pb(e);
	}
	REP(i,n){
		int e;
		cin>>e;
		y.pb(e);
	}
	vii points;
	REP(i,n){
		points.pb(mp(x[i],y[i]));

	}
	hull(points,n);
	// sort(x.begin(),x.end());
	



	 
return 0;
}