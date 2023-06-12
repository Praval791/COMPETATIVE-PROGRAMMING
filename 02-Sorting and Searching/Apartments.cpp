// ! Date :- 12-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> applicant(n), apartments(m);
    for (int i = 0; i < n; i++)
        cin >> applicant[i];
    for (int i = 0; i < m; i++)
        cin >> apartments[i];
    sort(applicant.begin(), applicant.end());
    sort(apartments.begin(), apartments.end());

    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m;)
    {
        if (abs(applicant[i] - apartments[j]) <= k)
            ans++, i++, j++;
        else if (applicant[i] < apartments[j])
            i++;
        else
            j++;
    }
    cout << ans << endl;
    return 0;
}