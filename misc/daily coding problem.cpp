#include<iostream>
using namespace std;

#ifndef deb(x)
#define deb(x) cout<<#x<<" "<<x<<endl;
#endif
int longest_1_stream(int n)
{int c=0;
    int maxc=INT_MIN;
    while(n>0){
        if((n&1)==1)
        c++;
        else{
            // deb(c);
            maxc=max(c,maxc);
            c=0;
      }
        n=n>>1;
    }
return max(maxc,c);
}

int main(){
    int n;
    cin>>n;

    cout<<longest_1_stream(n)<<endl;
    return 0;
}
