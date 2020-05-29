#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void ans(string path){
	int x=0,y=0;
	int i=0;
	if(path[i]=='L'){
			x--;
		}
		else if(path[i]=='R'){
			x++;
		}
		else if(path[i]=='U'){
			y++;
		}
		else if(path[i]=='D'){
			y--;
		}
		

	for(i=1;i<path.length();i++){
		// if(path[i]==path[i-1])
		// 	continue;
		if(path[i]=='L' and (path[i-1]!='R' and path[i-1]!='L')){
			x--;
		}
		if(path[i]=='R'  and (path[i-1]!='R' and path[i-1]!='L')){
			x++;
		}
		if(path[i]=='U'  and (path[i-1]!='D' and path[i-1]!='U')){
			y++;
		}
		if(path[i]=='D'  and (path[i-1]!='U' and path[i-1]!='D')){
			y--;

		}
		
	}
	cout<<x<<" "<<y<<endl;
	
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
		string s;
		cin>>s;
		ans(s);
	}

return 0;
}