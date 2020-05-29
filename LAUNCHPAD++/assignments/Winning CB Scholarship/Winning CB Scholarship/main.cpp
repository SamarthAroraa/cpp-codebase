//
//  main.cpp
//  Winning CB Scholarship
//
//  Created by Samarth Arora on 25/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;

long long n,m,x,y;
int main()
{
    cin>>n>>m>>x>>y;
    long long g=(y*n+m)/(x+y);
    cout<<g;
    
    return 0;
}
