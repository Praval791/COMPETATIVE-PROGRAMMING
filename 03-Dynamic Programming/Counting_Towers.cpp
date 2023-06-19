// ! Date :- 19-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

const ll mod = 1e9 + 7;

/*
   0          1          2          3          4
|__|__|    |_____|    |__|  |    |  |__|    |  |  |
|  |  |    |  |  |    |  |  |    |  |  |    |  |  |

|__|__|    |_____|    |     |
|     |    |     |    |     |
   5          6          7
*/

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    vector<ll> queries(t);
    for (int i = 0; i < t; i++)
        cin >> queries[i];
    ll max_query = *max_element(queries.begin(), queries.end());
    vector<array<ll, 8>> dp(max_query + 1);
    for (int i = 0; i < 8; ++i)
        dp[1][i] = 1;
    for (int i = 2; i <= max_query; ++i)
        for (int j = 0; j < 8; ++j)
            if (j >= 0 and j <= 4)
                dp[i][j] = (dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % mod;
            else
                dp[i][j] = (dp[i - 1][1] + dp[i - 1][6] + dp[i - 1][7]) % mod;

    for (auto i : queries)
        cout << (dp[i][1] + dp[i][6]) % mod << endl;
    return 0;
}