//
//  main.cpp
//  Is Palindrome?
//
//  Created by Samarth Arora on 30/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool ispalin(vector<char> arr){
    int n=arr.size();
    bool flag=true;
    int j=n-1;
        for(int i=0;i<=(int)n/2;i++){
        if(arr[i]!=arr[j]){
            flag=false;
            break;
        }
        j--;
        
    }
    return flag;
}

int main()
{   int n;
    vector<char> arr;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        arr.push_back(c);
    }
    if(ispalin(arr))
    cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    
    return 0;
}
