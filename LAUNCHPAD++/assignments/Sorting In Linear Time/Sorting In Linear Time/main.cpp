//
//  main.cpp
//  Sorting In Linear Time
//
//  Created by Samarth Arora on 07/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ones=0;
    int xer=0;
    int tw=0;
    int n;
    
    cin>>n;
    for(int i=0;i<n;i++){
        char chl;
        cin>>chl;
        if(chl=='1'){
            ones+=1;
        }
        else if(chl=='2'){
                tw++;
            }
        else
            xer++;
    }
    
    for(int i=0;i<xer;i++){
        cout<<"0"<<endl;
    }
    for(int i=0;i<ones;i++){
        cout<<"1"<<endl;
        
    }
    
    for(int i=0;i<tw;i++){
        cout<<"2"<<endl;
    }
    
    return 0;
}
