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
ll CountPS(string str, ll n) 
{ 
    // create empty 2-D matrix that counts all palindrome 
    // substring. dp[i][j] stores counts of palindromic 
    // substrings in st[i..j] 
    ll dp[n][n]; 
    memset(dp, 0, sizeof(dp)); 
  
    // P[i][j] = true if substring str[i..j] is palindrome, 
    // else false 
    bool P[n][n]; 
    memset(P, false , sizeof(P)); 
  
    // palindrome of single length 
    for (ll i= 0; i< n; i++) 
        P[i][i] = true; 
  
    // palindrome of length 2 
    for (ll i=0; i<n-1; i++) 
    { 
        if (str[i] == str[i+1]) 
        { 
            P[i][i+1] = true; 
            dp[i][i+1] = 1 ; 
        } 
    } 
  
    // Palindromes of length more than 2. This loop is similar 
    // to Matrix Chain Multiplication. We start with a gap of 
    // length 2 and fill the DP table in a way that gap between 
    // starting and ending indexes increases one by one by 
    // outer loop. 
    for (ll gap=2 ; gap<n; gap++) 
    { 
        // Pick starting poll for current gap 
        for (ll i=0; i<n-gap; i++) 
        { 
            // Set ending poll 
            ll j = gap + i; 
  
            // If current string is palindrome 
            if (str[i] == str[j] && P[i+1][j-1] ) 
                P[i][j] = true; 
  
            // Add current palindrome substring ( + 1) 
            // and rest palindrome substring (dp[i][j-1] + dp[i+1][j]) 
            // remove common palindrome substrings (- dp[i+1][j-1]) 
            if (P[i][j] == true) 
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1 - dp[i+1][j-1]; 
            else
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]; 
        } 
    } 
  
    // return total palindromic substrings 
    return dp[0][n-1]; 
} 
  
 ll countPalindromes(string s) 
{ 
    unordered_map<string, ll> m; 
    for (ll i = 0; i < s.length(); i++) { 
  
        // check for odd length palindromes 
        for (ll j = 0; j <= i; j++) { 
  
            if (!s[i + j]) 
                break; 
  
            if (s[i - j] == s[i + j]) { 
  
                // check for palindromes of length 
                // greater than 1 
                if ((i + j + 1) - (i - j) > 1) 
                    m[s.substr(i - j,  
                        (i + j + 1) - (i - j))]++; 
  
            } else
                break; 
        } 
  
        // check for even length palindromes 
        for (ll j = 0; j <= i; j++) { 
            if (!s[i + j + 1]) 
                break; 
            if (s[i - j] == s[i + j + 1]) { 
  
                // check for palindromes of length  
                // greater than 1 
                if ((i + j + 2) - (i - j) > 1) 
                    m[s.substr(i - j,  
                         (i + j + 2) - (i - j))]++; 
  
            } else
                break; 
        } 
    } 
    return m.size(); 
} 

  
bool allsame(string s){
	for(ll i=0;i<s.length()-1;i++){
		if(s[i]!=s[1+i])
			return  0;
	}
	return  1;

}
 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	// cout<<distinctSubstring(s)<<endl;
	// if(allsame(s))
	// 	cout<<"1\n";
	// else
	// {
		// cout<<ans(s)<<endl;
		
		ll n= s.length();
		ll ncr= n*(n-1)/2;
		deb(ncr)
		deb(CountPS(s,n))
		cout<<(ncr+1-CountPS(s,n))<<"\n";
	// }	



	 
return 0;
}