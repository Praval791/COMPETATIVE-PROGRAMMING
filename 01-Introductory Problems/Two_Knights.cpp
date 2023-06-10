// ! Date :- 10-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll countWays(ll k)
{
    // possible ways to place knight1 in a k X k size board
    ll k1 = k * k;
    // possible ways to place knight2 in a k X k size board
    ll k2 = k1 - 1;
    // the total number of ways to place two knights
    ll place2knights = k1 * k2 / 2;
    // number of attacks possible by a knight in a 2 X 3 size block or 3 X 2 size block
    ll attackPossiblePerBlock = 2;
    // find possible number of 2 X 3 size blocks that can be placed in k X k size board
    ll noOf2by3 = (k - 1) * (k - 2);
    // find possible number of 3 X 2 size blocks that can be placed in k X k size board
    ll noOf3by2 = (k - 2) * (k - 1);
    // total number of 2 X 3 or 3 X 2 size blocks that can be placed in k X k size board
    ll totalNoOfBlocks = noOf2by3 + noOf3by2;
    // total number of attacks possible by a knight in a k X k size board
    ll notPlacableCells = totalNoOfBlocks * attackPossiblePerBlock;
    return place2knights - notPlacableCells;
}

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);

    ll n;
    cin >> n;
    for (ll k = 1; k <= n; k++)
        cout << countWays(k) << endl;

    return 0;
}