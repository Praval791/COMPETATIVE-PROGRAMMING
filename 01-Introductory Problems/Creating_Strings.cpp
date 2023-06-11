// ! Date :- 11-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

set<string> ans;
void util(vector<char> &v, string s, int sze)
{
    if (s.size() == sze)
    {
        ans.insert(s);
        return;
    }
    for (int i = 0; i < 26; i++)
        if (v[i] > 0)
        {
            v[i]--;
            util(v, s + (char)(i + 'a'), sze);
            v[i]++;
        }

    return;
}
int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    vector<char> v(26, 0);
    int size = 0;
    char c;
    while (cin >> c)
        v[c - 'a']++, ++size;
    string s = "";
    util(v, s, size);
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << endl;
    return 0;
}