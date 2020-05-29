#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

double cp(pair<int, int> ab, pair<int,int> ac){
	return ab.first*ac.second - ab.second*ac.first;
}
double area(int i, int j, int k, std::vector<int> x, vector<int> y){
	 pair<int, int> ab(x[k]-x[i],y[k]-y[i]);
	 pair<int, int> ac(x[j]-x[i],y[j]-y[i]);
	 return (cp(ab,ac))/2;
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
	std::vector<int> x(n);
	std::vector<int> y(n);
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	for(int i=0;i<n;i++){
		cin>>y[i];
	}
	double ans=0;
	for(int i=1;i<n-1;i++){
		ans+=area(0,i,i+1,x,y);
	}
	cout<<(ll)abs(ans);	 
return 0;
}