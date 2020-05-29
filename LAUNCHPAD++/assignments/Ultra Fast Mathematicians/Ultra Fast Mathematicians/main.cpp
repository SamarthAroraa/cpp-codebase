//
//  main.cpp
//  Ultra Fast Mathematicians
//
//  Created by Samarth Arora on 27/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include<vector>
#include <string>
using namespace std;

void print(vector<int> a)
{
    for(int i=0;i<a.size();i++){
        cout<<a[i];
   
    }
     cout<<endl;
}
int main()
{   string a;
    string b;
    vector<int> ans;
    int t;
    cin>>t;
    while (t--) {
        cin>>a;
        cin>>b;
        for(int k=0;k<a.size();k++){
            if(a[k]==b[k])
                ans.push_back(0);
            else
                ans.push_back(1);
        }
        print(ans);
            
            
        a.clear();
        ans.clear();
        b.clear();
    }    return 0;
}
