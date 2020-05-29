//
//  main.cpp
//  Strings-Remove Duplicates
//
//  Created by Samarth Arora on 10/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int i;
    
    cin>>str;
    for(i=0;i<str.length();i++){
        if(str[i]==str[i+1]){
            cout<<str[i];
            char temp=str[i];
            while(str[i]==temp){
                i++;
                
            }
            i--;
        }
        else
            cout<<str[i];
    }
    
    return 0;
}

