#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	char c;
	cin>>c;
	if(isupper(c)){
		cout<<"U";

	}
	else if(islower(c))
		cout<<"L";
	else cout<<'I';
return 0;
}