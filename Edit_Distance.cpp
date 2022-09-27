// ! Date :- 27-09-2022

// * https://practice.geeksforgeeks.org/problems/edit-distance3702/1

// dp Memoization
class Solution
{
    string s, t;
    int sn, tn;
    vector<vector<int>> dp;
    int dpUtil(int sInd, int tInd)
    {
        if (tInd == tn)
            return sn - sInd;
        if (sInd == sn)
            return tn - tInd;
        if (dp[sInd][tInd] != -1)
            return dp[sInd][tInd];
        if (s[sInd] == t[tInd])
            return dp[sInd][tInd] = dpUtil(sInd + 1, tInd + 1);
        return dp[sInd][tInd] = 1 + min(dpUtil(sInd + 1, tInd),
                                        min(dpUtil(sInd, tInd + 1),
                                            dpUtil(sInd + 1, tInd + 1)));
    }

public:
    int editDistance(string s, string t)
    {
        // Code here
        if (s == t)
            return 0;
        this->s = s;
        this->t = t;
        sn = s.size();
        tn = t.size();
        dp.resize(sn, vector<int>(tn, -1));
        return dpUtil(0, 0);
    }
};

// dp Tabulation
class Solution
{
public:
    int editDistance(string s, string t)
    {
        if (s == t)
            return 0;
        int sn = s.length(), tn = t.length();
        vector<vector<int>> dp(sn + 1, vector<int>(tn + 1, 0));

        for (int j = 0; j < tn + 1; j++)
            dp[sn][j] = tn - j;
        for (int i = 0; i < sn + 1; i++)
            dp[i][tn] = sn - i;

        for (int i = sn - 1; i >= 0; --i)
            for (int j = tn - 1; j >= 0; --j)
            {
                if (s[i] == t[j])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = 1 + min({dp[i + 1][j],
                                        dp[i][j + 1],
                                        dp[i + 1][j + 1]});
            }
        return dp[0][0];
    }
};