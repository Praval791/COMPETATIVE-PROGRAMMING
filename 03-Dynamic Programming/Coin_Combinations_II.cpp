// ! Date :- 18-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

class Solution
{
    ll n;
    const static ll MOD = 1e9 + 7;

public:
    // Tabulation
    void sol1(ll n, ll targetSum, vector<ll> &nums)
    {
        this->n = n;
        vector<ll> dp(targetSum + 1, 0);
        dp[0] = 1;
        for (ll x = 0; x < n; ++x)
            for (ll currSum = 1; currSum <= targetSum; ++currSum)
                if (currSum >= nums[x])
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
    solution.sol1(n, targetSum, nums);
    return 0;
}