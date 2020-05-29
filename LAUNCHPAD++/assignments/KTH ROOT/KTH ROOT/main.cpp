//
//  main.cpp
//  KTH ROOT
//
//  Created by Samarth Arora on 10/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n;
    int k,t;
    cin>>t;
    while(t--){
        
    
    cin>>n>>k;
        int j=1;
        while((long long)pow(j,k)<=n){
            j++;
        
    }
        if(pow(j,k)>n){
            j--;
        }
        cout<<j<<endl;
       
    }
    
    return 0;
}
