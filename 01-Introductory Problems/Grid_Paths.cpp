// ! Date :- 11-06-2023

#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;
#define ll long long int

bool visited[7][7] = {0};
string s;
ll ans = 0;

void util2(int i, int j, int curr)
{
    if (i == 6 and j == 0)
    {
        ans += (curr == 48);
        return;
    }

    // check if we move from here then will this move divide the grid into two visited parts
    if (((i + 1 == 7 || i == 0 || (visited[i - 1][j] && visited[i + 1][j])) && j - 1 >= 0 && j + 1 < 7 && !visited[i][j - 1] && !visited[i][j + 1]) ||
        ((j + 1 == 7 || j == 0 || (visited[i][j - 1] && visited[i][j + 1])) && i - 1 >= 0 && i + 1 < 7 && !visited[i - 1][j] && !visited[i + 1][j]))
        return;

    visited[i][j] = true;
    if (i + 1 < 7 and !visited[i + 1][j] and (s[curr] == 'D' or s[curr] == '?'))
        util2(i + 1, j, curr + 1);

    if (i - 1 >= 0 and !visited[i - 1][j] and (s[curr] == 'U' or s[curr] == '?'))
        util2(i - 1, j, curr + 1);

    if (j + 1 < 7 and !visited[i][j + 1] and (s[curr] == 'R' or s[curr] == '?'))
        util2(i, j + 1, curr + 1);

    if (j - 1 >= 0 and !visited[i][j - 1] and (s[curr] == 'L' or s[curr] == '?'))
        util2(i, j - 1, curr + 1);

    visited[i][j] = false;
}

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);

    // auto start = high_resolution_clock::now();
    cin >> s;

    // cout << util(0, 0, s, 0) << endl;
    util2(0, 0, 0);
    cout << ans << endl;

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds"<< "\n";
    return 0;
}