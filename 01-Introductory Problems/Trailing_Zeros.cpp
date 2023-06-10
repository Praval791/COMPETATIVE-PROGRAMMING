// ! Date :- 10-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);

    ll n;
    cin >> n;
    ll ans = 0;
    ll current = 5;
    while (current <= n)
    {
        ans += n / current;
        current *= 5;
    }
    cout << ans << endl;
    return 0;
}