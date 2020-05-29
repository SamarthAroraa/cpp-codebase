#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int ans(int n){
	std::vector<int> total(n);
	std::vector<int> left;
	for(int i=0;<n;i++){
		total[i]=i+1;
	}
	int groups=0;
	int prod=1;
	for(int i=0;i<total.size();i++){
		if(gcd(prod,total[i])!=1){
			left.push_back(i+1);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t start, end; 
	time(&start);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	}

//code here

	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}