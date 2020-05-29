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
	ll t;
	cin>>t;
	while(t--){
		ll l,r,u,d;
		cin>>l>>r>>d>>u;
		ll x,y,x1,x2,y1,y2;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		ll hzntl=x+r-l;
		ll vrtcl= y+u-d;
		// if(u==d){

		// }
		// bool va=1;
		// bool ha=1;
		// if(u==d){
		// 	if((vrtcl+1>=y1 and vrtcl+1<=y2) or (vrtcl-1>=y1 and vrtcl-1<=y2)){

		// 	}
		// 	else{
		// 		va=0;
		// 	}
		// }
		// if(l==r){
		// 	if((hzntl+1>=x1 and hzntl+1<=x2) or (hzntl-1>=x1 and hzntl-1<=x2)){

		// 	}
		// 	else{
		// 		ha=0;
		// 	}
		// }
		if(x1==x2 and (l!=0 or r!=0))
		{
			cout<<"NO\n";
			cerr<<'a'<<endl;
		}
		else if(y1==y2 and (u!=0 or d!=0)){
			cout<<"NO\n";
			cerr<<'b'<<endl;

		}
		else if(hzntl<=x2 and hzntl>=x1 and vrtcl<=y2 and vrtcl>=y1){
			cout<<"YES\n";
			cerr<<'c'<<endl;

		}
		else{
			cerr<<'d'<<endl;

			cout<<"NO\n";
		}

	}


return 0;
}