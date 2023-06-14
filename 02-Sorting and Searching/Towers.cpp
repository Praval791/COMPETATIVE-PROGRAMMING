// ! Date :- 14-06-2023

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
    multiset<ll> mp;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        int e;
        cin >> e;
        auto it = mp.upper_bound(e);
        if (it != mp.end())
            mp.erase(it);
        else
            ans++;
        mp.insert(e);
    }
    cout << ans << endl;
    return 0;
}