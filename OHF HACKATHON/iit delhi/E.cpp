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
int _lis( int arr[], int n, int *max_ref) 
{ 
    /* Base case */
    if (n == 1) 
        return 1; 
  
    // 'max_ending_here' is length of LIS ending with arr[n-1] 
    int res, max_ending_here = 1;  
  
    /* Recursively get all LIS ending with arr[0], arr[1] ... 
       arr[n-2]. If   arr[i-1] is smaller than arr[n-1], and 
       max ending with arr[n-1] needs to be updated, then 
       update it */
    for (int i = 1; i < n; i++) 
    { 
        res = _lis(arr, i, max_ref); 
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here) 
            max_ending_here = res + 1; 
    } 
  
    // Compare max_ending_here with the overall max. And 
    // update the overall max if needed 
    if (*max_ref < max_ending_here) 
       *max_ref = max_ending_here; 
  
    // Return length of LIS ending with arr[n-1] 
    return max_ending_here; 
} 
  
// The wrapper function for _lis() 
int lis(int arr[], int n) 
{ 
    // The max variable holds the result 
    int max = 1; 
  
    // The function _lis() stores its result in max 
    _lis( arr, n, &max ); 
  
    // returns max 
    return max; 
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
	TC(t){
		int n;
		cin>>n;
		int arr[n];
		set<int  > s;
		unordered_map<int,bool> fi;
		int dc=0;
		FOR(i,0,n){
			cin>>arr[i];
			if(fi[arr[i]]==0){
				dc++;
				fi[arr[i]]=1;
			}

		}
		int lislen=lis(arr,n);
		deb(lislen)
		deb(dc)
		int shortage= dc-lislen;
		cout<<shortage+1<<endl;

			
}


	 
return 0;
}