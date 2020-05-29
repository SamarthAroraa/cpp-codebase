#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

string checker(string inp){
	string out="";
	int l = inp.length();
	for(int i=0;i<l;i++){
		out+=inp[i];
		int cnt=1;
		while(inp[i]==inp[i+1]){
			i++;
			cnt++;
		}
		out+=to_string(cnt);

	}
	deb(inp)
	deb(out)
if(out.length()<inp.length())
return "YES";
else 
return "NO";
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
int t;
cin>>t;
while(t--){


string a;
cin>>a;
cout<<checker(a)<<endl;
}return 0;
}