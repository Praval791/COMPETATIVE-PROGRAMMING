// ! Date :- 03-10-2022

// * https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1

class Solution
{
public:
    int minimumNumberOfSwaps(string S)
    {
        vector<int> pos;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] == '[')
                pos.push_back(i);

        int openingBrace = 0;
        int nextPos = 0; // give the position of the next opening brace by which we perform swap operation
        long totalSwaps = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            // Increment openingBrace and move nextPos to next position
            if (s[i] == '[')
            {
                ++openingBrace;
                ++nextPos;
            }
            else if (s[i] == ']')
                --openingBrace;

            // We have encountered an unbalanced part of string
            // since the number of opening brackets and closing brackets are same
            // thus we make sure that we have at least one opening bracket after current index.
            if (openingBrace < 0)
            {
                // Increment totalSwaps by number of swaps required
                totalSwaps += pos[nextPos] - i;
                swap(s[i], s[pos[nextPos]]);
                // increment the nextPos because curr nextPos '[' can't help us another time to balancing the string
                ++nextPos;

                // Reset openingBrace to 1
                openingBrace = 1;
            }
        }
        return totalSwaps;
    }
};

class Solution
{
public:
    int minimumNumberOfSwaps(string S)
    {
        // code here
        int openBraces = 0, closeBrace = 0;
        int extraClose = 0;
        int swaps = 0;
        for (const char &x : S)
            if (x == '[')
            {
                ++openBraces;
                if (extraClose > 0) // only if we have extra close braces then swap it with current opening brace
                    swaps += extraClose--;
            }
            else
            {
                ++closeBrace;
                extraClose = closeBrace - openBraces;
            }

        return swaps;
    }
};