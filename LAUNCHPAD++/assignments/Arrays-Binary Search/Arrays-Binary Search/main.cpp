//
//  main.cpp
//  Arrays-Binary Search
//
//  Created by Samarth Arora on 07/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
long binsearch(vector<long> arr, long ele){
    unsigned long n=arr.size();
    
    //ll=lower limit    ul=upper limit   ele=element     n=size of array
    
    long mid=n/2, ul=n-1,ll=0;
    
    while(arr[mid]!=ele and ul  > ll)
    {
//        cout << ul << " " <<
        if(ele>arr[mid])
        {
            ll = mid +1;
            mid=(ul+ll)/2;
        }
        else if(ele<arr[mid])
        {
            ul = mid - 1;
            mid=(ul+ll)/2;
        }
//        cout << mid << endl;
        
    }
    //if ul==ll, whole array searched but ele not found
    if(ll > ul){
        return -1;
    }
    else
        return mid;
    
}
int main()
{
    vector<long> arr;
    unsigned long n;
    cin>>n;
    for(long j=0;j<n;j++){
        long k;
        cin>>k;
        arr.push_back(k);
//        cout << " dhfs " <<endl;
    }
    long ele;
    cin>>ele;
    cout<<binsearch(arr, ele)<<endl;
    return 0;
}
