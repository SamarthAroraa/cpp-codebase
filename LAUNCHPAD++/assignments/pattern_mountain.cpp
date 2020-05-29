#include<iostream>
using namespace std;
int main(){
    int n,j;
    int spaces;

    cin>>n;
    for(int i=1;i<=n;i++){
        spaces=2*n-1-2*i;
            if(spaces<0)spaces=0;

        for(int j=1;j<=i;j++)
        {
            cout<<j <<" ";
        }
        for(j=1;j<=spaces;j++){
            cout<< "  ";

        }
        if (spaces!=0){
        for(j=i;j>0;j--){
            cout<<j<<" ";
        }}
        else{
        for(j=i-1;j>0;j--){
            cout<<j<<" ";
        }}

    cout<<endl;
}

    return 0;
}
