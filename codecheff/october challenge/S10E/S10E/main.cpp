//
//  main.cpp
//  S10E
//
//  Created by Samarth Arora on 06/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int gooddays(vector<int> prices){
    int days=prices.size();
    int gds=1;
    
    for(int i=1;i<days;i++){
        int prevbound=0;
        
        if(i<5){
            prevbound=0;
        }
        else
            prevbound=i-5;
        int prevbest=prices[prevbound];
        for(int j=prevbound+1;j<i;j++){
            if(prices[j]<prevbest){
                prevbest=prices[j];
            }
        }
        if(prevbest>prices[i]){
            gds++;
        }
        
    }
    
    return gds;
    
}
int main()
{
    int t;
    cin>>t;
    vector<int> prices;
    while(t--){
        
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            prices.push_back(k);
            
        }
    
        cout<<gooddays(prices)<<endl;
        prices.clear();
        
    }
    return 0;
    
}
