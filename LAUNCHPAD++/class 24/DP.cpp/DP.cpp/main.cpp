//
//  main.cpp
//  DP.cpp
//
//  Created by Samarth Arora on 12/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//vector<int> storage(100,-1);
//int fibo_dp_optim(int n){
//
//    if(n==0 or n==1)
//        return n;
//    if(storage[n]!=-1)
//        return storage[n];
//
//    int fibn=fibo_dp_optim(n-1)+fibo_dp_optim(n-2);
//    storage[n]=fibn;
//    return fibn;
//}
vector<int> dp(100,-1);

int div_by(int n,int count){
    if(dp[n]!=-1)
        return dp[n];
    
    int two=INT_MAX;
    int three=INT_MAX;
    int minus=INT_MAX;
    if(n<=1)
        return 0;
    if(n%3==0){
//        if(dp[n/3]!=-1){
//            three=dp[n/3];
//        }
        
//        else{
             three=div_by(n/3, count)   ;
            dp[n/3]=three;
//        }
    }
    if(n%2==0){
//        if(dp[n/2]!=-1)
//             two= dp[n/2];
//        else
        dp[n/2]=div_by(n/2, count);
            two=dp[n/2];
    }
        
        
//    }
//    if(dp[n-1]!=-1)
//        minus= dp[n-1];
//    else
        minus=div_by(n-1, count);
    int n_count=min(minus,min(three,two))+1;
        dp[n]=n_count;
    return n_count;
}

int div_by_iter(int n){
    vector<int> dp={0,0};
    int count1,count2,count3;
    for(int i=2;i<=n;i++){
        count2=INT_MAX;
        count3=INT_MAX;
        count1=INT_MAX;
        if(i%2==0){
             count2=dp[i/2];
        }
        if(i%3==0){
            count3=dp[i/3];
        }
        count1=dp[i-1];
        dp[i]=min(count1,min(count2,count3))+1;
    }
    return dp[n];
    
}

int bsts_iter(int n){
    
    vector<int> stor={1,1};
    for(int i=2;i<=n;i++)
    {
        int temp=0;
        for (int j=1; j<=i; j++) {
            temp+=stor[j-1]*stor[i-j];
            
        }
        stor[i]=temp;

        
//        int i_1=stor[i-1];
//
//        int n_i=stor[n-i];
//        stor[i]=n_i*i_1;
        }
    return stor[n];
    
}
int balanced(int n){
    vector<int> storage={1,1};
    for(int i=2;i<=n;i++)
    {
        storage[i]=storage[i-1]*storage[i-1]+2*storage[i-1]*storage[i-2];
    }
    
    return storage[n];
    
}
//int rod_cutting_memoized(int n,vector<int> prices){
//    if(n==0)
//        return 0;
//    int q;
//    for(int i=0;i<n;i++){
//         q=INT_MIN;
//        q=max(q,rod_cutting_memoized(n-i, prices)+prices[i]);
//    }
//    return q;
//}

int maxlen=INT_MIN;
int cnt=0;
unordered_map<string, int> memo;
int longest_subseq(string seq,string ans){
    if(seq.length()==0){
        if(memo[ans]!=0){
            cout<<"memo"<<endl;
            cnt++;
            return memo[seq];
        }
        int len=1;
        for(int i=0;i<ans.length()-1;i++)
        {
            int ch=ans[i]-'0';
            
            int next=ans[i+1]-'0';
            if(ch<next)
                len++;
            else break;
        }
        memo[ans]=len;
        return len;}
    
    int len=max(longest_subseq(seq.substr(1), ans+seq[0]),longest_subseq(seq.substr(1), ans));
    return len;
}

int itert_longest_subs(vector<int> array){
    int n= array.size();
    vector<int>  dp(n+1,1);
    for(int i=1;i<n;i++)
    {
        if(array[i]>array[i-1]){
            int temp=1;
            for(int j=i-1;j>=0;j--){
                temp=max(temp,dp[j]);
            }
            dp[i]=temp;
            dp[i]++;
            dp[i+1]=dp[i];

            
        }
        
    }
    int max=dp[0];
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
        if(max<dp[i])
            max=dp[i];
    }
    
    return max;}
int grouping(int n){
    vector<int> s={1,1};
    for(int i=2;i<=n;i++){
        int count1=(i-1)*s[i-2]+s[i-1];
        s[i]=count1;
    }
    return s[n];}




int num_ways(int n){
    vector<int> ways={1,1};
    int total=0;
    for(int i=2;i<=n;i++){
        total=ways[i-1]+ways[i-2];
        ways[i]=total;
        
    }
    return ways[n];
    
}
int numways_given_step_set(int n, vector<int> step_len)
{
//    if(n==0 or n==1)
//        return n;
    int s=step_len.size();
    vector<int> ways={1,1};
    int newways=0;
    for(int i=2;i<=n;i++){
        newways=0;
        for(int j=0;j<s;j++)
        {
            if(i-step_len[j]<0)
                continue;
            newways+=ways[i-step_len[j]];
            
        }
        ways[i]=newways;}
    
    return ways[n];
    
}
int longest_common(string str1, string str2,int len){
//    vector<int> st1;
//    vector<int> st2;
    if(str1.length()==0 or str2.length()==0)
        return len;
    
    if(str1[0]==str2[0])
        return longest_common(str1.substr(1), str2.substr(1),len+1);
    else{
        int len1=longest_common(str1, str2.substr(1), len);
        int len2=longest_common(str1.substr(1), str2, len);
        int newlen=max(len1,len2);
        return newlen;
    }
           
}

int longest_common_sp(string str1, string str2){
    int n1=str1.length();
    int n2=str2.length();
    //row and column of 2d dp array represent string length of first and second string
    int dp[n1][n2];
    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            dp[i][j]=0;
        }
    }
    int maxm=INT_MIN;
    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            if(i==0 or j==0)
                dp[i][j]=0;
            else{
                int pr1=i-1?i-1>=0:0;
                int pr2=j-1?j-1>=0:0;
                dp[i][j]= 1+  max(dp[i][pr2], dp[pr1][j]);
            }
        if(dp[i][j]>maxm)
            maxm=dp[i][j];
            }
    }

    return maxm;
    
}

int min_edits(string present,string goal,int steps){
    if(present==goal or present.length()==0 and goal.length()==0)
        return steps;
    if(present.length()==0)
        return steps+goal.length();
    if(goal.length()==0)
        return steps+present.length();
    
//    if(present.length()==0)
//        return -1;
    
    
    if(present[0]==goal[0])
        return min_edits(present.substr(1), goal.substr(1),steps);
        
    int replace=min_edits(goal[0]+present.substr(1), goal, steps+1);
    int del=INT_MAX;
    if(present.length()!=0)
        del=min_edits(present.substr(1), goal, steps+1);
    

    int insert=min_edits(present, goal.substr(1), steps+1);

    return min(replace,min(insert,del));
}
int min_edits_dp(string s1, string s2){
    int n=s1.length();
    int m=s2.length();
    int dp[n+1][m+1];
    for (int i=0; i<=n; i++) {
           for (int j=0; j<=m; j++) {
               if(i==0 or j==0)
                   dp[i][j]=i+j;
               else
                   dp[i][j]=0;
           }
       }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            int i_bound=i-1;
            int j_bound=j-1;
            if(s2[j-1]==s1[i-1]and i*j!=0){
                dp[i][j]=dp[i-1][j-1];
                cout<<'m';}
            else{
            dp[i][j]= 1 + min(dp[i_bound][j],min(dp[i][j_bound],dp[i_bound][j_bound]));
            }
            
        }
        
    }
    
    return dp[n-1][m-1];
    
}
int knapsack(vector<int> weights, vector<int> cost, int lim,int i){
   //RETURN MAX SUM
    
    if(i==weights.size())
        return 0;
//    if(weight>=lim)
//        return val;
    int max_without=INT_MIN;
    int max_with=INT_MIN;
    max_without=knapsack(weights,cost,lim,i+1);
    if(weights[i]<=lim)
    max_with=cost[i]+knapsack(weights,cost,lim-weights[i],i+1);
    
    return max(max_with,max_without);
}
int knapsack_dp(vector<int> weights, vector<int> values, int capacity){
    int m=values.size();
    int arr[m+1][capacity+1];
    //weight capacity array
    int i=0,j=0;
    for(i=0;i<=m;i++){
        //is the number of items in consideration from the weight stack
        for(j=0;j<=capacity;j++){
            
            // j is the current dynamic capacity of  the knaosack
            if(i*j==0){
                arr[i][j]=0;
                continue;
            }
            else{
                if(weights[i-1]<=j){
                    arr[i][j]=max(arr[i-1][j-weights[i-1]]+values[i-1], arr[i-1][j]);
                }
                else{
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
    }
    return arr[m][capacity];
    
}
int main()
{
//    cout<<div_by_iter(21)<<endl;
//    cout<<bsts_iter(4)<<endl;
//    cout<<balanced(5);
//    vector<int> array={-1,9,3,5,8,2,2};
//    cout<<itert_longest_subs(array);
//    cout<<rod_cutting_memoized(10, prices);
//    cout<<longest_subseq("035822", "");
//    cout<<'\n'<<cnt;
//    cout<<grouping(5);
//    cout<<num_ways(3);
//    vector<int> step_len={1,2};
//    cout<<numways_given_step_set(4, step_len);
//    string str1,str2;
//    cin>>str1;
//    cin>>str2;
//    cout<<min_edits_dp(str1, str2)<<endl;
    vector<int> weights={5,3,6,4};
    vector<int> val={50,30,60,50};
    int lim=9;
    cout<<knapsack_dp(weights, val, lim);
//    cout<<fibo_dp_optim(40);
    return 0;
}
