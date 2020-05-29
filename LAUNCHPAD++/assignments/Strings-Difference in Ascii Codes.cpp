#include<iostream>
#include<string>
using namespace std;

string insertascii(string inp){
	string ans=inp.substr(0,1);
	for(int i=0;i<inp.length()-1;i++)
	{
		int diff= inp[i+1]-inp[i];
		ans= ans+ to_string(diff)+inp[i+1];

	}
return ans;
}
int main()
{
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string inp="";
	cin>>inp;
		cout<<insertascii(inp);
		

		return 0;
}
