class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int arr[n];
        arr[0] = h.at(0);
        int max = h.at(0);
        for (int i = 1; i < n; i++) {
            arr[i] = max;
            if (max < h.at(i))
                max = h.at(i);
        }
        int brr[n];
        brr[n - 1] = h.at(n - 1);
        max = h.at(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            brr[i] = max;
            if (max < h.at(i))
                max = h.at(i);
        }
        int water = 0;
        for (int i = 0; i < n; i++) {
            int minVal = min(arr[i], brr[i]);
            if (h.at(i) < minVal) {
                water += (minVal - h.at(i));
            }
        }
        return water;
    }
};
