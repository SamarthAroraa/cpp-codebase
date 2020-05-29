#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b){
	return a.second<=b.second;
}
int maxac(std::vector<pair<int,int> > times, int n){
	sort(times.begin(),times.end(), comp);
	int count=1;
	int et=times[0].second;
	for(int i=0;i<n;i++){
		cerr<<times[i].first<<" "<<times[i].second<<endl;
		if(times[i].first>=et){
			count++;
			et= times[i].second;

		}
	}
return count;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
int n;
cin>>n;
std::vector<pair<int,int> > times(n);
for(int i=0;i<n;i++){
	cin>>times[i].first;
	cin>>times[i].second;
	deb(times[i].first)
	deb(times[i].second)
	cerr<<endl;

}
cout<<maxac(times,n)<<endl;
return 0;
}