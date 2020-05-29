//
//  main.cpp
//  homework
//
//  Created by Samarth Arora on 21/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int recpower(int n,int power){
    //base case
//    if(power==1 )
//        return n;
    if(power==0)
        return 1;
    
    int ans;
    if((power&1)==1){
        ans=n*recpower(n, power/2)*recpower(n, power/2);
        return ans;
    }
    else{
        ans=recpower(n, power/2)*recpower(n, power/2);
        return ans;
        
    }
    return ans;}

int main()
{
    int n,p;
    cin>>n>>p;
    cout<<recpower(n, p)<<endl;
    return 0;
}
