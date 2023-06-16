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
    ll machines, products;
    cin >> machines >> products;
    vector<ll> requiredTime(machines);
    ll minTime = LLONG_MAX;
    for (ll i = 0; i < machines; minTime = min(minTime, requiredTime[i]), i++)
        cin >> requiredTime[i];
    ll low = minTime, high = minTime * products;
    ll ans = high;
    // lambda function in cpp that name canMake return bool
    auto canMake = [&](ll time)
    {
        ll productsMade = 0;
        for (auto &timePerProd : requiredTime)
        {
            productsMade += time / timePerProd;
            if (productsMade >= products)
                return true;
        }
        return false;
    };

    while (low <= high)
    {
        ll currTime = low + (high - low) / 2;
        if (canMake(currTime))
            ans = currTime, high = currTime - 1;
        else
            low = currTime + 1;
    }
    cout << ans << endl;
    return 0;
}