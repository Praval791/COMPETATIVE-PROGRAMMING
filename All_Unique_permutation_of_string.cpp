// ! Date :- 14-07-2022

// * https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

class Solution
{
    vector<string> permutations;
    vector<bool> visited;
    unordered_set<string> hash;
    void dfs(string output, string s, int &n)
    {
        if (output.length() == n)
        {
            if (hash.find(output) == hash.end())
                permutations.push_back(output), hash.insert(output);
            return;
        }
        for (int i = 0; i < n; i++)
            if (!visited[i])
            {
                visited[i] = true;
                dfs(output + s[i], s, n);
                visited[i] = false;
            }
    }

public:
    vector<string> find_permutation(string S)
    {
        // Code here there
        int n = S.length();
        visited.resize(n, 0);
        dfs("", S, n);
        sort(permutations.begin(), permutations.end());
        return permutations;
    }
};

class Solution
{
    vector<string> permutations;
    unordered_set<string> hash;
    void dfs(int index, string s, int &n)
    {
        if (index == n - 1 && hash.find(s) == hash.end())
            permutations.push_back(s), hash.insert(s);
        else
            for (int i = index; i < n; i++)
            {
                swap(s[i], s[index]);
                dfs(index + 1, s, n);
                swap(s[i], s[index]);
            }
    }

public:
    vector<string> find_permutation(string S)
    {
        // Code here there
        int n = S.length();
        dfs(0, S, n);
        sort(permutations.begin(), permutations.end());
        return permutations;
    }
};
