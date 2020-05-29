

// An efficient C++ program to 
// count distinct elements in 
// every window of size k 
#include <iostream> 
#include <map> 
using namespace std; 

void countDistinct(string arr[], int k, int n) 
{ 
	// Creates an empty hashmap hm 
	map<string, int> hm; 

	// initialize distinct element count for current window 
	int dist_count = 0; 

	// Traverse the first window and store count 
	// of every element in hash map 
	for (int i = 0; i < k; i++) 
	{ 
	if (hm[arr[i]] == 0) 
	{ 
		dist_count++; 
	} 
	hm[arr[i]] += 1; 
	} 

// Print count of first window 
// cout << dist_count << endl; 
int maxi=max(0,dist_count);
// Traverse through the remaining array 
for (int i = k; i < n; i++) 
{ 
	// Remove first element of previous window 
	// If there was only one occurrence, then reduce distinct count. 
	if (hm[arr[i-k]] == 1) 
	{ 
		dist_count--; 
	} 
// reduce count of the removed element 
	hm[arr[i-k]] -= 1; 

// Add new element of current window 
// If this element appears first time, 
// increment distinct element count 

	if (hm[arr[i]] == 0) 
	{ 
	dist_count++; 
	} 
	hm[arr[i]] += 1; 

// Print count of current window 
	// cout << dist_count << endl; 
	maxi=max(dist_count,maxi);
} 
cout<<maxi<<endl;
} 

int main() 
{ 
	
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		#endif
	

	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	string arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];

	}


// int size =  
// int k = 4; 
countDistinct(arr, k, n); 
}
int a[6] = {1, 2, 3};
cerr << a <<" "<< &a;
return 0; 
} 
//This solution is contributed by Aditya Goel 
