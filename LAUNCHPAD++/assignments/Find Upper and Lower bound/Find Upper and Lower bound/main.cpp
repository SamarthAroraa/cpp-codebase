//
//  main.cpp
//  Find Upper and Lower bound
//
//  Created by Samarth Arora on 12/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t,n,i,low=-1,max=-1;
    int ele;
    
    vector<int> arr;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
        
    }
    cin>>t;
    while(t--)
    {
        cin>>ele;
        low=-1;
        max=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==ele){
                low=i;
                while(arr[i]==ele){
                    i++;
                    
                }i--;
                max=i;
                break;
            }
        }
       
        cout<<low<< " "<<max<<endl;
    }
    return 0;
}
