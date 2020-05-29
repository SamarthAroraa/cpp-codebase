//
//  main.cpp
//  counting
//
//  Created by Samarth Arora on 16/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//bool countwin(bool turn, long long n,long long target,char mode)
//{
//    if(n>=target){
//        cout<<mode<<endl;
//        return !(turn);
//    }
//    //1 aron 0  B
//
//    if(mode=='B')
//        mode='A';
//    else
//        mode='B';
//    bool res1=countwin(!(turn),n+1,target,mode);
//     bool res2=countwin(!(turn),n+2,target,mode);
//     bool res3=countwin(!(turn),n+3,target,mode);
//
//    if(mode=='B')
//        return res3*res1*res2;
//    else return res2+res1+res3;
//
//}
//
//long long main(){
//    cout<<countwin(0,2,10,'A');
//    return 0;
//}
long long numways_given_step_set(long long n, vector<int> step_len)
{
//    if(n==0 or n==1)
//        return n;
    long long s=step_len.size();
    vector<int> ways={1,1};
    long long newways=0;
    for(long long i=2;i<=n;i++){
        newways=0;
        for(long long j=0;j<s;j++)
        {
            if(i-step_len[j]<0)
                continue;
            newways+=ways[i-step_len[j]];
            
        }
        ways[i]=newways;}
    
    return ways[n]%pow(10,9);
    
}

int main(){
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> set;
        for(int i=0;i<2;i++){
            int ni;
            cin>>ni;
            set.push_back(ni);
        }
        cout<<numways_given_step_set(n, set);
    }
    
}
