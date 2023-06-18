// ! Date :- 18-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
// #define LOCAL

class Solution
{
    const static ll mod = 1e9 + 7;
    int util(ll targetSum, vector<ll> &dp)
    {
        if (targetSum == 0)
            return 1;
        if (dp[targetSum] != -1)
            return dp[targetSum];
        long long ans = 0;
        for (ll i = 1; i <= min(targetSum, 6); i++)
            ans += util(targetSum - i, dp);
        return dp[targetSum] = ans % mod;
    }

public:
    // Memoization
    void sol1(ll targetSum)
    {
        vector<ll> dp(targetSum + 1, -1);
        cout << util(targetSum, dp);
    }

    // Tabulation
    void sol2(ll targetSum)
    {
        vector<ll> dp(targetSum + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= targetSum; ++i)
            for (int j = 1; j <= min(i, 6); ++j)
                dp[i] = (1ll * dp[i] + dp[i - j]) % mod;

        cout << dp[targetSum];
    }
};

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll targetSum;
    cin >> targetSum;
    Solution solution;
    // solution.sol1(targetSum);
    solution.sol2(targetSum);
    return 0;
}