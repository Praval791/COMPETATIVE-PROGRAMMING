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
    vector<ll> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins.begin(), coins.end());

    ll requiredSum = 1;
    for (auto x : coins)
    {
        if (x > requiredSum)
            break;
        requiredSum += x;
    }
    cout << requiredSum << endl;
    return 0;
}