// ! Date :- 18-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

const ll mod = 1e9 + 7;

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    /*
    0 : without trap
    1 : with trap
    */
    vector<vector<bool>> grid(n, vector<bool>(n));

    char ch;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < n; ++j)
        {
            cin >> ch;
            if (ch == '*')
                grid[i][j] = 1;
        }
    if (grid[0][0] || grid[n - 1][n - 1])
    {
        cout << 0;
        return 0;
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    dp[0][0] = 1;
    for (int j = 0; j < n and !grid[0][j]; ++j)
        dp[0][j] = 1;
    for (int i = 0; i < n and !grid[i][0]; ++i)
        dp[i][0] = 1;
    for (ll i = 1; i < n; ++i)
        for (ll j = 1; j < n; ++j)
            if (!grid[i][j])
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    cout << dp[n - 1][n - 1];
    return 0;
}