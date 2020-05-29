#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int mindist(int ci[], int n){
	int eaten=0;
	sort(ci,ci+n);
	int cal=0;
	int curr;
	for(int j=0;j<n;j++){
		int min=INT_MAX;
	for(int i=0;i<n;i++){
		curr=pow(2,eaten)*ci[i];
		if(curr<min){
			min=curr;
			ci[i]=INT_MAX;

		}

	}
	deb(min)
	eaten++;
	cal+=min;
	}
return cal;}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int ci[n];
	for(int i=0;i<n;i++){
		cin>>ci[i];
	}
	cout<<mindist(ci,n);

return 0;
}