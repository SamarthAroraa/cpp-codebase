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

 double nonDuplicatedAverage(vector <int> prices){
 	unordered_map<int,bool > occ;
 	int sum=0;
 	int items=0;
 	for(int i=0;i<prices.size();i++)
 	{
 		if(occ[prices[i]]==0){
 			sum+=prices[i];
 			occ[prices[i]]=1;
 			items++;
 			deb(prices[i])
 			deb(occ[prices[i]])

 		}
 	}
 	deb(sum)
 	deb(items)
 	return (double)sum/items;
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
vi prices(n);
FOR(i,0,n){
	cin>>prices[i];
}
cout<<nonDuplicatedAverage(prices);


	 
return 0;
}