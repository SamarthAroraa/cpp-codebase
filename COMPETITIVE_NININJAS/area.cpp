// C++ program to evaluate area of a polygon using 
// shoelace formula 
#include<bits/stdc++.h>
#include<string>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;


	


// (X[i], Y[i]) are coordinates of i'th point. 
double polygonArea(vector<int> X, std::vector<int> Y, int n) 
{ 
	
	double area = 0.0; 
 // int X,Y;
	// Calculate value of shoelace formula 
	int j = n - 1; 
	for (int i = 0; i < n; i++) 
	{ 
		area += (X[j] + X[i]) * (Y[j] - Y[i]); 
		j = i; // j is previous vertex to i 
	} 

	// Return absolute value 
	return abs(area / 2.0); 
} 

// Driver program to test above function 
int main() 
{ 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	// std::vector< pair<int,int> >  coordinates;
	std::vector<int> X;
	std::vector<int> Y;
	int x=0,y=0;
	int n= strlen(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='R')
			x++;
		else if(s[i]=='L')
			x--;
		else if(s[i]=='U')
			y++;
		else if(s[i]=='D')
			y--;
	// coordinates.push(make_pair(x,y));
		X.push_back(x);
		Y.push_back(y);
	}
	

	// int n = strlen(s);

	cout << polygonArea(X,Y, n);
	} 
return 0;
} 
