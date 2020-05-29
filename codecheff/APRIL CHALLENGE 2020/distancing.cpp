#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t start, end; 
	time(&start);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		// string s="";
		char c;
		bool flag=0;
		int distancing=-1;
		for(int i=0;i<n;i++){
			cin>>c;
			if(c=='1' and distancing!=-1){
				if(i-distancing<6)
				{
					// cout<<"NO\n";
					flag=1;
				}
				distancing=i;
			}
			if(c=='1' and distancing==-1){
				distancing=i;
			}

		}
		if(flag==0){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}

//code here

	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}