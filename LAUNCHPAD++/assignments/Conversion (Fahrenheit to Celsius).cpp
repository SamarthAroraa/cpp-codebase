#include<iostream>

using namespace std;

float tocelcius(int n){
float cel=5*(n-32)/9;

    return cel;
}

int main(){
    int min,max;
    cin>>min>>max;
    int step;
    cin>>step;
    for(int i=min;i<=max;i+=step){
        cout<<i<<"\t"<<tocelcius(i)<<endl;
    }
return 0;
}
