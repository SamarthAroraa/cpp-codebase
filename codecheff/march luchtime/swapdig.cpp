#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;


int ans(int a, int b){
// int m= a.length();
// int n=b.length();
// if(m==1 and n==1){
// 	int digita=a[0]-'0';
// 	int digitb=b[0]-'0';
// 	return digitb+digita;
// }
// if(m>1 and n>1){
// 	if((int)(a[0]-'0')<(int)(b[1]-'0'))
// 		return (int)(b[1]-'0')*10+(int)(a[1]-'0')+(int)(b[0]-'0')*10+(int)(a[0]-'0');
// 	else if((int)(b[0]-'0')<(int)(a[1]-'0')){
// 		return (int)(a[1]-'0')*10+(int)(b[1]-'0')+(int)(a[0]-'0')*10+(int)(b[0]-'0');

// 	}
// }
// if(m>1 and n==1){
// 	if((int)(a[0]-'0')<(int)(b[0]-'0'))
// 		return (int)(b[0]-'0')*10+(int)(a[1]-'0')+(int)(a[0]-'0');

// }
// if(n>1 and m==1){
// 	if((int)(b[0]-'0')<(int)(a[0]-'0'))
// 		return (int)(a[0]-'0')*10+(int)(b[1]-'0')+(int)(b[0]-'0');

// }
// if(m>1 and n>1)
// 		return (int)(b[0]-'0')*10+(int)(b[1]-'0')+(int)(a[0]-'0')*10+(int)(a[1]-'0');
// if(m>1 and n==1)
// 		return (int)(b[0]-'0')*10+(int)(b[1]-'0')+(int)(a[0]-'0');
// if(m==1 and n>1)
// 		return (int)(b[0]-'0')+(int)(a[0]-'0')*10+(int)(a[1]-'0');
// return -1 ;
int ao=0,at=0,bo=0,bt=0;
at=a/10;
ao=a%10;
bt=b/10;
bo=b%10;

int normal= a+b;
int swap1=0,swap2=0;
if(at!=0)
swap1=bo*10+ao + bt*10 + at;
if(bt!=0)
swap2=at*10 + bt + ao*10+bo;
return(max(max(swap2,swap1),normal) );

}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<ans(a,b)<<"\n";
	}

return 0;
}