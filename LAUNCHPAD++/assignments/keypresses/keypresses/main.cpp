//
//  main.cpp
//  keypresses
//
//  Created by Samarth Arora on 03/12/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include<vector>
#include <boost/algorithm/string.hpp>
#include <string>

using namespace std;

bool res(string arr[2]){
    string res1="";
    string res2="";
    vector<string> result;
    boost::split(result, arr[0], boost::is_any_of(","));
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    return 1;}
int main(int argc, const char * argv[]) {
    // insert code here...
    res("a,b,c,d,-B","abc");
    return 0;
}
