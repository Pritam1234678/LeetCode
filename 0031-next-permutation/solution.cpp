class Solution {
public:
    void nextPermutation(vector<int>& nums) {

          int n = nums.size();
    int idx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums.at(i) < nums.at(i + 1))
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        reverse(nums.begin(), nums.end()); // Fix: Reverse the entire array
        return;
    }

    reverse(nums.begin() + idx + 1, nums.end());
    int j = -1;
    for (int i = idx + 1; i < n; i++)
    {
        if (nums.at(i) > nums.at(idx))
        {
            j = i;
            break;
        }
    }

    swap(nums.at(idx), nums.at(j));
    return; 
    }
};
