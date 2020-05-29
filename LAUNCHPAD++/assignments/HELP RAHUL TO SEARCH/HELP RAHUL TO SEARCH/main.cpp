//
//  main.cpp
//  HELP RAHUL TO SEARCH
//
//  Created by Samarth Arora on 07/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,j,i;
    cin>>n;
    vector<int> arr;
    for(i=0;i<n;i++){
        cin>>j;
        arr.push_back(j);
    }
    cin>>j;
    for( i=0;i<n;i++){
        if(j==arr[i]){
            break;
        }
    }
    if(i==n){
        cout<<-1<<endl;
        
    }
    else cout<<i<<endl;
    return 0;
}

