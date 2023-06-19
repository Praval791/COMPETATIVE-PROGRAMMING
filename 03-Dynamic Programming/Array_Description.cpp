// ! Date :- 19-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

class Solution
{
    ll n;
    const static ll mod = 1e9 + 7;
    ll util(ll i, ll m, vector<ll> &nums)
    {
        if (i == n)
            return 1;

        ll ans = 0;
        if (i == 0)
        {
            if (nums[i] != 0)
                ans = (1ll * ans + 1ll * util(i + 1, m, nums)) % mod;
            else
            {
                for (ll currVal = 1; currVal <= m; ++currVal)
                {
                    nums[i] = currVal;
                    ans = (1ll * ans + 1ll * util(i + 1, m, nums)) % mod;
                }
                nums[i] = 0;
            }
        }
        else
        {
            if (nums[i] != 0)
            {
                if (abs(nums[i] - nums[i - 1]) <= 1)
                    ans = (1ll * ans + 1ll * util(i + 1, m, nums)) % mod;
            }
            else
            {
                for (ll currVal = max(1ll, nums[i - 1] - 1); currVal <= min(m, nums[i - 1] + 1); ++currVal)
                {
                    // if (i == 9)
                    //     cout << "HERE";
                    nums[i] = currVal;
                    ans = (1ll * ans + 1ll * util(i + 1, m, nums)) % mod;
                }
                nums[i] = 0;
            }
        }
        return ans;
    }

public:
    // Brute Recursion
    void sol1(ll m, vector<ll> &nums)
    {
        n = nums.size();
        cout << util(0, m, nums);
    }

    // Tabulation DP
    void sol2(ll m, vector<ll> &nums)
    {
        n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
        if (nums[0] == 0)
            for (ll val = 1; val <= m; ++val)
                dp[0][val] = 1;
        else
            dp[0][nums[0]] = 1;

        for (ll i = 1; i < n; ++i)
            if (nums[i] != 0)
            {
                dp[i][nums[i]] = dp[i - 1][nums[i] - 1] + dp[i - 1][nums[i]];
                if (nums[i] < m)
                    dp[i][nums[i]] += dp[i - 1][nums[i] + 1];
                dp[i][nums[i]] %= mod;
            }
            else
            {
                for (ll val = 1; val <= m; ++val)
                {
                    nums[i] = val;
                    dp[i][nums[i]] = dp[i - 1][nums[i] - 1] + dp[i - 1][nums[i]];
                    if (nums[i] < m)
                        dp[i][nums[i]] += dp[i - 1][nums[i] + 1];
                    dp[i][nums[i]] %= mod;
                }
            }
        ll ans = 0;
        for (int i = 1; i <= m; ++i)
            ans = (ans + dp[n - 1][i]) % mod;
        cout << ans << ' ';
    }
};

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    Solution solution;
    solution.sol2(m, arr);
    return 0;
}