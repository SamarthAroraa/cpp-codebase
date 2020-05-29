// C++ implementation to count number of ways to 
// tile a floor of size n x m using 1 x m tiles 
#include <bits/stdc++.h> 

using namespace std; 

// function to count the total number of ways 
unsigned long long countWays(unsigned long long n, unsigned long long m) 
{ 

	// table to store values 
	// of subproblems 
	unsigned long long count[n + 1]; 
	count[0] = 0; 

	// Fill the table upto value n 
	for (unsigned long long i = 1; i <= n; i++) { 
		// recurrence relation 
		if (i > m) 
			count[i] = (count[i - 1] + count[i - m])%1000000007; 

		// base cases 
		else if (i < m) 
			count[i] = 1; 

		// i = = m 
		else
			count[i] = 2; 
	} 

	// required number of ways 
	return count[n]%1000000007; 
	cerr<<count[n];
} 

// Driver program to test above 
int main() 
{ 
	#ifndef ONLINE_JUDGE
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	#endif

	unsigned long long t;
	cin>>t;
	while(t--){
	unsigned long long n,m;
	cin>>n>>m;
	cout<< countWays(n, m)<<endl; 
	}
	return 0; 
} 
