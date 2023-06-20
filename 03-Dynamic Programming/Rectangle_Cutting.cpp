// ! Date :- 19-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif
    ll length, width;
    cin >> length >> width;
    ll dp[length + 1][width + 1] = {0};

    // if there is only one width, then we need to cut length - 1 times
    for (int i = 1; i <= length; ++i)
        dp[i][1] = i - 1;

    // if there is only one length, then we need to cut width - 1 times
    for (int i = 1; i <= width; ++i)
        dp[1][i] = i - 1;

    for (int len = 2; len <= length; ++len)
        for (int wid = 2; wid <= width; ++wid)
            if (len != wid)
            {
                dp[len][wid] = 1e7;
                for (int i = 1; i < len; ++i)
                    dp[len][wid] = min(dp[len][wid], dp[i][wid] + dp[len - i][wid] + 1);
                for (int j = 1; j < wid; ++j)
                    dp[len][wid] = min(dp[len][wid], dp[len][j] + dp[len][wid - j] + 1);
            }
    cout << dp[length][width] << endl;

    return 0;
}