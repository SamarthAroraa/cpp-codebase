//
//  main.cpp
//  rat in maze
//
//  Created by Samarth Arora on 10/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.

#include <iostream>
using namespace std;

bool chckright(char board[1000][1000], int n,int m,int i,int j){
    if(board[i][j+1]=='O')
        return true;
    else return false;
    
}
bool chckdown(char board[1000][1000], int n,int m, int i,int j){
    if(board[i+1][j]=='O')
        return true;
    else return false;
    
}
void printb(char board[1000][1000],int n,int m){
//    cout<<"************************"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='U'){
            cout<<"1 ";
            
        }
        else if(board[i][j]=='O' or board[i][j]=='X'){
            cout<<"0 ";
        }
        }
        cout<<endl;
    }
//    cout<<"****************************"<<endl;
}

int goratty(char board[1000][1000],int n,int m,int i,int j){
    if(i==n-1 and j==n-1){
//        printb(board, n,m);
        board[i][j]='U';
        return true;
    }
    else if(i>=n or j>=m)
        return false;
    if(board[i][j]=='X')
        return false;
        
    
    
//    for(int j=0;j<n;j++){
       
            board[i][j]='U';
            if(goratty(board, n,m, i, j+1))
                return true;
           
            
        
       
           
            if(goratty(board, n,m, i+1, j))
                return true;
            board[i][j]='O';
        
    
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    string input;
//    cin>>input;
    char board[1000][1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            
        }
    }
//    printb(board, n, m);
    if(goratty(board, n,m, 0, 0))
    {
        printb(board, n,m);
    }
    else{
        cout<<-1;
    }
    
    
    return 0;
}
