#include <vector>
using namespace std;

class Solution {
public:

    int binary(vector<int>& v, int t, int lo, int hi) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] == t) {
                return mid;
            }
            if (v[mid] > t) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& v, int t) {
        int n = v.size();
        int lo = 0;
        int hi = n - 1;

        if (n == 2) {
            if (t == v[0]) return 0;
            if (t == v[1]) return 1;
            return -1;
        }

        int pivot = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // Ensure we do not go out of bounds
            if (mid < hi && v[mid] > v[mid + 1]) {
                pivot = mid + 1;
                break;
            }
            if (mid > lo && v[mid] < v[mid - 1]) {
                pivot = mid;
                break;
            }

            if (v[mid] >= v[lo]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // If no pivot is found, the array is not rotated
        if (pivot == -1) {
            return binary(v, t, 0, n - 1);
        }

        // Decide which part to perform binary search on
        if (t >= v[0] && t <= v[pivot - 1]) {
            return binary(v, t, 0, pivot - 1);
        } else {
            return binary(v, t, pivot, n - 1);
        }
    }
};

