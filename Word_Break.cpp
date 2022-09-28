// ! Date :- 28-09-2022

// * https://practice.geeksforgeeks.org/problems/word-break1352/1

// DP Memoization
class Solution
{
    string str;
    unordered_set<string> map;
    vector<vector<int>> dp;
    bool util(int index, int size)
    {
        if (size == 0)
            return true;
        if (dp[index][size] != -1)
            return dp[index][size];

        for (int i = 1; i <= size; i++)
            if (map.count(str.substr(index, i)) and util(index + i, size - i))
                return dp[index][size] = true;
        return dp[index][size] = false;
    }

public:
    bool wordBreak(string str, vector<string> &B)
    {
        // code here
        this->str = str;
        for (const string &s : B)
            map.insert(s);
        dp.resize(str.length(), vector<int>(str.length() + 1, -1));
        return util(0, str.length());
    }
};

// DP Memoization optimized
class Solution
{
    string str;
    unordered_set<string> map;
    vector<int> dp;
    bool util(int index, int size)
    {
        if (size == 0)
            return true;
        if (dp[index] != -1)
            return dp[index];

        for (int i = 1; i <= size; i++)
            if (map.count(str.substr(index, i)) and util(index + i, size - i))
                return dp[index] = true;
        return dp[index] = false;
    }

public:
    bool wordBreak(string str, vector<string> &B)
    {
        // code here
        this->str = str;
        for (const string &s : B)
            map.insert(s);
        dp.resize(str.length(), -1);
        return util(0, str.length());
    }
};