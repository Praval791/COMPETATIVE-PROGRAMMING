// ! Date :- 16-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif
    /*
    n = total numbers
    target = distinct element count
    */
    ll n, target;
    cin >> n >> target;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    long long ans = 0;
    multiset<ll> s;
    long long distinctCount = 0;
    ll left = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s.find(nums[i]) == s.end())
            distinctCount++;
        s.insert(nums[i]);
        while (distinctCount > target)
        {
            s.erase(s.find(nums[left]));
            if (s.find(nums[left]) == s.end())
                distinctCount--;
            left++;
        }
        // cout << s.size() << ' ' << left << endl;
        ans += s.size();
    }
    cout << ans;
    return 0;
}