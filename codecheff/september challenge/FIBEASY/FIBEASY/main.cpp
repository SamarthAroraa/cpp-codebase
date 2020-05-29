//
//  main.cpp
//  FIBEASY
//
//  Created by Samarth Arora on 11/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void genfib(vector<int>&d,long long n){
    d.push_back(0);
    d.push_back(1);
    for(int i=2;i<n;i++){
        int temp=d[i-1]+d[i-2];
        d.push_back(temp%10);
    }
   
    
}
int main()
{
    vector <int> d;
    long long n;
    int t;
    cin>>t;
    while(t--){
    cin>>n;
 
        genfib(d,n);

    int index=log2(n);
    
    index=pow(2,index)-1;
    cout<<d[index]<<endl;
        
    }
    
    return 0;
    
}
