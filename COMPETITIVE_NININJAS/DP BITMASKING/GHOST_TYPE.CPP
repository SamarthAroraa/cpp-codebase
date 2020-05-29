#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
int gen(int n, int mask){
	if(mask==(1<<n)-1){
		cerr<<endl;
		
		return 1;
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if((mask & (1<<i))==0){
			bool flag=0;
					for(int m=1;m<=n;m++){
						if(i+1==m)
							continue;
						if(((i+1)&m)==(i+1) ){
							if((mask & 1<<(m-1))==1){
								flag=1;
								break;
							}
							
						}
					}
					if(!flag){
						sum+=gen(n,mask | (1<<i));
						cerr<<i+1<<" ";
					}
					else{
						cerr<<endl;
						continue;
					}	
				}
			}
		
	
return sum;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
		int n;
		cin>>n;
		int mask=0;
		cout<<gen(n,mask);
	


	 
return 0;
}