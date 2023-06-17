// ! Date :- 17-06-2023

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
    /*
    n = total numbers
    k = divide the array into k subArrays
    */
    ll n, k;
    cin >> n >> k;
    ll low = INT_MIN, high = 0;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        low = max(low, nums[i]);
        high += nums[i];
    }

    auto check = [&](ll maxSum)
    {
        ll currSum = 0;
        ll subArray = 1;
        for (auto &num : nums)
        {
            if (currSum + num > maxSum)
            {
                currSum = num;
                subArray++;
                if (subArray > k)
                    return false;
            }
            else
                currSum += num;
        }
        return true;
    };

    ll ans = high;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans;

    return 0;
}