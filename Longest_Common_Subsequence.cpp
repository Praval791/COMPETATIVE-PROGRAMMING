// ! Date :- 03-10-2022

// * https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

class Solution
{
    vector<vector<int>> dp;
    int x, y;
    string s1, s2;

public:
    int util(int i, int j)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + util(i - 1, j - 1);
        return dp[i][j] = max(util(i - 1, j), util(i, j - 1));
    }

public:
    int lcs(int x, int y, string text1, string text2)
    {
        this->x = x;
        this->y = y;
        s2 = text2;
        s1 = text1;
        dp.resize(x + 1, vector<int>(y + 1, -1));
        return util(x - 1, y - 1);
    }
};

class Solution
{
public:
    int lcs(int n1, int n2, string text1, string text2)
    {
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (text1[i] == text2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[n1][n2];
    }
};