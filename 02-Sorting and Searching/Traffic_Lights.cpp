// ! Date :- 14-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
#define pll pair<ll, ll>
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll n, x;
    cin >> n >> x;
    set<ll> trafficLights{0, n};
    multiset<ll> lengths{0, n};
    ll l = 0, r = n;
    ll ans = 0;
    for (ll i = 1; i <= x; i++)
    {
        int e;
        cin >> e;

        auto [it, bo] = trafficLights.insert(e);

        ll prevVal = *prev(it);
        ll nextVal = *next(it);

        lengths.erase(lengths.find(nextVal - prevVal));
        lengths.insert(e - prevVal);
        lengths.insert(nextVal - e);

        cout << *lengths.rbegin() << " ";
    }
    return 0;
}