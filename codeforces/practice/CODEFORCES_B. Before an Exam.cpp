#include<bits/stdc++.h>
using namespace std;
int main()
{
	int d,maxsum=0,mins=0,maxs=0,minc,maxc;
	cin>>d>>maxsum;
	for(int i=0;i<d;i++)
	{
		cin>>minc;
		cin>>maxc;
		mins+=minc;
		maxs+=maxc;
	}
if(minc<=maxsum and maxc>=maxsum)
	{
		cout<<"YES"<<endl;
		
	}
else cout<<"NO"<<endl;
}