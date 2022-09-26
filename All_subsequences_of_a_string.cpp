// ! Date :- 15-07-2022

// *https://www.geeksforgeeks.org/print-subsequences-string/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class SubSequences
{
    void util1(int index, string input, vector<string> &sequences, string output = "")
    {
        if (index >= input.size())
        {
            sequences.push_back(output);
            return;
        }
        // either we pick the current char
        util1(index + 1, input, sequences, output + input[index]);
        // or either we not.
        util1(index + 1, input, sequences, output);
    }

    void util2(int index, int &size, string input, vector<string> &sequences, string output = "")
    {
        if (index == size)
            return;

        if (!output.empty())
            sequences.push_back(output);

        for (int i = index + 1; i < size; i++)
        {
            util2(i, size, input, sequences, output + input[i]);
        }
    }

public:
    vector<string> getAllSubsequences1(string input)
    {
        vector<string> sequences;
        util1(0, input, sequences);
        return sequences;
    }

    vector<string> getAllSubsequences2(string input)
    {
        vector<string> sequences;
        int n = input.length();
        util2(-1, n, input, sequences);
        return sequences;
    }

    vector<string> getAllSubsequences3(string input)
    {
        vector<string> sequences;
        int n = input.length();
        unsigned int possibleCombination = (1 << n);
        for (int num = 0; num < possibleCombination; ++num)
        {
            string output("");
            for (int i = 0; i < n; ++i)
                if (num & (1 << i))
                    output += input[i];

            if (output.length() > 0)
                sequences.push_back(output);
        }
        return sequences;
    }
};

// Driver code
int main()
{
    // auto start = high_resolution_clock::now();

    string input;
    cin >> input;
    SubSequences obj;
    vector<string> sequences;
    // method 1
    // sequences = obj.getAllSubsequences1(input);

    // method 2
    //  sequences = obj.getAllSubsequences2(input);

    // method 3
    if (input.length() < 31)
        sequences = obj.getAllSubsequences3(input);

    for (auto x : sequences)
        cout << x << " ";
    cout << endl;

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() << endl;

    return 0;
}
