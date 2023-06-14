// ! Date :- 14-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
#define pll pair<ll, ll>
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll x;
    cin >> x;
    set<ll> nums1, nums2;
    for (ll i = 1; i <= x; i++)
        nums1.insert(i);

    bool flag = true;
    while (nums1.size())
    {

        for (auto it = nums1.begin(); it != nums1.end(); it++)
        {
            if (flag)
                nums2.insert(*it);
            else
                cout << *it << " ";
            flag = !flag;
        }
        nums1.clear();
        swap(nums1, nums2);
    }

    return 0;
}