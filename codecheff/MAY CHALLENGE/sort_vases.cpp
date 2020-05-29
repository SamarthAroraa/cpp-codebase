#include <bits/stdc++.h>
using namespace std;

#define deb(x) cerr << #x << " " << x << endl;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define FOREACH(a, b) for (auto &(a) : (b))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define bitcount __builtin_popcount
#define gcd __gcd
#define se second
#define mp make_pair
#define pb push_back
#define TC(t) while (t--)
#define MAXN 19
// bool portals[MAXN][MAXN];
int minSwaps(int arr[], int n, unordered_map<int, bool> portals)
{
    // Create an array of pairs where first
    // element is array element and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    // Sort the array by array element values to
    // get right position of every element as second
    // element of pair.
    sort(arrPos, arrPos + n);

    // To keep track of visited elements. Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);

    // Initialize result
    int ans = 0;

    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;

        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            if (portals[j] != 1 or portals[arrPos[j].second] != 1)
                cycle_size++;

            // move to next node
            j = arrPos[j].second;
        }

        // Update answer by adding current cycle.
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }

    // Return result
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    TC(t)
    {
        
        int n, m;
        cin >> n >> m;
        int arr[n];
        REP(i, n)
        {
            cin >> arr[i];
        }
        // vii swaps;
        // RESET((portals), 0);
        unordered_map<int, bool> portals;
        REP(i, 19)
        {
            portals[i] = 0;
        }
        REP(i, m)
        {
            int f, s;
            cin >> f >> s;
            portals[f - 1] = 1;
            portals[s - 1] = 1;
        }

        cout << minSwaps(arr, n, portals) << endl;
    }

    return 0;
}

