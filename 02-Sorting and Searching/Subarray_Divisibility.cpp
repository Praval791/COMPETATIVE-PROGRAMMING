// ! Date :- 16-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    map<ll, ll> mp{{0, 1}};
    ll ans = 0;
    ll prefixSum = 0;
    for (int i = 0; i < n; ++i)
    {
        prefixSum += nums[i];
        ll rem = prefixSum % n;
        rem = rem < 0 ? rem + n : rem;
        ans += mp[rem]++;
    }
    cout << ans;
    return 0;
}