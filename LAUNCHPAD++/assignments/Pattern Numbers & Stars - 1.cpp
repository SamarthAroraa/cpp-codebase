#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
     int stars=0;
    for(int i=0;i<n;i++){
        stars=2*i-1;
        if(stars<0)
        stars=0;

        for(int j=0;j<n-i;j++){
            cout<<j+1<<" ";
        }
        for(int j=0;j<stars;j++){
            cout<<"* ";
        }
    cout<<endl;
}
return 0;
}
