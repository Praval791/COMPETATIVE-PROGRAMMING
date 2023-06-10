// ! Date :- 10-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const ll mod = 1000000007;

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);

    ll n;
    cin >> n;
    ll ans = 1;
    while (n--)
    {
        ans = (ans * 2) % mod;
    }
    cout << ans << endl;
    return 0;
}