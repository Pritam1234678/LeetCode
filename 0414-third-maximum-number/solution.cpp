class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long max1 = LONG_MIN , max2 = LONG_MIN , max3 = LONG_MIN;

        for(int i = 0; i < n; i++){
            if(nums[i] == max1 || nums[i] == max2 || nums[i] == max3) continue;

            if(nums[i] > max1){
                max3 = max(max3 , max2);
                max2 = max(max2 , max1);
                max1 = nums[i];
            }
            else{
                if(nums[i] > max2){
                    max3 = max(max3 , max2);
                    max2 = nums[i];
                }
                else{
                    max3 = max(max3 , (long long) nums[i]);
                }
            }
        }

        if(max3 != LONG_MIN) return max3;

        return max1;
    }
};
