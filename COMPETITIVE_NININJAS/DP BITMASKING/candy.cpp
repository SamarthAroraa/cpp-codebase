#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
bool like[17][17];

int ways(int n)
{	std::vector<int> v(1<<n,0);
	v[0]=1;
	for(int mask=0;mask<(1<<n)-1;mask++){
		int k=__builtin_popcount(mask);
		
		deb(v[mask])
		for(int j=0;j<n;j++){
			if((mask&(1<<j))==0 and like[k][j]){
				v[mask | (1<<j)]+=v[mask];
			}
		}
	}
	return v[(1<<n)-1];

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
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		cin>>like[i][j];
	}
	}
	cout<<ways(n);

//code here

	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}