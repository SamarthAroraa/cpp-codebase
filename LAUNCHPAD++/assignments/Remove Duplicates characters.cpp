#include<bits/stdc++.h>
using namespace std;
string duplicate(string a){
	if(a.length()==0){
		return "";
	}

	string res=duplicate(a.substr(1));
	if(a[0]==res[0]){
		return res;
	}
	 res=a[0]+res;
return res;}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	// cout<<duplicate("hello");
	string inp;
	cin>>inp;
	cout<<duplicate(inp);

return 0;
}