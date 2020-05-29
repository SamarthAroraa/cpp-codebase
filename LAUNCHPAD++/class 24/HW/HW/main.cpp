//
//  main.cpp
//  HW
//
//  Created by Samarth Arora on 15/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int min_slits(string str){
    int n=str.length();
    vector<int> sltst(n,n-1);
    for(int i=1;i<=n-1;i++){
        if(str[i]==str[i-1])
        {
            sltst[i]-=1;
        }
        if(str[i-1]==str[i+1] ){
            int j=i+1;
            while(str[j]==str[n-j-1] and j<n){
                sltst[i]-=2;
                if(sltst[i]<0)
                    sltst[i]=0;
            
            j++;
            }
            
        }
        sltst[i+1]=sltst[i];
    }
    
//    return sltst[n-1]?sltst[n-1]>=0:0;
    return sltst[n-1];
    
}
int main()
{
    string str;
    cin>>str;
    
    cout<<min_slits(str)<<endl;
    
    return 0;
}
