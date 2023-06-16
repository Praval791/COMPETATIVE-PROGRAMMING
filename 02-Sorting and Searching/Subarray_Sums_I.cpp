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
    ll n, target;
    cin >> n >> target;
    vector<ll> nums(n), prefix(n + 1);
    for (int i = 0; i < n; prefix[i + 1] = prefix[i] + nums[i], ++i)
        cin >> nums[i];

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        binary_search(prefix.begin(), prefix.end(), prefix[i] - target) ? ans++ : ans;
    cout << ans;
    return 0;
}