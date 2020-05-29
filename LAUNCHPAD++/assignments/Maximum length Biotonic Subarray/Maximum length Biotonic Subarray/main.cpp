#include <iostream>
#include<vector>
#include <climits>
using namespace std;

long long maxbio(vector<long long> seq){
    long long n=seq.size();
    vector<long long> lis(n,1);
    vector<long long> lds(n,1);
    
    // compute LIS
    for (long long i=1; i<n; i++) {
        for (long long j=i-1; j>=0; j--) {
            if(seq[j]<=seq[i])
            {
                lis[i]=lis[j]+1;
                break;
            }
        }
    }
    long long max=INT_MIN;
//    for(long long i=0;i<n;i++)
//        if(max<lis[i])
//            max=lis[i];
    
    //compute LDS
    for (long long i=n-2; i>=0; i--) {
        for (long long j=i+1; j<=n; j++) {
            if(seq[j]<seq[i]){
                lds[i]=lds[j]+1;
                break;
            }
        }
    }
//    long long max_lds=long long_MIN;
//    for(long long i=0;i< n; i++){
//        if(max_lds<lds[i])
//            max_lds=lds[i];
//    }
    
    for(long long i=0;i<n;i++){
        long long val=lds[i]+lis[i]-1;
        if(max<val)
            max=val;
    }
    
    
    return max;
    
}

int main()
{
    long long t;
    cin>>t;
    while (t--) {
        long long n;
        cin>>n;
        vector<long long> seq(n,0);
        for(long long i=0;i<n;i++)
            cin>>seq[i];
        
        cout<<maxbio(seq)<<endl;
    }
    return 0;
    
}
