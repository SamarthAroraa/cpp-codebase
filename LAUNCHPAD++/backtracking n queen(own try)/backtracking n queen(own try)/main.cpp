//
//  main.cpp
//  backtracking n queen(own try)
//
//  Created by Samarth Arora on 30/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
#define n 4
void printboard(bool board[n][n])
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";

    cout<<endl;
    }

}
bool issafe(bool board[n][n],int row, int col){
    int i,j;
    //check column attack
    for(int i=0;i<n;i++){
        if(board[i][col]==1)
            return false;
    }
    //check upper diaganol left
    for(i=col,j=row;i>=0 and j>=0;i--,j--){
        if(board[j][i]==1)
            return false;

    }
    //check upper diagonal right
    for(i=col,j=row;i<n and j>=0;i++,j--){
        if(board[j][i]==1)
            return false;
    }

    return true;

}
int placequeens(bool board[n][n],int row){
    //base case
    if(row>=n){
        printboard(board);
        cout<<endl;

        return true;
    }
    bool rval=false;
    for(int i=0;i<n;i++){
        if(issafe(board, row, i)){
            board[row][i]=1;
        if(placequeens(board, row+1))
        {

            board[row][i]=0;
            rval=true;


        }
        board[row][i]=0;
        }//backtrack
    }
    return rval;

}

int main()
{

    bool board[][n]={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}

    };
    if(placequeens(board, 0))
//    printboard(board);
    return  0;
}
