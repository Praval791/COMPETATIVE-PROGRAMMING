// ! Date :- 13-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll n, m;
    cin >> n >> m;
    vector<ll> nums(n + 1), positions(n + 2);

    for (ll i = 1; i <= n; i++)
        cin >> nums[i], positions[nums[i]] = i;

    ll ans = 0;
    for (ll num : nums)
        if (positions[num] > positions[num + 1])
            ans++;
    set<pair<ll, ll>> updatedPair;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        ll num1 = nums[a], num2 = nums[b];
        if (num1 + 1 <= n)
            updatedPair.insert({num1, num1 + 1});
        if (num1 - 1 >= 1)
            updatedPair.insert({num1 - 1, num1});
        if (num2 + 1 <= n)
            updatedPair.insert({num2, num2 + 1});
        if (num2 - 1 >= 1)
            updatedPair.insert({num2 - 1, num2});

        // remove contribution of previous pair
        for (auto &[n1, n2] : updatedPair)
            ans -= (positions[n1] > positions[n2]);

        // previous pair is updated
        swap(nums[a], nums[b]);
        positions[num1] = b;
        positions[num2] = a;

        // add contribution of new pair
        for (auto &[n1, n2] : updatedPair)
            ans += (positions[n1] > positions[n2]);

        updatedPair.clear();
        cout << ans << endl;
    }
    return 0;
}