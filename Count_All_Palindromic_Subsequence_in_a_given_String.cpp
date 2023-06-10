// ! Date :- 30-09-2022

// * https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
class Solution
{
    const static int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    string str;
    int n;
    long long int util(int i, int j)
    {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (str[i] == str[j])
            return dp[i][j] = (1 + util(i + 1, j) + util(i, j - 1)) % MOD;
        return dp[i][j] = ((util(i + 1, j) + util(i, j - 1) - util(i + 1, j - 1)) % MOD + MOD) % MOD;
    }

public:
    long long int countPS(string str)
    {
        // Your code here
        this->str = str;
        n = str.length();
        dp.resize(n, vector<int>(n, -1));
        return util(0, n - 1);
    }
};
