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
// we don't actually concern about size because the recursion is first goes for prefix
// if prefix1 = 'prefix' then suppose we can break this into dictionary words then
// for another overlapping problem that check for prefix2 and now this prefix2 have any prefix same as
// prefix1 then we don't need check for every size of this prefix
// so that's why we don't need to keep track of size.

// Simply the dp[index] is true if str[i.....n] can be break into dictionary entries.
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