class Solution {
    public int subarraysDivByK(int[] nums, int k) {

        int n = nums.length;

        for (int i = 1; i < n; i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        HashMap<Integer, Integer> map = new HashMap<>();

        map.put(0, 1);

        int count = 0;

        for (int i = 0; i < n; i++) {

            int rem = ((nums[i] % k) + k) % k;

            if (map.containsKey(rem)) {
                count = count + map.get(rem);
            }

            map.put(rem, map.getOrDefault(rem, 0) + 1);
        }

        return count;
    }
}
