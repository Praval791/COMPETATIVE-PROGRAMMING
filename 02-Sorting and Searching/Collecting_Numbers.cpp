// ! Date :- 13-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    ll n, x, ans = 0;
    cin >> n;
    set<ll> numbers;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        auto it = numbers.find(x - 1);
        if (it != numbers.end())
            numbers.erase(it);
        else
            ans++;
        numbers.insert(x);
    }
    cout << ans << endl;
    return 0;
}