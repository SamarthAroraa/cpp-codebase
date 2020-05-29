#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define mod 1000000007
#define SORTV(a) sort(a.begin(),a.end())
#define eb emplace_back
#define SORTA(a,n) sort(a,a+n)
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
#define INF (int)1e9
#define EPS 1e-9
#define bitcount  __builtin_popcount
#define fill(a,v) memset(a, v, sizeof a)
#define checkbit(n,b) ( (n >> b) & 1)
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int ddx[] = {1,0,-1,0,1,-1,-1,1};
int ddy[] = {0,1,0,-1,1,-1,1,-1};
#define MAXV(v) *max_element(v.begin(),v.end())
#define MINV(v) *min_element(v.begin(),v.end())
#define MAXA(a,n) *max_element(a,a+n)
#define MINA(a,n) *min_element(a,a+n)
#define REV(v) reverse(v.begin(),v.end())
#define SUM(v) accumulate(v.begin(),v.end(),0)
#define gcd __gcd
#define TC(t) while (t--)
int s[200000]; 

void sieveOfEratosthenes(int N) 
{ 
    // Create a boolean array "prime[0..n]" and 
    // initialize all entries in it as false. 
    vector <bool> prime(N+1, false); 
  
    // Initializing smallest factor equal to 2 
    // for all the even numbers 
    for (int i=2; i<=N; i+=2) 
        s[i] = 2; 
  
    // For odd numbers less then equal to n 
    for (int i=3; i<=N; i+=2) 
    { 
        if (prime[i] == false) 
        { 
            // s(i) for a prime is the number itself 
            s[i] = i; 
  
            // For all multiples of current prime number 
            for (int j=i; j*i<=N; j+=2) 
            { 
                if (prime[i*j] == false) 
                { 
                    prime[i*j] = true; 
  
                    // i is the smallest prime factor for 
                    // number "i*j". 
                    s[i*j] = i; 
                } 
            } 
        } 
    } 
} 
  
// Function to generate prime factors and its power 
void generatePrimeFactors(int N,unordered_map<int,std::vector<int>> & primep) 
{ 
    // s[i] is going to store smallest prime factor 
    // of i. 
  
    // Filling values in s[] using sieve 
    sieveOfEratosthenes(N); 
  
    // printf("Factor Power\n"); 
  
    int curr = s[N];  // Current prime factor of N 
    int cnt = 1;   // Power of current prime factor 
  
    // Printing prime factors and their powers 
    while (N > 1) 
    { 
        N /= s[N]; 
  
        // N is now N/s[N].  If new N als has smallest 
        // prime factor as curr, increment power 
        if (curr == s[N]) 
        { 
            cnt++; 
            continue; 
        } 
  		primep[curr].pb(cnt);
        // printf("%d\t%d\n", curr, cnt); 
  
        // Update current prime factor as s[N] and 
        // initializing count as 1. 
        curr = s[N]; 
        cnt = 1; 
    } 
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
		int arr[n];
		FOR(i,0,n)cin>>arr[i];

		unordered_map<int,std::vector<int> > primep;
		FOR(i,0,n){
			generatePrimeFactors(arr[i],primep);
		}
		int ans=1;
		FOREACH(i, primep){
			if(i.se.size()>=n-1){
			SORTV(primep[i.first]);
			if(i.se.size()==n)
			ans= ans * pow(i.fi,max(i.se[0],i.se[1]));
		else
			ans=ans * pow(i.fi,i.se[0]);
		}
			// cout<<endl;
		}
		cout<<ans<<"\n";

	// }


	 
return 0;
}