#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;
#define ll long long

ll __gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	a %= b;
	return __gcd(b, a);
}

ll abso(ll a)
{
	if (a < 0)
		return -a;
	else
		return a;
}
ll npr(ll n, ll r)
{
	ll k = 0;
	ll mul = n;
	ll p = 1; //holds n*(n-1)*(n-2)..(n-k+1)
	while (k < n - r)
	{
		k++;
		p *= mul;
		mul--;
		// cerr<<p<< " " ;
	}
	return p;
}
ll ncr(ll n, ll r)
{

	// p holds the value of n*(n-1)*(n-2)...,
	// k holds the value of r*(r-1)...
	ll p = 1, k = 1;

	// C(n, r) == C(n, n-r),
	// choosing the smaller value
	if (n - r < r)
		r = n - r;

	if (r != 0)
	{
		while (r)
		{
			p *= n;
			k *= r;

			// gcd of p, k
			ll m = __gcd(p, k);

			// dividing by gcd, to simplify product
			// division by their gcd saves from the overflow
			p /= m;
			k /= m;

			n--;
			r--;
		}

		// k should be simplified to 1
		// as C(n, r) is a natural number
		// (denominator should be 1 ) .
	}

	else
		p = 1;

	// if our approach is correct p = ans and k =1
	return p;
}

ll ans(string a, string b, ll n)
{
	ll na = 0, nb = 0;
	for (auto c : a)
	{
		if (c == '1')
			na++;
	}
	for (auto c : b)
	{
		if (c == '1')
		{
			nb++;
		}
	}
	ll nmin = abso(na - nb) % 1000000007;
	ll nmax = 0;
	if (na + nb <= n)
	{
		nmax = (na + nb) % 1000000007;
	}
	else
	{
		nmax = (2 * n - na - nb) % 1000000007;
	}

	ll sum = 0;
	for (ll k = nmin; k <= nmax; k += 2)
	{
		sum += ncr(n, k);
	}
	cerr << nmin << " " << nmax << endl;
	return sum % 1000000007;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		ll prod = ans(a, b, n);
		cout << prod << endl;
		// cerr<<"npr"<<n pr(5,2)<<endl;
	}
}
