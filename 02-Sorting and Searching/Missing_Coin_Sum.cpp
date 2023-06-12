// ! Date :- 12-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    ll n;
    cin >> n;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins.begin(), coins.end());

    /* currentSum = all sum that can be made till now
    if next element is x then it can be paired with all the elements
    from 1 ... currentSum and make sum from 1+x ... currentSum+x
    thus now you have sum
    from {1 ... currentSum and x, 1 + x ... currentSum+x}

    so if(x > currentSum + 1) that means there is a gap in the sum
    and currentSum + 1 is the smallest sum that cannot be made
    */
    ll currSum = 0, requiredSum = currSum + 1;
    for (auto x : coins)
    {
        requiredSum = currSum + 1;
        if (x > requiredSum)
            break;
        currSum += x;
    }

    cout << requiredSum << endl;
    return 0;
}