#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int ans(string str)

{
	int sum=0;
	int l= str.length();
	for(int i=0;i<l;i++){
		char c= str[i];
		int num= c- '0';
		cerr<<num;
		sum+=num;


	}
return sum;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		cout<<ans(str)<<endl;

	}

return 0;
}