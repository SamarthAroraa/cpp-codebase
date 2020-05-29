//
//  main.cpp
//  Count Set Bits
//
//  Created by Samarth Arora on 10/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int setbits(int n){
    int counter=0;
    while(n>0){
        counter+=(n&1);
        n=n>>1;
    }
    return counter;}
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<setbits(n);
        cout<<endl;
    }
    return 0;
}
