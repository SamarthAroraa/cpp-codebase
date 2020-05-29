#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll  long long
// #define INT_BITS 32
using namespace std;
ll rightRotate(ll n,  ll d,ll INT_BITS) 
{ 
	// // deb(INT_BITS)
	// int g= sizeof(ll)*8;
	// // deb(g)
	// ll k = n<<(INT_BITS-d);
	// // deb(k)
	// ll t= k<<(g-INT_BITS);
	// t= t>>(g-INT_BITS);
	// t=-t;
	// // deb(t)
 //    return (n >> d)|t; 

	if((n&1)==0){
		n=(ll)n>>1;

		return n;
	}
		n=(ll)n>>1;

	n=(ll)(n | (ll)((ll)1<<(INT_BITS-1)));
	return n;
} 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t start, end; 
	time(&start); 

	ll t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		ll ind;
		ll ta=a,tb=b;
		ll maxor=INT_MIN;
		ll asize=0,bsize=0;
		while(ta!=0){
			ta=ta>>1;
			asize++;
		}
		while(tb!=0){
			tb=tb>>1;
			bsize++;
		}
		ll size=max(asize,bsize);
		deb(size)
		for(ll i=0;i<size;i++){


			deb((a^b))

			if((a^b)>maxor){
				maxor=a^b;
				// if(i!=size-1)
				 ind= i;
				// else if(i==size-1){
				// 	ind=0;
				// }
			}
			deb(rightRotate(b,1,size))

			b=rightRotate(b,1,size);

			// maxor= max(a^b,maxor);
		}
		cout<<ind<<" " <<maxor<<"\n";
	} 
	
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 

return 0;
}