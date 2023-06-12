// ! Date :- 12-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    ll n, x, ans = 0;
    cin >> n >> x;
    vector<ll> children(n);
    for (int i = 0; i < n; i++)
        cin >> children[i];
    sort(children.begin(), children.end());

    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (children[i] + children[j] <= x)
            i++, j--;
        else
            j--;
        ans++;
    }

    cout << ans << endl;
    return 0;
}