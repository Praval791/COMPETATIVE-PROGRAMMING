// ! Date :- 12-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> nums(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums[i] = {x, i + 1};
    }
    sort(nums.begin(), nums.end());

    int i = 0, j = n - 1;
    while (i < j)
    {
        ll sum = nums[i].first + nums[j].first;
        if (sum == x)
        {
            cout << nums[i].second << ' ' << nums[j].second << endl;
            return 0;
        }
        else if (sum < x)
            i++;
        else
            j--;
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}