#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;



bool isbeaut(long long num,unordered_map<long long,bool> &forest){

	if(forest.count(num+1) or forest.count(num-1)){
		return 1;
	}
	return 0;
}
void display(unordered_map<long long,bool> forest){
	for(auto tree:forest){
		cout<<tree.first<<" "<<tree.second<<endl;
	}

}
long long ansfunct(unordered_map<long long,bool> &forest){
	long long count=0;
	for(auto tree:forest){
		if(!isbeaut(tree.first,forest)){
			forest[tree.first+1]=1;
			count++;


		}

	}
	display(forest);
return count;
}


int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		unordered_map<long long,bool> forest;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			long long tp;
			cin>>tp;
			forest[tp]=1;
		}

	cout<<ansfunct(forest)<<endl;
	}
	return 0;
}