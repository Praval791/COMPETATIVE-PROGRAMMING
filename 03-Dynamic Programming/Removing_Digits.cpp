// ! Date :- 18-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    vector<ll> dp(n + 1, 1e9);

    for (ll i = 0; i <= min(9, n); ++i)
        dp[i] = 1;
    ll temp;
    for (ll i = 10; i <= n; ++i)
    {
        temp = i;
        while (temp)
        {
            dp[i] = min(dp[i], 1 + dp[i - temp % 10]);
            temp /= 10;
        }
    }
    cout << dp[n];

    return 0;
}