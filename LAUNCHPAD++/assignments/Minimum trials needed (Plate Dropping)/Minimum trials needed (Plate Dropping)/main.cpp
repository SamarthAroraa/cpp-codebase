//
//  main.cpp
//  Minimum trials needed (Plate Dropping)
//
//  Created by Samarth Arora on 12/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include<math.h>
using namespace std;

int main()
{

    int t,k,n;
    cin>>t;
    while(t--){
    cin>>k>>n;
        int ans= log2(n);
        ans++;
        
        if(ans>k) ans=k;
        cout<<ans<<endl;
        
    }
}
