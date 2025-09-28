import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> arr;

    public List<List<Integer>> subsets(int[] nums) {
        arr = new ArrayList<>();
        List<Integer> current = new ArrayList<>();
        backtrack(0, nums, current);
        return arr;
    }

    private void backtrack(int index, int[] nums, List<Integer> current) {
        // base case: reached end — add a copy of current subset
        if (index == nums.length) {
            arr.add(new ArrayList<>(current));
            return;
        }
        backtrack(index + 1, nums, current);
        current.add(nums[index]);
        backtrack(index + 1, nums, current);
        current.remove(current.size() - 1);
    }
}

