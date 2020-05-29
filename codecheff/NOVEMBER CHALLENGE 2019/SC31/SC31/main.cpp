//
//  main.cpp
//  SC31
//
//  Created by Samarth Arora on 02/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int ans(vector<string> strings,int n){
    //    int n=strings.size();
    string res;
    //    string res=strings[1];
    for(int i=0;i<n-1;i++){
        string t="";
        
        string sr1=strings[i];
        res=strings[i+1];
        for(int j=0;j<10;j++){
            if(sr1[j]=='1' and res[j]=='1'){
                t+='0';
            }
            else if((sr1[j]=='1' and res[j]=='0') or (sr1[j]=='0' and res[j]=='1')){
                t+='1';
            }
            else{
                t+='0';
            }
        }
        strings[i+1]=t;
        t.clear();
        
        
    }
    int count=0;
    for(int i=0;i<10;i++){
        if(strings[n-1][i]=='1')
            count++;
    }
    //    cout<<strings[n-1];
    return count;
    
}
int main()
{
    int t;
    cin>>t;
    string sr;
    while (t--) {
        int n;
        cin>>n;
        vector<string> strings;
        for(int i=0;i<n;i++){
          
            cin>>sr;
            strings.push_back(sr);
            
            sr.clear();
        }
        cout<<ans(strings,n)<<endl;
    }
}
