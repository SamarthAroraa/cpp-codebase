#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void solve(int n){
	std::vector<std::vector<int> > list;
	int temp=n;
	while(temp--){
	int k;
	cin>>k;
	std::vector<int> ithd(k);
	for(int i=0;i<k;i++){
		int e;
		cin>>e;
		ithd[i]= e-1;
	}
	list.push_back(ithd);
}
	int unwedd=-1;

	std::vector<bool> princes(n,0);

	for(int i=0;i<n;i++){
		bool flag=0;
		for(int j=0;j<list[i].size();j++){
			int curr= list[i][j];
			if(!princes[curr]){
				// cerr<<"1\n";
				
				princes[curr]=1;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			unwedd=i;
		}
	}
// 		if(!flag)
// 		{
// 			int k;
// 			for(k=0;k<n;k++){
// 				if(princes[k]==0)
// 					break;
// 			}
			
// 			cout<<"IMPROVE\n";
// 			cout<<(i+1)<<" "<<k+1<<endl;
// 			return;
// 		}
// 	}
// list.clear();
// cout<<"OPTIMAL\n";
	int unwedp=-1;
	for(int i=0;i<n;i++){
		if(princes[i]==0){
			unwedp=i;
		}

	}
	if(unwedd!=-1 and unwedp!=-1){
		cout<<"IMPROVE\n";
		cout<<unwedd+1<< " "<<unwedp+1<<"\n";
	}
	else{
		cout<<"OPTIMAL\n";
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve(n);
	}
return 0;
}