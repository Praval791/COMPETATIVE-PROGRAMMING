// ! Date :- 19-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
// #define LOCAL

class Solution
{
    ll n;
    ll util(ll i, ll moneyIHave, vector<ll> &prices, vector<ll> &pages, vector<vector<ll>> &dp)
    {
        if (i == n or moneyIHave == 0)
            return 0;

        if (dp[i][moneyIHave] != 0)
            return dp[i][moneyIHave];

        // not buy current
        ll ans = util(i + 1, moneyIHave, prices, pages, dp);
        // purchase current book
        if (prices[i] <= moneyIHave)
            ans = max(ans, pages[i] + util(i + 1, moneyIHave - prices[i], prices, pages, dp));

        return dp[i][moneyIHave] = ans;
    }

public:
    void sol1(ll moneyIHave, vector<ll> &prices, vector<ll> &pages)
    {
        n = prices.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(moneyIHave + 1, 0));
        ll ans = util(0, moneyIHave, prices, pages, dp);
        cout << ans;
    }

    /*
    Since it is hard to keep track of the index of the book we are buying, we will buy books in order
    like first we buy only i = 0 book then store answers for all moneyIHave,
    then we buy i = 1 book and so on...
    */
    void sol2(ll moneyIHave, vector<ll> &prices, vector<ll> &pages)
    {
        ll n = prices.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(moneyIHave + 1, 0));
        for (ll i = 1; i <= n; ++i)
            for (ll availableMoney = 1; availableMoney <= moneyIHave; ++availableMoney)
            {
                // max of not buying current book and buying current book
                if (availableMoney >= prices[i - 1])
                    dp[i][availableMoney] = max(dp[i - 1][availableMoney], pages[i - 1] + dp[i - 1][availableMoney - prices[i - 1]]);
                else // if we don't have enough money to buy current book
                    dp[i][availableMoney] = dp[i - 1][availableMoney];
            }
        cout << dp[n][moneyIHave];
    }
};

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll nBooks, moneyIHave;
    cin >> nBooks >> moneyIHave;
    vector<ll> prices(nBooks), pages(nBooks);
    for (ll i = 0; i < nBooks; ++i)
        cin >> prices[i];
    for (ll i = 0; i < nBooks; ++i)
        cin >> pages[i];

    Solution solution;
    solution.sol2(moneyIHave, prices, pages);

    return 0;
}