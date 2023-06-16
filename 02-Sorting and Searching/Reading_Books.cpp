// ! Date :- 16-06-2023

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
    ll nBooks;
    cin >> nBooks;
    vector<ll> books(nBooks);
    ll totalTime = 0;
    for (ll i = 0; i < nBooks; totalTime += books[i], i++)
        cin >> books[i];

    sort(books.begin(), books.end());
    ll ans = totalTime;
    // takes more time to read the last book then all other books combined
    if (totalTime - books[nBooks - 1] < books[nBooks - 1])
        ans = 2 * books[nBooks - 1];
    cout << ans << endl;
    return 0;
}