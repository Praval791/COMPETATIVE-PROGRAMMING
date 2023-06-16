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
    ll nTasks;
    cin >> nTasks;
    vector<pair<ll, ll>> tasks(nTasks);
    for (ll i = 0; i < nTasks; i++)
        cin >> tasks[i].first >> tasks[i].second;

    sort(tasks.begin(), tasks.end(), [](pair<ll, ll> &a, pair<ll, ll> &b)
         { return a.first != b.first ? a.first < b.first : a.second > b.second; });

    ll ans = 0, time = 0;
    for (auto [duration, deadline] : tasks)
        ans += deadline - (time += duration);

    cout << ans << endl;
    return 0;
}