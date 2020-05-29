#include <iostream>
#include <vector>
#include <numeric>

// #define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
ll answer(ll n, ll *arr)
{
	// along rows- gcd and along columns indexes of array elements
	ll **dp = new ll *[101];
	for (ll i = 0; i < 101; i++)
	{
		dp[i] = new ll[n];
	}
	for (ll i = 0; i < 101; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			dp[i][j] = 0;
		}
	}
	dp[arr[0]][0]++;
	for (ll i = 1; i < n; i++)
	{
		dp[arr[i]][arr[i] - 1]++;

		for (ll j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				// dp[1][i]+=dp[1][j];
				for (ll k = 0; k < 101; k++)
				{
					if (dp[k][j] != 0)
					{
						ll newgcd = gcd(dp[k][j], arr[i]);
						// deb(newgcd)
						// deb(i)
						dp[newgcd][i] = (dp[newgcd][i] % 1000000007 + (dp[k][j] % 1000000007)) % 1000000007;
					}
				}
			}
		}
	}

	// for(ll i=0;i<101;i++){
	// 		for(ll j=0;j<=n;j++){
	// 			cout<<dp[i][j]<<"\t";
	// 		}
	// 	cout<<endl;
	// 	}

	// cout<<"**********************\n";
	ll sum = 0;
	for (ll i = 0; i < n; i++)
	{
		sum = (sum % 1000000007 + dp[1][i] % 1000000007) % 1000000007;
	}
	for (ll i = 0; i < 101; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin >> n;
	ll *arr = new ll[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << answer(n, arr);
	delete[] arr;
	// cerr<<gcd(2,2)
	return 0;
}