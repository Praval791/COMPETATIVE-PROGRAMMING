// ! Date :- 14-07-2022

// * https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

// DP Memoization
class Solution
{
    vector<vector<int>> dp;
    int dpUtil(int i, int j, string str)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (str[i] == str[j] && i != j)
            return dp[i][j] = 1 + dpUtil(i - 1, j - 1, str);

        return dp[i][j] = max(dpUtil(i - 1, j, str), dpUtil(i, j - 1, str));
    }

public:
    int LongestRepeatingSubsequence(string str)
    {
        dp.resize(str.length() + 1, vector<int>(str.length() + 1, -1));
        return dpUtil(str.length() - 1, str.length() - 1, str);
    }
};

// DP Tabulation
class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {

        int n1 = str.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n1 + 1, 0));

        for (int i = 0; i < n1; i++)
            for (int j = 0; j < n1; j++)
                if (str[i] == str[j] && i != j)
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);

        return dp[n1][n1];
    }
};