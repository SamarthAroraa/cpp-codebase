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
ll pow(ll a, ll b, ll c){
	if(b==0)
		return  1;

		ll val=pow(a,b/2,c);
		ll ans= (val*val)%c;
		if(b%2!=0){
			ans =( ans* (a%c))%c;
		}
		return ((ans+c)%c);

}
int comp(const void* a, const void* b) 
{ 
    return *(int*)a > *(int*)b; 
} 
  
// Function to count all possible triangles with arr[] 
// elements 
int findNumberOfTriangles(int arr[], int n) 
{ 
    // Sort the array elements in non-decreasing order 
    qsort(arr, n, sizeof(arr[0]), comp); 
  
    // Initialize count of triangles 
    int count = 0; 
  
    // Fix the first element. We need to run till n-3 
    // as the other two elements are selected from 
    // arr[i+1...n-1] 
    for (int i = 0; i < n - 2; ++i) { 
        // Initialize index of the rightmost third 
        // element 
        int k = i + 2; 
  
        // Fix the second element 
        for (int j = i + 1; j < n; ++j) { 
            // Find the rightmost element which is 
            // smaller than the sum of two fixed elements 
            // The important thing to note here is, we 
            // use the previous value of k. If value of 
            // arr[i] + arr[j-1] was greater than arr[k], 
            // then arr[i] + arr[j] must be greater than k, 
            // because the array is sorted. 
            while (k < n && arr[i] + arr[j] > arr[k]) 
                ++k; 
  
            // Total number of possible triangles that can 
            // be formed with the two fixed elements is 
            // k - j - 1. The two fixed elements are arr[i] 
            // and arr[j]. All elements between arr[j+1]/ to 
            // arr[k-1] can form a triangle with arr[i] and arr[j]. 
            // One is subtracted from k because k is incremented 
            // one extra in above while loop. 
            // k will always be greater than j. If j becomes equal 
            // to k, then above loop will increment k, because arr[k] 
            // + arr[i] is always greater than arr[k] 
            if (k > j) 
                count += k - j - 1; 
        } 
    } 
  
    return count; 
} 
#define int long long


void solveQues(){
	// int arr[]={1,2,2,3,3,4};
	// cout<<findNumberOfTriangles(arr,6);

	int a , b , c , d ;
	int ans = 0 ;
	cin>>a>>b>>c>>d;
	for(int i = max(a + b , c) ; i <= c+d ; i++)
ans += min(i-c,d-c+1) * (i-a-b+1 - max(0ll,i-b-b) - max(0ll,i-a-c) + max(0ll,i-b-c-1));
cout <<ans<<"\n";
	return;
}

 



signed main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solveQues();


	 
return 0;
}