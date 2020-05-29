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

// C++ implementation of SPFA 

#include <bits/stdc++.h> 
using namespace std; 

// Graph is stored as vector of vector of pairs 
// first element of pair store vertex 
// second element of pair store weight 
vector<pair<int, int> > graph[100000]; 

// Function to add edges in the graph 
// connecting a pair of vertex(frm) and weight 
// to another vertex(to) in graph 
void addEdge(int frm, int to, int weight) 
{ 

	graph[frm].push_back({ to, weight }); 
} 

// Function to print shortest distance from source 
void print_distance(int d[], int V) 
{ 
	cout << "Vertex \t\t Distance"
		<< " from source" << endl; 

	for (int i = 1; i <= V; i++) { 
		printf("%d \t\t %d\n", i, d[i]); 
	} 
} 

// Function to compute the SPF algorithm 
void shortestPathFaster(int S, int V) 
{ 
	// Create array d to store shortest distance 
	int d[V + 1]; 

	// Boolean array to check if vertex 
	// is present in queue or not 
	std::vector<bool>inQueue(V + 1,false) ; 

	// Initialize the distance from source to 
	// other vertex as INT_MAX(infinite) 
	for (int i = 0; i <= V; i++) { 
		d[i] = INT_MAX; 
	} 
	d[S] = 0; 

	queue<int> q; 
	q.push(S); 
	inQueue[S] = true; 

	while (!q.empty()) { 

		// Take the front vertex from Queue 
		int u = q.front(); 
		q.pop(); 
		inQueue[u] = false; 

		// Relaxing all the adjacent edges of 
		// vertex taken from the Queue 
		for (int i = 0; i < graph[u].size(); i++) { 

			int v = graph[u][i].first; 
			int weight = graph[u][i].second; 

			if (d[v] > d[u] + weight) { 
				d[v] = d[u] + weight; 

				// Check if vertex v is in Queue or not 
				// if not then push it into the Queue 
				if (!inQueue[v]) { 
					q.push(v); 
					inQueue[v] = true; 
				} 
			} 
		} 
	} 

	// Print the result 
	print_distance(d, V); 
} 

// Driver code 
int main() 
{ 
	// int V = 5; 
	// int S = 1; 

	// Connect vertex a to b with weight w 
	// addEdge(a, b, w) 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	// int t;
	// cin>>t;
	// while(t--){
		int n,k;
		cin>>n>>k;
		string a,b;
		cin>>a>>b;
		FORN(i,1,k){
			FORN(j,1,k){
				int w;
				cin>>w;
				addEdge(i, j, w); 
				addEdge(j, i, w); 



			}
		}
	for(int i=0;i<n;i++){
	 		int index1= a[i]-'a'+1;
	 		deb(index1)

	 		int index2=b[i]-'a'+1;
	 		deb(index2)
			shortestPathFaster(index2,k);shortestPathFaster(index1,k);
		}
	// Calling shortestPathFaster function 
	// shortestPathFaster(, ); 
// }
	return 0; 
} 

// int main(){
	
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
	



	 
// return 0;
// }