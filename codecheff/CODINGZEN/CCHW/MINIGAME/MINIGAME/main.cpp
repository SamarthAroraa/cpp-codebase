//
//  main.cpp
//  MINIGAME
//
//  Created by Samarth Arora on 16/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
//#include <queue>
#include<vector>
#include<algorithm>
using namespace std;
int result(vector<int> numbers){
    int s= numbers.size();
//    priority_queue<int> q;
//    for(int i=0;i<s;i++){
//        q.push(numbers[i]);
//    }
//    int dora=0, boots=0;
//    while (!q.empty()) {
//        dora+=q.top();
//        q.pop();
//        boots+=q.top();
//        q.pop();
//
//    }
//
//    if(boots>dora)
//        return 0;
//    else if(boots==dora)
//        return -1;
//    else
//        return 1;
//
    sort(numbers.begin(),numbers.end(),greater<int>());
    int dora=0;
    int boots=0;
    for(int i=0;i<s;i++){
        if(i%2==1)
            boots+=numbers[i];
        else
            dora+=numbers[i];
    }
//    cout<<dora<<'\n'<<boots<<endl;
        if(boots>dora)
            return 0;
        else if(boots==dora)
            return -1;
        else
            return 1;
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        if(result(nums)==1)
            cout<<"Dora"<<endl;
        else if(result(nums)==0)
            cout<<"Boots"<<endl;
        else
            cout<<"Draw"<<endl;
    }
    return 0;
}
