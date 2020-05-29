#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    long long ele=0;
    int trend=0;
    long long prev=1000000000;
    //0-decreasing 1- increAsing
    while(t--){
        cin>>ele;
        if(ele <= prev and trend == 0){

        }
        else if(ele>prev and trend == 1 )
        {

        }
        else if(trend == 0 and ele >= prev){
            trend++;

        }
        else if(trend ==1 and ele <= prev)
        {
            trend++;

        }

        prev=ele;
        // cout<<trend<<endl;

    }
    if (trend<=1)
    cout<<"true";
    else std::cout << "false" << '\n';
return 0;
}
