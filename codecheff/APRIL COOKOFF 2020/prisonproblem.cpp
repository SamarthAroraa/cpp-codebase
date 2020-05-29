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
#define N 4
int xdir[]={1,-1,0,0};
int ydir[]={0,0,1,-1};
vi path;
bool check(bool cells[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!cells[i][j])
				return 0;
		}
	}
	return 1;
}

bool safe(bool cells[N][N], int si, int sj){
	if(si==3 and sj==0)
		return 1;
	if(si>=N or sj>=N or si<0 or sj<0)
		return 0;
	if(cells[si][sj]==1)
		return 0;
	return 1;
}
bool solve(bool cells[N][N], int di, int dj, int si, int sj){
	int number= si*N + sj+1;
	if(number == 3 or number==12){
	deb(si)
	deb(sj)
}
	path.pb(number);
	if(si==di and sj==dj and check(cells)) {
		cout<<path.size()<<"\n";
		for(int i=0;i<path.size();i++){
			cout<<path[i]<<" ";
		}
		cout<<endl;
		cout<<"*************************\n\n";
		return 1;
	}
	bool res=0;

	for(int i=0;i<4;i++){
		if(safe(cells,si+xdir[i],sj+ydir[i])){
			// if(si+xdir[i]!=3 and sj+ydir[i]!=0){
			cells[si+xdir[i]][sj+ydir[i]]=1;

			res=solve(cells,di,dj,si+xdir[i], sj+ydir[i])|| res;
			cells[si+xdir[i]][sj+ydir[i]]=0;
			path.pop_back();
		// }
		}
	}
// cerr<<"fail"

return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool cells[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cells[i][j]=0;
		}
	}
	int si,sj;
	cin>>si>>sj;
	int di,dj;
	cin>>di>>dj;
	cells[si][sj]=1;
	path.clear();
	// cells[si][sj]=1;
	solve(cells, di,dj, si, sj);

	



	 
return 0;
}