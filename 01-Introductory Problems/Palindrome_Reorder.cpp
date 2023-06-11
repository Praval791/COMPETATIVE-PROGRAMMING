// ! Date :- 10-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    vector<int> chars(26, 0);
    char c;
    while (cin >> c)
        chars[c - 'A']++;
    // chars with character
    int oddCount = -1;
    for (int i = 0; oddCount != -2 and i < 26; i++)
        if (chars[i] & 1)
            oddCount = oddCount == -1 ? i : -2;
    if (oddCount == -2)
        cout << "NO SOLUTION" << endl;
    else
    {
        string ans = "";
        for (int i = 0; i < 26; ++i)
            ans += string(chars[i] / 2, i + 'A');
        cout << ans;
        if (oddCount != -1)
            cout << char(oddCount + 'A');
        cout << string(ans.rbegin(), ans.rend()) << endl;
    }
    return 0;
}