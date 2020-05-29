//
//  main.cpp
//  STRING_COMPRESSION.cpp
//
//  Created by Samarth Arora on 27/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main()
{
    string s,comp_s="";
    vector<int> reps;
    cin>>s;
    int count;
    for(int i=0;i<s.length();i++)
    {    count=1;
      comp_s+=s[i];
         count=1;
        while(s[i]==s[i+1]){
            count++;
            i++;
        }
        reps.push_back(count);
    }
    for(int i=0;i<comp_s.length();i++){
        cout<<comp_s[i]<<reps[i];
    }
    return 0;
}
