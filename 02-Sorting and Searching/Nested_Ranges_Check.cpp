// ! Date :- 16-06-2023

#include <bits/stdc++.h>

using namespace std;
#define ll int
// l, r, index
typedef array<ll, 3> query;
#define endl "\n"

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    vector<query> queries(n);
    for (int i = 0; i < n; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][2] = i;
    }

    /*
    1 _________ 10
    1 ________ 9
     2 _______ 8
      3 ____ 6
    */
    sort(queries.begin(), queries.end(), [](query a, query b)
         { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });

    // contains other ranges
    vector<bool> contains(n);
    ll minRightBound = INT_MAX;
    for (ll i = n - 1; i >= 0; --i)
    {
        if (queries[i][1] >= minRightBound)
            contains[queries[i][2]] = 1;
        minRightBound = min(minRightBound, queries[i][1]);
    }
    for (auto i : contains)
        cout << i << " ";
    cout << endl;

    // contained by other ranges
    vector<bool> contained(n);
    ll maxRightBound = INT_MIN;
    for (ll i = 0; i < n; ++i)
    {
        if (queries[i][1] <= maxRightBound)
            contained[queries[i][2]] = 1;
        maxRightBound = max(maxRightBound, queries[i][1]);
    }
    for (auto i : contained)
        cout << i << " ";

    return 0;
}