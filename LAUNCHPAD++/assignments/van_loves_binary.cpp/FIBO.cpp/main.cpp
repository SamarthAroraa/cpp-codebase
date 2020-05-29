#include<iostream>
#include <string>
#include<math.h>
using namespace std;

int btd(string st){
    int k =0;
    int num=0;
    while(k<st.size()){
        if(st[k]=='1'){
            num+=pow(2,st.size()-k-1);
            
            
        }
        k++;
        
    }
    return num;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string st;
        cin>>st;
        cout<<btd(st)<<endl;
    }
        return 0;
    
}
