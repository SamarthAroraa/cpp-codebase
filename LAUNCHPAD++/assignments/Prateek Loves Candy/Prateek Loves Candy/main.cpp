////
////  main.cpp
////  Prateek Loves Candy
////
////  Created by Samarth Arora on 29/08/19.
////  Copyright © 2019 Samarth Arora. All rights reserved.
////
//
//#include<iostream>
//using namespace std;
//bool isprime(int a){
//    bool flag=0;
//    if (a==1 or a==0)
//        return 0;
//    for(int i=2;i<=(int)a/2;i++)
//    {
//        if(a%i==0){
//            flag=-1;
//            break;
//        }
//
//
//    }
//    if(flag==0)
//        return 1;
//    else
//        return 0;
//
//
//}
//
//a
//int main()
//{
//    int pcount=0,t,i,n;
//    cin>>t;
//    while(t--){
//        cin>>n;
//        pcount=0;
//        i=2;
//        while(pcount<n){
//            pcount+=isprime(i);
//            i++;
//        }
//        cout<<i-1<<endl;
//
//    }
//
//    return 0;
//}\

#include <iostream>
#include <math.h>
#include<numeric>
#include<vector>
using namespace std;

void print(vector<bool> a)
{
    for(int i=0;i<a.size();i++){
        cout<<a[i];
        
    }
    cout<<endl;
}

bool isprime(int a){
    bool flag=0;
    if (a==1 or a==0)
        return 0;
    for(int i=2;i<=(int)a/2;i++)
    {
        if(a%i==0){
            flag=-1;
            break;
        }
        
        
    }
    if(flag==0)
        return 1;
    else
        return 0;
    
    
}
int main()

{int t;
    int n;
    cin>>t;
    
    int b,sum=0;
    while (t--) {
        
        cin>>n;
        
       
        vector <bool> sieve(1);
        bool*ptr=&sieve[0];
        for(int i=2;i<=b;i++){
            if(sieve[i]==1)
            {
                if(isprime(i)){
                    
                    for(int j=2*i;j<=b;j+=i)
                    {
                        sieve[j]=0;
                    }
                }
                else
                    sieve[i]=0;
            }
            sum=0;
            accumulate(ptr, ptr+b, sum);
            if(sum==n)
        }
        print(sieve);
        
    }

        
        return 0;
    }
