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

    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (ll i = 0; i < n; ++i)
        cin >> nums[i];

    stack<ll> st;
    for (ll i = 0; i < n; ++i)
    {
        while (!st.empty() and nums[st.top()] >= nums[i])
            st.pop();
        if (st.empty())
            cout << 0 << ' ';
        else
            cout << st.top() + 1 << ' ';
        st.push(i);
    }

    return 0;
}