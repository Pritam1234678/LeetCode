class Solution {
public:
    int first(vector<int>& v, int t) {
        int lo = 0;
        int hi = v.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] == t) {
                if (mid == 0 || v[mid - 1] != t) {
                    return mid;
                } else {
                    hi = mid - 1;
                }
            } else if (v[mid] > t) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }

    int last(vector<int>& v, int t) {
        int lo = 0;
        int hi = v.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] == t) {
                if (mid == v.size() - 1 || v[mid + 1] != t) {
                    return mid;
                } else {
                    lo = mid + 1;
                }
            } else if (v[mid] < t) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& v, int t) {
        int x = first(v, t);
        int y = last(v, t);
        return {x, y};
    }
};
