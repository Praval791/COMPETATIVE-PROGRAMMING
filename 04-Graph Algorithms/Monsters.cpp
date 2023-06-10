// https://cses.fi/problemset/task/1194

// You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

// Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

// Input
// The first input line has two integers n and m : the height and width of the map.
// After this there are n lines of m characters describing the map. Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.

// Output
// First print "YES" if your goal is possible, and "NO" otherwise.
// If your goal is possible, also print an example of a valid path (the length of the path and its description using characters D, U, L, and R). You can print any path, as long as its length is at most n * m steps.

// Constraints
// 1≤n,m≤1000

// Example

// Input:
// 5 8
// ########
// #M..A..#
// #.#.M#.#
// #M#..#..
// #.######

// Output:
// YES
// 5
// RRDDR

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

char dir[] = {'D', 'U', 'R', 'L'};
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool isValid(int x, int y, int n, int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}

bool dfs(int i, int j, vector<vector<int>> &dist, vector<vector<char>> &labyrinth, int n, int m, string &path)
{
    if (labyrinth[i][j] != '#')
    {
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
        {
            cout << "YES" << endl;
            cout << path.size() << endl;
            cout << path << endl;
            return true;
        }
    }
    bool ans = false;
    int currDist = dist[i][j];
    for (int ind = 0; ind < 4; ++ind)
    {
        int ni = i + dr[ind];
        int nj = j + dc[ind];

        if (isValid(ni, nj, n, m) and labyrinth[ni][nj] != '#' and dist[ni][nj] > currDist + 1)
        {
            path += dir[ind];
            dist[ni][nj] = currDist + 1;
            ans = ans || dfs(ni, nj, dist, labyrinth, n, m, path);
            path.pop_back();
        }
    }
    return ans;
}

// TLE Solution
int main()
{

    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    /*
    . = floor
    # = wall
    A = start
    M = monster
    */
    vector<vector<char>> labyrinth(n, vector<char>(m, 0));
    /*
    stores minimum distance from any of the monsters
    -1 is for wall
    */
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    int sourceI, sourceJ;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'M')
                dist[i][j] = 0, q.push({i, j}); // source for bfs
            else if (labyrinth[i][j] == 'A')
                sourceI = i,
                sourceJ = j; // source for bfs
            else if (labyrinth[i][j] == '#')
                dist[i][j] = -1; // not reachable
        }

    // int time = 1;
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        int distReachCur = dist[i][j];
        for (int ind = 0; ind < n; ++ind)
        {
            int ni = i + dr[ind];
            int nj = j + dc[ind];
            if (isValid(ni, nj, n, m) and dist[ni][nj] > distReachCur + 1)
                dist[ni][nj] = distReachCur + 1, q.push({ni, nj});
        }
    }
    dist[sourceI][sourceJ] = 0;

    // dist matrix
    // for (auto v : dist)
    // {
    //     for (auto i : v)
    //         cout << setw(3) << i;
    //     cout << endl;
    // }

    // dfs from A to reach the boundary
    string path = "";
    bool isPossible = dfs(sourceI, sourceJ, dist, labyrinth, n, m, path);
    if (!isPossible)
        cout << "NO" << endl;

    return 0;
}