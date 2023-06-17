// ! Date :- 17-06-2023

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
// #define LOCAL

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution
{
    ll totalCost(ll k, ordered_set<pair<ll, ll>> &s)
    {
        ll ans = 0;
        ll mid = k / 2;
        ll medianEle = (s.find_by_order(mid))->first;
        for (auto &ele : s)
            ans += abs(ele.first - medianEle);

        if (k % 2 == 0)
        {
            mid--;
            medianEle = (s.find_by_order(mid))->first;
            ll temp = 0;
            for (auto &ele : s)
                temp += abs(ele.first - medianEle);
            ans = min(ans, temp);
        }
        return ans;
    }

public:
    /*
    Using Ordered Set GIVING TLE
    */
    void sol1(ll n, ll k, vector<ll> &nums)
    {

        ordered_set<pair<ll, ll>> s;

        for (int i = 0; i < k; ++i)
            s.insert({nums[i], i});
        cout << totalCost(k, s) << ' ';

        for (int i = 0; i + k < n; ++i)
        {
            s.erase({nums[i], i});
            s.insert({nums[i + k], i + k});
            cout << totalCost(k, s) << ' ';
        }
    }

private:
    ll k;
    multiset<ll> lowVals, HighVals;
    ll lowSum, highSum;
    void insertInSets(ll val)
    {
        if (lowVals.empty() || val <= *lowVals.rbegin())
        {
            lowVals.insert(val);
            lowSum += val;
            if (lowVals.size() > (k + 1) / 2)
            {
                auto it = lowVals.rbegin();
                highSum += *it;
                lowSum -= *it;
                HighVals.insert(*it);
                lowVals.erase(--lowVals.end());
            }
        }
        else
        {
            HighVals.insert(val);
            highSum += val;
            if (HighVals.size() > k / 2)
            {
                auto it = HighVals.begin();
                lowSum += *it;
                highSum -= *it;
                lowVals.insert(*it);
                HighVals.erase(it);
            }
        }
    }

    void eraseInSets(ll val)
    {
        if (HighVals.find(val) != HighVals.end())
        {
            highSum -= val;
            HighVals.erase(HighVals.find(val));
        }
        else
        {
            lowSum -= val;
            lowVals.erase(lowVals.find(val));
            if (lowVals.empty() and !HighVals.empty())
            {
                lowSum += *HighVals.begin();
                lowVals.insert(*HighVals.begin());
                highSum -= *HighVals.begin();
                HighVals.erase(HighVals.begin());
            }
        }
    }

    ll median()
    {
        return *lowVals.rbegin();
    }

public:
    /*
        Using 2 multiSet
        lowerGroupCost = submissionOf[M - X]  ,for all X of LowerGroup and M = median
        => M*SizeOfLowerGroup - SumOfLowerGroup
        higherGroupCost = submissionOf[X - M]  ,for all X of HigherGroup and M = median
        => SumOfHigherGroup - M*SizeOfHigherGroup
        TotalCost = lowerGroupCost + higherGroupCost
        TotalCost = SumOfHigherGroup - SumOfLowerGroup
    */
    void sol2(ll n, ll k, vector<ll> &nums)
    {
        this->k = k;
        lowSum = highSum = 0;
        for (int i = 0; i < k; ++i)
            insertInSets(nums[i]);
        if (k % 2 == 0)
            cout << highSum - lowSum << ' ';
        else
            cout << highSum - lowSum + median() << ' ';
        for (int i = 0; i + k < n; ++i)
        {
            eraseInSets(nums[i]);
            insertInSets(nums[i + k]);
            if (k % 2 == 0)
                cout << highSum - lowSum << ' ';
            else
                cout << highSum - lowSum + median() << ' ';
        }
    }
};

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
    Solution solution;
    // solution.sol1(n, k, nums);
    solution.sol2(n, k, nums);
    return 0;
}