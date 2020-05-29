#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


//
//  main.cpp
//  SUBSEQUENCES_REC
//
//  Created by Samarth Arora on 22/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

// #include <iostream>
// #include <vector>
// using namespace std;
// int k=1;
unordered_map <string, int> frequency;
void subsequences(string str,string ans){
    //base case
    if(str.length()==0){
        
       // cerr<<ans<<endl;
//            cout<<ans<<" ";
        frequency[ans]++;
        
        return ;
    }
    //recursive
    subsequences(str.substr(1),ans);
//    cout<<ans<<endl;
    subsequences(str.substr(1),ans+str[0]);//important step.. ans+str[0]means changes are being accumulated at the end. If it ha been str[0]+ans changes would be accumultaed at the beginnning
//    cout<<ans<<endl;
    
    
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    #endif
    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
    string str;
    cin>>str;
    subsequences(str,"");
//    cout<<endl;
//        cout<<subseq.size()<<endl;;
    int k=0;
    for(auto n: frequency){
        // cerr<<n.first<<" "<<n.second<<endl;
        if(n.second>1){
            // cout<<n.second<<endl;
            if(n.first.length()>k)
                k=n.first.length();

        }

        // str.clear();
        // subseq.clear();
    
    }
        // cerr<<k<<endl;
        str.clear();
        cout<<k<<endl;
        k=0;
        frequency.clear();
}
//    char c=1+'0';
//    cout<<c;
    
    return 0;
}


        

  









