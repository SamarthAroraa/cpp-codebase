//
//  main.cpp
//  Recursion-Convert String to Integer
//
//  Created by Samarth Arora on 21/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include<math.h>
using namespace std;

int rec_to_dedc(string str,int index,int size){
//#base case
    if(index==size)
        return 0;
    
//#recursive
    int num=rec_to_dedc(str, index+1, size);
    char c=str[index];
    int x=c-'0';
    
    return num+=x*pow(10,size-index-1);
    
    
    
}
int main()
{
    string str;
    cin>>str;
    cout<<rec_to_dedc(str, 0, str.length());
    return 0;
}
