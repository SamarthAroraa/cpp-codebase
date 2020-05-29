//
//  main.cpp
//  Prime Visits prime visits
//
//  Created by Samarth Arora on 27/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

//#include <bits/stdc++.h>
//
//#include <math.h>
//#include<vector>
//using namespace std;
//
//bool sieve[1000001];
//int main()
//
//{
//    int t;
//    cin>>t;
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
//    long long int a,b;
//    long long i,j;
//    while (t--) {
//
//
//       cin>>a>>b;
//
//    int count=0;
//    for(i=a;i<=b;i++){
//        if(sieve[i]==0)
//        {
////            cout<<i<<endl;
//            count++;
//        }
//    }
////    print(sieve);
////    cout<<isprime(10);
//
//    cout<<count<<endl;
//    }
//
//    return 0;
//}
//
#include <iostream>
#include<vector>
using namespace std;

long long n;
long long num;
void rev(vector<long long> &arr){
    long long i=0;
    long long j=arr.size()-1;
    while(i<=j){
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
        i++;
        j--;
    }
    
    
}
int main(){
    vector<long long> arr;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
    rev(arr);
    for(long long i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
       }
    return 0;
}
