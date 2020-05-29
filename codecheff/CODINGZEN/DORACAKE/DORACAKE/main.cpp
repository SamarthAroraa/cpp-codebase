//
//  main.cpp
//  DORACAKE
//
//  Created by Samarth Arora on 16/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long maxamt(vector<int> buns, vector<int> jam,long n){
    sort(buns.begin(), buns.end());
    sort(jam.begin(), jam.end());
    long amt=0;
    for(long i=0;i<n;i++){
//        cout<<buns[i]<<" "<<jam[i];
        amt+=min(buns[i],jam[i]);
    }

    
    return amt;
    
}
long main()
{
    long t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        vector<int> buns(n);
        vector<int> jam(n);
        for(long i=0;i<n;i++){
            cin>>buns[i];
        }
        for(long i=0;i<n;i++){
            cin>>jam[i];
        }
        cout<<maxamt(buns, jam, n)<<endl;
        
}
    return 0;
    
}
