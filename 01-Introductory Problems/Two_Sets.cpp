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
    if (((n + 1) / 2) & 1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        if (n & 1)
        {
            cout << (n + 1) / 2 << endl
                 << 1 << ' ' << 2 << ' ';
            ll fir = 4, sec = n;
            while (fir < sec)
            {
                cout << fir << ' ' << sec << ' ';
                fir += 2;
                sec -= 2;
            }
            cout << endl
                 << n / 2 << endl
                 << 3 << ' ';
            fir = 5, sec = n - 1;
            while (fir < sec)
            {
                cout << fir << ' ' << sec << ' ';
                fir += 2;
                sec -= 2;
            }
        }
        else
        {
            ll fir = 1, sec = n;
            cout << n / 2 << endl;
            while (fir < sec)
            {
                cout << fir << ' ' << sec << ' ';
                fir += 2;
                sec -= 2;
            }
            cout << endl;
            fir = 2, sec = n - 1;
            cout << n / 2 << endl;
            while (fir < sec)
            {
                cout << fir << ' ' << sec << ' ';
                fir += 2;
                sec -= 2;
            }
        }
        cout << endl;
    }
    return 0;
}