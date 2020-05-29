#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;

	int p1,p2;
	int leader;
	int maxlead=INT_MIN;
	int cs_1=0,cs_2=0;
 //0 for p1,1 for p2 
	for(int i=0;i<n;i++){
		cin>>p1>>p2;
		cs_1+=p1;
		cs_2+=p2;
		if(cs_1>=cs_2){
			int lead=cs_1-cs_2;
			if(lead>maxlead){
				maxlead=lead;
				leader=1;
			}

		}
		else{
			int lead=cs_2-cs_1;
			if(lead>maxlead){
				maxlead=lead;
				leader=2;
			}

		}
	}

	cout<<leader<<" "<<maxlead;


return 0;
}