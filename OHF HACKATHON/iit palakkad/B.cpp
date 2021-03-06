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
int print_distance(int d[], int V,int index2) 
{ 
	
	return d[index2];
} 

// Function to compute the SPF algorithm 
int shortestPathFaster(int S, int V,int index2) 
{ 
	// Create array d to store shortest distance 
	int d[V + 1]; 

	// Boolean array to check if vertex 
	// is present in queue or not 
	std::vector<bool> inQueue(V+1,0); 

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
	         
	        return print_distance(d, V,index2);  
} 

// Driver code 
// int main() 
// { 
// 	int V = 5; 
// 	int S = 1; 

// 	// Connect vertex a to b with weight w 
// 	// addEdge(a, b, w) 

// 	addEdge(1, 2, 1); 
// 	addEdge(2, 3, 7); 
// 	addEdge(2, 4, -2); 
// 	addEdge(1, 3, 8); 
// 	addEdge(1, 4, 9); 
// 	addEdge(3, 4, 3); 
// 	addEdge(2, 5, 3); 
// 	addEdge(4, 5, -3); 

// 	// Calling shortestPathFaster function 
// 	shortestPathFaster(S, V); 

// 	return 0; 
// } 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
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
		int cost=0;
		for(int i=0;i<n;i++){
	 		int index1= a[i]-'a'+1;
	 		int index2=b[i]-'a'+1;
			cost+=min(shortestPathFaster(index2,k,index1), shortestPathFaster(index1,k,index2));
		}
		cout<<cost<<endl;
	
	



	 
return 0;
}