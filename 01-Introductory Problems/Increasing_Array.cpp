#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    int maxSoFar = v[0];
    long long ans = 0;
    for (int &i : v)
        if (i < maxSoFar)
            ans += maxSoFar - i;
        else
            maxSoFar = i;
    cout << ans << endl;

    return 0;
}