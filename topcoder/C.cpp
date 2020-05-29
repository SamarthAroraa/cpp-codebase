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

class ValueDivision{
    public:
     vector <int> getArray(vector <int> arr){
     int n= arr.size();
   	unordered_map<int, int > freq;

     for (int i=0;i<n;i++){
     freq[arr[i]]++;
     }

	
	bool k=1;
	while(k==1){
		k=0;
	for(int i=0;i<n;i++){
		if(arr[i]==1 or freq[arr[i]]==1){
			continue;
		}
		else{
			k=1;
			int repval= arr[i];
			// arr[i]=arr[i]-1;
			// freq[repval]--;
			// if(freq[repval]==1){
			// 	continue;
			// }
			// freq[arr[i]]++;

			for(int j=0;j<n;j++){
				if(arr[j]==repval){
					arr[j]--;
					freq[arr[j]]++;
					freq[repval]--;
					if(freq[repval]==1){
						break;
				}
				}
			}
		}
	}
}
std::vector<int> v(arr);
 return v;
     }
    
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vi arr(n);
	// unordered_map<int, int > freq;

	for(int i=0;i<n;i++){
		cin>>arr[i];
		// freq[arr[i]]++;

	}
	ValueDivision c;
	vi v=c.getArray(arr);
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}

	 
return 0;
}

