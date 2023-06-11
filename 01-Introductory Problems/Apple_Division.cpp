// ! Date :- 11-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll util(int i, ll s1, vector<ll> &v, ll &sum)
{
    if (i == v.size())
        return abs((sum - s1) - s1);

    return min(util(i + 1, s1 + v[i], v, sum), util(i + 1, s1, v, sum));
}

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    ll ans = LLONG_MAX;
    cout << util(0, 0, v, sum);
    return 0;
}