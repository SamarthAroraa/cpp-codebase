#include<bits/stdc++.h>
using namespace std;


vector <bool> sieve(100001,1);

void gensieve(){

    sieve[0]=0;
    sieve[1]=0;

    for(long i=2;i<=100000;i++){
        if(sieve[i]==1){
            for(long  j=i*i;j<=100000;j+=i){
                sieve[j]=0;
            }
        }
    }
}

long  retprice(std::vector<bool>sieve,long  n){
    long  count=0;
    long  i=1;
    while(count<n){
        i++;
        cerr<<sieve[i]<<" "<<i<<endl;
        if(sieve[i]==1){
            count++;
        }

    }


return i;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    long  t,n;
    gensieve();
    cin>>t;
    while(t--){
        cin>>n;
        cout<<retprice(sieve,n)<<endl;

    }
return 0;
}
