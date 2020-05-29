[19:58, 4/29/2020] Samarth Arora: ho sake toh
[19:58, 4/29/2020] Utkarsh Gupta ECE NSUT: #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;


bool allcoloured(bool*colour,int n){
    for(int i = 1; i < n+1 ; i++){
        if(!colour[i]){
            return false;
        }
    }
    return true;
}

int helper(bool* colour,int n){
    if(allcoloured(colour,n)){
        return 1;
    }
    int sum = 0;
    for(int i = 1 ; i < n+1 ; i++){
        int a = 0;
        if(!colour[i] && (colour[i-1] || colour[i+1])){
            colour[i] = true;
            a = helper(colour,n);
            colour[i] = false;
        }
        sum = (sum % INT_MAX + a % INT_MAX) % INT_MAX;
    }
    return sum % INT_MAX;
}

int main() {

    int n;
    cin >> n;
    int m;
    cin >> m;
    bool* colour = new bool[n+2];
    for(int i = 0 ; i < n+2 ; i++){
        colour[i] = false;
    }
    colour[0] = false;
    colour[n+1] = false;
    for(int i = 0 ; i < m ; i++){
        int v1;
        cin >> v1;
        colour[v1] = true;
    }
    int ans = helper(colour,n) % INT_MAX;
    cout << ans;
    return 0;
}