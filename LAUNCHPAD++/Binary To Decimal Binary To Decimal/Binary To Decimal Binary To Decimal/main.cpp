//
//  main.cpp
//  Binary To Decimal Binary To Decimal
//
//  Created by Samarth Arora on 08/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include<math.h>
using namespace std;

int converttodec(string binary){
    int num=0;
    int power=0;
    int len=binary.length();
    for(int i=len-1;i>=0;i--){
        if(binary[i]=='1'){
            num+=(pow(2,power));
            
            }
        power++;}
    return num;
    
}
int main()
{
    string bimnary;
    cin>>bimnary;
    cout<<converttodec(bimnary);
    return 0;
}

