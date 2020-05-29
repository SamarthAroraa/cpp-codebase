#include<iostream>
using namespace std;
int main(){
    int n1,n2,i=1;
    cin>>n1>>n2;
    int count=0;
    while(count<n1){
        if((3*i+2)%n2!=0)
        {
            count++;
            cout<<3*i+2<<endl;
        }
        i++;
    }
return 0;
}
