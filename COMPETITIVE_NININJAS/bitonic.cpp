#include<bits/stdc++.h>

#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;



	int longestBitonicSubarray(int *input, int n) {
		vector<int> inc(n,1);
        vector<int> dec(n,1);
        inc[0]=1;
        dec[0]=1;
        int max_len=INT_MIN;
        for(int i=1;i<n;i++){
         for(int j=i-1;j>=0;j--){
                
                if(input[j]<input[i]){
                if(inc[j]+1>inc[i]){
                    inc[i]=inc[j]+ 1;
                }
                }
                
            
            }  
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                
                if(input[j]<input[i]){
                    if(dec[j]+1>dec[i]){
                    dec[i]=dec[j]+1;
                } 
                
                }
                
            
            }  
        }

        for(int i =0 ; i< n; i++){
            max_len=max(max_len, dec[i]+inc[i]-1);deb(i);deb(dec[i]);deb(inc[i])
        }
        return max_len;
     	
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int* input= new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cout<<longestBitonicSubarray(input,n)<<endl;
    delete []input;

return 0;
}

