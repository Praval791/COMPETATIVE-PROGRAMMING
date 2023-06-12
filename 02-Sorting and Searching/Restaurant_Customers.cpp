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
    map<int, int> customers;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        customers[a]++;
        customers[b]--;
    }
    ll ans = 0, curr = 0;
    for (auto &[k, v] : customers)
    {
        curr += v;
        ans = max(ans, curr);
    }
    cout << ans << endl;
    return 0;
}