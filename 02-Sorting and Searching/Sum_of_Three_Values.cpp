// ! Date :- 16-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif
    ll n, target;
    cin >> n >> target;
    vector<pair<ll, ll>> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i)
    {
        ll findAble = target - nums[i].first;
        ll left = i + 1, right = n - 1;
        while (left < right)
        {
            ll sum = nums[left].first + nums[right].first;
            if (sum == findAble)
            {
                cout << nums[i].second << ' ' << nums[left].second << ' ' << nums[right].second;
                return 0;
            }
            else if (sum > findAble)
                --right;
            else
                ++left;
        }
        // while (i + 1 < n and nums[i] == nums[i + 1])
        //     ++i;
    }

    cout << "IMPOSSIBLE";
    return 0;
}