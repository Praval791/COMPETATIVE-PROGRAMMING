// ! Date :- 19-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

/*
dp[n-1][maxSum] is valid because it counts the number of ways of making half the original target sum using a subset of numbers that excludes the final number n. Why does this work?

It's often easier to count "more ordered" versions of the things we want to count. Here, it's easy enough to count ordered bipartitions (that is, bipartitions in which we distinguish, say, 1, 4 | 2, 3 from 2, 3 | 1, 4), but for our purposes this would count them twice -- we want to count unordered ones. One way to do this is to continue counting the "more ordered version" as before, but impose constraints on which objects will be counted. Observe that, because all numbers are distinct, exactly one of the two parts in any "ordered bipartition" will contain the highest number n -- and that every unordered bipartition corresponds to exactly two of these ordered bipartitions (the one in which n appears in the first part, and the one in which n appears in the second part, obtained by swapping parts). So if we count only the "ordered bipartitions" in which the second part contains n, we count the number of unordered bipartitions. (This reasoning would work for any particular input element; n is just convenient.)

dp[n][maxSum]/2 would work if you were using unbounded integers, instead of modulo arithmetic. It doesn't work here (all the time) because division does not respect the modulo arithmetic. Suppose the correct answer is 500000004. That means that, before dividing by 2, you must have dp[n][maxSum] = 1000000008 -- but the modulo computation in your code would reduce that back to 1, leaving the incorrect final result dp[n][maxSum]/2 = 1/2 = 0.
*/

const ll mod = 1e9 + 7;
int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2)
    {
        cout << 0;
        return 0;
    }
    sum /= 2;
    vector<vector<ll>> dp(n, vector<ll>(sum + 1, 0));
    dp[0][0] = 1;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            ll left = j - i;
            if (left >= 0)
                (dp[i][j] += dp[i - 1][left]) %= mod;
        }
    }
    cout << dp[n - 1][sum];
    return 0;
}