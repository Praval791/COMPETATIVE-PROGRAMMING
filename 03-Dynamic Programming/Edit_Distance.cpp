// ! Date :- 19-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
// #define LOCAL

class Solution
{
    string s1, s2;
    ll n, m;
    ll util(ll i, ll j, vector<vector<ll>> &dp)
    {
        if (i == n)
            return m - j;
        if (j == m)
            return n - i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = util(i + 1, j + 1, dp);

        dp[i][j] = 1e9;
        // Insert in s1
        dp[i][j] = min(dp[i][j], 1 + util(i, j + 1, dp));
        // remove in s2
        dp[i][j] = min(dp[i][j], 1 + util(i + 1, j, dp));
        // replace in s1
        dp[i][j] = min(dp[i][j], 1 + util(i + 1, j + 1, dp));
        return dp[i][j];
    }

public:
    Solution(string s_1, string s_2) : s1(s_1), s2(s_2), n(s_1.length()), m(s_2.length()) {}

    // Top Down, Memoization
    void sol1()
    {
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
        cout << util(0, 0, dp) << endl;
    }

    // Bottom up, Tabulation
    void sol2()
    {
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});

        cout << dp[n][m] << endl;
    }
};

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol(s1, s2);
    sol.sol2();

    return 0;
}