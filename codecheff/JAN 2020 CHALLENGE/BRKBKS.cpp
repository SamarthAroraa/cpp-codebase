#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;


ll ans(std::vector<int> brick, int s){
	// int sum=0;
	int i,j,k,hits=0;
	i=0;j=2;k=0;

	while(i<=j){
		int lh=0,rh=0;
		if(s<brick[i] and s<brick[j])
			return -1;
		int a,b;
		a=i;
		b=j;
		int damage=0;
		while(a<3 and damage<=s){
			damage+=brick[a++];
			
		}
		a--;
		damage=0;
		while(b>-1 and damage<=s){
			damage+=brick[b--];
			
		}
		b++;
		if((j-b)<=(a-i)){
			i+=(a-i);
		}
		else{
			j-=(j-b);
		}
		deb(i)
		deb(j)
		hits++;

	}


	return hits;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
{
	std::vector<int> brick;
	int s,w1,w2,w3;
	cin>>s>>w1>>w2>>w3;
	if(w1+w2+w3<=s){
		cout<<1<<endl;
		continue;
	}
	brick={w1,w2,w3};
	cout<<ans(brick,s)<<endl;
}
return 0;
}