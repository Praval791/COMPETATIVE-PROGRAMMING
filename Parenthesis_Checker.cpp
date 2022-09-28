// ! Date :- 28-09-2022

// * https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

class Solution
{
public:
    bool ispar(string expr)
    {
        stack<char> temp;
        for (int i = 0; i < expr.length(); i++)
            if (temp.empty())
                temp.push(expr[i]);
            else if ((temp.top() == '(' && expr[i] == ')') || (temp.top() == '{' && expr[i] == '}') || (temp.top() == '[' && expr[i] == ']'))
                temp.pop();
            else
                temp.push(expr[i]);

        return temp.empty();
    }
};