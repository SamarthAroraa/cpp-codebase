//
//  main.cpp
//  Simple Input.cpp
//
//  Created by Samarth Arora on 29/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{   int cum_sum=0;
    while(cum_sum>=0){
        int n;
        cin>>n;
        cum_sum+=n;
        if(cum_sum>=0){cout<<n<<endl;}
    }
    return 0;
}
