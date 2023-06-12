// ! Date :- 12-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    ll n;
    cin >> n;
    vector<pair<int, int>> tickets(n);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        tickets[i] = {b, a};
    }
    sort(tickets.begin(), tickets.end());
    ll ans = 0, occupiedTill = -1;
    for (int i = 0; i < n; ++i)
    {
        if (tickets[i].second >= occupiedTill)
        {
            ans++;
            occupiedTill = tickets[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}