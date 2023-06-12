// ! Date :- 12-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    int n;
    cin >> n;
    set<ll> v;

    for (int i = 0, x; i < n; i++)
        cin >> x, v.insert(x);

    cout << v.size() << endl;
    return 0;
}