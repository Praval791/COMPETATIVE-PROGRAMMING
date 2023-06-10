// ! Date :- 10-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll spiralNo = max(x, y);
        ll firstElement = (spiralNo - 1) * (spiralNo - 1) + 1;
        ll ans;
        if (spiralNo & 1)
        {
            if (x == spiralNo)
                ans = firstElement + y - 1;
            else
                ans = firstElement + y - 1 + spiralNo - x;
        }
        else
        {
            if (y == spiralNo)
                ans = firstElement + x - 1;
            else
                ans = firstElement + x - 1 + spiralNo - y;
        }
        cout << ans << endl;
    }
    return 0;
}