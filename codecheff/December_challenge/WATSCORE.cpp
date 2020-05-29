#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

unsigned long total_score(int n){
	unsigned long score=0;
	unordered_map<int,int> prev;
	for(int i=0;i<n;i++)
	{
		int pi,si;
		cin>>pi>>si;
		if(pi>8)
			continue;
		if(prev[pi]>=si){
			continue;
		}
		else{
			prev[pi]=si;
		}
	}
for(int i=1;i<=8;i++){
	score+=prev[i];
}
return score;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<total_score(n)<<endl;
	}

	return 0;


}