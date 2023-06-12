// ! Date :- 12-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    ll n, ans = 0, mid;
    cin >> n;
    vector<ll> lengths(n);
    for (int i = 0; i < n; i++)
        cin >> lengths[i];
    sort(lengths.begin(), lengths.end());

    mid = lengths[n / 2];
    for (auto x : lengths)
        ans += (abs(x - mid));
    cout << ans << endl;
    return 0;
}