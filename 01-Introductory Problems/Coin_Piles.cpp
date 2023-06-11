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
        ll p1, p2;
        cin >> p1 >> p2;
        if (p1 == p2)
        {
            if (p1 % 3 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (p1 > p2)
        {
            if (p1 > 2 * p2)
            {
                cout << "NO" << endl;
                continue;
            }
            ll diff = p1 - p2;
            ll pi = p1 - 2 * diff;
            ll pj = p2 - diff;
            if (pi == pj && pi % 3 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            if (p2 > 2 * p1)
            {
                cout << "NO" << endl;
                continue;
            }
            ll diff = p2 - p1;
            ll pi = p1 - diff;
            ll pj = p2 - 2 * diff;
            if (pi == pj && pi % 3 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}