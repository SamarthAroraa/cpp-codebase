#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
void subsequence(string s, string ans)
{
	if(s.length()==0)
	{	cout<<ans<<endl;
		return;
	}
	subsequence(s.substr(1), ans);
	subsequence(s.substr(1), s[0]+ans);

}


int main(){
	
	subsequence("abcd","");

return 0;
}