//
//  main.cpp
//  PIVOT OF SORTED AND ROTATED ARRAY
//
//  Created by Samarth Arora on 31/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{   vector<int> arr;
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {int v;
        cin>>v;
        arr.push_back(v);
        
    }
    int j=0;
    while(arr[j]<arr[j+1]){
        j++;
    }
    cout<<j;
    return 0;
}
