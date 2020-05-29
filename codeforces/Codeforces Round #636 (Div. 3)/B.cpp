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
void oddIntegers(int n, int k) 
{ 
    // Condition to check if there 
    // exist such K integers 
    if (n % 2 != k % 2) { 
        cout << "-1"
             << "\n"; 
        return; 
    } 
  
    int sum = 0; 
    int i = 1; 
    int j = 1; 
  
    // Loop to find first K-1 
    // distinct odd integers 
    while (j < k) { 
        sum = sum + i; 
        cout << i << " "; 
        i = i + 2; 
        j++; 
    } 
  
    // Final Kth odd number 
    int finalOdd = n - sum; 
  
    cout << finalOdd << "\n"; 
} 
  


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(((n/2)&1)!=0){
			cout<<"NO\n";
			continue;
		}
		else{
			cout<<"YES\n";
		}
		ll sum=0;
		for(int i=2;i<=n;i+=2){
			sum+=i;
			cout<<i<<" ";
		}
		oddIntegers(sum, n/2);
	}


	 
return 0;
}