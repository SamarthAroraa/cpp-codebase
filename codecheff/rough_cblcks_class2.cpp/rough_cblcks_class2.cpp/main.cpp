//
//  main.cpp
//  rough_cblcks_class2.cpp
//
//  Created by Samarth Arora on 24/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> bin){
    for(int i=0;i<bin.size();i++){
        cout<<bin[i]<<" ";
    }
    cout<<endl;
    
}
void conbin(long n,vector<int>&str)
{
    if(n>1){
        conbin(n/2,str);
    }
    str.push_back(n%2);
    
}
int main()
{
    vector<int> bin;
    int t;
    long n;
    cin>>t;
    while(t--){
        cin>>n;
        long count=0;
        conbin(n,bin);
        for(int i=0;i<bin.size();i++){
            if(bin[i]==0)
                count++;
            
        }
        cout<<count<<endl;
        bin.clear();
    }
    return 0;
}

