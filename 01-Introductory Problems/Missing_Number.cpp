#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == mid + 1)
            l = mid + 1;
        else
            r = mid;
    }
    cout << r + 1 << endl;
    return 0;
}