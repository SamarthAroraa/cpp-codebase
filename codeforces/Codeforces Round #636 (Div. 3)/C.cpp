// C++ program to find the 
// length of longest alternate 
// subsequence 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 

typedef vector<int> vi; 


#define pb push_back 
#define TC(t) while (t--)



// LAS[i][pos] array to find 
// the length of LAS till 
// index i by including or 
// excluding element arr[i] 
// on the basis of value of pos 

ll solve(ll arr[], ll n, ll i, bool pos,ll LAS[200001][2]) 
{ 
	// Base Case 
	if (i == n) 
		return 0; 

	if (LAS[i][pos]) 
		return LAS[i][pos]; 

	ll inc = 0, exc = 0; 

	// If current element is 
	// positive and pos is true 
	// Include the current element 
	// and change pos to false 
	if (arr[i] > 0 && pos == true) { 
		pos = false; 

		// Recurr for the next 
		// iteration 
		inc = 1 + solve(arr, n, i + 1, pos,LAS); 
	} 

	// If current element is 
	// negative and pos is false 
	// Include the current element 
	// and change pos to true 
	else if (arr[i] < 0 && pos == false) { 
		pos = true; 

		// Recurr for the next 
		// iteration 
		inc = 1 + solve(arr, n, i + 1, pos,LAS); 
	} 

	// If current element is 
	// excluded, reccur for 
	// next iteration 
	exc = solve(arr, n, i + 1, pos,LAS); 

	LAS[i][pos] = max(inc, exc); 

	return LAS[i][pos]; 
} 
ll maxSum(vi arr, ll n, ll k) 
{ 
    // k must be greater 
    if (n < k) 
    { 
       cout << "Invalid"; 
       return -1; 
    } 
  
    // Compute sum of first window of size k 
    ll res = 0; 
    for (ll i=0; i<k; i++) 
       res += arr[i]; 
  
    // Compute sums of remaining windows by 
    // removing first element of previous 
    // window and adding last element of  
    // current window. 
    ll curr_sum = res; 
    for (ll i=k; i<n; i++) 
    { 
       curr_sum += arr[i] - arr[i-k]; 
       res = max(res, curr_sum); 
    } 
  
    return res; 
} 

	
	



	 

// Driver's Code 
int main() 
{ 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){ 

		ll n;
		ll LAS[200001][2] = { false }; 

		cin>>n;
		ll arr[n];
		// ll arr3[n];
		int size=0;

		vi arr2;
		int prev=0;
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			if(prev==0){
				arr2.pb(arr[i]);
				prev=arr[i];
			}
			else{
				if(prev*arr[i]>0){
					if(prev<arr[i])
					{
						arr2.pop_back();
						arr2.pb(arr[i]);
						prev=arr[i];
					}
				}
				else if(prev*arr[i]<0){
					arr2.pb(arr[i]);
					prev=arr[i];
				}
			}

		}

	 
			ll k= max(solve(arr, n, 0, 0,LAS), 
				solve(arr, n, 0, 1,LAS)); 
		// ll size=0;


		
		// cout<<endl;
		cout<<maxSum(arr2,arr2.size(), k)<<"\n";

		
		

}
}

// #include<bits/stdc++.h>
// using namespace std;

// #define deb(x) cerr<<#x<<" "<<x<<endl;
// typedef long long ll; 
// typedef pair<int, int> pii; 
// typedef pair<ll, ll> pll; 
// typedef pair<string, string> pss; 
// typedef vector<int> vi; 
// typedef vector<vi> vvi; 
// typedef vector<pii> vii; 
// typedef vector<ll> vl; 
// typedef vector<vl> vvl; 
// #define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
// #define REP(i, n) FOR(i, 0, n) 
// #define REPN(i, n) FORN(i, 1, n)
// #define FOREACH(a, b) for (auto&(a) : (b)) 
// #define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
// #define RESET(a, b) memset(a, b, sizeof(a)) 
// #define fi first 
// #define bitcount __builtin_popcount
// #define gcd __gcd
// #define se second 
// #define mp make_pair 
// #define pb push_back 
// #define TC(t) while (t--)


// ll main(){
	
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
	



	 
// return 0;
// }