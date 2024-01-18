class Solution {
public:
    void sortColors(vector<int>& nums) {
  

    int i = 0;
    int j = 0;
    int k = nums.size() - 1;
    while (j <= k)
    {
        if (nums.at(j) == 2)
        {
           int temp =nums[j];
           nums[j]=nums[k];
           nums[k]=temp;
            k--;
        }
        else if (nums.at(j) == 0)
        {  
        int temp =nums[j];
           nums[j]=nums[i];
           nums[i]=temp;
            
            i++;
            j++;
        }

        else
            j++;
    }
}
};
