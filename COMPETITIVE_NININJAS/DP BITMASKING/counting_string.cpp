#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 1e5+5;
ll dp[N][3][3] , n , mod = 1e9+7;


int solve(int i , int big , int smaller)
{
    if (i > n)
    {
        return dp[i][big][smaller] = (big && !smaller);
    }
    if (dp[i][big][smaller] != -1)
        return dp[i][big][smaller];

    int ans = 0;
    for(char ch = 'A'; ch<='Z'; ch++)
    {
        if (ch > s[i]) ans = ((ans%mod) + (solve(i+1 , 1 , 0)%mod))%mod;
        else if (ch < s[i])
        {
            if (big) ans = ((ans%mod) + (solve(i+1 , big , 1)%mod))%mod;
        }
        else
        {
            ans = ((ans%mod) + (solve(i+1 , big , smaller)%mod))%mod;
        }
    }
    return dp[i][big][smaller] = ans;
}
int countStrings(char*st){
     string s= st;
     n = s.length();

     s = ' '+s;

    memset(dp , -1 , sizeof(dp));
return solve(1,0,0);

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
   
    cin >> s;
   

    cout << countStrings(s)<< "\n";

//
    return 0;
}