// ! Date :- 17-06-2023

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll int
// #define LOCAL

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif
    /*
    n = total numbers
    k = size of window
    */
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    ordered_set<pair<ll, ll>> s;
    for (int i = 0; i < k; ++i)
        s.insert({nums[i], i});
    cout << (s.find_by_order((k - 1) / 2))->first << ' ';

    for (int i = 0; i + k < n; ++i)
    {
        s.erase({nums[i], i});
        s.insert({nums[i + k], i + k});
        cout << (s.find_by_order((k - 1) / 2))->first << ' ';
    }
    return 0;
}