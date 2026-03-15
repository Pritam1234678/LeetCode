class Solution {
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    bool canMeasureWater(int x, int y, int target) {

        if (target > x + y) {
            return false;
        }

        int g = gcd(x, y);

        if (g == 0) {
            return target == 0;
        }

        return target % g == 0;
    }
};
