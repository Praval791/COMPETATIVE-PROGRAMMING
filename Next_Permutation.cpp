// ! Date :- 28-09-2022

// * https://practice.geeksforgeeks.org/problems/next-permutation5226/1

class Solution
{
public:
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        // 1 2 3 6 4 2
        // ____|______
        // code here
        // this mark the element, that's right side only have a decreasing sub array
        // hence these elements can't be swapped with each other
        // to make a next lexigraphically greater order
        // because they are already in a greatest possible order
        int index;
        for (index = n - 2; index >= 0; --index)
            if (arr[index] < arr[index + 1])
                break;

        int greaterThanInd;
        // if array is sorted
        if (index == -1)
            return vector<int>(arr.rbegin(), arr.rend());

        // new from the right sub array we find the element
        // that is just greater than the index's element.
        for (greaterThanInd = n - 1; greaterThanInd >= 0; --greaterThanInd)
            if (arr[greaterThanInd] > arr[index])
                break;
        swap(arr[greaterThanInd], arr[index]);
        // reverse the right array to get the smallest permutation of right array
        // because we just swapped the index with greaterThanInd that is
        // index < greaterThanInd so this will give the greater permutation of left side's sub array
        // and we have to minimize the right side so get the next greater
        reverse(arr.begin() + index + 1, arr.end());
        return arr;
    }
};