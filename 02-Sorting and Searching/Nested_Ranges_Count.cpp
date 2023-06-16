// ! Date :- 16-06-2023

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll int
#define endl "\n"
// #define LOCAL
// l, r, index
typedef array<ll, 3> query;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    vector<ll> contains(n);
    // right boundary , index (index is just used differentiate boundaries that have same value)
    ordered_set<pair<ll, ll>> rightBoundaries;
    for (ll i = n - 1; i >= 0; --i)
    {
        // insert current right boundary
        rightBoundaries.insert({queries[i][1], -1 * i});
        // the number of right boundaries that are less than current equal right boundary
        contains[queries[i][2]] = rightBoundaries.order_of_key({queries[i][1], -1 * i});
    }
    for (auto i : contains)
        cout << i << " ";
    cout << endl;

    // contained by other ranges
    vector<ll> contained(n);
    rightBoundaries.clear();
    for (ll i = 0; i < n; ++i)
    {
        // insert current right boundary
        rightBoundaries.insert({queries[i][1], -1 * i});
        // number of right boundaries that are greater than equal current right boundary
        contained[queries[i][2]] = rightBoundaries.size() - rightBoundaries.order_of_key({queries[i][1], -1 * i}) - 1;
    }
    for (auto i : contained)
        cout << i << " ";

    return 0;
}