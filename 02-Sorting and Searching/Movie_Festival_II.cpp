// ! Date :- 17-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif
    ll n, clubSize;
    cin >> n >> clubSize;
    vector<pair<int, int>> tickets(n);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        tickets[i] = {b, a};
    }
    sort(tickets.begin(), tickets.end());

    ll ans = 0;
    ll index = 1;
    multiset<ll> mp; // occupied Till

    for (auto &[end, start] : tickets)
    {
        if (mp.empty())
        {
            mp.insert(end);
            ++ans;
        }
        else
        {
            if (*mp.begin() <= start)
            {
                auto it = mp.upper_bound(start);
                if (it != mp.begin())
                    --it;
                mp.erase(it);
                mp.insert(end);
                ++ans;
            }
            else if (mp.size() < clubSize)
            {
                mp.insert(end);
                ++ans;
            }
        }
        // cout << "Map->";
        // for (auto &x : mp)
        //     cout << x << ' ';
        // cout << endl;
        ++index;
    }
    cout << ans << endl;
    return 0;
}