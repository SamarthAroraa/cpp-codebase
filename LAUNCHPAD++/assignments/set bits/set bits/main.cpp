//
//  main.cpp
//  set bits
//
//  Created by Samarth Arora on 08/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <math.h>
#include<string>
using namespace std;
int todec(string s){
    int num=0;
    for(int i=0;i<s.length();i++){
        num+=(s[i]-'0')*(pow(2,s.length()-i-1));
    }
              return num;
            
              }
//int setbitcount(int n){
//    int count=0;
//    while(n>=1){
//        count+=(n&1);
//        n=n>>1;
//    }
//    return count;
//
//}
int tobin(int n){
    int k=0,bin=0;
    while(n>=1){
        bin+=(n&1)*pow(10,k);
        n=n>>1;
        k++;
    }
    return bin;}
int main()
{   int count=0;
    int arr[]={1,1,1,2,2,3,3,3,5,4,4,4,2};
    for(int i=0;i<13;i++){
        count+=(tobin(arr[i]));
//        cout<<endl<<count;
    }
    string str=to_string(count);
    int len=str.length();
    string s="";
    for(int i=0;i<len;i++){
        int k=str[i]-'0';
        s+=to_string(k%3);
        
        
        
    }
    cout<<endl<<s<<endl;
    cout<<todec(s)<<endl;
    
    return 0;
    
}
