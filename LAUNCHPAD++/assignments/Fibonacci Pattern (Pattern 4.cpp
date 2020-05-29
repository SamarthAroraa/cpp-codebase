
#include<bits/stdc++.h>
using namespace std;
void printpattern(int n){
	int digits= n*(n+1)/2;
	long long fib[digits+1];
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<digits;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	int abs=0;
//printing loop
	for(int newline=1;newline<=n;newline++){
		for(int j=0;j<newline;j++){
			cout<<fib[abs++]<<" ";
		}cout<<endl;
	}
	return;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

int n;
cin>>n;
printpattern(n);
return 0;
}