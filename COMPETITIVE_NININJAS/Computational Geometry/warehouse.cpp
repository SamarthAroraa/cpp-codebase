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


double dist(int i , int j , int k, vii points){
	int x1=points[j].fi-points[i].fi;
	int y1=points[j].se-points[i].se;
	int x2=points[k].fi-points[i].fi;
	int y2=points[k].se-points[i].se;
	double dist2=sqrt(x1*x1 + y1*y1);
	int cross= x1*y2- x2*y1;
	if(dist2!=0)
	return abs((double)cross/dist2);
	else{
		return sqrt(pow(points[k].fi-points[i].fi,2) + pow(points[k].se- points[i].se,2));
	}


}
int solve(vii points , int n){
	double maxw=INT_MIN;
	for(int i=0;i<n;i++){
		FOR(j,0,n){
			// if(j==i)
			// 	continue;
			FOR(k,0,n){
				// if(j==k or k==i)
				// 	continue;
				maxw=max(maxw, dist(i,j,k,points));
				deb(dist(i,j,k,points))
				cerr<<points[i].fi<< " " <<points[i].se<<endl;
				cerr<<points[j].fi<< " " <<points[j].se<<endl;
				cerr<<points[k].fi<< " " <<points[k].se<<endl;
			}
		}
	}
	if(floor(maxw)==maxw){
		maxw--;
	}
	else{
		maxw=floor(maxw);
	}

return maxw;
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
	points.pb(mp(0,200));
	points.pb(mp(200,0));
	points.pb(mp(0,0));
	points.pb(mp(200,200));
	cout<<solve(points,n);


return 0;
}