class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);

        int sum = 0;
        int total = 0;

        for (int i = satisfaction.length - 1; i >= 0; i--) {

            sum = sum + satisfaction[i];

            if (sum <= 0) {
                break;
            }

            total = total + sum;
        }

        return total;
    }
}
