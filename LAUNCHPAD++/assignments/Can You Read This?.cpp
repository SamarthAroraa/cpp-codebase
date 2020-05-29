#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	#endif
 int i=0;
	string inp;
	cin>>inp;
	for(char c:inp)
	{
		if(isupper(c) and i!=0)
			cout<<endl;
		i++;
		cout<<c;

	}
	return 0;
}
