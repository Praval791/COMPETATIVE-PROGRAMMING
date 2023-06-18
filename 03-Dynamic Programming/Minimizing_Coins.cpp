// ! Date :- 18-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
// #define LOCAL

class Solution
{
    ll n;
    const static ll MAX_VAL = 1e6 + 10;
    ll util(ll targetSum, vector<ll> &nums, vector<ll> &dp)
    {
        // cout << targetSum << endl;
        if (targetSum == 0)
            return 0;
        if (targetSum < 0)
            return MAX_VAL;

        ll temp = MAX_VAL;
        for (ll x = 0; x < n and nums[x] <= targetSum; ++x)
            temp = min(temp, util(targetSum - nums[x], nums, dp) + 1);
        return dp[targetSum] = temp;
    }

public:
    // Memoization (TLE)
    void sol1(ll n, ll targetSum, vector<ll> &nums)
    {
        this->n = n;
        vector<ll> dp(targetSum + 1, -1);
        ll ans = util(targetSum, nums, dp);
        cout << (ans == MAX_VAL ? -1 : ans);
    }
    // Tabulation
    void sol2(ll n, ll targetSum, vector<ll> &nums)
    {
        this->n = n;
        vector<ll> dp(targetSum + 1, MAX_VAL);
        dp[0] = 0;
        for (ll currSum = 1; currSum <= targetSum; ++currSum)
            for (ll x = 0; x < n and nums[x] <= currSum; ++x)
                dp[currSum] = min(dp[currSum], dp[currSum - nums[x]] + 1);

        cout << (dp[targetSum] == MAX_VAL ? -1 : dp[targetSum]);
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