// C++ program to answer queries to count number 
// of elements smaller tban or equal to x. 

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




// structure to hold queries 
struct Query 
{ 
	int l, r, x, idx; 
}; 

// structure to hold array 
struct ArrayElement 
{ 
	int val, idx; 
}; 

// bool function to sort queries according to k 
bool cmp1(Query q1, Query q2) 
{ 
	return q1.x < q2.x; 
} 

// bool function to sort array according to its value 
bool cmp2(ArrayElement x, ArrayElement y) 
{ 
	return x.val < y.val; 
} 

// updating the bit array 
void update(int bit[], int idx, int val, int n) 
{ 
	for (; idx<=n; idx +=idx&-idx) 
		bit[idx] += val; 
} 

// querying the bit array 
int query(int bit[], int idx, int n) 
{ 
	int sum = 0; 
	for (; idx > 0; idx -= idx&-idx) 
		sum += bit[idx]; 
	return sum; 
} 

void answerQueries(int n, Query queries[], int q, 
							ArrayElement arr[]) 
{ 
	// initialising bit array 
	int bit[n+1]; 
	memset(bit, 0, sizeof(bit)); 

	// sorting the array 
	sort(arr, arr+n, cmp2); 

	// sorting queries 
	sort(queries, queries+q, cmp1); 

	// current index of array 
	int curr = 0; 

	// array to hold answer of each Query 
	int ans[q]; 

	// looping through each Query 
	for (int i=0; i<q; i++) 
	{ 
		// traversing the array values till it 
		// is less than equal to Query number 
		while (arr[curr].val <= queries[i].x && curr<n) 
		{ 
			// updating the bit array for the array index 
			update(bit, arr[curr].idx+1, 1, n); 
			curr++; 
		} 

		// Answer for each Query will be number of 
		// values less than equal to x upto r minus 
		// number of values less than equal to x 
		// upto l-1 
		ans[queries[i].idx] = query(bit, queries[i].r+1, n) - 
							query(bit, queries[i].l, n); 
	} 

	// printing answer for each Query 
    deb(q)

	for (int i=0 ; i<q; i++) 
		cout << ans[i] << endl; 
} 

// driver function 
int main() 
{ 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// size of array 
	// int t;
	// cin>>t;
	// TC(t){
	// 	int n;
	// 	cin>>n;
	// 	int q=n-1;
	// 	Query queries[q]; 

	// 	ArrayElement arr[n];
	// 	for(int i=0;i<n;i++){
	// 		cin>>arr[i].val;
	// 		arr[i].idx=i;
	// 		queries[i].l=0;
	// 		if(i!=0){
	// 		queries[i].r=i-1;
	// 		queries[i].x=arr[i].val;
	// 		queries[i].idx=i-1;
	// 	}
	// 	}
	// answerQueries(n, queries, q, arr); 


	// }
	int n = 4; 
  
    // initialising array value and index 
    ArrayElement arr[n]; 
    arr[0].val = 1; 
    arr[0].idx = 0; 
    arr[1].val = 5; 
    arr[1].idx = 1; 
    arr[2].val = 3; 
    arr[2].idx = 2; 
    arr[3].val = 5; 
    arr[3].idx = 3; 
  
    // number of queries 
    int q = 3; 
    Query queries[q]; 
    queries[0].l = 0; 
    queries[0].r = 0; 
    queries[0].x = 5; 
    queries[0].idx = 0; 
    queries[1].l = 0; 
    queries[1].r = 1; 
    queries[1].x = 3; 
    queries[1].idx = 1; 
    queries[2].l = 0; 
    queries[2].r = 2; 
    queries[2].x = 5; 
    queries[2].idx = 2; 
  	
    answerQueries(n, queries, q, arr); 
  
    // return 0; 

	

	return 0; 
} 
