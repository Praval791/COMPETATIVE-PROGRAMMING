// ! Date :- 12-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void sol1()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> price(n), ans(m, -1), customerCapacity(m);
    set<ll> notUsed;

    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < m; i++)
        cin >> customerCapacity[i];
    for (int i = 0; i < n; ++i)
        notUsed.insert(i);
    sort(price.begin(), price.end());
    for (int i = 0; i < m; ++i)
    {
        ll low = 0, high = n - 1, ind = -1;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (price[mid] <= customerCapacity[i])
            {
                ind = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (ind == -1)
            continue;
        auto it = notUsed.find(ind);
        if (it == notUsed.end())
        {
            it = notUsed.lower_bound(ind);
            if (it == notUsed.begin())
                continue;
            it--;
        }

        notUsed.erase(it);
        ans[i] = price[*it];
    }

    // print ans
    for (ll i = 0; i < m; i++)
        cout << ans[i] << endl;
}

void sol2()
{
    int n, m, x;
    cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        tickets.insert(x);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        auto it = tickets.upper_bound(x);
        if (it == tickets.begin())
            cout << -1 << "\n";
        else
            cout << *(--it) << "\n",
                tickets.erase(it);
    }
}

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    sol2();
    return 0;
}