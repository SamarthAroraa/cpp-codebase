#include<bits/stdc++.h>
#include<unordered_map>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
set<string> data;
int ans(string buttons, unordered_map<char, string> keypad,string answ,string output[]){

if(buttons.size()==0)
	{	data.insert(answ);
		// i++;
		return 1;
	}
int count=0;
	// ans(buttons.substr(1), keypad,answ);
	for(int i=0;i<keypad[buttons[0]].size();i++){
		count+=ans(buttons.substr(1),keypad,answ+keypad[buttons[0]][i],output);
		
	}
return count;}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	unordered_map <char, string> keypad;
	keypad['2'] =   "abc";
	keypad['3']	=   "def";
	keypad['4'] =   "ghi";
	keypad['5']	=	"jkl";
	keypad['6']	=	"mno";
	keypad['7']	=	"pqrs";
	keypad['8']	=	"tuv";
	keypad['9']	=	"wxyz";
	string output[1000];
	// int j=0;

	int c = ans("8", keypad , "",output);
	for(auto n: data){
		cout<<n<<endl;
	}




return 0;
}