// ! Date :- 11-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    int n;
    cin >> n;
    unordered_set<string> ans;
    string curr = string(n, '0');
    cout << curr << endl;
    ans.insert(curr);
    while (true)
    {
        int curSize = ans.size();
        for (int i = 0; i < n; ++i)
        {
            if (curr[i] == '0')
                curr[i] = '1';
            else
                curr[i] = '0';
            if (ans.find(curr) == ans.end())
            {
                ans.insert(curr);
                cout << curr << endl;
                break;
            }

            if (curr[i] == '0')
                curr[i] = '1';
            else
                curr[i] = '0';
        }
        if (ans.size() == curSize)
            break;
    }
    return 0;
}