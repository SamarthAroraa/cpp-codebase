#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

void nswer(std::vector<int> v1, std::vector<int> v2, std::vector<int> v3){
	map<int,int> freq;
	for(int i=0;i<v1.size();i++){
		freq[v1[i]]++;
	}
	for(int i=0;i<v2.size();i++){
		freq[v2[i]]++;
	}
	for(int i=0;i<v3.size();i++){
		freq[v3[i]]++;
	}
	int count=0;
	for(auto n: freq){
		if(n.second>=2){
			count++;
		}
	}
	cout<<count<<endl;
	for(auto n: freq){
		if(n.second>=2){
			cout<<n.first<<endl;
		}
	}

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	std::vector<int> v1(n1);
	std::vector<int> v2(n2);
	std::vector<int> v3(n3);
	for(int i=0;i<n1;i++){
		cin>>v1[i];
	}
	for(int i=0;i<n2;i++){
		cin>>v2[i];
	}
	for(int i=0;i<n3;i++){
		cin>>v3[i];
	}
	nswer(v1,v2,v3);

return 0;
}