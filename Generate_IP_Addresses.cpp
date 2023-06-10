// ! Date :- 03-10-2022

// * https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1

// Backtracking
class Solution
{
    int n;
    string s;
    vector<string> ans;
    void util(int i, int prevVal, int noOfDot, string out)
    {
        if (prevVal > 255 or noOfDot > 3)
            return;
        if (i == n)
        {
            if (noOfDot == 3)
                ans.push_back(out);
            return;
        }
        if (prevVal == 0 or prevVal > 25) // 0 can't be a prefix and 25 is the max value of a single digit of ip (255)
            util(i + 1, s[i] - '0', noOfDot + 1, (out + '.' + s[i]));
        else
        {
            util(i + 1, prevVal * 10 + (s[i] - '0'), noOfDot, (out + s[i])); // if we don't put a dot
            util(i + 1, s[i] - '0', noOfDot + 1, (out + '.' + s[i]));        // if we put a dot
        }
    }

public:
    vector<string> genIp(string &s)
    {
        n = s.length();
        if (n > 12 or n < 4)
            return ans;

        this->s = s;
        string out;
        out = s[0];
        util(1, s[0] - '0', 0, out);
        return ans;
    }
};
