
#include <bits/stdc++.h>
using namespace std;


int main()
{

    
    long k;
    cin>>k;
    long gmax=0;
    
    string s;
    cin>>s;
    s+="n";
    for(long i=0;i<s.length();i++){
//        int next=-1;
        long j=i;
        char gs=s[i];
        long length=0;
        while(k>=0 and j<s.length()){
            if(s[j]!=gs){
                k--;
               
//                if(next!=-1) next=j;
            }
            
                j++;
//            cout<<j;
        
            length++;
        }
        length--;
        
        if(gmax<length){
            gmax=length;
        }
//        i=next;
    }
    cout<<gmax;
    
    
    return 0;
}
