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
#define MAXN 2000001
int spdarr[MAXN];
void spd(){	
	spdarr[0]=1;
	spdarr[1]=1;
	FOR(i,1,MAXN){
		spdarr[i]=i;
	}
	for(int i=2;i*i<=MAXN;i++){
		if(spdarr[i]==i){
		for(int j=i*2;j<=MAXN;j+=i){
			if(spdarr[j]==j){
			spdarr[j]=i;
		}
		}
	}
	}

}
int get_smallestd(int n){
	
	return spdarr[n];
}


void solve(int n){
	unordered_map<int, bool > visited;
	int i=n;
	while(i>=1){
		if(visited[i]==0){
			visited[i]=1;
			vi itharray;
			int smallest= get_smallestd(i);
			itharray.pb(i);
			int temp=i-smallest;
			int temp2=i;

			while(smallest>1){
			temp=i-smallest;
			while(temp>0){
				// visited[temp]=1;
				if(visited[temp]==0){
				itharray.pb(temp);
				visited[temp]=1;
				}
				temp-=smallest;
			}
			// temp=i;
			while(temp2%smallest==0){
				
				temp2=temp2/smallest;
				// deb(temp2)
			// deb(smallest)


			}
			smallest= temp2;
			// deb(i)

			
		}
		sort(itharray.begin(), itharray.end(),greater<int>());
		FOREACH(k, itharray){
			cout<<k<< " ";
		}

	}
		
		i--;
	}
// cout<<1<<"\n";
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	spd();
	cin>>n;
	solve(n);



	 
return 0;
}