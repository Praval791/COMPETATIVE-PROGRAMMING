// ! Date :- 15-06-2023

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll int
#define endl "\n"
#define pll pair<ll, ll>
// #define LOCAL

// https://codeforces.com/blog/entry/11080
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solutions
{

public:
    void sol1(ll n, ll k)
    {
        int p = k % n;
        ordered_set<int> indexedSet;
        for (int i = 1; i <= n; i++)
            indexedSet.insert(i);
        while (indexedSet.size())
        {
            auto itr = indexedSet.find_by_order(p);
            cout << *itr << endl;
            indexedSet.erase(itr);
            if (indexedSet.size())
                p = (p + k) % indexedSet.size();
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll n, k;
    cin >> n >> k;
    Solutions solution;
    solution.sol1(n, k);
    return 0;
}