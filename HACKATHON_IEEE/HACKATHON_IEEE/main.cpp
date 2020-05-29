//
//  main.cpp
//  HACKATHON_IEEE
//
//  Created by Samarth Arora on 13/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.


#include <iostream>
#include<vector>
using namespace std;

void rot(vector<int> &arr){
    int val=arr[0];
    
    int l=arr.size();
    for(int i=1;i<l;i++){
        arr[i-1]=arr[i];
    }
    arr[l-1]=val;
}

int main(){
    vector<int> arr;
    int n,d, num;
    cin>>n>>d;
        for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }

    for(int i=0;i<d;i++){
        rot(arr);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
//
//    for(int i=0;i<d;i++){
//        cout<<arr[i]<<" ";
//    }

    return 0;
}
//int main(){
//    int n,k,ele;
//    int t;
//    cin>>t;
//    while(t--){
//    long min=10e7;
//    cin>>n>>k;
////    vector<int> arr;
//    for(int i=0;i<n;i++){
//        cin>>ele;
////        arr.push_back(ele);
//        if(ele<min) min=ele;
//    }
//    cout<<k-min<<endl;
////        arr.clear();
//    }
//    return 0;
//}
//#include <iostream>
//
//#include <math.h>
//#include<vector>
//using namespace std;
//
//bool sieve[1000001];
//int main()
//
//{
//
//    for(long long int i=0;i<=1000001;i++)sieve[i]=0;
//    sieve[0] = 1;
//    sieve[1] = 1;
//    for(long long int i=2;i<=1000001;i++)
//    {
//        if(sieve[i]==0)
//        {
//
//            for(long long int j=i*i;j<=1000001;j+=i)
//            {
//                sieve[j]=1;
//            }
//        }
//    }
//    int n,j;
//    cin>>n;
//    for(j=n;j>=0;j--){
//        if(sieve[j]==0)
//            break;
//    }
//    cout<<j<<endl;
//    return 0;
//}
