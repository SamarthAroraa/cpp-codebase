//
//  main.cpp
//  CCHW
//
//  Created by Samarth Arora on 16/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string hamster_9(string inp){
    //count all except x
    long l=inp.length();
    long sum=0;
    long x=0;
    for(long i=0;i<l;i++){
        char ch= inp[i];
        if(inp[i]!='x'){
            long num=ch-'0';
            sum+=num;
            
        }
        else x++;
    }
    long factor=0;
    if(sum>=9){
    factor=sum%9;
    }
    else
    factor=9%sum;
    if(factor==0){
        
        factor=9;}
   
    
    
    char ch= factor+'0';
    
//    cout<<sum<<" "<<factor<<endl;

    string ans="";
    for(long i=0;i<l;i++){
        if(inp[i]!='x')
        {
            ans+=inp[i];
        }
        else if(inp[i]=='x' and x==1){
            ans+=ch;
            x--;
        }
        
        else{
            ans+='9';
            x--;
            
        }
            
        
            
    }
    
    return ans;
    
}
int main(){
    long t;
    cin>>t;
    while(t--){
        string inp;
        cin>>inp;
        cout<<hamster_9(inp)<<endl;
    }

}
