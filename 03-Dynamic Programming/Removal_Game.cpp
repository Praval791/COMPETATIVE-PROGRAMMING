// ! Date :- 19-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll totalSum = 0; // s1 + s2
    vector<ll> nums(n);
    vector<vector<ll>> minDiffForInterval(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
        totalSum += nums[i];
        minDiffForInterval[i][i] = nums[i];
    }
    for (int right = 0; right < n; ++right)
        for (int left = right - 1; left >= 0; --left)
        {
            ll chooseLeft = nums[left] - minDiffForInterval[left + 1][right];
            ll chooseRight = nums[right] - minDiffForInterval[left][right - 1];
            minDiffForInterval[left][right] = max(chooseLeft, chooseRight);
        }

    ll minDiffForBoundary = minDiffForInterval[0][n - 1]; // s1 - s2
    ll s1 = (totalSum + minDiffForBoundary) / 2;
    cout << s1 << endl;
    return 0;
}