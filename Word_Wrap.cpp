// ! Date :- 27-09-2022

// * https://practice.geeksforgeeks.org/problems/word-wrap1646/1

// DP Memoization
class Solution {
    int dp[505][2005];
    int solve(int index, int remaining, vector<int> &nums, int &k)
    {
        //Base Case: at last we will ignore the spaces so here we pay 0 cost
        if(index == nums.size()) return 0;
        // if we already had calculated then simply return it
        if(dp[index][remaining] != -1) return dp[index][remaining];
        
        int ans;
        // when we don't have choices bcoz if we fill nums[index] here then 
        // it will disobey the limit so we go to new line
        if(nums[index] > remaining)
        {
            // coz our 'remaining' include a space seperator but 
            // if this is last then we have to count that space in 'remaining' as well
            ans = (remaining + 1) * (remaining + 1) ;
            // k - nums[index] -1 = 'remaining',
            // when we fill next line by nums[index] and a space
            ans +=  solve(index + 1, k - nums[index] - 1, nums, k);
        }
        // Otherwise we have 2 choices
        else
        {
            // either we fill next word into new line
            int choice1 = (remaining + 1) * (remaining + 1) + solve(index + 1, k - nums[index] - 1, nums, k); 
            // or we fill in same line
            int choice2 = solve(index + 1, remaining - nums[index] - 1, nums, k);
            // we have to minimize the answer
            ans = min(choice1,choice2);
        }
        return dp[index][remaining] = ans;
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        memset(dp,-1,sizeof dp);
        return solve(0,k, nums , k);
    } 
};