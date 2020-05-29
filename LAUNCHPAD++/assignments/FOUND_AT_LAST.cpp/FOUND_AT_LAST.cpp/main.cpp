//
//  main.cpp
//  FOUND_AT_LAST.cpp
//
//  Created by Samarth Arora on 27/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int pos=-1;
    vector<long> arr;
    long c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        arr.push_back(c);
    }
    
    cin>>c;
    for(int j=n-1;j>=0;j--){
        if(arr[j]==c){
            pos=j;
            break;
        }
    }
    cout<<pos;
    
    return 0;
}
