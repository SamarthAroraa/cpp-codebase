//
//  main.cpp
//  Manmohan Loves Patterns - I
//
//  Created by Samarth Arora on 28/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if (n<=1){
        cout<<"1";
        return 0;
    }
    else{
    int i,k;
        cout<<"1"<<endl;
    for(i=1;i<=n;i++){
        cout<<i;
        for(k=0;k<i-1;k++)
        {
            cout<<"0";
        }
        cout<<i<<endl;
//        if(i%2!=0){
//            for(k=0;k<i;k++){
//                cout<<"1";
//            }cout<<endl;
//
//        }
//        else if(i%2==0){
//            cout<<"1";
//            for(m=0;m<j;m++){
//                cout<<"0";
//            }
//            j+=2;cout<<"1"<<endl;
//
//        }
    }
    return 0;
    }}

