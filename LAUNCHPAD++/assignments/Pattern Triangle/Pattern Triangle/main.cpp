//
//  main.cpp
//  Pattern Triangle
//
//  Created by Samarth Arora on 30/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;


int main()
{
    int n,spaces,i;
    cin>>n;
    spaces=2*(n-1);
    for(i=1;i<=n;i++){
        for(int j=1;j<=spaces;j++){
            cout<<" ";
        
        }
        spaces-=2;
        int cand=i;
        while(cand<=2*i-1){
            cout<<cand<<" ";
            cand++;
            
        }
        cand-=2;
        while(cand>=i){
            cout<<cand<<" ";
            cand--;
        }
        cout<<endl;
        
    }
    
    return 0;
}
