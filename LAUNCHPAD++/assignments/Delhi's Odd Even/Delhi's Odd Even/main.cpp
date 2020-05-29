//
//  main.cpp
//  Delhi's Odd Even
//
//  Created by Samarth Arora on 28/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string num;
    int t;
    cin>>t;
    int odds,evesu;
    while(t--){
        odds=0;
        evesu=0;
        cin>>num;
        for(int k=0;k<num.length();k++){
            char c=num[k];
            int n=c-'0';
            if(n%2==0){
                evesu+=n;
            }
            else{
                odds+=n;
                
            }
        }
        cout<<odds<<" "<<evesu<<endl;
        if(odds%3==0 or evesu%4==0){
            cout<<"Yes"<<endl;
            
        }
        else{
            cout<<"No"<<endl;
        }
        num.clear();
    }
    
    return 0;
}
