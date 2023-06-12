// ! Date :- 12-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    ll ans = LLONG_MIN, prefixSum = 0, minPrefix = 0;
    for (auto x : nums)
    {
        prefixSum += x;
        ans = max(ans, prefixSum - minPrefix);
        minPrefix = min(minPrefix, prefixSum);
    }

    cout << ans << endl;
    return 0;
}