
#include <bits/stdc++.h>
using namespace std;


int main()
{	
	#ifndef O_J
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

int k;
cin>>k;
int gmax=0;

	string s;
	cin>>s;
	for(int i=0;i<s.length()-1;i++){
		int next=-1;
		int j=i;
		int length=0;
		while(k>=0 and j<s.length()){
			if(s[j]!=s[j+1]){
				k--;
				if(next!=-1) next=j;
			}
			j++;
			cout<<j;
			length++;
		}
		length--;

		if(gmax<length){
			gmax=length;
		}
	i=next;
}
cout<<gmax;


return 0;
}