//
//  main.cpp
//  SAKTAN
//
//  Created by Samarth Arora on 06/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void flipall(vector<vector<bool>>&array,int x,int y,int rows,int cols){
//row flips
    for(int i=x+1;i<rows;i++){
        array[i][y]=!(array[i][y]);
    }
    for(int i=0;i<x;i++){
        array[i][y]=!(array[i][y]);
    }
//col flips
    for(int i=y+1;i<cols;i++){
        array[x][i]=!(array[x][i]);
    }
    for(int i=0;i<y;i++){
        array[x][i]=!(array[x][i]);
    }
    
    
}
int odds(vector<vector<bool>> array, int rows,int colums){
    int odds=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<colums;j++){
            if(array[i][j]==1)
            {odds+=1;}
            
        }
    }
    return odds;}


int main()
{
    int t;
    cin>>t;
    while(t--){
        
        int m,n,q;
        cin>>n>>m>>q;
        vector<vector<bool>> array(n,vector<bool>(m));
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                array[i][j]=0;
//            }
//        }
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            x--;y--;
            flipall(array, x, y, n, m);
        }
        cout<<odds(array,n,m)<<endl;
        array.clear();
        
    }

    return 0;}

