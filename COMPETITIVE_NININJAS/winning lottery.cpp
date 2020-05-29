#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
string winning(int d, int s){
	string ans="";
	int msd=1;
	int remaining=s-1;
	bool a=false;
	while(!a){
		a=false;
		while(remaining>0 and ans.length()<=d-1){
		if(remaining>=9){
			ans= '9'+ans ;
			remaining-=9;
		}

		else{
			char diff= remaining + '0';
			ans= diff+ans;
			a=true;
			remaining=0;
		}
	}
	if(a){
	int n= ans.length();
	if(n<d-1){
		while(n!=d-1){
			ans='0' + ans;
			n++;
		}
	}
}
else{
	msd++;
}
}
ans= (char)(msd+'0')+ ans;
return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int d,s;
	cin>>s>>d;
	cout<<winning(d,s);

return 0;
}