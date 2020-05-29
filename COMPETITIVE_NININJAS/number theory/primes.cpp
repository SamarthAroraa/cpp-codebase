#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
#define MAX_SIZE 1000
bool sieve[MAX_SIZE];

void gensieve(int n){
	sieve[0]=0;
	sieve[1]=0;
	for(int i=2;i<=sqrt(n);i++){
		if(sieve[i]==1){
			int c=i;
			int p=i;

			while(p<=MAX_SIZE){
				p=i*c;

					sieve[p]=0;
					c++;

			}
		}
	}
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
	int primes=0;
	memset(sieve,1, sizeof sieve);
	gensieve(n);
	for(int i=0;i<=n;i++){

		cerr<<sieve[i]<<" ";
		primes+=sieve[i];
	}
	cout<<primes;


return 0;
}