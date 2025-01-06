class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            // Check if the current position is empty and both neighbors are
            // empty (or out of bounds)
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1; // Plant a flower
                n--;              // Decrease the required number of flowers

                if (n <= 0)
                    return true; // Stop early if n flowers are planted
            }
        }
        return n <=
               0; // Return true if all flowers are planted, false otherwise
    }
};

