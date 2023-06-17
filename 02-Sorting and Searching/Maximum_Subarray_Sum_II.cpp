// ! Date :- 17-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    /*
    n = length of nums
    a = min length of subarray
    b = max length of subarray
    */
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> nums(n), prefix(n + 1);
    for (int i = 0; i < n; prefix[i + 1] = prefix[i] + nums[i], i++)
        cin >> nums[i];

    ll ans = LLONG_MIN;
    /*
        8 3 5
         1  2  3  4  5  6  7  8    // index
        -1  3 -2  5  3 -5  2  2    // nums
      0 -1  2  0  5  8  3 -2  0    // prefixSum

      i = 3, essentialElements = {-1, 3, -2}, additional possibility = {}
      sum = prefix[3] - prefix[3 - 3]

      i = 4, essentialElements = {3, -2, 5}, additional possibility = {-1}
      sum = max(prefix[4] - prefix[4 - 3], prefix[4] - prefix[4 - 4])

      i = 5, essentialElements = {-2, 5, 3}, additional possibility = {3, -1}
      sum = max(prefix[5] - prefix[5 - 3], prefix[5] - prefix[5 - 4], prefix[5] - prefix[5 - 5])

      i = 6, essentialElements = {5, 3, -5}, additional possibility = {-2, 3}
      sum = max(prefix[6] - prefix[6 - 3], prefix[6] - prefix[6 - 4], prefix[6] - prefix[6 - 5])

      generalized sum for each index i
      sum = prefix[i] - min(prefix[i - a], prefix[i - a + 1], ..., prefix[i - b])

      all these prefixes can be stored in a multiset
    */
    multiset<ll> prefixSumOfOptionalElements;
    for (int i = a; i <= n; ++i)
    {
        if (i > b)
            prefixSumOfOptionalElements.erase(prefixSumOfOptionalElements.find(prefix[i - b - 1]));
        prefixSumOfOptionalElements.insert(prefix[i - a]);
        ans = max(ans, prefix[i] - *prefixSumOfOptionalElements.begin());
    }
    cout << ans;
    return 0;
}