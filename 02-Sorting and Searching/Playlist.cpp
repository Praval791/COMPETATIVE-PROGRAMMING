// ! Date :- 13-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
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
    map<ll, ll> mp;
    ll ans = 0;
    ll left = 0;
    for (ll right = 1; right <= n; right++)
    {
        int e;
        cin >> e;
        auto &x = mp[e];
        if (x > left)
            left = x;
        ans = max(ans, right - left);
        x = right;
    }
    // cout << left << endl;
    ans = max(ans, n - left);
    cout << ans << endl;
    return 0;
}