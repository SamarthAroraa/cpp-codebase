//ll main()
//
//{
//    ll t;
//    cin>>t;
//    for(long long ll i=0;i<=1000001;i++)sieve[i]=0;
//    sieve[0] = 1;
//    sieve[1] = 1;
//    for(long long ll i=2;i<=1000001;i++)
//    {
//        if(sieve[i]==0)
//        {
//
//            for(long long ll j=i*i;j<=1000001;j+=i)
//            {
//                sieve[j]=1;
//            }
//        }
//    }

#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
bool sieve[10000001];

int res(ll n,ll k){
	while (n % 2 == 0)  
    {  
        cout << 2 << " ";  
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            cout << i << " ";  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        cout << n << " ";
       cout<<endl;  
    return 1;

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
	   for( ll i=0;i<=10000001;i++)sieve[i]=0;
   sieve[0] = 1;
   sieve[1] = 1;
   for( ll i=2;i<=10000001;i++)
   {
       if(sieve[i]==0)
       {

           for( ll j=i*i;j<=10000001;j+=i)
           {
               sieve[j]=1;
           }
       }
   }
   ll t;
   cin>>t;

   while(t--){
   	ll x,k;
   	cin>>x>>k;
   	cerr<<res(x,k)<<"\n";

   }

//code here

	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}