//
//  main.cpp
//  Manmohan Loves Patterns - I
//
//  Created by Samarth Arora on 28/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Hello ";
    return 0;
    int n;
    cin>>n;
    
    int i,j=0,k,m;
    for(i=1;i<=n;i++){
        if(i%2!=0){
            for(k=0;k<i;k++){
                cout<<"1";
            }cout<<endl;
            
        }
        else if(i%2==0){
            cout<<"1";
            for(m=0;m<j;m++){
                cout<<"0";
            }
            j+=2;cout<<"1"<<endl;
            
        }
    }
    return 0;
}
