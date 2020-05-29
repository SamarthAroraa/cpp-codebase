#include <bits/stdc++.h>

using namespace std;




int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    long long t;
    cin >> t;
    while(t--)
    {
        long long n, m;

        cin >> n >> m;
    long long fruit_type[n],fruit_cost[n];//change 2
long long sumcost[m+1];

    for(long long i=0;i<=m;i++){
        sumcost[i]=0;
    }

        for(long long i = 0;i<n;i++)
            cin >> fruit_type[i];

         for(long long i = 0;i<n;i++)
            cin >> fruit_cost[i];

        long long minsum = INT_MAX,sum = 0;//CHANGE 1
        // for(long long i = 1;i<=m;i++)
        // {
        //     sum = 0;
        //     for(long long j = 0;j<n;j++)
        //         {
        //             if(fruit_type[j] == i)
        //             sum += fruit_cost[j];

        //         }
        // if(sum!=0)
        //    minsum=min(minsum,sum);


        //  }

        //  if(minsum==INT_MAX)
        //     minsum=0;
        for(long long i=0;i<n;i++){
            sumcost[fruit_type[i]]+=fruit_cost[i];
        }

        // long long minsum=INT_MAX;
        for(long long i=1;i<=m;i++){
            if(sumcost[i]!=0)
            minsum=min(minsum, sumcost[i]);
        }
        // if(minsum!=INT_MAX)
        cout << minsum <<endl;

    }

return 0;
}