// ! Date :- 19-06-2023

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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    set<ll> s;
    s.insert(0);
    for (int i : a)
    {
        vector<ll> temp;
        for (int j : s)
            temp.push_back(i + j);
        for (int j : temp)
            s.insert(j);
    }
    cout << s.size() - 1 << endl;
    for (int i : s)
        if (i != 0)
            cout << i << " ";
    return 0;
}