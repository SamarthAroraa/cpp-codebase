#include<iostream>
#include <vector>

#define ll unsigned long long
using namespace std;

bool checkincdedc(vector<ll> v,int n){
//0=increasing
//1=decreasing
    bool trend=0;
    if(v[0]>v[1]){
        trend=1;
    }
    int limit=0;
    int i=1;
    while(limit<1 and i<n){

            if(v[i-1]<=v[i] and trend==1){
                limit++;
                trend=!(trend);
            }
            else if(v[i-1]>=v[i] and trend==0){
                limit++;
                trend=!(trend);
            }
        i++;
    }
    if(i!=v.size() ) return false;
    else return true;


}

int main()
{
    std::vector<ll> v;
    int n;
    ll h;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h;
        v.push_back(h);
    }
    if(checkincdedc(v,n))
    cout<<"true"<<endl;
    else
    std::cout << "false" << '\n';

    return 0;
}
