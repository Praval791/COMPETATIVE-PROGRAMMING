// ! Date :- 11-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(char grid[][8], int i, int j)
{
    // not in same row
    for (int x = 0; x < 8; x++)
        if (grid[i][x] == 'Q' && x != j)
            return false;
    for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--)
        if (grid[x][y] == 'Q')
            return false;
    for (int x = i + 1, y = j - 1; x < 8 && y >= 0; ++x, y--)
        if (grid[x][y] == 'Q')
            return false;
    return true;
}

ll util(ll j, char grid[][8])
{
    if (j == 8)
        return 1;

    ll ans = 0;
    for (int k = 0; k < 8; k++)
        if (grid[k][j] == '.')
        {
            grid[k][j] = 'Q';
            if (check(grid, k, j))
                ans += util(j + 1, grid);
            grid[k][j] = '.';
        }
    return ans;
}

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    char grid[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> grid[i][j];
    ll ans = 0;

    for (int i = 0; i < 8; ++i)
        if (grid[i][0] == '.')
        {
            grid[i][0] = 'Q';

            ans += util(1, grid); // fill q in rest of cols
            grid[i][0] = '.';
        }
    cout << ans << endl;
    return 0;
}