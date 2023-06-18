// ! Date :- 18-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

class Solution
{
    ll n;
    const static ll MOD = 1e9 + 7;
    ll util(ll targetSum, vector<ll> &nums, vector<ll> &dp)
    {
        // cout << targetSum << endl;
        if (targetSum == 0)
            return 1;
        if (targetSum < 0)
            return 0;

        ll temp = 0;
        for (ll x = 0; x < n and nums[x] <= targetSum; ++x)
            temp = (temp + util(targetSum - nums[x], nums, dp)) % MOD;
        return dp[targetSum] = temp;
    }

public:
    // Memoization (TLE)
    void sol1(ll n, ll targetSum, vector<ll> &nums)
    {
        this->n = n;
        vector<ll> dp(targetSum + 1, -1);
        ll ans = util(targetSum, nums, dp);
        cout << ans;
    }
    // Tabulation
    void sol2(ll n, ll targetSum, vector<ll> &nums)
    {
        this->n = n;
        vector<ll> dp(targetSum + 1, 0);
        dp[0] = 1;
        for (ll currSum = 1; currSum <= targetSum; ++currSum)
            for (ll x = 0; x < n and nums[x] <= currSum; ++x)
                dp[currSum] = (dp[currSum] + dp[currSum - nums[x]]) % MOD;
        cout << dp[targetSum];
    }
};

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll n, targetSum;
    cin >> n >> targetSum;
    vector<ll> nums(n);
    for (ll i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());

    Solution solution;
    // solution.sol1(n, targetSum, nums);
    solution.sol2(n, targetSum, nums);
    return 0;
}